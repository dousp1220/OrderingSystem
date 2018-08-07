#include "GLXSqlUtils.h"
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlRecord>

//http://www.cnblogs.com/wiessharling/p/3848962.html
GLXSqlUtils *GLXSqlUtils::m_pSql = NULL;

GLXSqlUtils *GLXSqlUtils::getGlxSqlUtils()
{
    if (m_pSql == NULL)
    {
        m_pSql = new GLXSqlUtils();
    }
    return m_pSql;
}

bool GLXSqlUtils::initGlxSqlUtils(QString dataBaseName)
{
    return m_pSql->open(dataBaseName);
}

void GLXSqlUtils::deleteGlxSqlUtils()
{
    delete m_pSql;
}

QSqlError GLXSqlUtils::getLastError()
{
    return m_pSql->m_pDB.lastError();
}

GLXSqlUtils::GLXSqlUtils()
{
}

GLXSqlUtils::~GLXSqlUtils()
{
    m_pDB.close();
}

bool GLXSqlUtils::open(QString dataBaseName)
{
    m_sDatabaseName = dataBaseName;
    m_pDB = QSqlDatabase::addDatabase("QSQLITE");
    m_pDB.setDatabaseName(m_sDatabaseName);
    //("QSQLITE", "QMYSQL", "QMYSQL3", "QODBC", "QODBC3", "QPSQL", "QPSQL7")
//    qDebug() << QSqlDatabase::drivers();
    if(m_pDB.open())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GLXSqlUtils::createTable(QString strSql)
{
    QSqlQuery query(m_pDB);

    if (!query.exec(strSql))
    {
        qDebug() << "Create Table Failed!";
        return false;
    }
    else
    {
        qDebug() << "Create Table success!";
        return true;
    }
}

bool GLXSqlUtils::createTable()
{
    QSqlQuery query(m_pDB);
    QString strSql = "CREATE TABLE hehe ("
                                                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                                        "zi varchar(30), "
                                                        "py varchar(30), "
                                                        "wubi varchar(30), "
                                                        "bushou varchar(30), "
                                                        "bihua INTEGER, "
                                                        "pinyin varchar(30), "
                                                        "jijie varchar, "
                                                        "xiangjie varchar)";


    if (!query.exec(strSql))
    {
        qDebug() << "Create Table Failed!";
        return false;
    }
    else
    {
        qDebug() << "Create Table success!";
        return true;
    }
}

bool GLXSqlUtils::add(QString &table, QStringList &names, QStringList &values)
{
    if (names.size() != values.size())
    {
        return false;
    }

    QSqlQuery query(QSqlDatabase::database());

    QString sql = QString("insert into ") + table + QString("(");

    int i;

    for (i=0; i < names.size(); i++)
    {
        sql = sql + names.value(i);
        if (i != names.size() - 1)
        {
            sql+=QString(",");
        }
        else
        {

            sql = sql + QString(")");
        }
    }

    sql = sql + QString("values (");

    for (i = 0; i < values.size(); i++)
    {
        sql = sql + QString("'") + values.value(i) + QString("'");
        if (i != values.size()-1)
        {
            sql = sql + QString(",");
        }
    }

    sql = sql + QString(")");

    if (query.exec(sql))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GLXSqlUtils::del(QString &table, QString &expression)
{
    //DELETE FROM 表名称 WHERE 列名称 = 值
    QSqlQuery query(QSqlDatabase::database());
    QString sql = QString("delete from ") + table + QString(" where ") + expression;

    if (query.exec(sql))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GLXSqlUtils::update(QString &table, QStringList &names, QStringList &values, QString &expression)
{
    if (names.size() != values.size())
    {
        return false;
    }

    //UPDATE 表名称 SET 列名称 = 新值 WHERE 列名称 = 某值
    QSqlQuery query(QSqlDatabase::database());
    QString sql = QString("update ")+table+QString(" set ");
    for (int i = 0; i < names.size(); i++)
    {
        sql = sql + names.value(i);
        sql = sql + QString(" = '");
        sql = sql + values.value(i);
        sql = sql + QString("'");
        if (i != names.size()-1)
        {
            sql = sql + QString(" ,");
        }
    }

    sql = sql + QString(" where ") + expression;
    if (query.exec(sql))
    {
        return true;
    }
    else
    {
        return false;
    }
}

QSqlQuery GLXSqlUtils::select(QString &table, QStringList &values, QString where, bool isWhere)
{
    if (!m_pDB.open())
    {
        return QSqlQuery();
    }

    QSqlQuery query(m_pDB);

    QString sql = QString("select * from ") + table;
    if (isWhere)
    {
        sql += " where " + where;
    }

    int res = query.exec(sql);

    if (res)
    {
        return query;
    }

    return QSqlQuery();
}

void GLXSqlUtils::setDatabaseName(QString dbName)
{
    m_sDatabaseName = dbName;
}

void GLXSqlUtils::closeDb()
{
    m_pDB.close();
}

