#include "PPFish.h"
#include "PetProfile.h"
#include "ui_ppfish.h"

 FishPP::FishPP(const PetProfile& p, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FishPP)
{
    ui->setupUi(this);
    QString name = QString::fromStdString(p.getName());
    ui->label->setText("Pet Profile | " + name);
}

FishPP::~FishPP()
{
    delete ui;
}

void FishPP::on_btnAddPet_clicked()
{

}

