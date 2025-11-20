#include <iostream>
using namespace std;

// Рекурсивная функция для подсчета суммы элементов массива
int arraySum(int arr[], int size) {
    // Базовый случай: пустой массив
    if (size == 0) {
        return 0;
    }
    // Рекурсивный случай: последний элемент + сумма остальных
    return arr[size - 1] + arraySum(arr, size - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int sum = arraySum(arr, size);
    cout << "Сумма элементов: " << sum << endl;
    
    return 0;
}
