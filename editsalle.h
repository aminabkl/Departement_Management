#ifndef EDITSALLE_H
#define EDITSALLE_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>

namespace Ui {
class EditSalle;
}

class EditSalle : public QDialog
{
    Q_OBJECT

public:
    explicit EditSalle(QWidget *parent = nullptr);
    ~EditSalle();

private slots:
    void on_SalleReturn_clicked();

    void on_SearchButton_clicked();

    void on_EditButton_clicked();

private:
    Ui::EditSalle *ui;
    QSqlDatabase db;
};

#endif // EDITSALLE_H
