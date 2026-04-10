#ifndef PPCAT_H
#define PPCAT_H

#include <QDialog>

namespace Ui {
class PPCat;
}

class PPCat : public QDialog
{
    Q_OBJECT

public:
    explicit PPCat(QWidget *parent = nullptr);
    ~PPCat();

private:
    Ui::PPCat *ui;
};

#endif // PPCAT_H
