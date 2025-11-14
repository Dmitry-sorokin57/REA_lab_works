#include <iostream>
#include <vector>
using namespace std;

// Итеративная версия
int ternary_search_iterative(vector<int>& arr, int target) {
    /**
     * Тернарный поиск (итеративная версия).
     * Возвращает индекс элемента или -1, если не найден.
     */
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        
        if (arr[mid1] == target) {
            return mid1;
        }
        if (arr[mid2] == target) {
            return mid2;
        }
        
        if (target < arr[mid1]) {
            right = mid1 - 1;
        } else if (target > arr[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    
    return -1;
}

// Рекурсивная версия
int ternary_search_recursive(vector<int>& arr, int target, int left, int right) {
    /**
     * Тернарный поиск (рекурсивная версия).
     */
    if (left > right) {
        return -1;
    }
    
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;
    
    if (arr[mid1] == target) {
        return mid1;
    }
    if (arr[mid2] == target) {
        return mid2;
    }
    
    if (target < arr[mid1]) {
        return ternary_search_recursive(arr, target, left, mid1 - 1);
    } else if (target > arr[mid2]) {
        return ternary_search_recursive(arr, target, mid2 + 1, right);
    } else {
        return ternary_search_recursive(arr, target, mid1 + 1, mid2 - 1);
    }
}

int ternary_search_recursive(vector<int>& arr, int target) {
    return ternary_search_recursive(arr, target, 0, arr.size() - 1);
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int target = 8;
    
    cout << "Массив: ";
    for (int num : arr) cout << num << " ";
    cout << "\nПоиск элемента " << target << endl;
    
    // Тестирование обеих версий
    int result_iter = ternary_search_iterative(arr, target);
    int result_rec = ternary_search_recursive(arr, target);
    
    cout << "Итеративная версия: элемент ";
    if (result_iter != -1) {
        cout << "найден на позиции " << result_iter << endl;
    } else {
        cout << "не найден" << endl;
    }
    
    cout << "Рекурсивная версия: элемент ";
    if (result_rec != -1) {
        cout << "найден на позиции " << result_rec << endl;
    } else {
        cout << "не найден" << endl;
    }
    
    // Тестирование на разных случаях
    vector<int> test_cases = {1, 15, 8, 20, -5};
    cout << "\nТестирование итеративной версии:" << endl;
    for (int test_target : test_cases) {
        int idx = ternary_search_iterative(arr, test_target);
        if (idx != -1) {
            cout << "Элемент " << test_target << ": найден на позиции " << idx << endl;
        } else {
            cout << "Элемент " << test_target << ": не найден" << endl;
        }
    }
    
    return 0;
}
