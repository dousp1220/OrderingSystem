#ifndef SQLUNTILS_H
#define SQLUNTILS_H

#include <QObject>
#include <QSqlDatabase>
#include <QUuid>

class sqlUntils : public QObject
{
    Q_OBJECT
private:
    explicit sqlUntils(QObject *parent = nullptr);
    ~sqlUntils();

public:
    static sqlUntils* getSqlUntils();
    static void raleseSqlUntils();
    static QString getGUID();

    bool openDb();
    void closeDb();

    /**
     * @brief execSql  主要用于查询，查询需要返回查询结果
     * @param sql
     * @return
     */
    QSqlQuery execSqlSelect(QString sql);

    /**
     * @brief execSql 主要用于新增，修改，删除
     * @param sql
     * @return
     */
    bool execSql(QString sql);

    QString getError();

signals:

public slots:

private:
    static sqlUntils* m_pInst;
    QSqlDatabase db;
};

#endif // SQLUNTILS_H
