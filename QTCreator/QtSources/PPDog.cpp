#include "PPDog.h"
#include "ui_ppdog.h"

PPDog::PPDog(const PetProfile& p, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PPDog)
{
    ui->setupUi(this);
    QString name = QString::fromStdString(p.getName());
    ui->label->setText("Pet Profile | " + name);
}

PPDog::~PPDog()
{
    delete ui;
}

void PPDog::on_pushButton_clicked()
{

}

