#ifndef ADDSALLE_H
#define ADDSALLE_H


#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>


namespace Ui {
class AddSalle;
}

class AddSalle : public QDialog
{
    Q_OBJECT

public:
    explicit AddSalle(QWidget *parent = nullptr);
    ~AddSalle();

private slots:
    void on_AddButton_clicked();

    void on_SalleReturn_clicked();

private:
    Ui::AddSalle *ui;
    QSqlDatabase db;
};

#endif // ADDSALLE_H
