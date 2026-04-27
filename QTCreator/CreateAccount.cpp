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

    setWindowTitle("Create An Account");

    setWindowTitle("Create An Account");

    this->setStyleSheet(R"(

/* =========================
   WINDOW BACKGROUND
========================= */
QMainWindow, QWidget#centralwidget {
    background:
        qradialgradient(
            cx:0.20, cy:0.18, radius:0.90,
            fx:0.20, fy:0.18,
            stop:0 rgba(155, 120, 255, 0.18),
            stop:1 rgba(0, 0, 0, 0)
        ),
        qradialgradient(
            cx:0.82, cy:0.78, radius:0.95,
            fx:0.82, fy:0.78,
            stop:0 rgba(90, 185, 255, 0.14),
            stop:1 rgba(0, 0, 0, 0)
        ),
        qlineargradient(
            x1:0, y1:0, x2:1, y2:1,
            stop:0 #111935,
            stop:0.35 #1a2346,
            stop:0.70 #222a52,
            stop:1 #1b2142
        );
    color: #eef2ff;
    font-family: "Segoe UI";
    font-size: 11pt;
}

QWidget {
    background: transparent;
    color: #eef2ff;
}

/* =========================
   MAIN PANEL
========================= */
QFrame#frame_2 {
    background-color: rgba(20, 28, 54, 0.62);
    border: 1px solid rgba(170, 180, 255, 0.26);
    border-radius: 30px;
}

/* =========================
   TITLE
========================= */
QLabel#lblTitle {
    color: #ffffff;
    font-size: 22pt;
    font-weight: 800;
    background: transparent;
    border: none;
    padding-bottom: 12px;
}

/* =========================
   FORM LABELS
========================= */
QLabel#lblEmail,
QLabel#lblUsername,
QLabel#lblUsername2,
QLabel#lblPassword,
QLabel#lblPassword2 {
    color: #f2f5ff;
    font-size: 11pt;
    font-weight: 600;
    background: transparent;
    border: none;
    padding-top: 4px;
}

/* =========================
   STATUS LABEL
========================= */
QLabel#lblStatus {
    color: #d3dcff;
    font-size: 10.5pt;
    font-weight: 500;
    background: transparent;
    border: none;
    padding-top: 10px;
}

/* =========================
   INPUT FIELDS
========================= */
QLineEdit#printEmail,
QLineEdit#editUsername,
QLineEdit#printUsername,
QLineEdit#editPassHash,
QLineEdit#printPassHash {
    background-color: rgba(18, 24, 48, 0.72);
    color: #f8fbff;
    border: 1px solid rgba(170, 180, 255, 0.28);
    border-radius: 18px;
    padding: 12px 16px;
    min-height: 26px;
    selection-background-color: #8b5cf6;
    selection-color: white;
}

QLineEdit#printEmail:focus,
QLineEdit#editUsername:focus,
QLineEdit#printUsername:focus,
QLineEdit#editPassHash:focus,
QLineEdit#printPassHash:focus {
    border: 1px solid #a78bfa;
    background-color: rgba(24, 31, 60, 0.86);
}

/* Pre-filled / read-only style */
QLineEdit#printEmail,
QLineEdit#printPassHash {
    color: #e5ecff;
    border: 1px solid rgba(108, 225, 208, 0.24);
    background-color: rgba(16, 22, 40, 0.58);
}

/* =========================
   CREATE BUTTON
========================= */
QPushButton#btnCreateAccount {
    color: white;
    font-size: 12pt;
    font-weight: 700;
    border: none;
    border-radius: 18px;
    padding: 12px 20px;
    min-height: 28px;
    background: qlineargradient(
        x1:0, y1:0, x2:1, y2:0,
        stop:0 #8b5cf6,
        stop:0.50 #a78bfa,
        stop:1 #67e8f9
    );
}

QPushButton#btnCreateAccount:hover {
    border: 1px solid rgba(255,255,255,0.25);
    background: qlineargradient(
        x1:0, y1:0, x2:1, y2:0,
        stop:0 #9b6cff,
        stop:0.50 #b89cff,
        stop:1 #7defff
    );
}

QPushButton#btnCreateAccount:pressed {
    background: qlineargradient(
        x1:0, y1:0, x2:1, y2:0,
        stop:0 #7c3aed,
        stop:0.50 #8b5cf6,
        stop:1 #4fd8f3
    );
}
)");

    ui->lblTitle->setText("Create An Account");
    ui->lblTitle->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->lblEmail->setText("Email Address");
    ui->lblUsername->setText("Username");
    ui->lblUsername2->setText("Confirm Username");
    ui->lblPassword->setText("Password");
    ui->lblPassword2->setText("Confirm Password");

    ui->btnCreateAccount->setText("Create Account");

    ui->printUsername->setPlaceholderText("Enter username");
    ui->editUsername->setPlaceholderText("Re-enter username");
    ui->printPassHash->setPlaceholderText("Enter password");
    ui->editPassHash->setPlaceholderText("Re-enter password");

    ui->lblStatus->setText("Fill out the form to create your account.");
    ui->lblStatus->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    ui->printEmail->setText(email);
    ui->printEmail->setReadOnly(false);   // optional if you want editable

    ui->printPassHash->clear();
    ui->editPassHash->clear();

    ui->printPassHash->setEchoMode(QLineEdit::Password);
    ui->editPassHash->setEchoMode(QLineEdit::Password);
}

CreateAccount::~CreateAccount()
{
    delete ui;
}

void CreateAccount::on_btnCreateAccount_clicked()
{
    QString email = ui->printEmail->text().trimmed();
    QString username = ui->printUsername->text().trimmed();
    QString confirmUsername = ui->editUsername->text().trimmed();
    QString password = ui->printPassHash->text();
    QString confirmPassword = ui->editPassHash->text();

    if (email.isEmpty() || username.isEmpty() || confirmUsername.isEmpty()
        || password.isEmpty() || confirmPassword.isEmpty()) {
        ui->lblStatus->setText("Please fill all fields.");
        return;
    }

    if (username != confirmUsername) {
        ui->lblStatus->setText("Usernames do not match.");
        return;
    }

    if (password != confirmPassword) {
        ui->lblStatus->setText("Passwords do not match.");
        return;
    }

    if (!authManager) {
        ui->lblStatus->setText("Authentication system unavailable.");
        return;
    }
    qDebug() << "Creating account with:"
             << "email =" << email
             << "username =" << username;
    bool success = authManager->registerUser(
        username.toStdString(),
        password.toStdString(),
        email.toStdString()
        );
    qDebug() << "registerUser success =" << success;
    if (success) {
        ui->lblStatus->setText("Account created successfully.");

        int userId = authManager->getUserIdByEmail(email.toStdString());

        mainwindow = new MainWindow(authManager,
                                    nullptr,
                                    nullptr,
                                    username.toStdString(),
                                    userId,
                                    this);

        mainwindow->show();
        mainwindow->raise();
        mainwindow->activateWindow();

        this->hide();
    } else {
        ui->lblStatus->setText("Failed to create account.");
    }
}