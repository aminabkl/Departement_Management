#ifndef COORDINATEUR_H
#define COORDINATEUR_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>

namespace Ui {
class Coordinateur;
}

class Coordinateur : public QDialog
{
    Q_OBJECT

public:
    explicit Coordinateur(QWidget *parent = nullptr);
    ~Coordinateur();

private slots:
    void on_AddButton_clicked();

    void on_EditButton_clicked();

    void on_DeleteButton_clicked();

    void on_SearchButton_clicked();

    void on_RefreshTable_clicked();

    void on_ReturnMenu_clicked();

private:
    Ui::Coordinateur *ui;
    QSqlDatabase db;
};

#endif // COORDINATEUR_H
