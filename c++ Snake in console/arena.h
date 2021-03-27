#include <iostream>
#include "fruct.h"
#include "sarpe.h"
#include <string>

using namespace std;
class arena
{
    public: int inaltime ;
            int latime;
            fruct fr;
            sarpe sar;
            int scor;
     public: arena(int inaltim,int latim,const fruct& f, const sarpe& sarp)
                {   sar=sarp;
                    fr=f;
                    inaltime=inaltim;
                    latime=latim;
                    scor=0;
                }
            friend ostream& operator<<(ostream& consola, const arena& are)
            {
                for(int i=1;i<=are.inaltime;i++)
                    {for(int j=1;j<=are.latime;j++)
                       {    int contor=0;
                           if(i==1||i==are.inaltime||j==1||j==are.latime)
                        {consola<<"#";
                         contor =1;   }
                         if(i==are.fr.y && j==are.fr.x)
                            {consola<<are.fr.c;
                            contor =1;}
                            for(int z=0;z<are.sar.lungime_afisata;z++)
                                if(are.sar.s[z].x==i && are.sar.s[z].y==j)
                            {consola<<are.sar.s[z].c;
                             contor =1;}
                             if(contor==0)
                                consola<<" ";
                        }
                        consola<<endl;
                        //consola<<"fruct.x "<< are.fr.x<<" fruct.y "<<are.fr.y;

                        }
                        consola<<"Pauza    (p)  Scor: "<<are.scor;
                        //consola<<"\n inaltime "<<are.inaltime<<" latime "<<are.latime;
                       // consola<<"\n cap.x "<<are.sar.s[0].x<<" cap.y "<<are.sar.s[0].y;
                        //consola<<"fruct.x "<< are.fr.x<<" fruct.y "<<are.fr.y<<endl;
                       // consola<<"cap.x "<<are.sar.s[0].x<<"cap.y "<<are.sar.s[0].y;

            }
            void muta()
            {
                if (sar.lungime_afisata>1){


                for (int i=sar.lungime-1;i>1;i--)
                {sar.s[i].x=sar.s[i-1].x;
                sar.s[i].y=sar.s[i-1].y;
                }
                sar.s[1].x=sar.x_trecut;
                sar.s[1].y=sar.y_trecut;
                }
            }
            void set_sarpe(const sarpe& a)
            {
                sar=a;

            }
            stanga()
            {
                sar.x_trecut=sar.s[0].x;
                sar.y_trecut=sar.s[0].y;
                sar.s[0].y--;
                muta();
            }
            dreapta()
            {
                 sar.x_trecut=sar.s[0].x;
                sar.y_trecut=sar.s[0].y;
                sar.s[0].y++;
                muta();
            }
            jos()
            {    sar.x_trecut=sar.s[0].x;
                sar.y_trecut=sar.s[0].y;
                sar.s[0].x++;
                muta();
            }
            sus()
            {    sar.x_trecut=sar.s[0].x;
                sar.y_trecut=sar.s[0].y;
                sar.s[0].x--;
                muta();
            }
            bool mancat()
            {

                if(fr.y==sar.s[0].x && fr.x==sar.s[0].y)
                    {   scor++;
                        return true;

                }else return false;
            }
             spown_fruct()
            {
                while(1)
                {fr.x= rand() %latime;
                fr.y= rand() % inaltime;
                int c=0;
                if (fr.x==1 || fr.x==0 || fr.y==0 || fr.y==1 )
                    c=1;
                for(int i=0;i<sar.lungime_afisata;i++)
                    if(fr.x==sar.s[i].x && fr.y== sar.s[i].y)
                    c=1;
                    if(c==0)
                        break;


                }


            }
            void lungeste_sarpe()
            {
                sar.lungime_afisata++;


            }
            bool pierdut()
            {
                if(sar.s[0].x==1 || sar.s[0].x==inaltime || sar.s[0].y==1 || sar.s[0].y==latime)
                    return true;
                for(int i=1;i<sar.lungime_afisata;i++)
                    if(sar.s[0].x==sar.s[i].x && sar.s[0].y==sar.s[i].y)
                    return true;
                return false;
            }
            int sco()
            {
                return scor;
            }
};
