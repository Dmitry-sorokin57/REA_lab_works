#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s = "AaBbCcDd";
    vector<char> arr1 = {};
    vector<char> arr2 = {};
    for (int i = 0; i < s.size(); i+=2) {
        arr1.push_back(s[i]);
    }
    // первый массив заполнили заглавными буквами
    for (int i = 1; i < s.size(); i+=2) {
        arr2.push_back(s[i]);
    }
    // второй массив заполнили строчными буквами
    
    // выведем массивы:
    for (int i = 0; i < arr1.size(); ++i) cout << arr1[i];
    cout << "\n";
    for (int i = 0; i < arr2.size(); ++i) cout << arr2[i];

    return 0;
}
