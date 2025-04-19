#include <iostream>
#include <ctime>
#include <chrono>

using namespace std::chrono;	
using namespace std;

void bubbleSort( int *B, int N) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			if (B[j] > B[j + 1]) {
				int b = B[j];
				B[j] = B[j + 1];
				B[j + 1] = b;
			}
		}
	}
}

void shellMetod(int *C, int N ) {

	for (int gap = N / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < N; ++i) {
			int temp = C[i];
			int j;
			for (j = i; j >= gap && C[j - gap] > temp; j -= gap) {
				C[j] = C[j - gap];
			}	
			C[j] = temp;
		}
	}
}

void switchSort(int* D, int N) {

	int min = 0; 
	int buf = 0;  

	for (int i = 0; i < N; i++)
	{
		min = i;

		for (int j = i + 1; j < N; j++) {
			min = (D[j] < D[min]) ? j : min;
		}

		if (i != min)
		{
			buf = D[i];
			D[i] = D[min];
			D[min] = buf;
		}
	}
}

void fastSort(int* E, int N, int low = 0) {
	if (low < N) { 
		int op = E[N - 1];
		int i = low - 1;  

		for (int j = low; j < N - 1; ++j) {
			if (E[j] <= op) {
				++i;
				swap(E[i], E[j]);
			}
		
		}
		swap(E[i + 1], E[N - 1]);
		int pi = i + 1;
		

		fastSort(E, pi, low);   
		fastSort(E, N, pi + 1);   
	}
}

int main() {
	setlocale(LC_ALL, "RU");
	srand(time(0));

	int N = 0;
	cout << "Введите N: "; cin >> N;
	cout << endl;

	int *A;
	A = new int[N];

	for (int i = 0; i < N; ++i) {
		A[i] = rand() %1000;  
	}

	cout << "Массив A: ";
	for (int i = 0; i < N; i++) {
		cout << A[i] << " ";
	}
	cout << endl << endl;

	int* B;
	B = new int[N];
	int* C;
	C = new int[N];
	int* D;
	D = new int[N];
	int* E;
	E = new int[N];

	for (int i = 0; i < N; i++) {
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
		E[i] = A[i];
	}

	while (true) {
		int sw;
		cout << "1 - пузырьковой сортировкой, 2 - методом Шелла, 3 - сортировкой выбора, 4 - быстрой сортировкой, 5 - выход: "; cin >> sw;
		
		if(cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		cout << endl;

		auto start = high_resolution_clock::now();

		switch (sw) {
		case 1: {
			bubbleSort(B, N);
			cout << "Массив B после сортировки: ";
			for (int i = 0; i < N; i++) {
				cout << B[i] << " ";
			}
			break;
		}

		case 2: {
			shellMetod(C, N);

			cout << "Массив C после сортировки: ";
			for (int i = 0; i < N; i++) {
				cout << C[i] << " ";
			}
			break;
		}

		case 3: {
			switchSort(D, N);

			cout << "Массив D после сортировки: ";
			for (int i = 0; i < N; i++) {
				cout << D[i] << " ";
			}
			break;
		}

		case 4: {
			fastSort(E, N);

			cout << "Массив E после сортировки: ";
			for (int i = 0; i < N; i++) {
				cout << E[i] << " ";
			}

			break;
		}

		case 5: {
			return 0;
		}

		default: {
			cout << "Ошибка попробуйте снова" << endl << endl;
			break;
		}
		}
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(end - start);
		auto minutes = duration.count() / 60000000;
		auto seconds = (duration.count() % 60000000) / 1000000;
		auto millisec = duration.count() % 1000000 / 1000;
		auto microsec = duration.count() % 1000;

		cout << endl;
		cout << "Расчетное время выполнения сортировки : " << minutes << " минут " << seconds << " секунд " << millisec << " миллисекунд " << microsec << " микросекунд" << endl << endl;
	}
	delete[] A;
	delete[] B;
	delete[] C;
	delete[] D;
	delete[] E;
}