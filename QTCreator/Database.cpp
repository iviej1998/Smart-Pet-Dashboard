#include "Database.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

bool Database::connect() {
    try {
        std::cout << "Host: [" << host << "]" << std::endl;
        std::cout << "User: [" << userName << "]" << std::endl;
        std::cout << "DB: [" << databaseName << "]" << std::endl;
        std::cout << "Port: [" << port << "]" << std::endl;

        driver = sql::mysql::get_mysql_driver_instance();

        sql::ConnectOptionsMap connection_properties;
        connection_properties["hostName"] = sql::SQLString(host);
        connection_properties["userName"] = sql::SQLString(userName);
        connection_properties["password"] = sql::SQLString(password);
        connection_properties["port"] = port;

        connection.reset(driver->connect(connection_properties));

        if (!databaseName.empty()) {
            connection->setSchema(databaseName);
        }

        std::cout << "Connected to database successfully." << std::endl;
        return true;

    } catch (const sql::SQLException& err) {
        std::cerr << "SQL Error: " << err.what()
        << "\nError Code: " << err.getErrorCode()
        << "\nSQLState: " << err.getSQLState()
        << std::endl;
    } catch (const std::bad_alloc& err) {
        std::cerr << "Memory Error: " << err.what() << std::endl;
    } catch (const std::exception& err) {
        std::cerr << "Error: " << err.what() << std::endl;
    }
    return false;
}
void Database::disconnect() {
    try {
        if (connection) {
            connection->close();
            connection.reset();
        }
    } catch (const sql::SQLException& err) {
        std::cerr << "SQL Error: " << err.what() << std::endl;
    }
}

bool Database::executeQuery(const std::string& query) {
    try {
        if (!connection) {
            std::cerr << "No active database connection." << std::endl;
            return false;
        }

        std::unique_ptr<sql::Statement> stmt(connection->createStatement());
        stmt->execute(query);
        return true;

    } catch (const sql::SQLException& err) {
        std::cerr << "SQL Error: " << err.what()
        << "\nError Code: " << err.getErrorCode()
        << "\nSQLState: " << err.getSQLState()
        << std::endl;
    }
    return false;
}

Database::QueryResult Database::executeSelectQuery(const std::string& query) {
    QueryResult actualRes;

    try {
        if (!connection) {
            std::cerr << "No active database connection." << std::endl;
            return actualRes;
        }

        std::unique_ptr<sql::Statement> stmt(connection->createStatement());
        std::unique_ptr<sql::ResultSet> res(stmt->executeQuery(query));
        sql::ResultSetMetaData* meta = res->getMetaData();

        int columnCount = meta->getColumnCount();

        while (res->next()) {
            Row row;

            for (int i = 1; i <= columnCount; ++i) {
                std::string colName = meta->getColumnLabel(i);

                if (res->isNull(i)) {
                    row[colName] = "";
                } else {
                    row[colName] = res->getString(i);
                }
            }

            actualRes.push_back(row);
        }

    } catch (const sql::SQLException& err) {
        std::cerr << "SQL Error: " << err.what()
        << "\nError Code: " << err.getErrorCode()
        << "\nSQLState: " << err.getSQLState()
        << std::endl;
    }

    return actualRes;
}

Database::~Database() {
    disconnect();
}