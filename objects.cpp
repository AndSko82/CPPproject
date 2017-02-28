#include<iostream>
#include<windows.h>
#include"objects.h"
using namespace std;
Obiekt::Obiekt():x(0),y(0),roomnumb(0),cena(0),name("") {}
Obiekt::Obiekt(int a,int b,string n):x(a),y(b),roomnumb(0),cena(0),name(n) {}
Obiekt::~Obiekt() {};
int Obiekt::getx()
{
    return x;
}
int Obiekt::gety()
{
    return y;
}
int Obiekt::gprice()
{
    return cena;
}
int Obiekt::getnumb()
{
    return roomnumb;
}
string Obiekt::getn()
{
    return name;
}
void Obiekt::sprice(int a)
{
    cena=a;
}
void Obiekt::setnumb(int a)
{
    roomnumb=a;
}
void Obiekt::setx(int a)
{
    x=a;
}
void Obiekt::sety(int b)
{
    y=b;
}
void Obiekt::setn(string n)
{
    name=n;
}

Gcard::Gcard():memory(0),nazwa("") {}
int Gcard::getmem()
{
    return memory;
}
string Gcard::getn()
{
    return nazwa;
}
void Gcard::setmem(int a)
{
    memory=a;
}
void Gcard::setn(string n)
{
    nazwa=n;
}

Drive::Drive() :cap(0),speed(0) {};
int Drive::getcap()
{
    return cap;
}
int Drive::getsp()
{
    return speed;
}
void Drive::setcap(int a)
{
    cap=a;
}
void Drive::setsp(int b)
{
    speed=b;
}

Monitor::Monitor():inch(0),name("") {};
int Monitor::gets()
{
    return inch;
}
string Monitor::getn()
{
    return name;
}
void Monitor::sets(int a)
{
    inch=a;
}
void Monitor::setn(string n)
{
    name=n;
}

Computer::Computer():cpu(0),ram(0) {};
void Computer::show()
{
    cout<<"Obiekt: "<<name<<endl;
    cout<<"Parametry komputera:"<<endl;
    cout<<endl;
    cout<<"Numer pokoju: "<<roomnumb<<"      Polozenie  x: "<<x<<" y: "<<y<<endl;
    cout<<"Predkosc procesora: "<<cpu<<" Ghz      Ilosc pamieci RAM: "<<ram<<" GB"<<endl;
    cout<<"Nazwa karty graficznej: "<<g.getn()<<"      Pamiec karty: "<<g.getmem()<<"      MB."<<endl;
    cout<<"Pojemnosc dysku: "<<d.getcap()<<" TB       Ilosc obr/min: "<<d.getsp()<<endl;
    cout<<"Nazwa monitora: "<<m.getn()<<"       Wielkosc ekranu: "<<m.gets()<<" cali."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Cena zestawu komputerowego: "<<cena<<" zl."<<endl;
}
void Computer::load()
{
    int e;
    string n;
    double c;
    cout<<"Podaj nazwe karty graficznej: ";
    cin>>n;
    g.setn(n);
    cout<<"Podaj ilosc pamieci(MB): ";
    cin>>e;
    g.setmem(e);
    cout<<"Podaj pojemnosc dysku(TB): ";
    cin>>e;
    d.setcap(e);
    cout<<"Podaj predkosc dysku(obr/min): ";
    cin>>e;
    d.setsp(e);
    cout<<"Podaj nazwe monitora: ";
    cin>>n;
    m.setn(n);
    cout<<"Podaj wielkosc ekranu monitora(cale): ";
    cin>>e;
    m.sets(e);
    cout<<"Podaj predkosc procesora(Ghz): ";
    cin>>c;
    cpu=c;
    cout<<"Podaj ilosc pamieci ram komputera(GB): ";
    cin>>e;
    ram=e;
}

