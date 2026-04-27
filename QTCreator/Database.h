#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include <mysql/jdbc.h>

class Database {
private:
    std::string host;
    std::string userName;
    std::string password;
    std::string databaseName;
    int port = 3306;

    sql::Driver* driver = nullptr;
    std::unique_ptr<sql::Connection> connection;

public:
    using Row = std::unordered_map<std::string, std::string>;
    using QueryResult = std::vector<Row>;

    Database() = default;

    Database(const std::string& hst,
             const std::string& usrNme,
             const std::string& passWrd,
             const std::string& dB,
             int prt)
        : host(hst), userName(usrNme), password(passWrd), databaseName(dB), port(prt) {}

    bool connect();
    void disconnect();
    bool executeQuery(const std::string& query);
    QueryResult executeSelectQuery(const std::string& query);

    ~Database();
};