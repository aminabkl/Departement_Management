#ifndef EDITCOORD_H
#define EDITCOORD_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>


namespace Ui {
class EditCoord;
}

class EditCoord : public QDialog
{
    Q_OBJECT

public:
    explicit EditCoord(QWidget *parent = nullptr);
    ~EditCoord();

private slots:
    void on_SearchButton_clicked();

    void on_EditButton_clicked();

    void on_SalleReturn_clicked();

private:
    Ui::EditCoord *ui;
    QSqlDatabase db;
};

#endif // EDITCOORD_H
