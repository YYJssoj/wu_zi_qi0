#ifndef DEMO_H
#define DEMO_H
#include<QString>

struct p
{
    QString account;
    QString password;
};

struct point
{
    int x;
    int y;
};

struct Record
{
    QString account1;
    QString account2;
    qint64 begin_time;
    int result;
    QString filename;
};

struct Record_2
{
    QString account_person;
    int com_color;
    qint64 begin_time;
    int result;
    QString filename;
};


QList<point> read_point();
void add_record(Record &p);
QList<Record_2> read_record();
QString timestamp_timestring(qint64 timestamp);
QList<Record> read_record_1();

#endif // DEMO_H
