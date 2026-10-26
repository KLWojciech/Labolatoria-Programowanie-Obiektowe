using namespace std;
#include <iostream>

// ZADANIE 1:
class Car {
private:
	string make, model;     //marka, model
	int year;              //rok produkcji
	int currentYear = 2026;
public:
	Car() {
	    make = "Toyota";
	    model = "Corolla";
	    year = 1986;
	}
	Car(string Make, string Model, int Year) {
		make   = Make;
		model  = Model;
		year   = Year;
	}
    ~Car()
    {
        cout<<"Destruktor wywołany dla: "<<make<<" "<<model<<"\n";
    }
};

// ZADANIE 2:
class Tablica {
    private:
        int* wskaznik = NULL;
    public:
        Tablica()
        {
            wskaznik = new int[10];
        }
        Tablica( int Rozmiar )
        {

            wskaznik = new int[Rozmiar];
        }
        ~Tablica()
        {
            delete[] wskaznik;
        }
    
};

int main()
{

    Tablica tab1;
    Tablica tab2(12);
    Car customCar("Fiat", "Punto", 2000);
    Car car;
    
	return 0;

}
