#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}
void Login::on_loginButton_clicked()
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    if(username == "amina" && password == "amina"){
        QMessageBox::information(this,"Login","Username and password are correct");
    }
    else {
        QMessageBox::warning(this,"Login","Username and password are not correct");
    }
}

