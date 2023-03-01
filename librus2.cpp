#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

// gotoXY

using namespace std;

void gotoxy(int x, int y)
{
    COORD c;
    c.X=x-1;
    c.Y= y-1;
    SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}

class uczniowienau{
protected:
    char imie[20];
    char haslo[50];
    char nazwisko[50];
    char klasa[2];
    char przedmiot[20];
    float ocena;
    char data[10];
    int uczennauczyciel;
    char nadawca [70];
    char wiadomosc[2000];
public:
	void logownie();
    void czysc();
    void setImie (char *imi);
    void setNazwisko (char *naz);
    void setKlasa(char *litera);
    char* getImie();
    char* getHaslo();
    char* getNazwisko();
    char* getKlasa();
    char* getNadawca();
    char* getWiadomosc();
    char* getPrzedmiot();
    char* getData();
    int getUczenNauczyciel();
    float getOcena();
    void dodajO(char *imi, char *naz, char *prze, float oce, char *dat);
    void dodajUNa(char *imi, char *has, char *naz, char *kla, int un);
    void napiszWiadomosc(char *nad, char *imi, char *naz, char *wiad, char *dat);
    void zmienHas(char *has);
    void drukujOceny();
    void drukuj();
    void piszXY (int x, int y);
};

void uczniowienau::czysc()
{
    strcpy(imie, "");
    strcpy(nazwisko, "");
    strcpy(haslo, "");
    strcpy(klasa, "");
    strcpy(nadawca, "");
    strcpy(wiadomosc, "");
    strcpy(przedmiot, "");
    strcpy(data, "");
    uczennauczyciel = 0;
    ocena = 0;
}


void uczniowienau::dodajO(char *imi, char *naz, char *prze, float oce, char *dat)
{
   	strcpy(imie, imi);
   	strcpy(nazwisko, naz);
   	strcpy(przedmiot, prze);
   	strcpy(data, dat);
   	ocena = oce;
}
void uczniowienau::dodajUNa(char *imi, char *has, char *naz, char *kla, int un)
{
   	strcpy(imie, imi);
   	strcpy(haslo, has);
   	strcpy(nazwisko, naz);
   	strcpy(klasa, kla);
   	uczennauczyciel = un;

}
void uczniowienau::napiszWiadomosc(char *nad, char *imi, char *naz, char *wiad, char *dat)
{
   	strcpy(nadawca, nad);
   	strcpy(imie, imi);
   	strcpy(nazwisko, naz);
   	strcpy(wiadomosc, wiad);
   	strcpy(data, dat);
}
void uczniowienau::zmienHas(char *has)
{
	strcpy(haslo, has);
}

char* uczniowienau::getImie()
{
	return imie;
}

char* uczniowienau::getHaslo()
{
	return haslo;
}

char* uczniowienau::getNazwisko()
{
	return nazwisko;
}

char* uczniowienau::getKlasa()
{
	return klasa;
}

char* uczniowienau::getNadawca()
{
	return nadawca;
}

char* uczniowienau::getWiadomosc()
{
	return wiadomosc;
}

char* uczniowienau::getPrzedmiot()
{
	return przedmiot;
}

char* uczniowienau::getData()
{
	return data;
}

int uczniowienau::getUczenNauczyciel()
{
	return uczennauczyciel;
}

float uczniowienau::getOcena()
{
	return ocena;
}

void uczniowienau::drukujOceny()
{
	cout << "Cos drukne";
}
void uczniowienau::drukuj()
{
	cout << "Imie: " << imie << ", nazwisko: " << nazwisko << ", haslo: " << haslo << ", klasa: " << klasa;
	cout << ", przedmiot: " << przedmiot << ", ocena: " << ocena << ", UCZEN(1)/NAUCZYCIEL(2): " << uczennauczyciel;
	cout << ", wiadomosc: " << wiadomosc << ", nadawca: " << nadawca << ", data: " << data << endl << "-----------------------" << endl;
}


