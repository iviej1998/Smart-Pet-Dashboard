#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QToolButton>
#include <QStyle>
#include <QIcon>
#include <QSize>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Smart Pet Dashboard");

    // =========================
    // Main Window Theme
    // =========================
    ui->centralwidget->setStyleSheet(R"(

/* =========================
   BASE
========================= */
QMainWindow, QWidget#centralwidget {
    background-color: #08101f;
    color: white;
    font-family: "Segoe UI";
    font-size: 11pt;
}

QWidget {
    background: transparent;
    color: white;
}

/* =========================
   MAIN CARDS
========================= */
QFrame#welcomeCard,
QFrame#petsCard,
QFrame#bottomNavBar {
    background-color: #121a30;
    border: 1px solid #2a365c;
    border-radius: 26px;
}

/* =========================
   TITLE
========================= */
QLabel#lblWelcome {
    font-size: 21pt;
    font-weight: 800;
    color: #eef2ff;
    padding-left: 10px;
}

/* =========================
   PET IMAGE CARDS
========================= */
QToolButton#imagePet1,
QToolButton#imagePet2,
QToolButton#imagePet3,
QToolButton#imagePet4 {
    border-radius: 24px;
    padding: 18px;
    min-width: 70;
    min-height: 70;
    font-size: 28pt;
    font-weight: 700;
    border: none;
}

/* Dog */
QToolButton#imagePet1 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:1,
        stop:0 #0f766e,
        stop:1 #14b8a6);
}

/* Cat */
QToolButton#imagePet2 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:1,
        stop:0 #7c3aed,
        stop:1 #c084fc);
}

/* Reptile */
QToolButton#imagePet3 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:1,
        stop:0 #166534,
        stop:1 #22c55e);
}

/* Fish */
QToolButton#imagePet4 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:1,
        stop:0 #4338ca,
        stop:1 #818cf8);
}

/* Hover glow */
QToolButton#imagePet1:hover { background-color: #15938a; }
QToolButton#imagePet2:hover { background-color: #9333ea; }
QToolButton#imagePet3:hover { background-color: #22c55e; }
QToolButton#imagePet4:hover { background-color: #5b5cf0; }

/* =========================
   ADD PET BUTTON (CLEAN FIX)
========================= */
QPushButton#btnCreatePet {
    border: none;
    background: transparent;
    outline: none;
}

/* glow effect only */
QPushButton#btnCreatePet:hover {
    background-color: rgba(168, 85, 247, 0.18);
    border-radius: 24px;
}

/* =========================
   PET ACTION BUTTONS
========================= */
QPushButton#btnPet1,
QPushButton#btnPet2,
QPushButton#btnPet3,
QPushButton#btnPet4 {
    border-radius: 18px;
    padding: 12px;
    font-size: 12pt;
    font-weight: 700;
    min-height: 46px;
    color: white;
    border: none;
}

/* matching gradients */
QPushButton#btnPet1 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:0,
        stop:0 #14b8a6,
        stop:1 #3b82f6);
}
QPushButton#btnPet2 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:0,
        stop:0 #d946ef,
        stop:1 #7c3aed);
}
QPushButton#btnPet3 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:0,
        stop:0 #84cc16,
        stop:1 #22c55e);
}
QPushButton#btnPet4 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:0,
        stop:0 #8b5cf6,
        stop:1 #4338ca);
}

/* hover */
QPushButton#btnPet1:hover,
QPushButton#btnPet2:hover,
QPushButton#btnPet3:hover,
QPushButton#btnPet4:hover {
    border: 1px solid rgba(255,255,255,0.35);
}

/* =========================
   BOTTOM NAV
========================= */
QToolButton#btnHome,
QToolButton#btnDevices,
QToolButton#btnNotifications {
    border-radius: 20px;
    padding: 12px 18px;
    font-size: 11pt;
    font-weight: 600;
    color: #d7def8;
    min-width: 130px;
    min-height: 74px;
}

/* active tab */
QToolButton#btnHome:checked {
    background-color: rgba(124,58,237,0.25);
    border: 1px solid #8b5cf6;
}

/* hover accents */
QToolButton#btnDevices:hover {
    background-color: rgba(34,197,94,0.16);
}

