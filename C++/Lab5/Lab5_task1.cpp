#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int tsp_brute_force(const vector<vector<int>>& graph) {
    int n = graph.size();
    if (n <= 1) return 0;

    // Создаём вектор городов: 0, 1, 2, ..., n-1
    vector<int> cities;
    for (int i = 0; i < n; i++) {
        cities.push_back(i);
    }

    int min_path = INT_MAX;

    // Перебираем все перестановки городов, начиная с города 0
    do {
        // Все маршруты начинаются и заканчиваются в городе 0
        if (cities[0] != 0) continue;

        // Вычисляем стоимость текущего маршрута
        int current_path = 0;
        for (int i = 0; i < n - 1; i++) {
            int from = cities[i];
            int to = cities[i + 1];
            if (graph[from][to] == 0 && from != to) {
                // Если нет пути между городами, пропускаем эту перестановку
                current_path = INT_MAX;
                break;
            }
            current_path += graph[from][to];
        }

        // Добавляем путь обратно в начальный город
        if (current_path != INT_MAX) {
            int last_city = cities[n - 1];
            if (graph[last_city][0] != 0) {
                current_path += graph[last_city][0];
            } else {
                current_path = INT_MAX;
            }
        }

        // Обновляем минимальную стоимость
        if (current_path < min_path) {
            min_path = current_path;
        }

    } while (next_permutation(cities.begin(), cities.end()));

    return min_path;
}

int main() {
    // Пример графа - матрица смежности
    vector<vector<int>> graph = {
            {0, 10, 15, 20},
            {10, 0, 35, 25},
            {15, 35, 0, 30},
            {20, 25, 30, 0}
    };

    int min_cost = tsp_brute_force(graph);

    if (min_cost == INT_MAX) {
        cout << "ERROR! No path" << endl;
    } else {
        cout << "Min cost: " << min_cost << endl;
    }

    return 0;
}
