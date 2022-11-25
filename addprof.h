#ifndef ADDPROF_H
#define ADDPROF_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>
namespace Ui {
class addprof;
}

class addprof : public QDialog
{
    Q_OBJECT

public:
    explicit addprof(QWidget *parent = nullptr);
    ~addprof();

private slots:
    void on_AddButton_clicked();

    void on_SalleReturn_clicked();

private:
    Ui::addprof *ui;
    QSqlDatabase db;
};

#endif // ADDPROF_H
