using namespace std;
#include <iostream>
#include <math.h>

class Osoba {
    private:
        string imie, nazwisko, email;
        int wiek, numerTelefonu;
    public:
        
        Osoba(string Imie, string Nazwisko, int Wiek, string Email, int Telefon)
        {
            
            this->setEmail(Email);
            this->setNumerTelefonu(Telefon);
            
            imie = Imie;
            nazwisko = Nazwisko;
            wiek = Wiek;
            
        }
        
        void setImie(string Imie){ imie = Imie; }
        void setNazwisko(string Nazwisko){ nazwisko = Nazwisko; }
        void setWiek(int Wiek){ wiek = Wiek; }
        void setEmail(string Email) { 
            if ( Email.find("@") < Email.size() )
            {
                email = Email;
            } else 
            { 
                throw invalid_argument( "email musi zawierać znak @" );
            } 
        }
        void setNumerTelefonu(int Numer) {
            int pom = Numer / 100000000;
            
            if ( 10 > pom && pom > 0 )
            {
                numerTelefonu = Numer;
            } else
            {
                throw invalid_argument( "numer telefonu musi być 9-cyfrowy" );
            }
        }
        
        string getImie(){return imie;}
        string getNazwisko(){return nazwisko;}
        int getWiek(){return wiek;}
        string getEmail() {return email;}
        int getNumerTelefonu() {return numerTelefonu;}
};
class Pracownik : public Osoba {
    protected:
        string stanowisko;
        float wynagrodzenie;
    public:
        Pracownik(string Imie, string Nazwisko, int Wiek, string Email, int Telefon, string Stanowisko, float Wynagrodzenie) : Osoba(Imie,Nazwisko,Wiek,Email,Telefon) {
            this->setStanowisko(Stanowisko);
            this->setWynagrodzenie(Wynagrodzenie);
        }
        Pracownik(string Imie, string Nazwisko, int Wiek, string Email, int Telefon, string Stanowisko, int Wynagrodzenie) : Osoba(Imie,Nazwisko,Wiek,Email,Telefon) {
            this->setStanowisko(Stanowisko);
            this->setWynagrodzenie(Wynagrodzenie);
        }
        
        string getStanowisko() { return stanowisko; }
        float getWynagrodzenie() { return wynagrodzenie; }
        
        void setStanowisko(string Stanowisko) { stanowisko = Stanowisko; }
        void setWynagrodzenie(float Wynagrodzenie) { wynagrodzenie = Wynagrodzenie; }
        void setWynagrodzenie(int Wynagrodzenie) { wynagrodzenie = static_cast<float>(Wynagrodzenie); }
        
        virtual void pokazDane() {};
        
};
class Nauczyciel : public Pracownik {
    public:
        Nauczyciel(string Imie, string Nazwisko, int Wiek, string Email, int Telefon, float Wynagrodzenie) : Pracownik(Imie, Nazwisko, Wiek, Email, Telefon, "Nauczyciel", Wynagrodzenie) {}
        void pokazDane() {
            string doPokazania = "Nauczyciel ";
            doPokazania += this->getImie()+" ";
            doPokazania += this->getNazwisko()+", ";
            doPokazania += to_string( this->getWiek() )+" lat, email: ";
            doPokazania += this->getEmail()+", numer telefonu: ";
            doPokazania += to_string( this->getNumerTelefonu() )+", stanowisko: ";
            doPokazania += this->getStanowisko()+", wynagrodzenie: ";
            float wynag = this->getWynagrodzenie();
            int zl = floor( wynag * 100 ) / 100;
            int gr = static_cast<int>( wynag * 100 ) % 100;
            doPokazania += to_string( zl )+"zł, "+to_string( gr )+"gr";
            cout<<doPokazania;
        }
};
class Administracja : public Pracownik {
    public:
        Administracja(string Imie, string Nazwisko, int Wiek, string Email, int Telefon, float Wynagrodzenie) : Pracownik(Imie, Nazwisko, Wiek, Email, Telefon, "Administrator", Wynagrodzenie) {}
        void pokazDane() {
            string doPokazania = "\nAdministrator ";
            doPokazania += this->getImie()+" ";
            doPokazania += this->getNazwisko()+", ";
            doPokazania += to_string( this->getWiek() )+" lat, email: ";
            doPokazania += this->getEmail()+", numer telefonu: ";
            doPokazania += to_string( this->getNumerTelefonu() )+", stanowisko: ";
            doPokazania += this->getStanowisko()+", wynagrodzenie: ";
            float wynag = this->getWynagrodzenie();
            int zl = floor( wynag * 100 ) / 100;
            int gr = static_cast<int>( wynag * 100 ) % 100;
            doPokazania += to_string( zl )+"zł, "+to_string( gr )+"gr\n";
            cout<<doPokazania;
        }
};


int main()
{
    
    Osoba czlowiek("Adam", "Nowak", 27, "AdamNowak@onet.pl", 123456789);
    
    cout<<czlowiek.getImie() + " " + czlowiek.getNazwisko() + ", wiek: " + to_string(czlowiek.getWiek())<<"\n";
    
    czlowiek.setImie("Jan");
    czlowiek.setNazwisko("Kowalski");
    czlowiek.setWiek(72);
    
    cout<<czlowiek.getImie() + " " + czlowiek.getNazwisko() + ", wiek: " + to_string(czlowiek.getWiek())+"\n";
    
    Nauczyciel nauczyciel("Jędrzej", "Ćma", 21, "JedrzejCma@gmail.com", 123123123, 12.1531);
    nauczyciel.pokazDane();
    
    Administracja administrator("Szymon", "Delta", 29, "SzymonDelta@gmail.com", 321321321, 18);
    administrator.pokazDane();
    
    return 0;
}