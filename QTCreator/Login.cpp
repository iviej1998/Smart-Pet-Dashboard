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
    ui->lblStatus->clear();

    QString email = ui->editEmail->text().trimmed();
    QString pass = ui->editPass->text();

    if (email.isEmpty() || pass.isEmpty()) {
        ui->lblStatus->setText("Please fill all fields.");
        return;
    }

    if (!authManager) {
        ui->lblStatus->setText("Authentication system unavailable.");
        return;
    }

    std::string Email = email.toStdString();
    std::string password = pass.toStdString();

    bool valid = authManager->ValidateCredentials(Email, password);

    if (!valid) {
        ui->lblStatus->setText("Invalid email or password.");
        return;
    }

    std::string username = authManager->getUsernameByEmail(Email);
    int userId = authManager->getUserIdByEmail(Email);

    if (username.empty() || userId == -1) {
        ui->lblStatus->setText("Could not load user profile.");
        return;
    }

    if (mainWindow) {
        delete mainWindow;
        mainWindow = nullptr;
    }

    mainWindow = new MainWindow(authManager,
                                nullptr,
                                nullptr,
                                username,
                                userId,
                                nullptr);

    mainWindow->show();
    this->hide();
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