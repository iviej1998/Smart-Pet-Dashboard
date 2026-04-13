//
// Created by Angel Madrigal on 4/11/26.
//
#include "Database.h"
#include <iostream>
#include <sstream>
#include <mysqlx/xdevapi.h>

bool Database::connect() {
    try {
        // Connect to the server
        session = new mysqlx::Session(host, port, userName, password, databaseName);
        //Grab database schema with name
        schema = new mysqlx::Schema(session->getSchema(databaseName));

        return true;

    } catch (const mysqlx::Error &err) {
        std::cerr << "Error: " << err.what() << std::endl;
    }
    return false;
}

void Database::disconnect() {
    try {
        session->close();
        delete session;
        session = nullptr;
        delete schema;
        schema = nullptr;
    } catch (const mysqlx::Error &err) {
        std::cerr << "Error: " << err.what() << std::endl;
    }
}
bool Database::executeQuery(const std::string& query) { //Use of INSERT, DELETE, UPDATE
    try {
        session->sql(query).execute();
        return true;
    } catch (const mysqlx::Error &err) {
        std::cerr << "Error: " << err.what() << std::endl;
    }
    return false;
}

Database::QueryResult Database::executeSelectQuery(const std::string& query) { //Use for SELECT
    QueryResult actualRes;
    try {
        mysqlx::RowResult res =  session->sql(query).execute();
        mysqlx::Row currentRow;
        const mysqlx::Columns& cols = res.getColumns();

        while ((currentRow = res.fetchOne())) {
            Row row;
            for (auto i = 0; i < res.getColumnCount(); ++i) {
                //Checks for int or string in row for value in map
                if (currentRow[i].getType() == mysqlx::Value::Type::INT64) {
                    row[cols[i].getColumnName()] = std::to_string(currentRow[i].get<int>());
                } else if (currentRow[i].getType() == mysqlx::Value::Type::DOUBLE) {
                    row[cols[i].getColumnName()] = std::to_string(currentRow[i].get<double>());
                } else if (currentRow[i].getType() == mysqlx::Value::Type::STRING) {
                    row[cols[i].getColumnName()] = currentRow[i].get<std::string>();
                } else if (currentRow[i].getType() == mysqlx::Value::Type::BOOL) {
                    row[cols[i].getColumnName()] = std::to_string(currentRow[i].get<bool>());
                } else if (currentRow[i].getType() == mysqlx::Value::Type::VNULL) {
                    row[cols[i].getColumnName()] = "";
                } else if (currentRow[i].getType() == mysqlx::Value::Type::UINT64) {
                    row[cols[i].getColumnName()] = std::to_string(currentRow[i].get<uint64_t>());
                }
            }
            actualRes.push_back(row);
        }
        return actualRes;
    } catch (const mysqlx::Error &err) {
        std::cerr << "Error: " << err.what() << std::endl;
    }
    return actualRes;
}

Database::~Database() {
    disconnect();
}


