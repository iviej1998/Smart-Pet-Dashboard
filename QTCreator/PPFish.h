#pragma once

#include "PetProfile.h"
#include <QDialog>

namespace Ui {
class FishPP;
}

class FishPP : public QDialog
{
    Q_OBJECT

public:
    explicit FishPP(QWidget *parent = nullptr);
    explicit FishPP(const PetProfile& p, QWidget *parent = nullptr);
    ~FishPP();

private slots:
    void on_btnAddPet_clicked();

private:
    Ui::FishPP *ui;
};
