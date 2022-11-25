#ifndef DELETECOORD_H
#define DELETECOORD_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>

namespace Ui {
class DeleteCoord;
}

class DeleteCoord : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteCoord(QWidget *parent = nullptr);
    ~DeleteCoord();

private slots:
    void on_SearchButton_clicked();

    void on_DeleteButton_clicked();

    void on_SalleReturn_clicked();

private:
    Ui::DeleteCoord *ui;
    QSqlDatabase db;
};

#endif // DELETECOORD_H
