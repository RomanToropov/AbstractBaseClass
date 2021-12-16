#include<iostream>
using namespace std;

class Weapon
{
	int damage;	//íàíîñèìûé óðîí
	int size;
public:
	Weapon(int damage, int size) :damage(damage), size(size)
	{
	}
	virtual ~Weapon()
	{
	}
	virtual void apply() = 0;	//×èñòî âèðòóàëüíûé ìåòîä (×èñòî âèðòóàëüíàÿ ôóíêöèÿ)
	//Êàê ðàç ýòîò ÷èñëî âèðòóàëüíûé ìåòîä è äåëàêò êëàññ àáñòðàêòíûì
	virtual void info()
	{
		cout << "Damage:\t" << damage << endl;
		cout << "Size:\t" << size << endl;
	}
};

class ColdArms :public Weapon
{
public:
	ColdArms(int damage, int size) :Weapon(damage, size) {}
	~ColdArms() {}
};

class Knife :public ColdArms
{
public:
	Knife(int damage, int size) :ColdArms(damage, size) {}
	~Knife() {}
	void apply()
	{
		cout << "×èñòèòü êàðòîøêó, ðåçàòü ÿáëîêè" << endl;
	}
	void info()
	{
		Weapon::info();
		apply();
	}
};

class Machete :public ColdArms
{
public:
	Machete(int damage, int size) :ColdArms(damage, size) {}
	~Machete() {}
	void apply()
	{
		cout << "Îòëè÷íî ðóáèò ñàõàðíûé òðîñíèê, òàê æå î÷åíü óäîáåí äëÿ ñòðèæêè äåðåâüåâ" << endl;
	}
	void info()
	{
		Weapon::info();
		apply();
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Weapon w(20, 5);	w.info();

	//ColdArms ca(20, 5);
	Knife kn(20, 5);	kn.info();
	Machete m(50, 25);	m.info();
}