#include "PPwindow.h"
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

    //ui->lblStatus->setText("Pet created!");
}


void PPWindow::on_sldrPetType_currentTextChanged(const QString &arg1)
{

}

