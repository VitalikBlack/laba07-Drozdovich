#include<iostream>
#include<string>

using namespace std; 

class child
{
private:
	string name;
	int probdni;
	bool spravka;
	bool oplata;
public:
	child();
	child(string name, int probdni, bool spravka);
	string Getname();
	int Getprobdni();
	bool Getspravka();
	bool Getoplata();
	void Setname(string name);
	void Setprobdni(int probdni);
	void Setspravka(bool spravka);
	void Setoplata(bool oplata);
	bool Prinyat();
	~child();
};