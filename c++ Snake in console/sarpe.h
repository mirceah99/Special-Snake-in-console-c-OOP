#include"buc.h"
class sarpe
{
    public: buc  s[200];
            int lungime;
            int lungime_afisata;
            int x_trecut;
            int y_trecut;



    public: sarpe ( )
            {
                lungime =0;
                lungime_afisata=1;
            }
            adauga( const char& caracter)
            {
                s[lungime].c=caracter;
                s[lungime].x=0;
                s[lungime].y=0;
                lungime++;

            }
            set_cap(int x ,int y )
            {
                s[0].x=x;
                s[0].y=y;
            }
            sarpe& operator=(const sarpe& x)
            {
                lungime=x.lungime;
                lungime_afisata=x.lungime_afisata;
                for(int i=0;i<lungime;i++)
                    {s[i].c=x.s[i].c;
                    s[i].x=x.s[i].x;
                    s[i].y=x.s[i].y;}
                    return *this;

            }


};
