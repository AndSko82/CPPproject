#include<iostream>
#include"room.h"
#include"objects.h"
#include<vector>
#include<windows.h>
using namespace std;
#define MAXROOMS 10
#define MAXOBJECTS 50
vector<Room> rvec;
vector<Room>::iterator it2;
vector<Obiekt*> obj;
vector<Obiekt*>::iterator it;
int a,e;
int calculate()
{
    int i,suma=0;
    for(i=0; i<obj.size(); i++)
        suma+=obj[i]->cena;
    return suma;
}
void addroom()
{
    string colr;
    if (rvec.size()<MAXROOMS)
    {
        rvec.push_back(Room());
        rvec[rvec.size()-1].load();
        cout<<"Utworzono pokoj nr "<<rvec.size()<<endl;
    }
    else cout<<"Nie mozna dodac pokoju. Maksymalna ilosc wynosi: "<<MAXROOMS<<endl;
}
void delroom()
{
    int i;
    if (rvec.empty()) cout<<"Brak pokoji do usuniecia !";
    else
    {
        if (rvec.size()==1)
        {
            rvec.erase(rvec.begin());
            for(i=0; i<obj.size(); i++)
                if (obj[i]->getnumb()==1)
                {
                    obj.erase(obj.begin()+i);
                    i--;
                }
            for(i=0; i<obj.size(); i++)
                obj[i]->setnumb(obj[i]->getnumb()-1);
            cout<<endl;
            cout<<"Usunieto pokoj o nr 1 wraz z wszystkimi obiektami."<<endl;
        }
        else
        {
            cout<<"Podaj nr pokoju:(1-"<<rvec.size()<<")";
            do
            {
                cin>>a;
                if (a<1||a>rvec.size()) cout<<"Pokoj o takim numerze nie istnieje!"<<endl;
            }
            while(a<1||a>rvec.size());
            rvec.erase(rvec.begin()+a-1);
            for(i=0; i<obj.size(); i++)
                if (obj[i]->getnumb()==a)
                {
                    obj.erase(obj.begin()+i);
                    i--;
                }
            for(i=0; i<obj.size(); i++)
                if (obj[i]->getnumb()>a) obj[i]->setnumb(obj[i]->getnumb()-1);
            cout<<endl;
            cout<<"Usunieto pokoj o nr "<<a<<" wraz z wszystkimi obiektami."<<endl;
        }
    }
}
void modify()
{
    if (rvec.empty()) cout<<"Brak pokoji do modyfikacji."<<endl;
    else
    {
        if (rvec.size()==1) rvec[0].load();
        else
        {
            cout<<"Podaj nr pokoju:(1-"<<rvec.size()<<") ";
            do
            {
                cin>>a;
                if (a<1||a>rvec.size()) cout<<"Pokoj o takim numerze nie istnieje!"<<endl;
            }
            while(a<1||a>rvec.size());
            cout<<"Aktualne parametry pokoju: "<<endl;
            cout<<endl;
            rvec[a-1].show();
            rvec[a-1].load();
            cout<<"Zmodyfikowano pokoj o nr "<<a<<endl;
        }
    }
}
void display()
{
    int i=1;
    system("cls");
    if (rvec.empty()) cout<<"Brak pokoji do wyswietlenia."<<endl;
    else
    {
        for(it2=rvec.begin(); it2!=rvec.end(); ++it2)
        {
            cout<<"Pokoj nr: "<<i<<endl;
            it2->show();
            i++;
        }
    }
}
void addobj()
{
    system("cls");
    if (rvec.empty()) cout<<"Aby dodac obiekt najpierw nalezy stworzyc pokoj!"<<endl;
    else if (obj.size()<MAXOBJECTS)
    {
        cout<<"Wybierz typ obiektu:"<<endl;
        cout<<"1. Komputer"<<endl;
        cout<<"2. Szafa"<<endl;
        cout<<"3. Stol"<<endl;
        cout<<"4. Lozko"<<endl;
        cout<<"5. Telewizor"<<endl;
        cout<<"6. Lodowka"<<endl;
        cout<<"7. Lampa"<<endl;
        cout<<"8. Biurko"<<endl;
        do
        {
            cin>>a;
            if (a<1||a>8) cout<<"Prosze wybrac wlasciwy numer (1-8)."<<endl;
        }
        while(a<1||a>8);
        switch(a)
        {
        case 1:
            obj.push_back(new Computer);
            obj[obj.size()-1]->setn("Komputer");
            break;
        case 2:
            obj.push_back(new Ward);
            obj[obj.size()-1]->setn("Szafa");
            break;
        case 3:
            obj.push_back(new Board);
            obj[obj.size()-1]->setn("Stol");
            break;
        case 4:
            obj.push_back(new Bed);
            obj[obj.size()-1]->setn("Lozko");
            break;
        case 5:
            obj.push_back(new TV);
            obj[obj.size()-1]->setn("Telewizor");
            break;
        case 6:
            obj.push_back(new Fridge);
            obj[obj.size()-1]->setn("Lodowka");
            break;
        case 7:
            obj.push_back(new Lamp);
            obj[obj.size()-1]->setn("Lampa");
            break;
        case 8:
            obj.push_back(new Desk);
            obj[obj.size()-1]->setn("Biurko");
            break;
        }
        if (rvec.size()==1) obj[obj.size()-1]->setnumb(1);
        else
        {
            cout<<"Podaj numer pokoju: (1-"<<rvec.size()<<"): ";
            do
            {
                cin>>e;
                if (e<1||e>rvec.size()) cout<<"Pokoj o takim numerze nie istnieje."<<endl;
            }
            while(e<1||e>rvec.size());
            obj[obj.size()-1]->setnumb(e);
        }
        cout<<"Podaj wspolrzedna x("<<rvec[obj[obj.size()-1]->getnumb()-1].getx1()<<" - "<<rvec[obj[obj.size()-1]->getnumb()-1].getx2()<<" ): ";
        cin>>e;
        obj[obj.size()-1]->setx(e);
        cout<<"Podaj wspolrzedna y("<<rvec[obj[obj.size()-1]->getnumb()-1].gety1()<<" - "<<rvec[obj[obj.size()-1]->getnumb()-1].gety2()<<" ): ";
        cin>>e;
        obj[obj.size()-1]->sety(e);
        obj[obj.size()-1]->load();
        cout<<"Podaj cene(zl) : ";
        cin>>e;
        obj[obj.size()-1]->sprice(e);
        cout<<endl;
        cout<<"Utworzono typ obiektu: "<<obj[obj.size()-1]->getn()<<endl;
    }
    else cout<<"Nie mozna utworzyc obiektu. Maksymalna ilosc wynosi: "<<MAXOBJECTS<<endl;
}
void objdisp()
{
    system("cls");
    cout<<"Liczba pokoji: "<<rvec.size()<<endl;
    cout<<endl;
    int i;
    if (obj.empty()) cout<<"Brak obiektow do wyswietlenia. "<<endl;
    else if (obj.size()==1)
    {
        cout<<1<<"  ";
        obj[0]->show();
    }
    else
        for(i=0; i<obj.size(); i++)
        {
            cout<<i+1<<"  ";
            obj[i]->show();
            cout<<endl;
            cout<<endl;
        }
    cout<<"Laczny koszt wyposazenia mieszkania wynosi: "<<calculate()<<" zl."<<endl;
}
void objmodify()
{
    system("cls");
    if (obj.empty()) cout<<"Brak obiektow do zmodyfikowania."<<endl;
    else if (obj.size()==1)
    {
        cout<<"Typ obiektu: "<<obj[0]->getn()<<endl;
        obj[0]->load();
    }
    else
    {
        cout<<"Podaj nr obiektu( 1 - "<<obj.size()<<" ): ";
        do
        {
            cin>>a;
            if(a<1||a>obj.size()) cout<<"Obiekt o takim numerze nie istnieje."<<endl;
        }
        while(a<1||a>obj.size());
        cout<<"Typ obiektu: "<<obj[a-1]->getn()<<endl;
        cout<<"Podaj wspolrzedna x("<<rvec[obj[obj.size()-1]->getnumb()-1].getx1()<<" - "<<rvec[obj[obj.size()-1]->getnumb()-1].getx2()<<" ): ";
        cin>>e;
        obj[a-1]->setx(e);
        cout<<"Podaj wspolrzedna y("<<rvec[obj[obj.size()-1]->getnumb()-1].gety1()<<" - "<<rvec[obj[obj.size()-1]->getnumb()-1].gety2()<<" ): ";
        cin>>e;
        obj[a-1]->sety(e);
        obj[a-1]->load();
        cout<<"Podaj cene(zl) : ";
        cin>>e;
        obj[a-1]->sprice(e);
    }
}
void objdel()
{
    system("cls");
    if (obj.empty()) cout<<"Brak obiektow do usuniecia."<<endl;
    else if (obj.size()==1)
    {
        obj.erase(obj.begin());
    }
    else
    {
        cout<<"Podaj nr obiektu( 1 - "<<obj.size()<<" ): ";
        do
        {
            cin>>a;
            if(a<1||a>obj.size()) cout<<"Obiekt o takim numerze nie istnieje."<<endl;
        }
        while(a<1||a>obj.size());
        obj.erase(obj.begin()+a-1);
        cout<<"Usunieto obiekt nr: "<<a<<endl;
    }
}
void menu()
{
    char znak;
    while(znak!='0')
    {
        //system("cls");
        cout<<endl;
        cout<<"======SYMULATOR PROJEKTOWANIA WNETRZ======"<<endl;
        cout<<endl;
        cout<<"Menu glowne: "<<endl;
        cout<<endl;
        cout<<"1. Dodaj pokoj."<<endl;
        cout<<"2. Usun pokoj."<<endl;
        cout<<"3. Modyfikuj pokoj."<<endl;
        cout<<"4. Wyswietl pokoje."<<endl;
        cout<<"5. Dodaj obiekt."<<endl;
        cout<<"6. Usun obiekt."<<endl;
        cout<<"7. Modyfikuj obiekt."<<endl;
        cout<<"8. Lista obiektow."<<endl;
        cout<<"0. Koniec."<<endl;
        cin>>znak;
        switch(znak)
        {
        case '1':
            addroom();
            break;
        case '2':
            delroom();
            break;
        case '3':
            modify();
            break;
        case '4':
            display();
            break;
        case '5':
            addobj();
            break;
        case '6':
            objdel();
            break;
        case '7':
            objmodify();
            break;
        case '8':
            objdisp();
            break;
        }
    }
}
int main()
{
    rvec.push_back(Room(50,50,200,200,"niebieski"));
    rvec.push_back(Room(250,50,400,200,"czerwony"));
    rvec.push_back(Room(100,200,300,400,"zielony"));
    menu();
    for(it=obj.begin(); it!=obj.end(); it++)
        delete *it;
    return 0;
}
