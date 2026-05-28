#ifndef DEMO1_H
#define DEMO1_H
#include<QString>

struct key
{
    QString account;
    QString random_key;
    QString cipher;
};

struct answer
{
    QString account;
    QString question;
    QString answers;
};

bool judgeac(const char *p);//判断账号合法性
bool judgepw(const char *p);//判断密码合法性
bool issame(const char *a,const char *b);//判断两个字符串是否相等
void add_key(key &k);//向key.csv文件中追加记录（若文件不存在则创建文件）
QList<key> read_key();//读取key.csv到内存
void add_answer(answer &a);//向answer.csv文件中追加记录
QList<answer> read_answer();//读取answer.csv文件到内存
void tran1(const char password[],char random[],char cipher[]);//加密
void tran2(char password[],char random[],const char cipher[]);//解密
int judge_key(QString ac,QString pw);//在key.csv中查找特定账号，并判断密码正确性(0代表账号存在且密码正确，1代表账号存在但是密码错误，2代表账号不存在)
bool find_ac_key(QString ac);//在key.csv中查找特定账号，返回查找结果
bool find_ac_answer(QString ac);//在answer.csv中查找特定账号，返回查找结果
QString find_question_answer(QString ac);//在answer.csv中查找特定账号，返回账号对应的问题（已经确定账号存在）
QString find_answer_answer(QString ac);//在answer.csv中查找特定账号，返回账号对应的答案（已经确定账号存在）
void change_pw_key(QString ac,QString pw);//在key.csv中找到特定账号并修改对应密码
void write_key(QList<key> &k);//将更改过的记录写入key.csv
QString pw_key(QString ac);//在key.csv中查找特定账号并返回对应密码
bool judge_question_answer(const char * str);
QString convert(const QString &str);

#endif // DEMO1_H
