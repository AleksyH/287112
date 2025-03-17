// programowanie2.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
//nie dzielic przez zero
//modulo 0 rowniez nie mozna
#include <iostream>
using namespace std;
double mem;
bool mem_used;
double add(double a, double b){
	double suma = a + b;
	return suma;
}
double sub(double a, double b){
	double roznica = a - b;
	return roznica;
}
double tim(double a, double b){
	double iloczyn = a * b;
	return iloczyn;
}
double div(double a, double b){
	double iloraz = a / b;
	return iloraz;
}
double mod(double a, double b) {
	return a - (int)(a / b) * b;
}

void erase(){}
void menu() {
	double a, b;
	int n;
	cout<< "1.dodawnie" << endl << "2.odejmowanie" << endl << "3.mnozenie" << endl<<"4.dzielenie"<<endl<<"5.reszta_z_dzielenia"<<endl;
	cin >> n;
	switch (n)
	{
	case(1):
		cout << "podaj liczby" << endl;
		cin >> a >> b;
		cout << add(a, b) << endl;;
		break;
	case (2):
		cout << "podaj liczby" << endl;
		cin >> a >> b;
		cout << sub(a, b) << endl;
		break;
	case (3):
		cout << "podaj liczby" << endl;
		cin >> a >> b;
		cout << tim(a, b)<<endl;
		break;
	case (4):
		cout << "podaj liczby" << endl;
		cin >> a >> b;
		while (b == 0) {
			cout << "nie mozna dzielic przez 0" << endl;
			cin >> b;
		}
		cout << div(a, b) << endl;
		break;
	case (5):
		cout << "podaj liczby" << endl;
		cin >> a >> b;
		while (b == 0) {
			cout << "nie mozna dzielic przez 0";
		}
		cout << mod(a, b)<<endl;

		break;
	deafult:
		cout << "nie ma takiej opcji";

		break;
	}

	
}
int main()
{
	//double a, b;
	//cin >> a >> b;
	menu();
	//add(a,b);
	//sub(a, b);
	//tim(a, b);
	//div(a, b);
	//mod(a, b);

}
