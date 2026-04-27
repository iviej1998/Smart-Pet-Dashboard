#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "AuthenticationManager.h"
#include "UserProfileManager.h"
#include "PetProfileManager.h"
#include "PPwindow.h"
#include "PPDog.h"
#include "PPCat.h"
#include "PPFish.h"
#include "PPReptile.h"

#include <QToolButton>
#include <QStyle>
#include <QIcon>
#include <QSize>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , authManager(nullptr)
    , userManager(nullptr)
    , petManager(nullptr)
    , currentUsername("Jillian")
    , currentUserId(1)
{
    ui->setupUi(this);
    setupDashboardUi();
}

MainWindow::MainWindow(AuthenticationManager* authManager,
                       UserProfileManager* userManager,
                       PetProfileManager* petManager,
                       const std::string& currentUsername,
                       int currentUserId,
                       QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , authManager(authManager)
    , userManager(userManager)
    , petManager(petManager)
    , currentUsername(currentUsername)
    , currentUserId(currentUserId)
{
    ui->setupUi(this);
    setupDashboardUi();
    loadPets();
    refreshDashboard();
}
void MainWindow::setupDashboardUi()
{
    setWindowTitle("Smart Pet Dashboard");
    resize(1280, 820);

    this->setStyleSheet(R"(

QMainWindow, QWidget#centralwidget {
    background:
        qradialgradient(
            cx:0.2, cy:0.3, radius:0.8,
            fx:0.2, fy:0.3,
            stop:0 rgba(120, 80, 255, 0.18),
            stop:1 rgba(0, 0, 0, 0)
        ),
        qradialgradient(
            cx:0.8, cy:0.7, radius:0.9,
            fx:0.8, fy:0.7,
            stop:0 rgba(80, 160, 255, 0.15),
            stop:1 rgba(0, 0, 0, 0)
        ),
        qlineargradient(
            x1:0, y1:0, x2:1, y2:1,
            stop:0 #0a0f1f,
            stop:0.3 #121a34,
            stop:0.6 #1a1f3f,
            stop:1 #141733
        );
    color: white;
    font-family: "Segoe UI";
    font-size: 11pt;
}

QMenuBar {
    background-color: #111827;
    color: white;
    spacing: 10px;
}

QMenuBar::item {
    background: transparent;
    padding: 8px 14px;
    border-radius: 10px;
}

QMenuBar::item:selected {
    background: rgba(124, 90, 240, 0.20);
}

QFrame#welcomeCard,
QFrame#petsCard,
QFrame#bottomNavBar {
    background-color: rgba(18, 26, 48, 0.88);
    border: 1px solid rgba(120, 140, 210, 0.35);
    border-radius: 26px;
}

QFrame#welcomeCard {
    border: 1px solid rgba(140, 160, 255, 0.40);
}

QLabel#lblWelcome {
    font-size: 21pt;
    font-weight: 800;
    color: #eef2ff;
    padding-left: 10px;
}

QToolButton#imagePet1,
QToolButton#imagePet2,
QToolButton#imagePet3,
QToolButton#imagePet4 {
    border-radius: 24px;
    padding: 18px;
    min-width: 70px;
    min-height: 70px;
    font-size: 28pt;
    font-weight: 700;
    border: none;
}

QToolButton#imagePet1 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:1, stop:0 #117d78, stop:1 #25b7aa);
}
QToolButton#imagePet2 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:1, stop:0 #7d3df0, stop:1 #ba82f2);
}
QToolButton#imagePet3 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:1, stop:0 #1c8c3f, stop:1 #38c96a);
}
QToolButton#imagePet4 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:1, stop:0 #5450d8, stop:1 #7b84f0);
}

QPushButton#btnCreatePet {
    border: none;
    background: transparent;
}

QPushButton#btnCreatePet:hover {
    background-color: rgba(130, 100, 255, 0.12);
    border-radius: 24px;
}

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

QPushButton#btnPet1 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:0, stop:0 #14b8a6, stop:1 #3b82f6);
}
QPushButton#btnPet2 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:0, stop:0 #d946ef, stop:1 #7c3aed);
}
QPushButton#btnPet3 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:0, stop:0 #84cc16, stop:1 #22c55e);
}
QPushButton#btnPet4 {
    background: qlineargradient(x1:0,y1:0,x2:1,y2:0, stop:0 #8b5cf6, stop:1 #4338ca);
}

QToolButton#btnHome,
QToolButton#btnDevices,
QToolButton#btnNotifications {
    border-radius: 20px;
    padding: 12px 18px;
    font-size: 11pt;
    font-weight: 600;
    color: #dbe4ff;
    min-width: 130px;
    min-height: 74px;
    background: transparent;
    border: none;
}

QToolButton#btnHome:checked {
    background-color: rgba(124, 90, 240, 0.22);
    border: 1px solid rgba(170, 140, 255, 0.45);
}

QToolButton#btnDevices:hover {
    background-color: rgba(50, 190, 170, 0.12);
    border: 1px solid rgba(50, 190, 170, 0.25);
}

