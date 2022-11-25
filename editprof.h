#ifndef EDITPROF_H
#define EDITPROF_H


#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>

namespace Ui {
class editprof;
}

class editprof : public QDialog
{
    Q_OBJECT

public:
    explicit editprof(QWidget *parent = nullptr);
    ~editprof();

private slots:
    void on_EditButton_clicked();

    void on_SalleReturn_clicked();

    void on_SearchButton_clicked();

private:
    Ui::editprof *ui;
    QSqlDatabase db;
};

#endif // EDITPROF_H
