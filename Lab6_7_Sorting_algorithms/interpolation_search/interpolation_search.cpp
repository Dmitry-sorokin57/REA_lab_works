#include <iostream>
#include <vector>
using namespace std;

int interpolationSearch(vector<int>& arr, int lo, int hi, int x) {
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        // Вычисляем позицию с помощью интерполяционной формулы
        int pos = lo + (((hi - lo) * (x - arr[lo])) / (arr[hi] - arr[lo]));
        
        // Если элемент найден
        if (arr[pos] == x) {
            return pos;
        }
        
        // Если x больше, x находится в правом подмассиве
        if (arr[pos] < x) {
            return interpolationSearch(arr, pos + 1, hi, x);
        }
        
        // Если x меньше, x находится в левом подмассиве
        if (arr[pos] > x) {
            return interpolationSearch(arr, lo, pos - 1, x);
        }
    }
    return -1;
}

// Итеративная версия интерполяционного поиска
int interpolationSearchIterative(vector<int>& arr, int x) {
    int lo = 0;
    int hi = arr.size() - 1;
    
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        // Вычисляем позицию с помощью интерполяционной формулы
        int pos = lo + (((hi - lo) * (x - arr[lo])) / (arr[hi] - arr[lo]));
        
        // Если элемент найден
        if (arr[pos] == x) {
            return pos;
        }
        
        // Если x больше, x находится в правом подмассиве
        if (arr[pos] < x) {
            lo = pos + 1;
        } 
        // Если x меньше, x находится в левом подмассиве
        else {
            hi = pos - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    int x = 18;
    
    cout << "Массив: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    // Рекурсивный поиск
    int result1 = interpolationSearch(arr, 0, arr.size() - 1, x);
    if (result1 != -1) {
        cout << "Рекурсивный поиск: элемент " << x << " найден на позиции " << result1 << endl;
    } else {
        cout << "Рекурсивный поиск: элемент " << x << " не найден" << endl;
    }
    
    // Итеративный поиск
    int result2 = interpolationSearchIterative(arr, x);
    if (result2 != -1) {
        cout << "Итеративный поиск: элемент " << x << " найден на позиции " << result2 << endl;
    } else {
        cout << "Итеративный поиск: элемент " << x << " не найден" << endl;
    }
    
    return 0;
}
