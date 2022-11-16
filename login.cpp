#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:/Users/lenovo/Documents/QT/DepartmentDB.db");
        if(!db.open()){
//            qDebug()<<"Can't connect to the database !";
            ui->db_status->setText("Failed to connect to database");
        }
        else{
//            qDebug()<<"Connected !";
            ui->db_status->setText("Connected !! ");
        }
}

Login::~Login()
{
    delete ui;
}
void Login::on_loginButton_clicked()
{
//    QString username = ui->username->text();
//    QString password = ui->password->text();
//    if(username == "amina" && password == "amina"){
//        QMessageBox::information(this,"Login","Username and password are correct");
//    }
//    else {
//        QMessageBox::warning(this,"Login","Username and password are not correct");
//    }
}

