#include"Child.h"
#include<windows.h>

int main ()
{   
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	int n;
	cout<<"������� �����. ��� ���������� ����� �� ���������� ����� � ������� ���� �����"
		<<" ������������� ������������ ���� ����������� �����. ��������� �������� � "
		<<"��������� ����� ���������� ���������� �������; �� ��������� ���� �������� "
		<<"����������� ��������� �� ������ (�� �����), ������� ��������� ��������� "
		<<"����� ������������. ����� ������ ��������� ���������� ������������. ���� "
		<<"� ������� 10 ���� ��������� �� ������������, �� ������ � ������� ����� "
		<<"�� �����������. �������� �� ������������� ����� ���������� ����������� "
		<<"������. �� ����, ������� ������������� ����� ��� ����, ����������� � "
		<<"����� ������ ��� ������� ����������� ������� � ��������. ������������ "
		<<"��������� ������ � ����������� � ������������ ������ �������� ����. \n";

	cout <<"���������� ����� \n";
	cin>>n;
	child *children= new child[n];

	char *name = new char[200];
	int probdni;
	bool spravka;
	bool oplata;
	
	for(int i=0; i<n; i++)
	{
	    cout<<"������� ���\n";
		cin>>name;
		cout<<"������� ����������� ���\n";
		cin>>probdni;
		cout<<"���� �� �������? 1 - ������� ����, � 0 - ������� ���\n";
		cin>>spravka;
		cout<<"���� �� ������? 1 - ������ ����, � 0 - ������ ���\n";
		cin>>oplata;
		children[i].Setname(name);
		children[i].Setprobdni(probdni);
		children[i].Setspravka(spravka);
		children[i].Setoplata(oplata);
	}

	cout<<"����, ������� ������ ��������� �� ����� : \n�����\t���\t���� ���������\t�������\t������\n";
	
	for(int i=0; i<n; i++)
	{
		cout<<i+1<<"\t"<<children[i].Getname()<<"\t"<<children[i].Getprobdni()<<"\t\t"<<children[i].Getspravka()<<"\t"
			<<children[i].Getoplata()<<"\t\n";
	}

	cout<<"\n\n\n����, ������� ������� : \n�����\t���\t���� ���������\t�������\t������\t�������� ����\n";
	setlocale(LC_ALL, "Russian");
	int j=0;
	for(int i=0; i<n; i++)
	{
		if(children[i].Prinyat())
		{
			setlocale(LC_ALL, "Russian");
			cout<<j+1<<"\t"<<children[i].Getname()<<"\t"<<children[i].Getprobdni()<<"\t\t"<<children[i].Getspravka()<<"\t"
				<<children[i].Getoplata()<<"\t"<<31-children[i].Getprobdni()<<"\n";
			j++;
		}
	}


	cout<<"\n\n\n����, ������� ����� ������� : \n�����\t���\t���� ���������\t�������\t������\t�������� ����\n";
	setlocale(LC_ALL, "Russian");
	j=0;
	for(int i=0; i<n; i++)
	{
		if((!children[i].Prinyat())&&(!children[i].Getspravka()))
		{
			cout<<j+1<<"\t"<<children[i].Getname()<<"\t"<<children[i].Getprobdni()<<"\t\t"<<children[i].Getspravka()<<"\t"
				<<children[i].Getoplata()<<"\t"<<31-children[i].Getprobdni()<<"\n";
			j++;
		}
	}

	cout<<"\n\n\n����, ������� ����� ������ : \n�����\t���\t���� ���������\t�������\t������\t�������� ����\n";
	setlocale(LC_ALL, "Russian");
	j=0;
	for(int i=0; i<n; i++)
	{
		if((!children[i].Prinyat())&&(!children[i].Getoplata()))
		{
			cout<<j+1<<"\t"<<children[i].Getname()<<"\t"<<children[i].Getprobdni()<<"\t\t"<<children[i].Getspravka()<<"\t"
				<<children[i].Getoplata()<<"\t"<<31-children[i].Getprobdni()<<"\n";
			j++;
		}
	}

	system("pause");
	return 0;
}