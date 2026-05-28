#ifndef STDSHARED_H
#define STDSHARED_H


enum ROLE{
    empty,player1,player2
};
enum result{
    he,black,white//winnner
};

struct movehistory{
    int r;
    int c;
    ROLE player;
};
#endif // STDSHARED_H
