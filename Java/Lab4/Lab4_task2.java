import java.util.*;

// Класс для представления ребра графа
class Edge {
    int destination;
    int weight;

    public Edge(int destination, int weight) {
        this.destination = destination;
        this.weight = weight;
    }
}

public class Main {

    // Метод для алгоритма Дейкстры
    public static void dijkstra(List<List<Edge>> graph, int source, int destination) {
        int n = graph.size();
        int[] distances = new int[n];
        int[] previous = new int[n];

        // Инициализация массивов
        Arrays.fill(distances, Integer.MAX_VALUE);
        Arrays.fill(previous, -1);
        distances[source] = 0;

        // Приоритетная очередь для хранения вершин по наименьшему расстоянию
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.offer(new int[]{0, source});

        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int currentDistance = current[0];
            int currentNode = current[1];

            // Если нашли более короткий путь через другую вершину, пропускаем
            if (currentDistance > distances[currentNode]) {
                continue;
            }

            // Обход всех соседей текущей вершины
            for (Edge edge : graph.get(currentNode)) {
                int nextNode = edge.destination;
                int weight = edge.weight;
                int newDistance = currentDistance + weight;

                // Если нашли более короткий путь
                if (newDistance < distances[nextNode]) {
                    distances[nextNode] = newDistance;
                    previous[nextNode] = currentNode;
                    pq.offer(new int[]{newDistance, nextNode});
                }
            }
        }

        // Печать кратчайшего пути
        if (distances[destination] == Integer.MAX_VALUE) {
            System.out.println("No path from top " + source + " to top " + destination);
        } else {
            System.out.println("Shortest path from top " + source + " to top " + destination +
                    " equal " + distances[destination]);
            System.out.print("Path: ");

            // Восстановление пути
            List<Integer> path = new ArrayList<>();
            for (int at = destination; at != -1; at = previous[at]) {
                path.add(at);
            }

            // Вывод пути в обратном порядке
            Collections.reverse(path);
            for (int node : path) {
                System.out.print(node + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        // Создание графа
        List<List<Edge>> graph = new ArrayList<>();

        // Инициализация списков смежности для 8 вершин
        for (int i = 0; i < 8; i++) {
            graph.add(new ArrayList<>());
        }

        // Добавление ребер графа
        graph.get(0).add(new Edge(1, 2));
        graph.get(0).add(new Edge(2, 5));

        graph.get(1).add(new Edge(2, 2));
        graph.get(1).add(new Edge(3, 3));
        graph.get(1).add(new Edge(4, 8));

        graph.get(2).add(new Edge(5, 4));

        graph.get(3).add(new Edge(1, 3));
        graph.get(3).add(new Edge(4, 2));
        graph.get(3).add(new Edge(6, 5));

        graph.get(4).add(new Edge(5, 3));
        graph.get(4).add(new Edge(7, 15));

        graph.get(5).add(new Edge(7, 10));

        graph.get(6).add(new Edge(7, 13));
        // Вершина 7 не имеет исходящих ребер

        int source = 0;
        int destination = 6;

        dijkstra(graph, source, destination);

        // Дополнительный пример: путь от 0 до 7
        System.out.println("\nAdditional example:");
        dijkstra(graph, 0, 7);
    }
}
