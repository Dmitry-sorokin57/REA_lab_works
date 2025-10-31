#include <iostream>
#include <vector>
using namespace std;

// Метод для разбиения массива
int partition(vector<int>& array, int low, int high) {
    // Выбираем последний элемент в качестве опорного
    int pivot = array[high];
    int i = low - 1; // Индекс меньшего элемента
    
    for (int j = low; j < high; j++) {
        // Если текущий элемент меньше или равен опорному
        if (array[j] <= pivot) {
            i++;
            // Поменять местами array[i] и array[j]
            swap(array[i], array[j]);
        }
    }
    
    // Поменять местами array[i+1] и array[high] (опорный элемент)
    swap(array[i + 1], array[high]);
    return i + 1;
}

// Метод для сортировки массива
void quickSort(vector<int>& array, int low, int high) {
    if (low < high) {
        // pi - это индекс разбиения, array[pi] находится на своем месте
        int pi = partition(array, low, high);
        
        // Отсортировать элементы до и после разбиения
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

// Вспомогательный метод для вывода массива
void printArray(const vector<int>& array) {
    for (int value : array) {
        cout << value << " ";
    }
    cout << endl;
}

// Основной метод для запуска сортировки
int main() {
    vector<int> array = {10, 7, 8, 9, 1, 5};
    
    cout << "Исходный массив:" << endl;
    printArray(array);
    
    quickSort(array, 0, array.size() - 1);
    
    cout << "\nОтсортированный массив:" << endl;
    printArray(array);
    
    return 0;
}
