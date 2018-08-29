
#include <iostream>
#include <conio.h>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    float juzZgromadzonaKwota;
    float pozadanaMiesiecznaEmerytura;
    float oprocentowanieLokaty;
    float podatek = 0.19;

    int wiekObecny;
    int wiekPrzejsciaNaEmeryture;
    char wybor,czyOdZera;

    cout << "Program oblicza ile powinienes odkladac miesiecznie aby zaoszczedzic na dodatek do emerytury." << endl;
    cout << "Dodatek ten bedzie  wyplacany wylacznie z odsetek od zgromadzonego kapitalu przez lata pozostale do przejscia na emeryture." << endl;
    cout << "Odpowiedz na pytania potrzebne do obliczen. " << endl;
    do{
        cout << "Czy masz juz zgromadzona jakas kwote,ktora chcesz doplacic do pierwszej wplaty <t/n>: " << endl;
        czyOdZera = getch();
        while ((czyOdZera != 't')&&(czyOdZera != 'n')){
           cout << "Wcisnij klawisz t lub klawisz n" << endl;
           czyOdZera = getch();
        }
        if (czyOdZera == 't'){
            cout << "Podaj ta kwote: " << endl;

            cin >> juzZgromadzonaKwota;
        }
        else if (czyOdZera=='n'){
          juzZgromadzonaKwota=0;
        }

        cout << "Ile masz lat: ";
        cin >> wiekObecny;

        cout << "W jakim wieku chcesz przejsc na emeryture: ";
        cin >> wiekPrzejsciaNaEmeryture;

        cout << "W jakiej wysokosci chcialbys miec dodatek do emerytury: ";
        cin >> pozadanaMiesiecznaEmerytura;

        cout << "Podaj oprocentowanie lokaty w procentach: ";
        cin >> oprocentowanieLokaty;

        int lataPracy = wiekPrzejsciaNaEmeryture - wiekObecny;
        oprocentowanieLokaty = oprocentowanieLokaty/100;
        float odsetkiWSkaliRoku = pozadanaMiesiecznaEmerytura*12/(1-podatek);
        float kwotaPotrzebnaDoOtrzymywaniaOkreslonejMiesiecznejEmerytury = odsetkiWSkaliRoku/oprocentowanieLokaty;
        // odsetki beda wyplacane na emeryturze z lokaty co miesiac na biezaco
        float liczbaPotegowana = (1+(oprocentowanieLokaty/12)*(1-podatek));
        float czynnikZLicznika = kwotaPotrzebnaDoOtrzymywaniaOkreslonejMiesiecznejEmerytury - juzZgromadzonaKwota*(pow(liczbaPotegowana,lataPracy*12));
        float licznik = czynnikZLicznika *(oprocentowanieLokaty/12)*(1-podatek);

        float mianownik = (pow(liczbaPotegowana,lataPracy*12) -1)*(1+oprocentowanieLokaty/12*(1-podatek));
        float miesiecznaSkladka=licznik/mianownik;
        cout << endl;
        cout << "Aby po " << lataPracy<< " latach pracy,  z odkladania na lokacie oprocentowanej na " << (oprocentowanieLokaty*100) << " procent "<<endl;
        cout << "miec dodatek do emerytury w wysokosci " << pozadanaMiesiecznaEmerytura << " zl wyplacanych wylacznie z odsetek " << endl;

        cout << fixed << setprecision(2);
        cout <<"nalezy miesiecznie odkladac " << miesiecznaSkladka << " zl."<<endl;
        cout << "To pozwoli ci uzbierac kwote w wysokosci " << kwotaPotrzebnaDoOtrzymywaniaOkreslonejMiesiecznejEmerytury << " zl."<<endl;
        cout << endl;
        cout << "Czy wykonac obliczenia dla nowych danych? <t/n>"<<endl;
        wybor = getch();
        while ((wybor != 't')&&(wybor != 'n')){
           cout << "Wcisnij klawisz t lub klawisz n" << endl;
           wybor = getch();
        }
    }
    while(wybor == 't');

    return 0;
}

