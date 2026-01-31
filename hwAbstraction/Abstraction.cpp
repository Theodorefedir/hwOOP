//Додати до даного проекта Horse та Elephant зробити це через абстрагування від певних типів.

#include <iostream>
#include <string>
using namespace std;

class ITransport
{
public:
	virtual void Drive() = 0;
};


class Auto : public ITransport
{
public:
	void Drive() override
	{
		cout << "The car drive on the road.\n";
	}
};


class Driver
{
public:
	void Travel(ITransport* transport)
	{
		transport->Drive();
	}
};

// Adaptee - определяет существующий интерфейс, который нуждается в адаптации.
// интерфейс животного
class IAnimal
{
public:
	virtual void Move() = 0;
};

class Camel : public IAnimal
{
public:
	void Move() override
	{
		cout << "Camel rides on the sands of the desert.\n";
	}
};

// Adapter - адаптирует интерфейс Adaptee к интерфейсу Target.
// Адаптер от Camel к ITransport
class CamelToTransportAdapter : public ITransport
{
	Camel camel;
public:
	CamelToTransportAdapter(Camel animal)
	{
		camel = animal;
	}
	void Drive()
	{
		camel.Move();
	}
};
class Horse : public IAnimal {
public:
	void Move() override
	{
		cout << "The Horse rides in the forest.\n";
	}
};
class Elephant : public IAnimal {
public:
	void Move() override
	{
		cout << "An Elephant rides in the jungle.\n";
	}
};
class HorseToTransportAdapter : public ITransport
{
	Horse horse;
public:
	HorseToTransportAdapter(Horse animal)
	{
		horse = animal;
	}
	void Drive()
	{
		horse.Move();
	}
};

class ElephantToTransportAdapter : public ITransport
{
	Elephant elephant;
public:
	ElephantToTransportAdapter(Elephant animal)
	{
		elephant = animal;
	}
	void Drive()
	{
		elephant.Move();
	}
};




class Engine {
protected:
	string engineType;

public:
	Engine() {
		engineType = "Basic";
	}
	Engine(string et) : engineType(et) {}

	virtual void StartEngine() {
		cout << "Starting " << engineType << endl;
	}

	virtual ~Engine() {}
};

class Car : virtual public Engine {
public:
	Car() : Engine("Car Engine") {}

	void DriveOnRoad() {
		StartEngine();
	}
};

class Boat : virtual public Engine {
public:
	Boat() : Engine("Boat Engine") {}

	void OnWater() {
		StartEngine();
	}
};

class AmphibiousVehicle : public Car, public Boat {
public:
	AmphibiousVehicle() : Engine("Amphibious Vehicle Engine") {}
	void ShowCapabilities() {
		DriveOnRoad();
		cout << endl;
		OnWater();
	}
};

int main()
{
	AmphibiousVehicle av;
	av.ShowCapabilities();
	// мандрівник
	Driver driver;
	Auto car;
	ITransport* transport = &car;
	// отправляемся в путешествие
	driver.Travel(transport);
	// встретились пески, необходимо использовать верблюда
	Camel camel;
	Horse horse;
	// Используем адаптер, который преобразует запрос в один или несколько вызовов к адаптируемому объекту.
	HorseToTransportAdapter adapter(horse);
	transport = &adapter;
	// продолжаем путь по пескам пустыни
	driver.Travel(transport);

	system("pause");
	return 0;
}