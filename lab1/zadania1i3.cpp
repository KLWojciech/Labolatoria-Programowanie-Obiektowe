using namespace std;
#include <iostream>

class Car {
private:
	string make, model;     //marka, model
	int year;              //rok produkcji
	int currentYear = 2026;
public:
	Car(string Make, string Model, int Year) {
		make   = Make;
		model  = Model;
		year   = Year;
	}
	void displayInfo() {
		cout<<"Make: "<<make<<"\nModel: "<<model<<"\nYear: "<<year<<"\n";
	}
	int getCarAge() {
		return currentYear-year;
	}
	bool isSameCar(Car otherCar) {
		return ( ( make == otherCar.make ) and ( model == otherCar.model ) and ( year == otherCar.year ) );
	}
};

/*

część 3:

1. Aby inne części kodu nie mogły bezpośrednio ingerować w obiekt. Getter i setter mogą wprowadzać obostrzenia odnośnie wprowadzanego typu, albo jakie części oraz kiedy mogą zczytywać / zniemiać wartości.
2. Inne części kodu mogą teraz zmieniać atrybuty utworzonych obiektów 'car'.
3. Można utworzyć wiele. Do atrybutów odnosi się dając kropkę po nazwie obiektu którego atrybut chcemy otrzymać.


*/

int main()
{

	cout<<"\nZadanie 1:\n\n";

	Car car("Toyota", "Corolla", 1986);
	car.displayInfo();

    cout<<"\nZadanie 2:\n\n";

	cout<<"Wiek samochodu: "<<car.getCarAge()<<"\n";

	cout<<"\nZadanie 3:\n\n";

	Car car2("Toyota", "Corolla", 1989);

	if (car.isSameCar(car2))
	{
		cout<<"Samochody są takie same.";
	}
	else
	{
		cout<<"Samochody nie są takie same.";
	}

	return 0;

}
