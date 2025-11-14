#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> bead_sort(std::vector<int> arr) {
    if (arr.empty() || *std::min_element(arr.begin(), arr.end()) < 0) {
        throw std::invalid_argument("Массив должен содержать только неотрицательные числа");
    }
    
    int n = arr.size();
    int max_val = *std::max_element(arr.begin(), arr.end());
    
    // Создаем матрицу бусин
    std::vector<std::vector<int>> beads(n, std::vector<int>(max_val, 0));
    
    // Расставляем бусины
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr[i]; j++) {
            beads[i][j] = 1;
        }
    }
    
    // "Падение" бусин
    for (int j = 0; j < max_val; j++) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += beads[i][j];
            beads[i][j] = 0;
        }
        for (int i = n - 1; i >= n - count; i--) {
            beads[i][j] = 1;
        }
    }
    
    // Преобразуем обратно в числа
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
        for (int j = 0; j < max_val; j++) {
            arr[i] += beads[i][j];
        }
    }
    
    return arr;
}

int main() {
    std::vector<int> arr = {3, 1, 4, 1, 5};
    std::cout << "До сортировки: ";
    for (int num : arr) std::cout << num << " ";
    
    std::vector<int> sorted = bead_sort(arr);
    
    std::cout << "\nПосле сортировки: ";
    for (int num : sorted) std::cout << num << " ";
    
    return 0;
}
