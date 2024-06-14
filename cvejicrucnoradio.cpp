#include<iostream>
using namespace std;
class Film{
private:
string naziv, reziser, uloga;
double godina, budzet, *prihod;
static int n,m;
public:
Film(){
naziv = "";
reziser = "";
uloga = "";
godina = 0;
budzet = 0;
prihod = new double[m];
for(int i; i < m; i++){
prihod[i] = 0;
n++;
}
}
Film(string nazivv, string reziserr, string ulogaa, double godinaa, double budzett, double* prihodd){
naziv = nazivv;
reziser = reziserr;
uloga = ulogaa;
godina = godinaa;
budzet = budzett;
for(int i = 0; i < m; i++){
prihod[i] = prihodd[i];
n++;
}
}
~Film(){
delete[] prihod;
n--;
}
static void setN(int nn){n = nn;}
static void setM(int mm){m = mm;}
static int getN(){return n;}
static int getM(){return m;}

void setNaziv(string nazivv){naziv = nazivv;}
void setReziser(string reziserr){reziser = reziserr;}
void setUloga(string ulogaa){uloga = ulogaa;}
void setGodina(double godinaa){godina = godinaa;}
void setBudzet(double budzett){budzet = budzett;}
void setPrihod(double* prihodd){
for(int i = 0; i < m; i++){
prihod[i] = prihodd[i];
}
}
string getNaziv(){return naziv;}
string getReziser(){return reziser;}
string getUloga(){return uloga;}
double getGodina(){return godina;}
double getBudzet(){return budzet;}
double* getPrihod(){return prihod;}
void unos(){
cout<<"Unesite naziv filma: "; cin>>naziv;
cout<<"Unesite rezisera: "; cin>>reziser;
cout<<"Unesite uloge: "; cin>>uloga;
cout<<"Unesite godinu: "; cin>>godina;
cout<<"Unesite budzet: "; cin>>budzet;
cout<<"Unesite budzete po mesecima: ";
for(int i = 0; i < m; i++){
cout<<"Mesec "<<i+1<<": ";cin>>prihod[i];
}

}
void ispis(){
cout<<"Naziv filma: "<<naziv;
cout<<"Reziser: "<<reziser;
cout<<"Uloga: "<<uloga;
cout<<"Godina: "<<godina;
cout<<"Budzet: "<<budzet;
cout<<"Budzeti po mesecima: ";
for(int i = 0; i < m; i++){
cout<<"Mesec "<<i+1<<": "<<prihod[i];
}
cout<<"\n";
}
};
int Film::n=0;
int Film::m=4;
main(){

int n;
cout<<"Unesite broj filmova: "; cin>>n;
Film *niz = new Film[n];
for(int i = 0; i < n; i++){
niz[i].unos();
}
for(int i = 0; i < n; i++){
niz[i].ispis();
}
//odredjivanje najveceg budzeta od svih filmova
Film max = niz[0];
for(int i = 0; i < n; i++){
if(niz[i].getBudzet() > max.getBudzet()){
max = niz[i];
}
}
cout<<"Film sa najvecim budzetom je: \n";
max.ispis();

Film *niz2 = new Film[n];
string glumac;
cout<<"Unesite datog glumca: ";cin>>glumac;
int j = 0;
for(int i = 0; i < n; i++){
if(niz[i].getUloga() == glumac){
niz2[j] = niz[i];
j++;
}
}
cout<<"Filmovi u kojima datu ulogu igra "<<glumac<<"su : \n";
if(j > 0){
for(int i = 0; i < n; i++){
cout<<niz2[i].getNaziv();
cout<<"\n";
}
}
else{
cout<<"Nema filmova sa datim glumcem.";
}

delete []niz;
delete []niz2;
}
