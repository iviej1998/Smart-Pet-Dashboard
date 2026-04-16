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
    std::string petName = name.toStdString();

    PetProfile p;
    p.setName(petName);

    if (ui-> sldrPetType->currentText() == "Dog") {
        PPDog *d = new PPDog(p, this);
        d->show();
    } else if (ui -> sldrPetType->currentText() == "Cat"){
        PPCat *c = new PPCat(p, this);
        c->show();
    }else if (ui -> sldrPetType->currentText() == "Fish"){
        FishPP *f = new FishPP(p, this);
        f->show();
    }else if (ui -> sldrPetType->currentText() == "Reptile"){

    }else if (ui -> sldrPetType->currentText() == "Other"){

    }

    ui->lblStatus->setText("Pet created!");
}


void PPWindow::on_sldrPetType_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Dog") {
        QString type = "Dog";
        std::string PetType = type.toStdString();


    }else if (arg1 == "Cat") {
        QString type = "Cat";
        std::string PetType = type.toStdString();

    } else if (arg1 == "Fish") {
        QString type = "Fish";
        std::string PetType = type.toStdString();

    } else if (arg1 == "Reptile") {
        QString type = "Reptile";
        std::string PetType = type.toStdString();

    } else if (arg1 == "Other") {
        return;
    } else {
        ui ->lblStatus -> setText("Please fill all fields!");
    }
}

