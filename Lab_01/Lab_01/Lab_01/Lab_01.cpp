#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
unsigned long int recursion(int n) {	
	if (n == 1) {
		return 0; 
	}
	if (n == 2) {
		return 1;
	}
	if (n == 3) {
		return 1;
	}
	return(recursion(n - 1) + recursion(n - 2));
}
int massiv(int n) {
	auto start = high_resolution_clock::now();
	unsigned long int* ch = new unsigned long int[n+2];
	ch[1] = 0;
	ch[2] = 1;
	for (int i = 3; i <= n; i++) {
		ch[i] = ch[i - 1] + ch[i - 2];
	}
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	auto minutes = duration.count() / 60000000; 
	auto seconds = (duration.count() % 60000000) / 1000000;
	auto millisec = duration.count() % 1000000 / 1000;
	auto microsec = duration.count() % 1000;
	cout << "Число под номером n при выполнении циклом: " << ch[n] << endl << "Расчетное время выполнения циклом: " << minutes << " минут " << seconds << " секунд "<< millisec  << " миллисекунд " << microsec << " микросекунд" << endl;
	delete[] ch;
	return n;
}
int main() { 
	setlocale(LC_ALL, "Ru");
	int n;
	while (true) {
		cout << "Введите номер числа n: "; cin >> n;
		if (cin.fail() || n < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ошибка, введите неотрицательное число." << endl;
		}
		else {
			break;
		}
	}
			massiv(n);
			auto start = high_resolution_clock::now();
			cout << "Число под номером n при выполнении рекурсией: " << recursion(n) << endl;
			auto end = high_resolution_clock::now();
			auto duration = duration_cast<microseconds>(end - start);
			auto minutes = duration.count() / 60000000;
			auto seconds = (duration.count() % 60000000) / 1000000;
			auto millisec = duration.count() % 1000000 / 1000;
			auto microsec = duration.count() % 1000;
			cout << "Расчетное время выполнения рекурсией: " << minutes << " минут " << seconds << " секунд " << millisec <<" миллисекунд " << microsec << " микросекунд" << endl;
	}
