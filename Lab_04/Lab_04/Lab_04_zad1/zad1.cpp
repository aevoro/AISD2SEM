#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

void customSort(int* price, int N) {
    if (N < 2) return; 

    sort(price, price + N, greater<int>());

    int *result;
    result = new int[N];

    int left = 0;       
    int right = N - 1;  

    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {
            result[i] = price[left++]; 
        }
        else {
            result[i] = price[right--]; 
        }
    }

    for (int i = 0; i < N; i++) {
        price[i] = result[i];
    }
    delete[] result;
}

int main() {
    setlocale(LC_ALL, "RU");

    int N = 0;
    srand(time(0));

    cout << "Введите число товаров (<10000): ";
    cin >> N;

    if (N > 10000 || N < 0) {
        cout << "Ошибка: число товаров должно быть от 0 до 10000." << endl;
        return 1;
    }
    if (cin.fail()) {
        cout << "Ошибка: введено не число." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 1;
    }

    int* price = new int[N];

    for (int i = 0; i < N; i++) {
        price[i] = rand() % 100+1;
    }

    cout << "Цены до сортировки: ";
    for (int i = 0; i < N; i++) {
        cout << price[i] << " ";
    }
    cout << endl;

    customSort(price, N);

    int maxPrice = 0;

    cout << "Цены после сортировки: ";
    for (int i = 0; i < N; i++) {
        cout << price[i] << " ";
        if (i % 2 != 0) {
            price[i] = 0;
        }
        maxPrice += price[i];
    }
    cout << endl << "Максимальная сумма чека: " << maxPrice;

    delete[] price;

    return 0;
}