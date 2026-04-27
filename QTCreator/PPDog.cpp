#include "PPDog.h"
#include "ui_ppdog.h"

PPDog::PPDog(const PetProfile& p, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PPDog)
{
    ui->setupUi(this);
    QString name = QString::fromStdString(p.getName());
    ui->lblStatus->setText("Pet Profile | " + name);
}

PPDog::PPDog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PPDog)
{
    ui->setupUi(this);
}

PPDog::~PPDog()
{
    delete ui;
}


void PPDog::on_btnAddPet_clicked()
{
//print page confirming dog profile details
}

