#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    // Базовый случай: если число состоит из одной цифры
    if (n == 0) {
        return 0;
    }
    // Рекурсивный случай: последняя цифра + сумма цифр оставшейся части
    return (n % 10) + sumOfDigits(n / 10);
}

int main() {
    int number;
    
    cout << "Введите число: ";
    cin >> number;
    
    // Обработка отрицательных чисел
    if (number < 0) {
        number = -number;
    }
    
    int result = sumOfDigits(number);
    cout << "Сумма цифр числа: " << result << endl;
    
    return 0;
}
