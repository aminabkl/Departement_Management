#ifndef NAVMENU_H
#define NAVMENU_H


#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>

namespace Ui {
class NavMenu;
}

class NavMenu : public QDialog
{
    Q_OBJECT

public:
    explicit NavMenu(QWidget *parent = nullptr);
    ~NavMenu();

private slots:
    void on_GoSalle_clicked();

    void on_GoProf_clicked();

    void on_LogoutButton_clicked();

private:
    Ui::NavMenu *ui;
    QSqlDatabase db;
};

#endif // NAVMENU_H
