#include"Child.h"


int main ()
{    int n;
setlocale(LC_ALL, "Russian");
	cout <<"���������� �����";
	cin>>n;
	child *children= new child[n];

	char *name = new char[200];
	int probdni;
	bool spravka;
	bool oplata;
	
	for(int i=0; i<n; i++)
	{
	    cout<<"������� ���";
		cin>>name;
		cout<<"������� ����������� ���";
		cin>>probdni;
		cout<<"���� �� �������? 1 - ������� ����, � 0 - ������� ���";
		cin>>spravka;
		cout<<"���� �� ������? 1 - ������ ����, � 0 - ������ ���";
		cin>>oplata;
		children[i].Setname(name);
		children[i].Setprobdni(probdni);
		children[i].Setspravka(spravka);
		children[i].Setoplata(oplata);
	}

	cout<<"Deti, kotorye podali dokumenty na prijom : \nNumber\tImya\tDnei propusheno\tSpravka\tOplata\n";
	setlocale(LC_ALL, "Russian");
	for(int i=0; i<n; i++)
	{
		cout<<i+1<<"\t"<<children[i].Getname()<<"\t"<<children[i].Getprobdni()<<"\t\t"<<children[i].Getspravka()<<"\t"
			<<children[i].Getoplata()<<"\t\n";
	}

	cout<<"\n\n\nDeti, kotorye prinyaty : \nNumber\tImya\tDnei propusheno\tSpravka\tOplata\tPosetil dnei\n";
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


	cout<<"\n\n\nDeti, kotorym nuzhna spravka : \nNumber\tImya\tDnei propusheno\tSpravka\tOplata\tPosetil dnei\n";
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

	cout<<"\n\n\nDeti, kotorym nuzhna oplata : \nNumber\tImya\tDnei propusheno\tSpravka\tOplata\tPosetil dnei\n";
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