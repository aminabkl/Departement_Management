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
    QString Username, Password;
    Username = ui->username->text();
    Password = ui->password->text();

    if(!db.isOpen()){
            qDebug()<<"Failed";
            return;
        }
    QSqlQuery qry;
        if(qry.exec("SELECT Username, Password FROM Login WHERE Username='"+Username+"'and Password='"+Password+"'" )){

            if (qry.next()){
                ui->auth_ver->setText("WELCOME");
                QString msg = "Username = " +qry.value(0).toString()+"\n" +
                        "Password = " +qry.value(1).toString()+"\n";

                QMessageBox::warning(this,"Welcome Two ",msg);
                    }
            else ui->auth_ver->setText("ERROR NO AUTH");

}}

