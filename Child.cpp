#include"Child.h"

child::child()
{
	this->name="Vasya";
	this->probdni=3;
	this->spravka=false;
}
child::child(string name, int probdni, bool spravka)
{
	this->name=name;
	this->probdni=probdni;
	this->spravka=spravka;
}

string child::Getname()
{
	return this->name;
}

int child::Getprobdni()
{
	return this->probdni;
}


bool child::Getspravka()
{
	return this->spravka;
}
void child::Setname(string name)
{
	this->name=name;
}
bool child::Getoplata()
{
	return this->oplata;
}

void child::Setprobdni(int probdni)
{
	this->probdni=probdni;
}

void child::Setspravka(bool spravka)
{
	this->spravka=spravka;
}
void child::Setoplata(bool oplata)
{
	this->oplata=oplata;
}

child::~child()
{
	this->name=nullptr;
	this->oplata=NULL;
	this->probdni=NULL;
	this->spravka=NULL;
}

bool child::Prinyat()
{
	if(this->probdni>=3)
	{
		if(!(this->spravka))
		{
			return false;
		}
		else
		{
			if(this->oplata==true)
			{
				return true;
			}
			return false;
		}
	}
	if(this->oplata==true)
		{
			return true;
	}
	return false;
}