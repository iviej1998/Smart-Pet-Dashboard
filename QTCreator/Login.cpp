#include "Login.h"
#include "AuthenticationManager.h"
#include "CreateAccount.h"
#include "mainwindow.h"
#include "ui_login.h"

Login::Login(AuthenticationManager* authManager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
    , authManager(authManager)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_btnSignIn_clicked()
{
    QString email = ui->editEmail->text();
    QString pass = ui->editPass->text();

    if (email.isEmpty() || pass.isEmpty()) {
        ui->lblStatus->setText("Please fill all fields");
        return;
    }

    std::string Email = email.toStdString();
    std::string password = pass.toStdString();

    if (!authManager) {
        ui->lblStatus->setText("Authentication system unavailable.");
        return;
    }

    bool valid = authManager->ValidateCredentials(Email, password);

    if (valid) {
        if (!mainWindow) {
            mainWindow = new MainWindow(this);
        }
        mainWindow->show();
        this->hide();
    } else {
        ui->lblStatus->setText("Invalid username/password.");
    }
}

void Login::on_btnCreateAccount_clicked()
{
    QString email = ui->editEmail->text();
    QString pass = ui->editPass->text();

    if (email.isEmpty() || pass.isEmpty()) {
        ui->lblStatus->setText("Please fill all fields");
        return;
    }

    if (!createAccountWindow) {
        createAccountWindow = new CreateAccount(email, pass, authManager, this);
    } else {
        createAccountWindow->close();
        delete createAccountWindow;
        createAccountWindow = new CreateAccount(email, pass, authManager, this);
    }

    createAccountWindow->show();
}