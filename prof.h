#ifndef PROF_H
#define PROF_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>
namespace Ui {
class prof;
}

class prof : public QDialog
{
    Q_OBJECT

public:
    explicit prof(QWidget *parent = nullptr);
    ~prof();
private slots:

    void on_AddButton_clicked();

    void on_EditButton_clicked();

    void on_DeleteButton_clicked();

    void on_SearchButton_clicked();

    void on_RefreshTable_clicked();

    void on_ReturnMenu_clicked();

private:
    Ui::prof *ui;
    QSqlDatabase db;
};

#endif // PROF_H
