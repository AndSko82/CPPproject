#include<iostream>
using namespace std;
class Point
{
    int x,y;
public:
    Point();
    int getx();
    int gety();
    void setx(int);
    void sety(int);
};

class Room
{
    Point w[2];
    string color;
public:
    Room();
    Room(int,int,int,int,string);
    string getc();
    int getx1();
    int gety1();
    int getx2();
    int gety2();
    void setc(string);
    void show();
    void load();
};
