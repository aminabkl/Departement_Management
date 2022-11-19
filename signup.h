#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlQuery>

namespace Ui {
class Signup;
}

class Signup : public QDialog
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();

private slots:
    void on_SignupButton_clicked();

    void on_LoginReturn_clicked();

private:
    Ui::Signup *ui;
    QSqlDatabase db;
};

#endif // SIGNUP_H
