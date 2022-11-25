#ifndef DELETEPROF_H
#define DELETEPROF_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>
namespace Ui {
class deleteprof;
}

class deleteprof : public QDialog
{
    Q_OBJECT

public:
    explicit deleteprof(QWidget *parent = nullptr);
    ~deleteprof();

private slots:
    void on_DeleteButton_clicked();

    void on_SalleReturn_clicked();

    void on_SearchButton_clicked();

private:
    Ui::deleteprof *ui;
    QSqlDatabase db;
};

#endif // DELETEPROF_H
