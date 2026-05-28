#include"demo.h"
#include <QWidget>
#include<QProgressBar>
#include<QTimer>
#include<QMainWindow>
#include <QMessageBox>
#include<QByteArray>
#include<QChar>
#include<QFile>
#include<QTextStream>
#include<QList>
#include<QApplication>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStringList>
#include<QDateTime>
#include<QTimeZone>


//读取对局过程文件到内存(record_2)
QList<point> read_point(QString &filename)
{
    QList<point> k1;
    QString path =QCoreApplication::applicationDirPath()+"/"+filename;
    QFile f(path);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr,"文件错误","文件打开失败！");
        return k1;
    }
    QTextStream read(&f);
    if(!read.atEnd())
    {
        read.readLine(); // 读取表头
    }
    while(!read.atEnd())
    {
        QString line=read.readLine().trimmed();//读取一整行
        QStringList parts=line.split("\t");//以\t为分隔符分割
        point k;
        k.x=parts[0].toInt();
        k.y=parts[1].toInt();
        k1.append(k);
    }
    f.close();
    return k1;
}



//读取record_2.csv到内存
QList<Record_2> read_record()
{
    QList<Record_2> k1;
    QString path = qApp->applicationDirPath() + "/record_2.csv";
    QFile f(path);
    if(!f.exists())
    {
        f.open(QIODevice::NewOnly | QIODevice::Text);
        f.close();
    }
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr,"文件错误","文件打开失败！");
        return k1;
    }
    QTextStream read(&f);
    while(!read.atEnd())
    {
        QString line=read.readLine().trimmed();//读取一整行
        QStringList parts=line.split("\t");//以\t为分隔符分割
        Record_2 k;
        k.account_person=parts[0];
        k.com_color=parts[1].toInt();
        k.begin_time=parts[2].toLongLong();
        k.result=parts[3].toInt();
        k.filename=parts[4];
        k1.append(k);
    }
    f.close();
    return k1;
}



//时间戳转换标准时间
QString timestamp_timestring(qint64 timestamp)
{
    QDateTime dt;
    if (timestamp > 1000000000000)
    {
        dt = QDateTime::fromMSecsSinceEpoch(timestamp);
    }
    else
    {
        dt = QDateTime::fromSecsSinceEpoch(timestamp);
    }
    dt.setTimeZone(QTimeZone("Asia/Shanghai"));
    return dt.toString("yyyy-MM-dd-HH-mm-ss-zzz");
}

//读取record.csv到内存
QList<Record> read_record_1()
{
    QList<Record> k1;
    QString path = qApp->applicationDirPath() + "/record.csv";
    QFile f(path);
    if(!f.exists())
    {
        f.open(QIODevice::NewOnly | QIODevice::Text);
        f.close();
    }
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr,"文件错误","文件打开失败！");
        return k1;
    }
    QTextStream read(&f);
    while(!read.atEnd())
    {
        QString line=read.readLine().trimmed();//读取一整行
        QStringList parts=line.split("\t");//以\t为分隔符分割
        Record k;
        k.account1=parts[0];
        k.account2=parts[1];
        k.begin_time=parts[2].toLongLong();
        k.result=parts[3].toInt();
        k.filename=parts[4];
        k1.append(k);
    }
    f.close();
    return k1;
}