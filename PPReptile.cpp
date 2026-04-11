#include "PPReptile.h"
#include "ui_ppreptile.h"

PPReptile::PPReptile(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PPReptile)
{
    ui->setupUi(this);
}

PPReptile::~PPReptile()
{
    delete ui;
}

void PPReptile::on_btnAddPet_clicked()
{

}