QToolButton#btnNotifications:hover {
    background-color: rgba(168,85,247,0.16);
}

)");

    // =========================
    // Welcome Card
    // =========================
    ui->lblWelcome->setText("Welcome back, Jillian");

    // =========================
    // Pet Icon Buttons
    // =========================
    // These are your top pet "image" buttons, now turned into icon-style buttons
    ui->imagePet1->setText("🐶");
    ui->imagePet2->setText("🐱");
    ui->imagePet3->setText("🦎");
    ui->imagePet4->setText("🐟");

    ui->imagePet1->setToolButtonStyle(Qt::ToolButtonTextOnly);
    ui->imagePet2->setToolButtonStyle(Qt::ToolButtonTextOnly);
    ui->imagePet3->setToolButtonStyle(Qt::ToolButtonTextOnly);
    ui->imagePet4->setToolButtonStyle(Qt::ToolButtonTextOnly);

    ui->imagePet1->setCursor(Qt::PointingHandCursor);
    ui->imagePet2->setCursor(Qt::PointingHandCursor);
    ui->imagePet3->setCursor(Qt::PointingHandCursor);
    ui->imagePet4->setCursor(Qt::PointingHandCursor);
    ui->btnCreatePet->setCursor(Qt::PointingHandCursor);

    ui->imagePet1->setToolTip("Luna");
    ui->imagePet2->setToolTip("Cat Profile");
    ui->imagePet3->setToolTip("Spike");
    ui->imagePet4->setToolTip("Bubbles");

    ui->imagePet1->setFixedSize(70, 70);
    ui->imagePet2->setFixedSize(70, 70);
    ui->imagePet3->setFixedSize(70, 70);
    ui->imagePet4->setFixedSize(70, 70);

    // =========================
    // Pet Buttons
    // =========================
    ui->btnPet1->setText("View Pet 1");
    ui->btnPet2->setText("View Pet 2");
    ui->btnPet3->setText("View Pet 3");
    ui->btnPet4->setText("View Pet 4");

    ui->btnCreatePet->setIcon(QIcon(":/images/AddPetButton.png"));
    ui->btnCreatePet->setText("");
    ui->btnCreatePet->setFixedSize(125, 125);
    ui->btnCreatePet->setMinimumSize(125, 125);
    ui->btnCreatePet->setMaximumSize(170, 170);
    ui->btnCreatePet->setIconSize(QSize(100, 100));


    // =========================
    // Bottom Navigation Buttons
    // =========================
    ui->btnHome->setText("Home");
    ui->btnDevices->setText("Devices");
    ui->btnNotifications->setText("Alerts");

    ui->btnHome->setCheckable(true);
    ui->btnDevices->setCheckable(true);
    ui->btnNotifications->setCheckable(true);

    ui->btnHome->setChecked(true);

    ui->btnHome->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->btnDevices->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->btnNotifications->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    ui->btnHome->setCursor(Qt::PointingHandCursor);
    ui->btnDevices->setCursor(Qt::PointingHandCursor);
    ui->btnNotifications->setCursor(Qt::PointingHandCursor);

    ui->btnHome->setIcon(style()->standardIcon(QStyle::SP_DesktopIcon));
    ui->btnDevices->setIcon(style()->standardIcon(QStyle::SP_ComputerIcon));
    ui->btnNotifications->setIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));

    ui->btnHome->setIconSize(QSize(44, 44));
    ui->btnDevices->setIconSize(QSize(44, 44));
    ui->btnNotifications->setIconSize(QSize(44, 44));

    // =========================
    // Bottom Nav Click Logic
    // =========================
    connect(ui->btnHome, &QToolButton::clicked, this, [=]() {
        ui->btnHome->setChecked(true);
        ui->btnDevices->setChecked(false);
        ui->btnNotifications->setChecked(false);

        QMessageBox::information(this, "Navigation", "Home clicked.");
    });

    connect(ui->btnDevices, &QToolButton::clicked, this, [=]() {
        ui->btnHome->setChecked(false);
        ui->btnDevices->setChecked(true);
        ui->btnNotifications->setChecked(false);

        QMessageBox::information(this, "Navigation", "Devices clicked.");
    });

    connect(ui->btnNotifications, &QToolButton::clicked, this, [=]() {
        ui->btnHome->setChecked(false);
        ui->btnDevices->setChecked(false);
        ui->btnNotifications->setChecked(true);

        QMessageBox::information(this, "Navigation", "Notifications clicked.");
    });

    // =========================
    // Pet Icon Click Logic
    // =========================
    connect(ui->imagePet1, &QToolButton::clicked, this, [=]() {
        QMessageBox::information(this, "Pet", "Luna clicked.");
    });

    connect(ui->imagePet2, &QToolButton::clicked, this, [=]() {
        QMessageBox::information(this, "Pet", "Cat clicked.");
    });

    connect(ui->imagePet3, &QToolButton::clicked, this, [=]() {
        QMessageBox::information(this, "Pet", "Spike clicked.");
    });

    connect(ui->imagePet4, &QToolButton::clicked, this, [=]() {
        QMessageBox::information(this, "Pet", "Bubbles clicked.");
    });

    // =========================
    // Pet Button Click Logic
    // =========================
    connect(ui->btnPet1, &QPushButton::clicked, this, [=]() {
        QMessageBox::information(this, "Profile", "Open Pet 1 profile.");
    });

    connect(ui->btnPet2, &QPushButton::clicked, this, [=]() {
        QMessageBox::information(this, "Profile", "Open Pet 2 profile.");
    });

    connect(ui->btnPet3, &QPushButton::clicked, this, [=]() {
        QMessageBox::information(this, "Profile", "Open Pet 3 profile.");
    });

    connect(ui->btnPet4, &QPushButton::clicked, this, [=]() {
        QMessageBox::information(this, "Profile", "Open Pet 4 profile.");
    });

    connect(ui->btnCreatePet, &QPushButton::clicked, this, [=]() {
        QMessageBox::information(this, "Profile", "Open Pet 5 profile.");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}