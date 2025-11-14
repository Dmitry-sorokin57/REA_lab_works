#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int jump_search(vector<int>& arr, int target) {
    /**
     * Поиск скачками в отсортированном массиве.
     * Возвращает индекс элемента или -1, если не найден.
     */
    int n = arr.size();
    if (n == 0) return -1;
    
    // Определяем размер шага
    int step = sqrt(n);
    
    // Поиск блока, где может находиться элемент
    int prev = 0;
    while (arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }
    
    // Линейный поиск в найденном блоке
    for (int i = prev; i < min(step, n); i++) {
        if (arr[i] == target) return i;
        if (arr[i] > target) break;
    }
    
    return -1;
}

int main() {
    vector<int> arr = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
    int target = 34;
    
    cout << "Массив: ";
    for (int num : arr) cout << num << " ";
    cout << "\nПоиск элемента " << target << endl;
    
    int result = jump_search(arr, target);
    if (result != -1) {
        cout << "Элемент найден на позиции " << result << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }
    
    return 0;
}
