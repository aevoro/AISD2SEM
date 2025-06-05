#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {

	setlocale(LC_ALL, "RU");

    int N = 0;
    srand(time(NULL));

    cout << "������� ���������� ����������(<10000): ";
    cin >> N;

    if (N > 10000 || N < 0) {
        cout << "������: ����� ���������� ������ ���� �� 0 �� 10000." << endl;
        return 1;
    }
    if (cin.fail()) {
        cout << "������: ������� �� �����." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return 1;
    }

    int* ball = new int[N];

    cout << "����� ����������: ";
    for(int i = 0;i < N; i++){
        ball[i] = rand() % 100+1;
        cout << ball[i] << " ";
    }
    cout << endl;

    sort(ball, ball+ N, greater<int>());

    cout << "����� ���������� ����� ����������: ";
    for (int i = 0; i < N; i++) {
        cout << ball[i] << " ";
    }
    cout << endl;

    int maxWinner = 0;
    int winner = 0;

    for (int i = 0; i < N; i++) {
        if (ball[i] == ball[i - 1]) {
            winner++;
        }
        else if (maxWinner >= 3) {
            break;
        }
        else if (ball[i] != ball[i-1]) {
            winner++;
            maxWinner++;
        }
        else {
            winner++;
            maxWinner++;
        }
    }
    cout << "�����������: " << winner;
}