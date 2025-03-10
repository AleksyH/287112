// 287112 powtórka.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void liczby_od_0_do_9(int N) {
	for (int i = 0; i < N; i++) {
		cout << i%10;
	}
}
void liczby_zero_jeden(int N) {
for (int i = 0; i < N; i++){
	cout << i % 2;
    }
}
void liczby_od_0_do_3(int N) {
	for (int i = 0; i < N; i++) {
		cout << i % 4;

	}
}
void liczby_od_0_do_3_trojki(int N) {
	for (int i = 0; i < N*4; i++) {
		cout << i % 4;

	}
}
void liczby_od_0_do_9_trojki(int N) {
	while (N > 0)
	{


		for (int i = 0; i < 10; i++) {
			cout << i;

		}
		N--;
	}
}
void petla_d(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = N; j > i; j--) {
			cout << j;

	}
	cout << endl; 
}}
int main()
{
	//liczby_od_0_do_9(15);
	//liczby_zero_jeden(13);
	//liczby_od_0_do_3(14);
	//liczby_od_0_do_3_trojki(7);
	//liczby_od_0_do_9_trojki(6);
	petla_d(5);
}

