#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "PetProfile.h"

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
    QString name = ui->txtPetName->text();
    QString type = ui->txtPetType->text();

    if (name.isEmpty() || type.isEmpty()) {
        ui->lblStatus->setText("Please fill all fields");
        return;
    }

    string petName = name.toStdString();
    string petType = type.toStdString();

    PetProfile p;
    p.setName(petName);
    p.setType(petType);

    ui->lblStatus->setText("Pet created!");
}

