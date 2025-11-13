#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

vector<double> bucketSort(vector<double>& arr) {
    if (arr.empty()) return arr;

    // Находим минимальное и максимальное значения
    double min_val = *min_element(arr.begin(), arr.end());
    double max_val = *max_element(arr.begin(), arr.end());

    // Создаем корзины
    int bucket_count = arr.size();
    vector<vector<double>> buckets(bucket_count);

    // Распределяем элементы по корзинам
    for (double num : arr) {
        int index = static_cast<int>((num - min_val) / (max_val - min_val) * (bucket_count - 1));
        buckets[index].push_back(num);
    }

    // Сортируем каждую корзину и объединяем результат
    vector<double> sorted_arr;
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        sorted_arr.insert(sorted_arr.end(), bucket.begin(), bucket.end());
    }

    return sorted_arr;
}

// Пример использования
int main() {
    vector<double> arr = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};

    cout << "Start array: ";
    for (double num : arr) {
        cout << num << " ";
    }
    cout << endl;

    vector<double> sorted_arr = bucketSort(arr);

    cout << "Sorted array: ";
    for (double num : sorted_arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
