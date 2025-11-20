#include <iostream>
#include <string>
#include <cctype> // для tolower()
using namespace std;

// Функция для проверки, является ли символ гласной
bool isVowel(char c) {
    c = tolower(c); // Приводим к нижнему регистру для универсальной проверки
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

// Рекурсивная функция для подсчета гласных
int countVowels(const string& str, int index = 0) {
    // Базовый случай: дошли до конца строки
    if (index >= str.length()) {
        return 0;
    }
    
    // Рекурсивный случай: проверяем текущий символ и переходим к следующему
    int currentCount = isVowel(str[index]) ? 1 : 0;
    return currentCount + countVowels(str, index + 1);
}

int main() {
    string text;
    
    cout << "Введите строку: ";
    getline(cin, text);
    
    int result = countVowels(text);
    cout << "Количество гласных букв: " << result << endl;
    
    return 0;
}
