#ifndef PPWINDOW_H
#define PPWINDOW_H

#include <QDialog>

namespace Ui {
class PPWindow;
}

class PPWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PPWindow(QWidget *parent = nullptr);
    ~PPWindow();

private slots:
    void on_btnCreatePet_clicked();

    void on_sldrPetType_currentTextChanged(const QString &arg1);

private:
    Ui::PPWindow *ui;
};

#endif // PPWINDOW_H
