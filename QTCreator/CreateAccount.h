#pragma once

#include "User.h"
#include <QMainWindow>
#include <QString>

namespace Ui {
class CreateAccount;
}

class CreateAccount : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateAccount(const QString& username, QWidget *parent = nullptr);
    ~CreateAccount();

private slots:
    void on_btnCreateAccount_clicked(User& u);

private:
    Ui::CreateAccount *ui;
    QString username;
};