Ward::Ward():wys(0),waga(0),color("") {};
void Ward::show()
{
    cout<<"Obiekt: "<<name<<endl;
    cout<<"Numer pokoju: "<<roomnumb<<"      Polozenie  x: "<<x<<" y: "<<y<<endl;
    cout<<"Wysokosc: "<<wys<<"    Waga: "<<waga<<"     Kolor: "<<color<<"    Cena: "<<cena<<" zl."<<endl;
}
void Ward::load()
{
    cout<<"Podaj wysokosc (cm): ";
    cin>>wys;
    cout<<"Podaj wage (kg): ";
    cin>>waga;
    cout<<"Podaj kolor: ";
    cin>>color;
}

Board::Board():sred(0),color("") {};
void Board::show()
{
    cout<<"Obiekt: "<<name<<endl;
    cout<<"Numer pokoju: "<<roomnumb<<"      Polozenie  x: "<<x<<" y: "<<y<<endl;
    cout<<"Srednica: "<<sred<<"    Kolor: "<<color<<"     Cena: "<<cena<<" zl."<<endl;
}
void Board::load()
{
    cout<<"Podaj srednice (cm): ";
    cin>>sred;
    cout<<"Podaj kolor: ";
    cin>>color;
}

Bed::Bed():len(0),wid(0) {};
void Bed::show()
{
    cout<<"Obiekt: "<<name<<endl;
    cout<<"Numer pokoju: "<<roomnumb<<"      Polozenie  x: "<<x<<" y: "<<y<<endl;
    cout<<"Dlugosc: "<<len<<"    Szerokosc: "<<wid<<"     Cena: "<<cena<<" zl."<<endl;
}
void Bed::load()
{
    cout<<"Podaj dlugosc (cm): ";
    cin>>len;
    cout<<"Podaj szerokosc (cm): ";
    cin>>wid;
}

TV::TV():tvname(""),inch(0) {};
void TV::show()
{
    cout<<"Obiekt: "<<name<<endl;
    cout<<"Numer pokoju: "<<roomnumb<<"      Polozenie  x: "<<x<<" y: "<<y<<endl;
    cout<<"Nazwa: "<<tvname<<"    Wielkosc ekranu: "<<inch<<"     Cena: "<<cena<<" zl."<<endl;
}
void TV::load()
{
    cout<<"Podaj nazwe: ";
    cin>>tvname;
    cout<<"Podaj wielkosc ekranu (cale): ";
    cin>>inch;
}

Fridge::Fridge():wys(0),waga(0),cap(0) {};
void Fridge::show()
{
    cout<<"Obiekt: "<<name<<endl;
    cout<<"Numer pokoju: "<<roomnumb<<"      Polozenie  x: "<<x<<" y: "<<y<<endl;
    cout<<"Wysokosc: "<<wys<<"   Waga: "<<waga<<"   Pojemnosc: "<<cap<<"     Cena: "<<cena<<" zl."<<endl;
}
void Fridge::load()
{
    cout<<"Podaj wysokosc (cm): ";
    cin>>wys;
    cout<<"Podaj wage (kg): ";
    cin>>waga;
    cout<<"Podaj pojemnosc (litr): ";
    cin>>cap;
}

Lamp::Lamp():wys(0),color("") {};
void Lamp::show()
{
    cout<<"Obiekt: "<<name<<endl;
    cout<<"Numer pokoju: "<<roomnumb<<"      Polozenie  x: "<<x<<" y: "<<y<<endl;
    cout<<"Wysokosc: "<<wys<<"   Kolor: "<<color<<"     Cena: "<<cena<<" zl."<<endl;
}
void Lamp::load()
{
    cout<<"Podaj wysokosc (cm): ";
    cin>>wys;
    cout<<"Podaj kolor: ";
    cin>>color;
}

Desk::Desk():wid(0),color("") {};
void Desk::show()
{
    cout<<"Obiekt: "<<name<<endl;
    cout<<"Numer pokoju: "<<roomnumb<<"      Polozenie  x: "<<x<<" y: "<<y<<endl;
    cout<<"Szerokosc: "<<wid<<"    Kolor: "<<color<<"     Cena: "<<cena<<" zl."<<endl;
}
void Desk::load()
{
    cout<<"Podaj szerokosc (cm): ";
    cin>>wid;
    cout<<"Podaj kolor: ";
    cin>>color;
}