void uczniowienau::piszXY(int x, int y)
{
	system("CLS");
	cout << "\n\n\n\n\n";
    gotoxy(x,y + 5);
    cout << "Imie:                               	";
    gotoxy(x + 10,y +5);
    cout <<imie;

    gotoxy(x,y + 6);
    cout << "Nazwisko:                               	";
    gotoxy(x+10,y + 6);
    cout << nazwisko;

    gotoxy(x,y + 7);
    cout << "Haslo:                               	";
    gotoxy(x+10,y + 7);
    cout << haslo;

    gotoxy(x,y + 8);
    cout << "Klasa:                               ";
    gotoxy(x+10,y + 8);
    cout << klasa;

    gotoxy(x,y + 9);
    cout << "Przedmiot:                              ";
    gotoxy(x+10,y + 9);
    cout << przedmiot;

    gotoxy(x,y + 10);
    cout << "Ocena:                     ";
    gotoxy(x+10,y + 10);
    cout << ocena;

    gotoxy(x,y + 11);
    cout << "Data:                               	";
    gotoxy(x+10,y + 11);
    cout << data;

    gotoxy(x,y + 12);
    cout << "Uczen(1)/Nauczyciel(2):                               	";
    gotoxy(x+25,y + 12);
    cout << uczennauczyciel;
    
    gotoxy(x,y + 13);
    cout << "Nadawca wiadomosci:                               	";
    gotoxy(x+20,y + 13);
    cout << nadawca;
    
    gotoxy(x,y + 14);
    cout << "Tresc wiadomosci:                               	";
    gotoxy(x+20,y + 14);
    cout << wiadomosc;
    cout << "\n\n";
}

//      LIBRUS
class librus:public uczniowienau
{
protected:
    uczniowienau *tab;
    uczniowienau *found;
    int licznosc, licznoscFound, rozmiar, current, currentFound, i;
public:
    librus(int rozmiar);
    librus();
    int logowan(char *naz, char *has);
    void czysccalosc();
    void dodajUN(char *imi, char *has, char *naz, char *kla, int un);
    void usunUN(char *imi, char *naz, int kczyw);
    void dodajOcene(char *imi, char *naz, char *prze, float oce, char *dat);
    void drukujwszystko();
    void wyslijWiadomosc(char *nad,char *imi, char *naz, char *wiad, char *dat);
    void sprawdzWiadomosci(char *imi, char *naz);
    void wyszukajOceny(char *imi, char *naz);
    void zmienHaslo(char *log2, char *log, char *noweh);
    void saveFile();
    void readFile();
    void sortOceny();
    void sortNazwisko();
    void deleteCurrent();
    void next();
    void previous();
    void setCurrent(int index);
    void showCurrent (int x, int y);
    bool foundPrzedmiotUczen();

    ~librus();
};

librus::librus(int rozmiar) // konstruktor paramteryczny
{
    this->rozmiar=rozmiar;
    tab = new uczniowienau[rozmiar];
    found = new uczniowienau[rozmiar];
    for (i=0; i<rozmiar; i++)
        tab[i].czysc();
    licznosc=0;
    current=-1;

    licznoscFound=0;
    currentFound=-1;
}

/*librus::librus()  //przeciazony kontruktor bezparametryczny
{
    this->rozmiar=500;
    tab = new uczniowienau[rozmiar];
    for (i=0; i<500; i++)
        tab[i].czysc();
    licznosc=0;
    current=-1;
}*/

int librus::logowan(char *naz, char *has)
{
	for (int i=0; i < licznosc; i++)
	{
		if (strcmp(tab[i].getNazwisko(),naz) == 0)
		{
			if (strcmp(tab[i].getHaslo(),has) == 0)
				{
					return tab[i].getUczenNauczyciel();
				}
		}
	}
	return 0;
}

void librus::sprawdzWiadomosci(char *imi, char *naz)
{
	char *abc = "";
	int czywiadomosc = 0;
	for (int i=0; i < licznosc; i++)
	{
		if (strcmp(tab[i].getNazwisko(), naz) == 0)
		{
			if (strcmp(tab[i].getImie(), imi) == 0)
			{
				if (strcmp(tab[i].getWiadomosc(),abc) > 0)
				{
					czywiadomosc = 1;
					cout << "Wiadomosc od: " << tab[i].getNadawca();
					cout << endl << "Wyslana dnia: " << tab[i].getData();
					cout << endl << "Tresc wiadomosci: " << tab[i].getWiadomosc();
					cout << endl << endl << endl;
				}
			}
		}
	}
	if (czywiadomosc == 0)
		cout << "Brak wiadomosci." << endl;
}
void librus::zmienHaslo(char *log2, char *log, char *noweh)
{
	char *abc = "";
	for (int i=0; i < licznosc; i++)
	{
		if (strcmp(tab[i].getNazwisko(), log) == 0)
		{
			if (strcmp(tab[i].getImie(), log2) == 0)
			{
				if (strcmp(tab[i].getHaslo(),abc) > 0)
				{
					tab[i].zmienHas(noweh);
				}
			}
		}
	}
}

