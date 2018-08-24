#include "sqlUntils.h"
#include <QDebug>
#include <QSqlError>
#include <assert.h>
#include <QSqlQuery>

sqlUntils* sqlUntils::m_pInst = nullptr;

sqlUntils::sqlUntils(QObject *parent) : QObject(parent)
{

}

sqlUntils::~sqlUntils()
{
    closeDb();
}

sqlUntils *sqlUntils::getSqlUntils()
{
    if (m_pInst == nullptr)
    {
        m_pInst = new sqlUntils();
    }
    return m_pInst;
}

void sqlUntils::raleseSqlUntils()
{
    if (m_pInst != nullptr)
    {
        delete m_pInst;
        m_pInst = nullptr;
    }
}

QString sqlUntils::getGUID()
{
    QUuid id = QUuid::createUuid();
    QString strId = id.toString();
    strId.replace("-", "");
    strId.remove(33, 1);
    strId.remove(0, 1);
    return strId;
}

bool sqlUntils::openDb()
{
    db = QSqlDatabase::addDatabase("QMYSQL", "douge");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("orderingsystem");
    db.setUserName("root");
    db.setPassword("123456");

    if (db.open())
    {
        return true;
    }
    return false;
}

void sqlUntils::closeDb()
{
    if (db.isOpen())
    {
        db.close();
    }
}

QString sqlUntils::getError()
{
    QSqlError e = db.lastError();
    qDebug() << e.text();
    return e.text();
}

QSqlQuery sqlUntils::execSqlSelect(QString sql)
{
    assert(sql.length() != 0);

    QSqlQuery query(db);
    qDebug() << sql;

    if (query.exec(sql))
    {
        return query;
    }
    //错误直接获取错误，打印出来
    getError();

    return QSqlQuery();
}

bool sqlUntils::execSql(QString sql)
{
    assert(sql.length() != 0);

    QSqlQuery query(db);
    qDebug() << sql;

    if (query.exec(sql))
    {
        return true;
    }
    //错误直接获取错误，打印出来
    getError();

    return false;
}
