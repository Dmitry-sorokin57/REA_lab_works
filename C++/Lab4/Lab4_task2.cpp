#include <iostream>

#include <vector>
#include <limits>
#include <queue>
using namespace std;

// Определение структуры для представления графа
struct Edge {
    int destination;
    int weight;
};

// Метод для алгоритма Дейкстры
void dijkstra(const vector<vector<Edge>>& graph, int source, int destination) {
    int n = graph.size();
    vector<int> distances(n, numeric_limits<int>::max());
    vector<int> previous(n, -1);
    distances[source] = 0;
    // Приоритетная очередь для хранения вершин по наименьшему расстоянию
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int current = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();

        if (current_distance > distances[current]) {
            continue;
        }

        for (const Edge& edge : graph[current]) {
            int next = edge.destination;
            int weight = edge.weight;
            int distance = current_distance + weight;

            if (distance < distances[next]) {
                distances[next] = distance;
                previous[next] = current;
                pq.push({distance, next});
            }
        }
    }

    // Печать кратчайшего пути
    if (distances[destination] == numeric_limits<int>::max()) {
        cout << "No path from top " << source << " to top " << destination << endl;
    } else {
        cout << "Shortest path from the top " << source << " to top " << destination << " equal " << distances[destination] << endl;
        cout << "Path: ";
        vector<int> path;
        for (int at = destination; at != -1; at = previous[at]) {
            path.push_back(at);
        }
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
}

int main() {
    // Определение графа
    vector<vector<Edge>> graph(8);
    graph[0] = {{1, 2}, {2, 5}};
    graph[1] = {{2, 2}, {3, 3}, {4, 8}};
    graph[2] = {{5, 4}};
    graph[3] = {{1, 3}, {4, 2}, {6, 5}};
    graph[4] = {{5, 3}, {7, 15}};
    graph[5] = {{7, 10}};
    graph[6] = {{7, 13}};
    graph[7] = {}; // вершина 7 не имеет исходящих ребер

    int source = 0;
    int destination = 6;

    dijkstra(graph, source, destination);

    return 0;
}