void librus::wyszukajOceny(char *imi, char *naz)
{
	char *abc = "";
	for (int i=0; i < licznosc; i++)
	{
		if (strcmp(tab[i].getNazwisko(), naz) == 0)
		{
			if (strcmp(tab[i].getImie(), imi) == 0)
			{
				if (!strcmp(tab[i].getWiadomosc(),abc) > 0)
				{
					if (!strcmp(tab[i].getHaslo(),abc) > 0)
					{
						cout << endl << "Ocena: " << tab[i].getOcena();
						cout << endl << "Przedmiot: " << tab[i].getPrzedmiot();
						cout << endl << "Data:" << tab[i].getData();
						cout << endl << endl << endl;
					}
				}
			}
		}
	}
}

void librus::czysccalosc()
{
    for (i=0; i<rozmiar; i++)
        tab[i].czysc();
    licznosc=0;
    current=-1;
}

void librus::dodajUN(char *imi, char *has, char *naz, char *kla, int un)
{
	if (licznosc <rozmiar)
    {
        tab[licznosc].dodajUNa(imi, has, naz, kla, un);
        licznosc++;
        current=licznosc-1;
    }
}

void librus::usunUN(char *imi, char *naz, int kczyw)
{
	int x = 0;
	char *abc = "";
	for (int i=0; i < licznosc; i++)
	{
		if (strcmp(tab[i].getNazwisko(),naz) == 0)
		{
			if (strcmp(tab[i].getImie(),imi) == 0)
				{
					if (strcmp(tab[i].getHaslo(),abc) > 0)
					{
						deleteCurrent();
						cout << endl << "Usunieto dane logowania." << endl;
					}
					if (kczyw == 2)
					{
						deleteCurrent();
						x = 1;
					}
				}
		}
	}
	if (x == 1)
		cout << endl << "Usunieto oceny ucznia." << endl;
}

void librus::dodajOcene(char *imi, char *naz, char *prze, float oce, char *dat)
{
	if (licznosc < rozmiar)
    {
        tab[licznosc].dodajO(imi, naz, prze, oce, dat);
        licznosc++;
        current=licznosc-1;
    }
}
void librus::drukujwszystko()
{
    for (i=0; i<licznosc; i++)
        tab[i].drukuj();
}

void librus::wyslijWiadomosc(char *nad, char *imi, char *naz, char *wiad, char *dat)
{
	if (licznosc < rozmiar)
    {
        tab[licznosc].napiszWiadomosc(nad, imi, naz, wiad, dat);
        licznosc++;
        current=licznosc-1;
    }
}

void librus::sortOceny()
{
    if(licznosc>1)
    {
        uczniowienau pom;
        for(int nr=1; nr<licznosc;nr++)
            for(i=0; i<licznosc-nr; i++)
                if(tab[i].getOcena()>tab[i+1].getOcena())
                {
                    pom=tab[i];
                    tab[i]=tab[i+1];
                    tab[i+1]=pom;
                }
    }
}

void librus::sortNazwisko()
{
    if(licznosc>1)
    {
        uczniowienau pom;
        for(int nr=1; nr<licznosc;nr++)
            for(i=0; i<licznosc-nr; i++)
                if(strcmp(tab[i].getNazwisko(),tab[i+1].getNazwisko())>0) //jak zwraca 0 to wtedy s¹ identyczne. Jezeli wieksze niz 0,
                //to znaczy ze jest wiekszy, starszy w slowniku, jak ujemne, to jest wczesniej w slowniku
                {
                    pom=tab[i];
                    tab[i]=tab[i+1];
                    tab[i+1]=pom;
                }
    }
}

void librus::deleteCurrent()
{
	if (licznosc >= 1)
    {
        for (i=current; i<licznosc - 1; i++)
            tab[i]=tab[i+1];
        if (current == licznosc-1)
            current--;
        licznosc--;
    }
}

void librus::setCurrent(int index)
{
	current = index;
}

void librus::next()
{
    if (current <licznosc-1)
        current++;
}

void librus::previous()
{
    if (current >0)
        current--;
}

void librus::showCurrent(int x, int y)
{
    if (current>=0 && current <licznosc)
        tab[current].piszXY(x,y);
}

void librus::saveFile()
{
    FILE *fp;
    fp=fopen("librus.dat", "wb");
    fwrite(&rozmiar, sizeof(rozmiar),1,fp);
    fwrite(&licznosc, sizeof(licznosc),1,fp);
    fwrite(tab, sizeof(*tab)*rozmiar,1,fp);

    fclose(fp);
}

