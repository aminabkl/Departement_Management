#ifndef SALLEID_H
#define SALLEID_H

#include <QDialog>

namespace Ui {
class SalleID;
}

class SalleID : public QDialog
{
    Q_OBJECT

public:
    explicit SalleID(QWidget *parent = nullptr);
    ~SalleID();

private:
    Ui::SalleID *ui;
};

#endif // SALLEID_H
