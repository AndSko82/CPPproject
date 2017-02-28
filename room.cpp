#include<windows.h>
#include"room.h"
using namespace std;
Point::Point():x(0),y(0) {}
int Point::getx()
{
    return x;
}
int Point::gety()
{
    return y;
}
void Point::setx(int a)
{
    x=a;
}
void Point::sety(int b)
{
    y=b;
}

Room::Room():color("")
{
    w[0].setx(2);
    w[0].sety(3);
    w[1].setx(0);
    w[1].sety(0);
}
Room::Room(int a,int b,int c,int d,string col)
{
    w[0].setx(a);
    w[0].sety(b);
    w[1].setx(c);
    w[1].sety(d);
    color=col;
}
int Room::getx1()
{
    return w[0].getx();
}
int Room::gety1()
{
    return w[0].gety();
}
int Room::getx2()
{
    return w[1].getx();
}
int Room::gety2()
{
    return w[1].gety();
}
void Room::show()
{
    cout<<"Wspolrzedne lewego gornego naroznika: "<<w[0].getx()<<" i "<<w[0].gety()<<" oraz prawego dolnego: "<<w[1].getx()<<" i "<<w[1].gety()<<endl;
    cout<<"Kolor scian: "<<color<<endl;
    cout<<endl;
}
void Room::load()
{
    int e;
    string n;
    cout<<"Podaj wspolrzedna x lewego gornego naroznika: ";
    cin>>e;
    w[0].setx(e);
    cout<<"Podaj wspolrzedna y lewego gornego naroznika: ";
    cin>>e;
    w[0].sety(e);
    cout<<"Podaj wspolrzedna x prawego dolnego naroznika: ";
    cin>>e;
    w[1].setx(e);
    cout<<"Podaj wspolrzedna y prawego dolnego naroznika: ";
    cin>>e;
    w[1].sety(e);
    cout<<"Podaj kolor scian: ";
    cin>>n;
    color=n;
}

