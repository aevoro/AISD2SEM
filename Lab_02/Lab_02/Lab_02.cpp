#include <iostream>
#include <vector>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	int N = 0;
	do {
		cout << "Введите N:";
		cin >> N;
	} while (N < 0);
	const int maxIt = ceil(log2(N));

	int choice = 0;
	int counter = 0;
	int left = 0;
	int right = N;
	int x = ceil(((double)left + right) / 2);
	vector<int> iterations;
	iterations.push_back(N);
	while (choice != 3) {
		iterations.push_back(x);
		counter++;
		cout << "X=" << x << endl;
		cout << "Выберите:\n(1)много\n(2)мало\n(3)угадал\n";
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
			left = x;
			x = ceil(((double)left + right) / 2);
			break;
		case 2:
			right = x;
			x = ceil(((double)left + right) / 2);
			break;
		case 3:
			cout << "Угадал!";
			break;
		default:
			cout << "Неверный ввод!";
			break;
		}

	}
	cout << endl << "Количество шагов: " << counter;
	cout << endl << "Максимальное количество шагов: " << maxIt << endl;
	for (int i : iterations) {
		cout << i << endl;
	}
}