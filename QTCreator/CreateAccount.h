#pragma once
#include <QMainWindow>
#include <QString>

class AuthenticationManager;
class MainWindow;

namespace Ui {
class CreateAccount;
}

class CreateAccount : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateAccount(const QString& email,
                           const QString& password,
                           AuthenticationManager* authManager,
                           QWidget *parent = nullptr);
    ~CreateAccount();

private slots:
    void on_btnCreateAccount_clicked();

private:
    Ui::CreateAccount *ui;
    QString email;
    QString password;
    AuthenticationManager* authManager;
    MainWindow* mainwindow = nullptr;

};