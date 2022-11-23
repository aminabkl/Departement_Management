#ifndef DELETESALLE_H
#define DELETESALLE_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>

namespace Ui {
class DeleteSalle;
}

class DeleteSalle : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteSalle(QWidget *parent = nullptr);
    ~DeleteSalle();

private slots:
    void on_SearchButton_clicked();

    void on_DeleteButton_clicked();

    void on_SalleReturn_clicked();

private:
    Ui::DeleteSalle *ui;
    QSqlDatabase db;
};

#endif // DELETESALLE_H
