#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();

    // Проходим по всем элементам массива
    for (int i = 0; i < n - 1; i++) {
        // Предполагаем, что текущий элемент - минимальный
        int minIndex = i;

        // Ищем минимальный элемент в оставшейся части массива
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Меняем найденный минимальный элемент с текущим элементом
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}


int main() {
    std::vector<int> testArray = {64, 25, 12, 22, 11};

    std::cout << "Start array: ";
    for (int num : testArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Сортируем массив
    selectionSort(testArray);

    std::cout << "Sorting array: ";
    for (int num : testArray) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
