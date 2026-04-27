#include "PPwindow.h"
#include "PPDog.h"
#include "PPCat.h"
#include "PPFish.h"
#include "ui_PPwindow.h"

PPWindow::PPWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PPWindow)
{
    ui->setupUi(this);
    setWindowTitle("Add New Pet");
    dogWindow = new PPDog(this);
    catWindow = new PPCat(this);
    fishWindow = new FishPP(this);

    this->setStyleSheet(R"(

QDialog {
    background:
        qradialgradient(
            cx:0.20, cy:0.22, radius:0.85,
            fx:0.20, fy:0.22,
            stop:0 rgba(130, 90, 255, 0.16),
            stop:1 rgba(0, 0, 0, 0)
        ),
        qradialgradient(
            cx:0.82, cy:0.78, radius:0.90,
            fx:0.82, fy:0.78,
            stop:0 rgba(80, 170, 255, 0.12),
            stop:1 rgba(0, 0, 0, 0)
        ),
        qlineargradient(
            x1:0, y1:0, x2:1, y2:1,
            stop:0 #0a0f1f,
            stop:0.30 #121a34,
            stop:0.65 #1b2142,
            stop:1 #151933
        );
    color: #eef2ff;
    font-family: "Segoe UI";
    font-size: 11pt;
        }

        /* labels */
        QLabel {
            color: #e8ecff;
            font-size: 11pt;
            font-weight: 600;
            background: transparent;
            border: none;
        }

        QLabel#lblStatus {
            color: #a5b4fc;
            font-size: 10pt;
            font-weight: 500;
        }

        /* line edits */
        QLineEdit {
            background-color: rgba(15, 22, 44, 0.88);
            color: #f8fbff;
            border: 1px solid rgba(128, 144, 220, 0.30);
            border-radius: 14px;
            padding: 10px 12px;
            min-height: 22px;
            selection-background-color: #7c3aed;
        }

        QLineEdit:focus {
            border: 1px solid #8b5cf6;
            background-color: rgba(19, 27, 52, 0.96);
        }

        /* combo box */
        QComboBox {
            background-color: rgba(15, 22, 44, 0.88);
            color: #f8fbff;
            border: 1px solid rgba(82, 220, 186, 0.32);
            border-radius: 14px;
            padding: 10px 12px;
            min-height: 22px;
        }

        QComboBox:focus {
            border: 1px solid #2dd4bf;
        }

        QComboBox::drop-down {
            border: none;
            width: 28px;
            background: transparent;
        }

        QComboBox::down-arrow {
            image: none;
            width: 0px;
            height: 0px;
            border-left: 6px solid transparent;
            border-right: 6px solid transparent;
            border-top: 8px solid #8be9dc;
            margin-right: 10px;
        }

        QComboBox QAbstractItemView {
            background-color: #121a30;
            color: #eef2ff;
            border: 1px solid rgba(120, 140, 210, 0.30);
            selection-background-color: rgba(124, 58, 237, 0.35);
            selection-color: white;
            outline: none;
        }

        /* create button */
        QPushButton#btnCreatePet {
            color: white;
            font-size: 12pt;
            font-weight: 700;
            border: none;
            border-radius: 16px;
            padding: 12px 18px;
            min-height: 24px;
            background: qlineargradient(
                x1:0, y1:0, x2:1, y2:0,
                stop:0 #2dd4bf,
                stop:0.55 #8b5cf6,
                stop:1 #60a5fa
            );
        }

        QPushButton#btnCreatePet:hover {
            border: 1px solid rgba(255,255,255,0.25);
        }

        QPushButton#btnCreatePet:pressed {
            background: qlineargradient(
                x1:0, y1:0, x2:1, y2:0,
                stop:0 #22c7b2,
                stop:0.55 #7c3aed,
                stop:1 #4f8cff
            );
        }
        )");
    ui->lblPetName->setText("Pet Name");
    ui->ConfirmPetName->setText("Confirm Pet Name");
    ui->lblPetType->setText("Pet Type");
    ui->btnCreatePet->setText("Create Pet");

    ui->editPetName->setPlaceholderText("Enter pet name");
    ui->editPetConfirm->setPlaceholderText("Re-enter pet name");

    ui->sldrPetType->clear();
    ui->sldrPetType->addItems({"Dog", "Cat", "Reptile", "Fish", "Bird", "Other"});

    ui->lblStatus->setText("Create a pet profile to get started.");
}
#include "PPwindow.h"
#include "ui_PPwindow.h"

std::string PPWindow::getPetName() const
{
    return petName;
}

std::string PPWindow::getPetType() const
{
    return petType;
}

std::string PPWindow::getOtherType() const
{
    return otherType;
}

double PPWindow::getFoodAmount() const
{
    return foodAmount;
}

int PPWindow::getTreatLimit() const
{
    return treatLimit;
}

bool PPWindow::getHasLamp() const
{
    return hasLamp;
}

PPWindow::~PPWindow()
{
    delete ui;
}

void PPWindow::on_btnCreatePet_clicked()
{
    QString name = ui->editPetName->text();

    if (name.isEmpty()) {
        ui->lblStatus->setText("Please fill all fields");
        return;
    }

    petName = name.toStdString();
    petType = ui->sldrPetType->currentText().toStdString();

    // set these from actual widgets once they exist
    otherType = "";
    foodAmount = 1.0;
    treatLimit = 3;
    hasLamp = (petType == "Reptile" || petType == "Fish");

    accept();
}

void PPWindow::on_sldrPetType_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Dog") {
        QString type = "Dog";
        std::string PetType = type.toStdString();
        dogWindow->show();


    }else if (arg1 == "Cat") {
        QString type = "Cat";
        std::string PetType = type.toStdString();
        catWindow->show();

    } else if (arg1 == "Fish") {
        QString type = "Fish";
        std::string PetType = type.toStdString();
        fishWindow->show();

    } else if (arg1 == "Reptile") {
        QString type = "Reptile";
        std::string PetType = type.toStdString();
        reptileWindow->show();

    } else if (arg1 == "Other") {
        return;
    } else {
        ui ->lblStatus -> setText("Please fill all fields!");
    }
}

