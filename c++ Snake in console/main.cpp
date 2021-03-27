#include <iostream>
#include"arena.h"
#include <windows.h>
#include<conio.h>

using namespace std;
fruct f;
sarpe s;
arena a(15,30,f,s);
int viteza=120;
enum directie
{
    stop,
    stanga,
    dreapta,
    sus,
    jos,
    pauza,

};
directie dir;
 int la_intamplare(int margine)
 {
     int x;
     x=rand() % margine;
     while (x==0 || x==1)
      x=rand() % margine;
        return x;
 }


bool ai_pierdut()
{
return a.pierdut();

}
void inceput()
{
    string nume = "@@scor 40= un baston@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
    dir=stop;
    for( int i=0;i<nume.length();i++)
   s.adauga(nume[i]);
   s.set_cap(la_intamplare(a.inaltime),la_intamplare(a.latime));
    a.set_sarpe( s);

}
void deseneaza()
{
system("cls");
cout<<a;

}
void apasa()
{
   if(_kbhit())
        switch(getch())
   {
   case 'w': dir=sus; break;
   case 'a': dir=stanga; break;
   case 's': dir=jos; break;
   case 'd': dir=dreapta; break;
   case 'p': dir=pauza; break;

   }

}

void logic()
{
    switch(dir)
    {
    case stanga: a.stanga(); break;
    case dreapta: a.dreapta(); break;
    case sus: a.sus();break;
    case jos: a.jos();break;

    }
    if(a.mancat())
        {   cout << '\a';
            a.lungeste_sarpe();
            a.spown_fruct();
            viteza= viteza-2;
            }
}
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
int main()
{
   hidecursor();
    inceput();
cout <<"ATENTIE LA SCOR 40 AI PRIMIT UN BASTON!!!(nu ai voie sa folosesti pauza de mai mult de 2 ori) \n comenzi a s d w \n jocul incepe in 15 secunde Bafta!";
    Sleep(17000);
    while(!ai_pierdut())
   {

    apasa();
    logic();
    deseneaza();
    Sleep(viteza);
    if(a.sco()==39)
       return 0;}

    system("cls");
    cout<<"Scor final: "<< a.scor<<endl;
    cout<<"Felicitari, acum iti ramne doar sa ajuti developerul sa mai faca jocuri, asa ca doneaza mi bani!!";



    return 0;
}
