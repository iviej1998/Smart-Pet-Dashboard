#pragma once

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class CreateAccount;
class MainWindow;
class AuthenticationManager;

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(AuthenticationManager* authManager, QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_btnSignIn_clicked();
    void on_btnCreateAccount_clicked();

private:
    Ui::Login *ui;
    AuthenticationManager* authManager;
    CreateAccount* createAccountWindow = nullptr;
    MainWindow* mainWindow = nullptr;
};