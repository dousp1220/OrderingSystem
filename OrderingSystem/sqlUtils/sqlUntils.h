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

    QSqlQuery execSql(QString sql);

    QString getError();

signals:

public slots:

private:
    static sqlUntils* m_pInst;
    QSqlDatabase db;
};

#endif // SQLUNTILS_H
