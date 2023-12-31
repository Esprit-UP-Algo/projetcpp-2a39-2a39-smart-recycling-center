#include "collect.h"
#include "mainwindow.h"

#include<QSqlQuery>
#include<QObject>
collect::collect()
{
    id_c="",empp="",qua="",quantite=0;
    date_co=QDate::currentDate();

}

collect::collect ( QString id_c, QDate date_co,QString empp,QString qua,int quantite)
{
    this->id_c=id_c;this->date_co=date_co ;this->empp=empp ; this->qua=qua ;this->quantite=quantite ;
}

QString collect:: getid_c(){return id_c ;}
QDate  collect::getdate_c(){return date_co ;}
QString  collect::getempp(){return empp ;}
QString  collect::getqua(){return qua ;}
int collect::getQuantite(){return quantite;}
void collect::setid_c(QString id_c){this->id_c=id_c;}
void collect::setdate_co(QDate date_co){this->date_co=date_co;}
void collect::setempp(QString empp){this->empp=empp;}
void collect::setqua(QString qua){this->qua=qua;}
void collect::setQuantite(int quantite){this->quantite=quantite;}
bool collect::ajouter()
{
    bool test=false;
    QSqlQuery query;
    query.prepare("INSERT INTO COLLECTE (ID_COL, DATE_DE_COLLECTE, EMPLACEMENT,QUANTITE,DATE_DE_PRODUCTION)/// "
                        "VALUES (:ID_COL, :DATE_DE_COLLECTE, :EMPLACEMENT,:QUANTITE,:DATE_DE_PRODUCTION)");
          query.bindValue(":ID_COL",id_c );
          query.bindValue(":DATE_DE_COLLECTE", date_co);
          query.bindValue(":EMPLACEMENT", empp);
          query.bindValue(":QUALITE",qua );
          query.bindValue(":QUANTITE",quantite );
          query.exec();

    return test;
}
bool collect::supprimer(QString id_c )
{
    bool test=false;
    QSqlQuery query;
    query.prepare("DELETE FROM COLLECTE WHERE id=:ID_COL" );
          query.bindValue(":ID_COL",id_c );
          query.exec();

    return test;

}

QSqlQueryModel* collect::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM COLLECTE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date_c"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("empp"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("qua"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("quantite"));
    return model;

}
