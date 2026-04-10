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

}

