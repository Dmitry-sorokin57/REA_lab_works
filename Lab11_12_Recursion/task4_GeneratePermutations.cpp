#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Рекурсивная функция генерации перестановок
void generatePermutations(string& str, int left, int right, vector<string>& result) {
    // Базовый случай: дошли до конца строки
    if (left == right) {
        result.push_back(str);
        return;
    }
    
    // Рекурсивный случай: перебираем все возможные позиции
    for (int i = left; i <= right; i++) {
        // Меняем местами текущий символ с символом в позиции left
        swap(str[left], str[i]);
        
        // Рекурсивно генерируем перестановки для оставшейся части
        generatePermutations(str, left + 1, right, result);
        
        // Возвращаем обратно (backtracking)
        swap(str[left], str[i]);
    }
}

vector<string> getAllPermutations(string str) {
    vector<string> result;
    if (str.empty()) {
        return result;
    }
    generatePermutations(str, 0, str.length() - 1, result);
    return result;
}

int main() {
    string input;
    
    cout << "Введите строку для генерации перестановок: ";
    cin >> input;
    
    // Получаем все перестановки
    vector<string> permutations = getAllPermutations(input);
    
    // Выводим результаты
    cout << "\nВсе перестановки строки \"" << input << "\":" << endl;
    cout << "Общее количество перестановок: " << permutations.size() << endl;
    cout << "Список перестановок:" << endl;
    
    for (size_t i = 0; i < permutations.size(); i++) {
        cout << i + 1 << ": " << permutations[i] << endl;
    }
    
    return 0;
}
