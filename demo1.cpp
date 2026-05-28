#include"demo1.h"
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
#include<iostream>
//判断账号合法性
bool judgeac(const char * p)
{
    int len=(int)qstrlen(p);
    if(len<8||len>20)
    {
        return false;
    }
    for(int i=0;i<len;i++)
    {
        if(p[i]==' '||p[i]=='\t'||p[i]<33||p[i]>126||p[i]=='\\'||p[i]=='/'||p[i]==':'||p[i]=='*'||p[i]=='?'||p[i]=='"'||p[i]=='<'||p[i]=='>'||p[i]=='|')
        {
            return false;
        }
    }
    return true;
}
//判断密码合法性
bool judgepw(const char *p)
{
    int len=(int)qstrlen(p);
    int t1=0,t2=0,t3=0;
    if(len<8||len>20)
    {
        return false;
    }
    for(int i=0;i<len;i++)
    {
        if(isdigit(p[i]))
        {
            t1=1;
        }
        else if((p[i]>='a'&&p[i]<='z')||(p[i]>='A'&&p[i]<='Z'))
        {
            t2=1;
        }
        else if((p[i]>=33&&p[i]<=47)||(p[i]>=58&&p[i]<=64)||(p[i]>=91&&p[i]<=96)||(p[i]>=123&&p[i]<=126))
        {
            t3=1;
        }
    }
    if(t1==1&&t2==1&&t3==1)
    {
        return true;
    }
    return false;
}
//判断两个字符串是否相等
bool issame(const char *a,const char *b)
{
    int len1=(int)qstrlen(a);
    int len2=(int)qstrlen(b);
    if(len1!=len2)
    {
        return false;
    }
    for(int i=0;i<len1;i++)
    {
        if(a[i]!=b[i])
        {
            return false;
        }
    }
    return true;
}
//加密
void tran1(const char password[],char random[],char cipher[])
{
    const int len=(int)strlen(password);
    random[len]='\0',cipher[len]='\0';
    srand(time(NULL));
    for (int i=0;i<len;i++)
    {
        random[i]=(char)(rand()%94+'!');
        cipher[i] = (char)(((password[i] - random[i] + 94) % 94) + '!');
    }
}
//解密
void tran2(char password[],char random[],const char cipher[])
{
    const int len=(int)strlen(random);
    for (int i=0;i<len;i++)
    {
        password[i]=(char)((random[i]+cipher[i]-'!'*2)%94+'!');
    }
    password[len]='\0';
}



//向key.csv文件中追加记录（若文件不存在则创建文件）
void add_key(key &k)
{
    QString path = QCoreApplication::applicationDirPath()+ "/key.csv";
    QFile f(path);
    // f.open(QIODevice::Append | QIODevice::Text);
    // QTextStream out(&f);
    // out<<k.account<<"\t"<<k.random_key<<"\t"<<k.cipher<<"\n";
    // qDebug()<<k.account<<"\t"<<k.random_key<<"\t"<<k.cipher<<"\n";
    // f.close();
    freopen("key.csv","a",stdout);
    std::cout<<k.account.toStdString()<<"\t"<<k.random_key.toStdString()<<"\t"<<k.cipher.toStdString()<<"\n";
}

//读取key.csv到内存
QList<key> read_key()
{
    QList<key> k1;
    QString path = QCoreApplication::applicationDirPath()+ "/key.csv";
    //QString path ="C:\\Users\\17708\\Desktop\\last2\\last2\\wu_zi_qi\\build\\Desktop_Qt_6_11_0_MinGW_64_bit-Debug\\key.csv";
    QFile f(path);
    if(!f.exists())
    {
        f.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&f);
        out<<"账号"<<"\t"<<"随机生成密文"<<"\t"<<"密文"<<"\n";
        f.close();
    }
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
        key k;
        k.account=parts[0];
        k.random_key=parts[1];
        k.cipher=parts[2];
        k1.append(k);
    }
    f.close();
    return k1;
}

//向answer.csv文件中追加记录
void add_answer(answer &a)
{
    QString path = qApp->applicationDirPath() + "/answer.csv";
    QFile f(path);
    if(!f.exists())
    {
        f.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&f);
        out<<"账号"<<"\t"<<"问题"<<"\t"<<"答案"<<"\n";
        f.close();
    }
    freopen("answer.csv","a",stdout);
    std::cout<<a.account.toStdString()<<"\t"<<a.question.toStdString()<<"\t"<<a.answers.toStdString()<<"\n";
}

