#ifndef GLXSQLUTILS_H
#define GLXSQLUTILS_H

#include <QtSql/QSqlDatabase>
#include <QStringList>

class GLXSqlUtils
{
public:
    static GLXSqlUtils* getGlxSqlUtils();
    static bool initGlxSqlUtils(QString dataBaseName);
    static void deleteGlxSqlUtils();

    static QSqlError getLastError();

private:
    GLXSqlUtils();
    virtual ~GLXSqlUtils();

public:
    bool open(QString dataBaseName);
    bool createTable(QString strSql);
    bool createTable();

    bool add(QString &table, QStringList &names, QStringList &values);
    bool del(QString &table, QString &expression);
    bool update(QString &table, QStringList &names, QStringList &values, QString &expression);
    QSqlQuery select(QString &table, QStringList &values, QString where, bool isWhere = false);

    void setDatabaseName(QString dbName);
    void closeDb();

private:
    QSqlDatabase m_pDB;
    QString m_sDatabaseName;

    static GLXSqlUtils *m_pSql;
};

#endif // GLXSQLUTILS_H
