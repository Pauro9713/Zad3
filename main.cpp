#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

typedef pair<double, double> Probka;    //
typedef vector <Probka> Dane;
Dane wczytaj(string nazwa_pliku)
{
Dane tablica;
ifstream Sygnal(nazwa_pliku);
string linia;
while (getline(Sygnal, linia))
    {
    stringstream ss(linia);
    double x1, x2;
    ss >> x1;
    ss.ignore();
    ss >> x2;
    Probka p1(x1, x2);
    tablica.push_back (p1);
    }
    Sygnal.close();
    return tablica;
}

void wypisz (Dane dane)
{
    for(int i=0; i<dane.size();i++)
    {
        cout<< dane[i].first<<"\t";
        cout<< dane [i].second<<endl;
    }
}

void zapisz (string n_plik, Dane odczyt)
{
    ofstream plik(n_plik);
    for(int i=0; i<odczyt.size();i++)
    {
            plik<<odczyt[i].first<<"\t";
            plik<<cout<<odczyt[i].second<<endl;
    }
    plik.close ();
}

double Srednia (Dane dane) {

double srednia = 0.0;

for (int i = 0; i < dane.size(); i++)
    {
        srednia = dane[i].first;
    }
if (dane.size() > 0)
    {
        srednia = srednia / dane.size();
    }
return srednia;

}

double Minimum(Dane dane)
{
    double minimum = 2;
    for ( int i=0; i<dane.size(); i++)
    {
        if (dane[i].second < minimum)
        minimum = dane[i].second;
    }
return minimum;
}

double Maksimum(Dane dane)
{
    double maksimum = -2;
    for ( int i=0; i<dane.size(); i++)
    {
        if (dane[i].second > maksimum)
        maksimum = dane[i].second;
    }
return maksimum;
}

double Dlugosc (Dane dane)
{
    double dlugosc=0;
    double minimum = 2;
    for ( int i=0; i<dane.size(); i++)
    {
        if (dane[i].second < minimum)
        minimum = dane[i].second;
    }

    double maksimum = -2;
    for ( int i=0; i<dane.size(); i++)
    {
        if (dane[i].second > maksimum)
        maksimum = dane[i].second;
    }
dlugosc = maksimum-minimum;
return dlugosc;
}

double Calka(Dane dane)
{
    double calka = 0, dt = 0, dpole = 0;
    for (int i=1; i < dane.size()-1; i++)

    {
        dt = dane[i+1].first - dane[i].first;
        dpole = (dane[i].second + dane[i+1].second) * dt / 2;
        calka = calka + dpole;
    }
return calka;
}


int main(int argc, char* argv[])
{
if (argc != 2)
    {
        throw runtime_error("sygnal.csv");
    }
    string nazwa_pliku = argv[1];
    cout<<"Odczytuje plik: "<< nazwa_pliku <<endl;
    Dane wx=wczytaj(nazwa_pliku);
    wypisz(wx);
    zapisz ("C:\\Users\\Admin\\Desktop\\Projekty c++\\Nowy folder\\Prubki\\out.csv", wx);

cout<<endl<<"Dlugosc: "<<Dlugosc(wx);

cout<<endl<<"Srednia: "<<Srednia(wx);

cout<<endl<<"Minimum: "<<Minimum(wx);

cout<<endl<<"Maksimum: "<<Maksimum(wx);

cout<<endl<<"Calka: "<<Calka(wx);


    return 0;
}
