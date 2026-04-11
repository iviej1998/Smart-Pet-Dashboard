#ifndef PPREPTILE_H
#define PPREPTILE_H

#include <QDialog>

namespace Ui {
class PPReptile;
}

class PPReptile : public QDialog
{
    Q_OBJECT

public:
    explicit PPReptile(QWidget *parent = nullptr);
    ~PPReptile();

private slots:
    void on_btnAddPet_clicked();

private:
    Ui::PPReptile *ui;
};

#endif // PPREPTILE_H
