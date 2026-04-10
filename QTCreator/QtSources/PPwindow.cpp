#include "PPwindow.h"
#include "PPDog.h"
#include "PPCat.h"
#include "ui_PPwindow.h"
#include "PetProfile.h"

PPWindow::PPWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PPWindow)
{
    ui->setupUi(this);
}

PPWindow::~PPWindow()
{
    delete ui;
}

void PPWindow::on_btnCreatePet_clicked()
{
    QString name = ui->editPetName->text();
    QString temp = ui->editPetConfirm->text();

    if (name.isEmpty() || temp.isEmpty()) {
        ui->lblStatus->setText("Please fill all fields");
        return;
    }

    string petName = name.toStdString();

    PetProfile p;
    p.setName(petName);

    if (ui-> sldrPetType->currentText() == "Dog") {
        PPDog *d = new PPDog(p, this);
        d->show();
    } else if (ui -> sldrPetType->currentText() == "Cat"){
        PPCat c;
        c.show();
    }else if (ui -> sldrPetType->currentText() == "Fish"){

    }else if (ui -> sldrPetType->currentText() == "Reptile"){

    }else if (ui -> sldrPetType->currentText() == "Other"){

    }

    ui->lblStatus->setText("Pet created!");
}


void PPWindow::on_sldrPetType_currentTextChanged(const QString &arg1)
{
    PetProfile p;
    if (arg1 == "Dog") {
        QString type = "Dog";
        string PetType = type.toStdString();
        p.setType(PetType);
        p.setFeeder(true);
        p.setLamp(false);

    }else if (arg1 == "Cat") {
        QString type = "Cat";
        string PetType = type.toStdString();
        p.setType(PetType);
        p.setFeeder(true);
        p.setLamp(false);

    } else if (arg1 == "Fish") {
        QString type = "Fish";
        string PetType = type.toStdString();
        p.setType(PetType);
        p.setFeeder(true);
        p.setLamp(true);

    } else if (arg1 == "Reptile") {
        QString type = "Reptile";
        string PetType = type.toStdString();
        p.setType(PetType);
        p.setFeeder(true);
        p.setLamp(true);

    } else if (arg1 == "Other") {
        return;
    } else {
        ui ->lblStatus -> setText("Please fill all fields!");
    }
}

