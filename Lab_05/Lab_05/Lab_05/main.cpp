#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <Windows.h>

using namespace std;

bool checkBrackets(const string& s) {
    stack<char> st;
    unordered_map<char, char> brackets = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {

        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        }

        else if (c == ')' || c == ']' || c == '}') {
           
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            if (brackets[c] != top) {
                return false;
            }
        }
    }
    return st.empty();
}

int main() {
    
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true) {
        string input;
        cout << "Введите строку: ";
        getline(cin, input);

        if (checkBrackets(input)) {
            cout << "Скобки расставлены верно" << endl;
        }
        else {
            cout << "Скобки расставлены не верно" << endl;
        }
    }

    return 0;
}