void librus::readFile()
{
    FILE *fp;
    fp=fopen("librus.dat", "rb");
    fread(&rozmiar, sizeof(rozmiar),1,fp);
    fread(&licznosc, sizeof(licznosc),1,fp);
    fread(tab, sizeof(*tab)*licznosc,1,fp); // lepiej*licznosc
    fclose(fp);
    if (licznosc >0){
		current=0;}
    else {
    	current=-1;}

}

librus::~librus()
{
    cout << "Halo tu destruktor, wcisnij enter"<< endl;
    delete [] tab;
    getchar();
}


int main()
{
    char login[50], haslo[50], login2[20], i[20], n[50], k[2], h[20],  w[2000], p[20], d[10], zn, wcz, nowehaslo[50];
    int un, zalogowany = 0, rozmiar, usunuo, ind, czy;
    float o;
    cout << "Ile elementow tablicy?: ";
    cin >> rozmiar;
    cin.ignore();
    librus baza(rozmiar);
    cout << "Czy chcesz wczytac z pliku zapisane dane (1 - Tak, Cokolwiek innego - Nie)?: ";
    wcz = getch();
    if (wcz=='1')
    {
    	baza.readFile();
        cout << endl << "Wczytano dane do librusa! " <<endl;
	}
	if (wcz!='1')
	{
		cout << endl <<"Nie wczytano danych, tworze konto admina. ";
		baza.dodajUN("admin", "admin", "admin", "", 2);
	}

    do{
    	cout << endl << "Logowanie - wpisz imie: ";
    	cin >> login2;
    	cout << endl << "Logowanie - wpisz nazwisko: ";
    	cin >> login;
    	cout << endl << "Logowanie - wpisz haslo: ";
    	cin >> haslo;
    	zalogowany = baza.logowan(login, haslo);

    	if (zalogowany == 0)
    	{
    		cout << "Niepoprawne dane logowania, sprobuj ponownie." << endl;
		}
	} while (zalogowany != 1 & zalogowany != 2);
	if (zalogowany == 2){
    do{
        cout << endl <<"1. Drukuj wszystko" << endl;
        cout << "2. Posortuj wedlug ocen." << endl;
        cout << "3. Dodaj ocene." << endl;
        cout << "4. Dodaj ucznia lub nauczyciela. " << endl;
        cout << "5. Usun ucznia lub nauczyciela. " << endl;
        cout << "6. Wyslij wiadomosc. " << endl;
        cout << "7. Zapisz dane do dokumentu tekstowego. " << endl;
        cout << "8. Wyszysc baze. " << endl;
        cout << "9. Sprawdz wiadomosci. " << endl;
        cout << "a. Posortuj wedlug nazwiska. " << endl;
        cout << "b. Zobacz wybrane." << endl;
        cout << "c. Nastepne." << endl;
        cout << "d. Poprzednie." << endl;
        cout << "e. Wybierz po indeksie." << endl;
        cout << "f. Usun wybrana pozycje." << endl;
        cout << "g. Wyszukaj oceny po imieniu i nazwisku." << endl;
        cout << "h. Zmien haslo do logowania." << endl;
        cout << "0. Wyjscie"<< endl << endl;

        zn=getch();
        system("CLS");
        cin.ignore();
        switch(zn){
            case '1':{
                baza.drukujwszystko();
                break;
            }
            case '2':{
            	baza.sortOceny();
                break;
            }
            case '3':{
            	cout << "Imie: ";
            	gets(i);
            	cout << "Nazwisko: ";
            	gets(n);
            	cout << "Przedmiot: ";
            	gets(p);
            	cout << "Ocena: ";
            	cin >> o;
            	cin.ignore();
            	cout << "Data (RRRR.MM.DD): ";
            	gets(d);
            	baza.dodajOcene(i, n, p, o, d);
                break;
            }
            case '4':{
            	cout << "Imie: ";
            	gets(i);
            	cout << "Nazwisko: ";
            	gets(n);
            	fflush(stdin);
            	cout << "Haslo (bez spacji i polskich znakow, max 50 znakow): ";
            	gets(h);
            	cout << "Uczen (1) czy nauczyciel (2): ";
            	cin >> un;
            	cout << "Klasa: ";
            	cin >> k;
            	fflush(stdin);
            	baza.dodajUN(i, h, n, k, un);
            	break;
            }
            case '5':{
            	cout << "Wpisz 1, jezeli chcesz usunac tylko dane logowania dla ucznia/naucziela." << endl;
            	cout << "Wpisz 2, jezeli chcesz usunac rowniez wszystkie oceny dla danego ucznia." << endl;
            	cin >> usunuo;
            	cin.ignore();
            	cout << "Podaj imie ucznia/nauczyciela: ";
            	gets(i);
            	cout << endl << "Podaj nazwisko ucznia/nauczyciela: ";
                gets(n);
                baza.usunUN(i, n, usunuo);
				break;
            }
            case '6':{
            	cout << "Do kogo chcesz wyslac wiadomosc, wpisz imie: ";
            	gets(i);
            	cout << "Nazwisko: ";
            	gets(n);
            	cout << "Tresc wiadomosc: ";
            	gets(w);
            	cout << "Podaj dzisiejsza date (RRRR.MM.DD)";
            	gets(d);
            	baza.wyslijWiadomosc(login, i, n, w, d);
                break;
            }
            case '7':{
            	baza.saveFile();
            	cout << endl << "Zapisano dane." << endl;
                break;
            }
            case '8':{
            	cout << endl << "Wyczyszczono tabele. " << endl;
            	baza.czysccalosc();
            	
                break;
            }
            case '9':{
            	baza.sprawdzWiadomosci(login2, login);
                break;
            }
            case '0':{
            	cout << "Wpisz 1, jezeli na pewno chcesz opuscic program: ";
            	cin >> czy;
        		if (czy == 1){
                	cout << "Do widzenia! " <<endl;
                	getchar();
            	}
            	else{
            		zn = 'z';
				}
            }
            case 'a':{
            	baza.sortNazwisko();
                break;
            }
            case 'b':{
            	baza.showCurrent(5,10);
                break;
            }
            case 'c':{
            	baza.next();
            	baza.showCurrent(5,10);
                break;
            }
            case 'd':{
            	baza.previous();
            	baza.showCurrent(5,10);
                break;
            }
            case 'e':{
            	cout << "Podaj indeks elementu: ";
            	cin >> ind;
            	baza.setCurrent(ind);
            	baza.showCurrent(5,10);
                break;
            }
            case 'f':{
            	cout << "Wpisz 1, jezeli na pewno chcesz usunac ten element: ";
            	cin >> czy;
        		if (czy == 1){
        			baza.deleteCurrent();
        			cout << endl <<"Usunieto wybrany element. " << endl;
				}
                break;
            }
            case 'g':{
            	cout << "Podaj imie: ";
            	cin >> i;
            	cout  << "Podaj nazwisko: ";
            	cin >> n;
            	baza.wyszukajOceny(i, n);
                break;
            }
            case 'h':{
				cout << "Podaj nowe haslo (bez spacji i polskich znakow, max 50 znakow)";
            	gets(nowehaslo);
            	baza.zmienHaslo(login2, login, nowehaslo);
            	baza.saveFile();
				break;
            }
            
        }
    }while(zn!='0');
    return 0;}

	if (zalogowany == 1){
    do{
        cout << endl <<"1. Sprawdz oceny" << endl;
        cout << "2. Sprawdz wiadomosci" << endl;
        cout << "3. Wyslij wiadomosc" << endl;
        cout << "4. Zmien haslo" << endl;
        cout << "5. Koniec"<< endl << endl;
        zn=getch();
        system("CLS");
        fflush(stdin);
        switch(zn){
            case '1':{
            	baza.wyszukajOceny(login2, login);
                break;
            }
            case '2':{
            	baza.sprawdzWiadomosci(login2, login);
                break;
            }
            case '3':{
            	cout << "Do kogo chcesz wyslac wiadomosc, wpisz imie: ";
            	gets(i);
            	cout << "Nazwisko: ";
            	gets(n);
            	cout << "Tresc wiadomosc: ";
            	gets(w);
            	cout << "Podaj dzisiejsza date (RRRR.MM.DD)";
            	gets(d);
            	baza.wyslijWiadomosc(login, i, n, w, d);
            	baza.saveFile();
                break;
            }
            case '4':{
            	cout << "Podaj nowe haslo (bez spacji i polskich znakow, max 50 znakow)";
            	gets(nowehaslo);
            	baza.zmienHaslo(login2, login, nowehaslo);
            	baza.saveFile();
                break;
            }
            case '5':{
                cout << "Wpisz 1, jezeli na pewno chcesz opuscic program: ";
            	cin >> czy;
        		if (czy == 1){
                	cout << "Do widzenia! " <<endl;
                	getchar();
            	}
            	else{
            		zn = 'z';
				}
            }
        }
    }while(zn!='5');
    return 0;
}
}