QToolButton#btnNotifications:hover {
    background-color: rgba(110, 220, 120, 0.12);
    border: 1px solid rgba(110, 220, 120, 0.25);
}

)");

    ui->lblWelcome->setText("Welcome back, Jillian");

    ui->imagePet1->setText("🐶");
    ui->imagePet2->setText("🐱");
    ui->imagePet3->setText("🦎");
    ui->imagePet4->setText("🐟");

    ui->imagePet1->setToolButtonStyle(Qt::ToolButtonTextOnly);
    ui->imagePet2->setToolButtonStyle(Qt::ToolButtonTextOnly);
    ui->imagePet3->setToolButtonStyle(Qt::ToolButtonTextOnly);
    ui->imagePet4->setToolButtonStyle(Qt::ToolButtonTextOnly);

    ui->imagePet1->setFixedSize(70, 70);
    ui->imagePet2->setFixedSize(70, 70);
    ui->imagePet3->setFixedSize(70, 70);
    ui->imagePet4->setFixedSize(70, 70);

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

    ui->btnHome->setIcon(style()->standardIcon(QStyle::SP_DesktopIcon));
    ui->btnDevices->setIcon(style()->standardIcon(QStyle::SP_ComputerIcon));
    ui->btnNotifications->setIcon(style()->standardIcon(QStyle::SP_MessageBoxInformation));

    ui->btnHome->setIconSize(QSize(44, 44));
    ui->btnDevices->setIconSize(QSize(44, 44));
    ui->btnNotifications->setIconSize(QSize(44, 44));
}
void MainWindow::loadPets()
{
    petIds.clear();

    if (!userManager || !petManager) {
        return;
    }

    try {
        //get PetIDs from UserPetAccess
        petIds = userManager->getPetIdsForUser(currentUserId);

        //load pet profile objects
        petManager->pullPetProfile(currentUserId);
        if(petIds.empty()) {
            qDebug() << "No pets found for UserID:" << currentUserId;
        }
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", QString("Failed to load pet profiles: %1").arg(e.what()));
    }
    catch (...) {
        QMessageBox::warning(this, "Error", "Failed to load pet profiles.");
    }
}

QString MainWindow::emojiForPetType(const std::string& type) const
{
    if (type == "Dog") return "🐶";
    if (type == "Cat") return "🐱";
    if (type == "Fish") return "🐟";
    if (type == "Reptile") return "🦎";
    return "🐾";
}

void MainWindow::refreshDashboard()

{
    if (!petManager) return;

    QList<QToolButton*> imageButtons = {
        ui->imagePet1, ui->imagePet2, ui->imagePet3, ui->imagePet4
    };

    QList<QPushButton*> petButtons = {
        ui->btnPet1, ui->btnPet2, ui->btnPet3, ui->btnPet4
    };

    for (int i = 0; i < 4; i++) {
        if (i < static_cast<int>(petIds.size())) {
            try {
                PetProfile& pet = petManager->returnPetProfile(petIds[i]);

                imageButtons[i]->setText(emojiForPetType(pet.getType()));
                imageButtons[i]->setToolButtonStyle(Qt::ToolButtonTextOnly);
                imageButtons[i]->setToolTip(QString::fromStdString(pet.getName()));

                petButtons[i]->setText(QString::fromStdString(pet.getName()));
                petButtons[i]->setEnabled(true);
                imageButtons[i]->setEnabled(true);
            }
            catch (...) {
                imageButtons[i]->setText("❓");
                petButtons[i]->setText("Unavailable");
                petButtons[i]->setEnabled(false);
                imageButtons[i]->setEnabled(false);
            }
        } else {
            imageButtons[i]->setText("—");
            petButtons[i]->setText("Empty");
            petButtons[i]->setEnabled(false);
            imageButtons[i]->setEnabled(false);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_btnCreatePet_clicked()
{
    if (!userManager) {
        QMessageBox::warning(this, "Error", "User manager not available.");
        return;
    }

    PPWindow p(this);

    if (p.exec() == QDialog::Accepted) {
        int petId = userManager->addPetToUser(
             currentUserId,
             p.getPetName(),
             p.getPetType(),
             p.getOtherType(),
             p.getFoodAmount(),
             p.getTreatLimit(),
             p.getHasLamp()
         );

         petIds.push_back(petId);
         refreshDashboard();

        QMessageBox::information(this, "Create Pet", "Pet dialog closed. Next step is saving dialog data to PetProfileManager.");
    }
}

void MainWindow::openPetAtIndex(int index)
{
    if (index < 0 || index >= static_cast<int>(petIds.size())) {
        QMessageBox::information(this, "Pet", "No pet assigned to that slot yet.");
        return;
    }

    try {
        PetProfile& pet = petManager->returnPetProfile(petIds[index]);
        const std::string type = pet.getType();

        if (type == "Dog") {
            PPDog* dogWindow = new PPDog(pet, this);
            dogWindow->show();
        }
        else if (type == "Cat") {
            PPCat* catWindow = new PPCat(pet, this);
            catWindow->show();
        }
        else if (type == "Fish") {
            FishPP* fishWindow = new FishPP(pet, this);
            fishWindow->show();
        }
        else if (type == "Reptile") {
            // Your PPReptile currently does NOT accept a PetProfile parameter.
            PPReptile* reptileWindow = new PPReptile(this);
            reptileWindow->show();
        }
        else {
            QMessageBox::information(this, "Pet", "No profile screen exists yet for this pet type.");
        }
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void MainWindow::on_btnHome_clicked()
{
    ui->btnHome->setChecked(true);
    ui->btnDevices->setChecked(false);
    ui->btnNotifications->setChecked(false);
}


void MainWindow::on_btnDevices_clicked()
{
    ui->btnHome->setChecked(false);
    ui->btnDevices->setChecked(true);
    ui->btnNotifications->setChecked(false);

    QMessageBox::information(this, "Devices", "Later this button should open feeder/light controls.");
}


void MainWindow::on_btnNotifications_clicked()
{
    ui->btnHome->setChecked(false);
    ui->btnDevices->setChecked(false);
    ui->btnNotifications->setChecked(true);

    QMessageBox::information(this, "Alerts", "Later this button should open reminders, feeding alerts, and device alerts.");
}


void MainWindow::on_btnPet1_clicked()
{

}


void MainWindow::on_btnPet2_clicked()
{

}


void MainWindow::on_btnPet3_clicked()
{

}


void MainWindow::on_btnPet4_clicked()
{

}

