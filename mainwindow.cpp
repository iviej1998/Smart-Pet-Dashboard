#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "PetOwner.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnCreatePet_clicked()
{
    //Get Input from UI
    Qstring name = ui -> txtPetName -> text();
    Qstring type = ui -> txtPetType -> text();
    //Validate Input
    if (name.isEmpty() || type.isEmpty()) {
        ui -> lblStatus -> setText("Missing info");
        return;
    }
    string PetName = name.toStdString();
    string PetType = type.toStdString();
    //Call backend
    PetProfile p;
    p.setName(PetName);
    p.setType(PetType);

    //update UI
    ui-> lblStatus -> setText("Pet Created!");


}

