#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int>& arr, int left, int right, int target) {
    /**
     * Вспомогательная функция бинарного поиска.
     */
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int exponential_search(vector<int>& arr, int target) {
    /**
     * Экспоненциальный поиск в отсортированном массиве.
     * Возвращает индекс элемента или -1, если не найден.
     */
    int n = arr.size();
    if (n == 0) return -1;
    
    // Если элемент в начале массива
    if (arr[0] == target) return 0;
    
    // Находим диапазон для бинарного поиска
    int i = 1;
    while (i < n && arr[i] <= target) {
        i *= 2;
    }
    
    // Выполняем бинарный поиск в найденном диапазоне
    int left = i / 2;
    int right = min(i, n - 1);
    return binary_search(arr, left, right, target);
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 15, 18, 20, 23, 35, 40, 55, 60, 78, 90};
    int target = 35;
    
    cout << "Массив: ";
    for (int num : arr) cout << num << " ";
    cout << "\nПоиск элемента " << target << endl;
    
    int result = exponential_search(arr, target);
    if (result != -1) {
        cout << "Элемент найден на позиции " << result << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }
    
    // Тестирование на разных случаях
    vector<int> test_cases = {2, 90, 15, 100, -1};
    cout << "\nТестирование:" << endl;
    for (int test_target : test_cases) {
        int idx = exponential_search(arr, test_target);
        if (idx != -1) {
            cout << "Элемент " << test_target << ": найден на позиции " << idx << endl;
        } else {
            cout << "Элемент " << test_target << ": не найден" << endl;
        }
    }
    
    return 0;
}
