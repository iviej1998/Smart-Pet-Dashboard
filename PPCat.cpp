#include "PPCat.h"
#include "ui_ppcat.h"

PPCat::PPCat(const PetProfile& p, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PPCat)
{
    ui->setupUi(this);

    QString name = QString::fromStdString(p.getName());
    ui->label->setText("Pet Profile | " + name);
}

PPCat::~PPCat()
{
    delete ui;
}

void PPCat::on_btnAddPet_clicked()
{

}

