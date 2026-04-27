#pragma once

#include "PetProfile.h"
#include <QDialog>

namespace Ui {
class PPCat;
}

class PPCat : public QDialog
{
    Q_OBJECT

public:
    explicit PPCat(QWidget *parent = nullptr);
    explicit PPCat(const PetProfile &p, QWidget *parent = nullptr);
    ~PPCat();

private slots:
    void on_btnAddPet_clicked();

private:
    Ui::PPCat *ui;
};

