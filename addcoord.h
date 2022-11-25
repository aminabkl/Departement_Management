#ifndef ADDCOORD_H
#define ADDCOORD_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>

namespace Ui {
class AddCoord;
}

class AddCoord : public QDialog
{
    Q_OBJECT

public:
    explicit AddCoord(QWidget *parent = nullptr);
    ~AddCoord();

private slots:
    void on_AddButton_clicked();

    void on_CoordReturn_clicked();

private:
    Ui::AddCoord *ui;
    QSqlDatabase db;
};

#endif // ADDCOORD_H
