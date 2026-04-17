#include "CreateAccount.h"
#include "AuthenticationManager.h"
#include "ui_createaccount.h"
#include "mainwindow.h"

CreateAccount::CreateAccount(const QString& email,
                             const QString& password,
                             AuthenticationManager* authManager,
                             QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreateAccount)
    , email(email)
    , password(password)
    , authManager(authManager)
{
    ui->setupUi(this);

    ui->printEmail->setText(email);

    QString masked_password(password.length(), '*');
    ui->printPassHash->setText(masked_password);
}

CreateAccount::~CreateAccount()
{
    delete ui;
}

void CreateAccount::on_btnCreateAccount_clicked()
{
    QString email = ui->printEmail->text();
    QString username = ui->editUsername->text();
    QString password = ui->editPassHash->text();

    if (email.isEmpty() || username.isEmpty() || password.isEmpty()) {
        ui->lblStatus->setText("Please fill all fields");
        return;
    }

    if (!authManager) {
        ui->lblStatus->setText("Authentication system unavailable.");
        return;
    }

    bool success = authManager->registerUser(
        username.toStdString(),
        password.toStdString(),
        email.toStdString()
        );

    if (success) {
        ui->lblStatus->setText("Account created successfully.");

        mainwindow = new MainWindow();
        mainwindow->show();
        mainwindow->raise();
        mainwindow->activateWindow();

        this->hide();
    } else {
        ui->lblStatus->setText("Failed to create account.");
    }
}