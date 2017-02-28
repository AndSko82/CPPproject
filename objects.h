#include<iostream>
using namespace std;
class Obiekt
{
protected:
    int x,y,cena,roomnumb;
    string name;
public:

    Obiekt();
    Obiekt(int,int,string);
    virtual~Obiekt();
    int getx();
    int gety();
    int gprice();
    int getnumb();
    string getn();
    void sprice(int);
    void setnumb(int);
    void setx(int);
    void sety(int);
    void setn(string);
    virtual void show()=0;
    virtual void load()=0;
    friend int calculate();

};

class Gcard
{
    int memory;
    string nazwa;
public:
    Gcard();
    int getmem();
    string getn();
    void setmem(int);
    void setn(string);
};

class Drive
{
    int cap,speed;
public:
    Drive();
    int getcap();
    int getsp();
    void setcap(int);
    void setsp(int);
};

class Monitor
{
    int inch;
    string name;
public:
    Monitor();
    int gets();
    string getn();
    void sets(int);
    void setn(string);
};

class Computer:public Obiekt
{
    Gcard g;
    Drive d;
    Monitor m;
    double cpu;
    int ram;
public:
    Computer();
    void show();
    void load();
};

class Ward : public Obiekt
{
    int wys,waga;
    string color;
public:
    Ward();
    void show();
    void load();
};

class Board : public Obiekt
{
    int sred;
    string color;
public:
    Board();
    void show();
    void load();
};

class Bed : public Obiekt
{
    int len,wid;
public:
    Bed();
    void show();
    void load();
};

class TV :public Obiekt
{
    int inch;
    string tvname;
public:
    TV();
    void show();
    void load();
};

class Fridge:public Obiekt
{
    int wys,waga,cap;
public:
    Fridge();
    void show();
    void load();
};

class Lamp:public Obiekt
{
    int wys;
    string color;
public:
    Lamp();
    void show();
    void load();
};
class Desk:public Obiekt
{
    int wid;
    string color;
public:
    Desk();
    void show();
    void load();
};

