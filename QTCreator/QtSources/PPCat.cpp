#include "PPCat.h"
#include "ui_ppcat.h"

PPCat::PPCat(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PPCat)
{
    ui->setupUi(this);
}

PPCat::~PPCat()
{
    delete ui;
}
