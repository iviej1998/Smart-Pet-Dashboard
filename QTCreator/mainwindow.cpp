#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Smart Pet Dashboard");

    // Main dashboard theme
    ui->centralwidget->setStyleSheet(R"(
        QWidget {
            background-color: #16181f;
            color: white;
            font-family: "Segoe UI";
            font-size: 11pt;
        }

        QFrame#overviewCard,
        QFrame#petsCard,
        QFrame#notificationsCard,
        QFrame#activityCard {
            background-color: #23262f;
            border: 1px solid #343847;
            border-radius: 16px;
        }

        QFrame#petsStatCard,
        QFrame#alertsStatCard,
        QFrame#DevicesStatCard {
            background-color: #2b3040;
            border: 1px solid #40475a;
            border-radius: 14px;
        }

        QPushButton {
            background-color: #3b82f6;
            color: white;
            border: none;
            border-radius: 10px;
            padding: 8px 14px;
            font-weight: 600;
        }

        QPushButton:hover {
            background-color: #60a5fa;
        }

        QPushButton:pressed {
            background-color: #2563eb;
        }
    )");

    // Welcome / top label
    ui->label->setText("Welcome, Jillian");
    ui->label->setStyleSheet("font-size: 16pt; font-weight: 700; color: #f8fafc;");

    // Overview title
    ui->lblOverviewTitle->setText("Overview");
    ui->lblOverviewTitle->setStyleSheet("font-size: 14pt; font-weight: 700; color: white;");

    // Stat cards
    ui->lblPetsTitle->setText("Pets");
    ui->lblPetsValue->setText("3");
    ui->lblPetsValue->setStyleSheet("font-size: 22pt; font-weight: 700; color: #93c5fd;");

    ui->lblDevicesTitle->setText("Connected Devices");
    ui->lblDevicesValue->setText("4");
    ui->lblDevicesValue->setStyleSheet("font-size: 22pt; font-weight: 700; color: #86efac;");

    ui->lblAlertsTitle->setText("Alerts");
    ui->lblAlertsValue->setText("1");
    ui->lblAlertsValue->setStyleSheet("font-size: 22pt; font-weight: 700; color: #fca5a5;");

    // My Pets section
    ui->lblMyPets->setText("My Pets");
    ui->lblMyPets->setStyleSheet("font-size: 14pt; font-weight: 700; color: white;");

    ui->pet1Label->setText("🐶 Luna");
    ui->pet2Label->setText("🦎 Spike");
    ui->pet3Label->setText("🐟 Bubbles");

    ui->pet1Label->setStyleSheet("font-size: 12pt; color: #e5e7eb;");
    ui->pet2Label->setStyleSheet("font-size: 12pt; color: #e5e7eb;");
    ui->pet3Label->setStyleSheet("font-size: 12pt; color: #e5e7eb;");

    ui->lblPetsValue->setStyleSheet("font-size: 26pt; font-weight: 700; color: #93c5fd; background: transparent; border: none;");
    ui->lblDevicesValue->setStyleSheet("font-size: 26pt; font-weight: 700; color: #86efac; background: transparent; border: none;");
    ui->lblAlertsValue->setStyleSheet("font-size: 26pt; font-weight: 700; color: #fca5a5; background: transparent; border: none;");

    ui->btnViewPet1->setText("View Profile");
    ui->btnViewPet2->setText("View Profile");
    ui->btnViewPet3->setText("View Profile");

    ui->lblStatus->setText("All pets healthy");
    ui->lblStatus->setStyleSheet("color: #94a3b8; font-size: 10pt;");

    // Notifications section
    ui->lblNotifications->setText("Notifications");
    ui->lblNotifications->setStyleSheet("font-size: 14pt; font-weight: 700; color: white;");

    ui->notif1Label->setText("🔔 Feeding scheduled for 6:00 PM");
    ui->notif2Label->setText("💡 Reptile lamp turned on");
    ui->notif3Label->setText("⚠ Water level low");

    ui->notif1Label->setStyleSheet("color: #cbd5e1;");
    ui->notif2Label->setStyleSheet("color: #cbd5e1;");
    ui->notif3Label->setStyleSheet("color: #cbd5e1;");

    // Activity section
    ui->lblAcivity->setText("Activity");
    ui->lblAcivity->setStyleSheet("font-size: 14pt; font-weight: 700; color: white;");

    ui->activity1Type->setText("🍽 Feeding");
    ui->activity2Type->setText("💡 Lighting");
    ui->activity3Type->setText("🐟 Aquarium");

    ui->activity1Text->setText("Luna was fed 2 hours ago");
    ui->activity2Text->setText("Lamp activated at 8:00 AM");
    ui->activity3Text->setText("Filter status checked");

    ui->activity1Type->setStyleSheet("font-weight: 600; color: white;");
    ui->activity2Type->setStyleSheet("font-weight: 600; color: white;");
    ui->activity3Type->setStyleSheet("font-weight: 600; color: white;");

    ui->activity1Text->setStyleSheet("color: #cbd5e1;");
    ui->activity2Text->setStyleSheet("color: #cbd5e1;");
    ui->activity3Text->setStyleSheet("color: #cbd5e1;");

    // Optional spacing polish through per-widget styling
    ui->petsCard->setStyleSheet(ui->petsCard->styleSheet() + "padding: 10px;");
    ui->notificationsCard->setStyleSheet(ui->notificationsCard->styleSheet() + "padding: 10px;");
    ui->activityCard->setStyleSheet(ui->activityCard->styleSheet() + "padding: 10px;");
    ui->overviewCard->setStyleSheet(ui->overviewCard->styleSheet() + "padding: 10px;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCreatePet_clicked()
{
}