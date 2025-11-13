#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Переворачивает вектор от 0 до i
void flip(vector<int>& arr, int i) {
    int start = 0;
    while (start < i) {
        swap(arr[start], arr[i]);
        start++;
        i--;
    }
}

// Находит индекс максимального элемента в векторе до n-го элемента
int findMaxIndex(const vector<int>& arr, int n) {
    int max_index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

// Основная функция блинной сортировки
void pancakeSort(vector<int>& arr) {
    int n = arr.size();
    
    // Начинаем с полного вектора и уменьшаем размер на 1 на каждой итерации
    for (int curr_size = n; curr_size > 1; curr_size--) {
        // Находим индекс максимального элемента в несортированной части
        int max_index = findMaxIndex(arr, curr_size);
        
        // Если максимальный элемент не на своем месте
        if (max_index != curr_size - 1) {
            // Переворачиваем вектор до максимального элемента
            if (max_index != 0) {
                flip(arr, max_index);
            }
            
            // Переворачиваем весь несортированный вектор
            flip(arr, curr_size - 1);
        }
    }
}

// Функция для вывода вектора
void printVector(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Пример использования
int main() {
    vector<int> arr = {23, 10, 20, 11, 12, 6, 7};
    
    cout << "Исходный массив: ";
    printVector(arr);
    
    vector<int> sorted_arr = arr;
    pancakeSort(sorted_arr);
    
    cout << "Отсортированный массив: ";
    printVector(sorted_arr);
    
    return 0;
}
