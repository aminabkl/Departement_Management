#ifndef SALLE_H
#define SALLE_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>

namespace Ui {
class Salle;
}

class Salle : public QDialog
{
    Q_OBJECT

public:
    explicit Salle(QWidget *parent = nullptr);
    ~Salle();

private slots:

    void on_AddButton_clicked();

    void on_EditButton_clicked();

    void on_DeleteButton_clicked();

    void on_SearchButton_clicked();

    void on_RefreshTable_clicked();

    void on_ReturnMenu_clicked();

private:
    Ui::Salle *ui;
    QSqlDatabase db;
};

#endif // SALLE_H
