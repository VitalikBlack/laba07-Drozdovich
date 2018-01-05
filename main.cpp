#include"Child.h"
#include<windows.h>

int main ()
{   
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	int n;
	cout<<"Детский садик. Для вычисления платы за пребывание детей в детском саду утром"
		<<" воспитателями производится учёт поступающих детей. Собранные сведения о "
		<<"пришедших детях передаются заведующей садиком; на основании этих сведений "
		<<"формируется квитанция об оплате (за месяц), которая передаётся родителям "
		<<"через воспитателей. После оплаты квитанция приносится воспитателям. Если "
		<<"в течении 10 дней квитанция не оплачивается, то ребёнок в детский садик "
		<<"не принимается. Сведения об отсутствующих детях передаются медицинской "
		<<"сестре. Те дети, которые отсутствовали более трёх дней, принимаются в "
		<<"садик только при наличии медицинской справки о здоровье. Сформировать "
		<<"коллекцию данных с информацией о посещаемости детьми детского сада. \n";

	cout <<"Количество детей \n";
	cin>>n;
	child *children= new child[n];

	char *name = new char[200];
	int probdni;
	bool spravka;
	bool oplata;
	
	for(int i=0; i<n; i++)
	{
	    cout<<"Введите имя\n";
		cin>>name;
		cout<<"Введите пропущенные дни\n";
		cin>>probdni;
		cout<<"Есть ли справка? 1 - справка есть, а 0 - справки нет\n";
		cin>>spravka;
		cout<<"Есть ли оплата? 1 - оплата есть, а 0 - оплаты нет\n";
		cin>>oplata;
		children[i].Setname(name);
		children[i].Setprobdni(probdni);
		children[i].Setspravka(spravka);
		children[i].Setoplata(oplata);
	}

	cout<<"Дети, которые подали документы на прием : \nНомер\tИмя\tДней пропущено\tСправка\tОплата\n";
	
	for(int i=0; i<n; i++)
	{
		cout<<i+1<<"\t"<<children[i].Getname()<<"\t"<<children[i].Getprobdni()<<"\t\t"<<children[i].Getspravka()<<"\t"
			<<children[i].Getoplata()<<"\t\n";
	}

	cout<<"\n\n\nДети, которые приняты : \nНомер\tИмя\tДней пропущено\tСправка\tОплата\tПосещено дней\n";
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


	cout<<"\n\n\nДети, которым нужна справка : \nНомер\tИмя\tДней пропущено\tСправка\tОплата\tПосещено дней\n";
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

	cout<<"\n\n\nДети, которым нужна оплата : \nНомер\tИмя\tДней пропущено\tСправка\tОплата\tПосещено дней\n";
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