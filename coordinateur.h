#ifndef COORDINATEUR_H
#define COORDINATEUR_H

#include <QDialog>

namespace Ui {
class Coordinateur;
}

class Coordinateur : public QDialog
{
    Q_OBJECT

public:
    explicit Coordinateur(QWidget *parent = nullptr);
    ~Coordinateur();

private:
    Ui::Coordinateur *ui;
};

#endif // COORDINATEUR_H
