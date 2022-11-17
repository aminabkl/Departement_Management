#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
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
    QString Username, Password;
    Username = ui->username->text();
    Password = ui->password->text();

    if(!db.isOpen()){
            qDebug()<<"Failed";
            return;
        }
    QSqlQuery qry;
    if(qry.exec("SELECT * FROM Login WHERE Username='"+Username+"'and Password='"+Password+"'" )){
        int count=0;
                    while(qry.next()){
                        count++;
                        qDebug()<<count;
                    }
                    if(count==1 ){
                           ui->auth_ver->setText("WELCOME");
                           QMessageBox::warning(this,"Login","WELCOME ADMIN");}

                   else{
                        ui->auth_ver->setText("ERROR NO AUTH");
                    QMessageBox::warning(this,"Login","Incorrect, Vérifier votre email ou votre mot de passe");
}
}

}


