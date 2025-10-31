#include <iostream>
#include <vector>
using namespace std;

// Метод для выполнения бинарного поиска
int binarySearch(const vector<int>& array, int target) {
    int left = 0; // Левая граница поиска
    int right = array.size() - 1; // Правая граница поиска
    
    while (left <= right) {
        // Находим середину массива
        int mid = left + (right - left) / 2;
        
        // Проверяем средний элемент
        if (array[mid] == target) {
            return mid; // Элемент найден
        }
        
        // Если искомый элемент меньше среднего
        if (array[mid] > target) {
            right = mid - 1; // Перемещаемся влево
        } else {
            left = mid + 1; // Перемещаемся вправо
        }
    }
    
    return -1; // Элемент не найден
}

int main() {
    vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 7;
    
    int result = binarySearch(sortedArray, target);
    
    if (result != -1) {
        cout << "Элемент найден на позиции: " << result << endl;
    } else {
        cout << "Элемент не найден" << endl;
    }
    
    return 0;
}
