#pragma once
#include "PetProfile.h"
#include <QDialog>

namespace Ui {
class PPDog;
}

class PPDog : public QDialog
{
    Q_OBJECT

public:
    explicit PPDog(const PetProfile& p, QWidget *parent = nullptr);
    ~PPDog();


private slots:
    void on_pushButton_clicked();

    void on_btnAddPet_clicked();

private:
    Ui::PPDog *ui;
};


