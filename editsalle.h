#ifndef EDITSALLE_H
#define EDITSALLE_H

#include <QDialog>

namespace Ui {
class EditSalle;
}

class EditSalle : public QDialog
{
    Q_OBJECT

public:
    explicit EditSalle(QWidget *parent = nullptr);
    ~EditSalle();

private:
    Ui::EditSalle *ui;
};

#endif // EDITSALLE_H
