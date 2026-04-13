#include "Login.h"
#include "AuthenticationManager.h"
#include "CreateAccount.h"
#include "User.h"
#include "mainwindow.h"
#include "ui_login.h"

using namespace std;

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete createAccountWindow;
    delete mainWindow;
    delete ui;
}

void Login::on_btnSignIn_clicked()
{
    QString username = ui->editEmail->text();
    QString pass = ui->editPass->text();

    if (username.isEmpty() || pass.isEmpty()) {
        ui->lblStatus->setText("Please fill all fields");
        return;
    }

    string userName = username.toStdString();
    string password = pass.toStdString();

    AuthenticationManager u;
    vector<User> users = u.getUsers();

    int count = 0;
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].get_username() == userName) {
            if (!mainWindow) {
                mainWindow = new MainWindow(this);
            }

            mainWindow->show();
            this->hide();
            ++count;
            break;
        }
    }

    if (count == 0) {
        if (!createAccountWindow) {
            createAccountWindow = new CreateAccount(username, this);
        } else {
            delete createAccountWindow;
            createAccountWindow = new CreateAccount(username, this);
        }

        createAccountWindow->show();
    }
}

void Login::on_btnCreateAccount_clicked()
{
    QString username = ui->editEmail->text();
    QString pass = ui->editPass->text();

    if (username.isEmpty() || pass.isEmpty()) {
        ui->lblStatus->setText("Please fill all fields");
        return;
    }

    if (!createAccountWindow) {
        createAccountWindow = new CreateAccount(username, this);
    } else {
        delete createAccountWindow;
        createAccountWindow = new CreateAccount(username, this);
    }

    createAccountWindow->show();
}