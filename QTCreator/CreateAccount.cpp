#include "CreateAccount.h"
#include "User.h"
#include "ui_createaccount.h"

CreateAccount::CreateAccount(const QString& username, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreateAccount)
    , username(username)
{
    ui->setupUi(this);

    QString masked(username.length(), '*');
    ui->printUsername->setText(masked);
}

CreateAccount::~CreateAccount()
{
    delete ui;
}

void CreateAccount::on_btnCreateAccount_clicked(User& u)
{
    string userName = username.toStdString();
    u.set_username(userName);

    u.set_role("Pet Owner");
}