//读取answer.csv文件到内存
QList<answer> read_answer()
{
    QList<answer> a1;
    QString path = qApp->applicationDirPath() + "/answer.csv";
    QFile f(path);
    if(!f.exists())
    {
        f.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream out(&f);
        out<<"账号"<<"\t"<<"问题"<<"\t"<<"答案"<<"\n";
        f.close();
    }
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr,"文件错误","文件打开失败！");
        return a1;
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
        answer a;
        a.account=parts[0];
        a.question=parts[1];
        a.answers=parts[2];
        a1.append(a);
    }
    f.close();
    return a1;
}

//在key.csv中查找特定账号，并判断密码正确性(0代表账号存在且密码正确，1代表账号存在但是密码错误，2代表账号不存在)
int judge_key(QString ac,QString pw)
{
    QList<key> k=read_key();
    for(int i=0;i<k.size();i++)
    {
        if(k[i].account==ac)
        {
            char a[50]={0};
            tran2(a,const_cast<char*>(qPrintable(k[i].random_key)),const_cast<char*>(qPrintable(k[i].cipher)));
            if(issame(a,qPrintable(pw)))
            {
                return 0;
            }
            return 1;
        }
    }
    return 2;
}

//在key.csv中查找特定账号，返回查找结果
bool find_ac_key(QString ac)
{
    QList<key> k=read_key();
    for(int i=0;i<k.size();i++)
    {
        if(k[i].account==ac)
        {
            return true;
        }
    }
    return false;
}

//在answer.csv中查找特定账号，返回账号对应的问题（已经确定账号存在）
QString find_question_answer(QString ac)
{
    QList<answer> answer=read_answer();
    for(int i=0;i<answer.size();i++)
    {
        if(answer[i].account==ac)
        {
            return answer[i].question;
        }
    }
    return " ";
}

//在answer.csv中查找特定账号，返回查找结果
bool find_ac_answer(QString ac)
{
    QList<answer> a=read_answer();
    for(int i=0;i<a.size();i++)
    {
        if(a[i].account==ac)
        {
            return true;
        }
    }
    return false;
}

//在answer.csv中查找特定账号，返回账号对应的答案（已经确定账号存在）
QString find_answer_answer(QString ac)
{
    QList<answer> answer=read_answer();
    for(int i=0;i<answer.size();i++)
    {
        if(answer[i].account==ac)
        {
            return answer[i].answers;
        }
    }
    return " ";
}

//将更改过的记录写入key.csv
void write_key(QList<key> &k)
{
    QString path = qApp->applicationDirPath() + "/key.csv";
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream out(&file);
    out << "账号\t随机生成密文\t密文\n";
    for(int i=0; i<k.size(); i++)
    {
        out << k[i].account << "\t"<< k[i].random_key << "\t"<< k[i].cipher << "\n";
    }
    file.close();
}

//在key.csv中找到特定账号并修改对应密码
void change_pw_key(QString ac,QString pw)
{
    QList<key> k=read_key();
    for(int i=0;i<k.size();i++)
    {
        if(k[i].account==ac)
        {
            char cipher1[50]={0};
            char random1[50]={0};
            tran1(pw.toLocal8Bit().constData(),random1,cipher1);
            k[i].cipher=QString(cipher1);
            k[i].random_key=QString(random1);
            break;
        }
    }
    write_key(k);
}

//在key.csv中查找特定账号并返回对应密码
QString pw_key(QString ac)
{
    QList<key> k=read_key();
    for(int i=0;i<k.size();i++)
    {
        if(k[i].account==ac)
        {
            char pw[30]={0};
            tran2(pw,const_cast<char*>(k[i].random_key.toLocal8Bit().constData()),k[i].cipher.toLocal8Bit().constData());
            return QString(pw);
        }
    }
    return " ";
}

bool judge_question_answer(const char * str)
{
    int len=(int)strlen(str);
    for(int i=0;i<len;i++)
    {
        if(str[i]<32||str[i]>126)
        {
            return false;
        }
    }
    return true;
}

QString convert(const QString &str) {
    QString res;
    for(int i=0;i<str.length();i++) {
        if (str[i]=='\\') {
            res+="\\";
        }
        else {
            res+=str[i];
        }
    }
    return res;
}