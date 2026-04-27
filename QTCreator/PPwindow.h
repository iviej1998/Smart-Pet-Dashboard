#pragma once
#include "PPCat.h"
#include "PPDog.h"
#include "PPFish.h"
#include "PPReptile.h"
#include <QDialog>
#include <string>

namespace Ui {
class PPWindow;
}

class PPWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PPWindow(QWidget *parent = nullptr );
    ~PPWindow();

    std::string getPetName() const;
    std::string getPetType() const;
    std::string getOtherType() const;
    double getFoodAmount() const;
    int getTreatLimit() const;
    bool getHasLamp() const;

private slots:
    void on_btnCreatePet_clicked();
    void on_sldrPetType_currentTextChanged(const QString &arg1);

private:
    Ui::PPWindow *ui;

    std::string petName;
    std::string petType;
    std::string otherType;
    PPDog* dogWindow;
    PPCat* catWindow;
    FishPP* fishWindow;
    PPReptile* reptileWindow;
    double foodAmount = 0.0;
    int treatLimit = 0;
    bool hasLamp = false;
};