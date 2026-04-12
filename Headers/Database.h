#pragma once
#include <string>
#include <vector>
#include <unordered_map>


class Database {
private:
    std::string host;
    std::string userName;
    std::string password;
    std::string databaseName;
    int port;

    // mysqlx::Session* session; // TODO: MySQL Connector object
public:
    using Row = std::unordered_map<std::string, std::string>;
    using QueryResult = std::vector<Row>;

    bool connect();
    void disconnect();
    bool executeQuery(const std::string& query);
    QueryResult executeSelectQuery(const std::string& query);
    Database(const std::string& h, const std::string& uN, const std::string& pD, const std::string& dB, int prt)
            : host(h), userName(uN), password(pD), databaseName(dB), port(prt) {};
    ~Database();
};

