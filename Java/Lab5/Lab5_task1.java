import java.util.*;


public class Main {

    public static int tspBruteForce(int[][] graph) {
        int n = graph.length;
        if (n <= 1) return 0;

        // Создаём список городов
        List<Integer> cities = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            cities.add(i);
        }

        int minPath = Integer.MAX_VALUE;

        // Генерируем все перестановки
        do {
            // Все маршруты начинаются с города 0
            if (cities.get(0) != 0) continue;

            int currentPath = 0;
            boolean validPath = true;

            // Вычисляем стоимость маршрута
            for (int i = 0; i < n - 1; i++) {
                int from = cities.get(i);
                int to = cities.get(i + 1);

                if (graph[from][to] == 0 && from != to) {
                    validPath = false;
                    break;
                }
                currentPath += graph[from][to];
            }

            // Добавляем обратный путь
            if (validPath) {
                int lastCity = cities.get(n - 1);
                if (graph[lastCity][0] != 0) {
                    currentPath += graph[lastCity][0];
                    minPath = Math.min(minPath, currentPath);
                }
            }

        } while (nextPermutation(cities));

        return minPath;
    }

    // Генерация следующей перестановки
    private static boolean nextPermutation(List<Integer> array) {
        int n = array.size();
        int i = n - 2;

        while (i >= 0 && array.get(i) >= array.get(i + 1)) {
            i--;
        }

        if (i < 0) return false;

        int j = n - 1;
        while (array.get(j) <= array.get(i)) {
            j--;
        }

        Collections.swap(array, i, j);
        Collections.reverse(array.subList(i + 1, n));
        return true;
    }

    public static void main(String[] args) {
        // Матрица смежности (расстояния между городами)
        int[][] graph = {
                {0, 10, 15, 20},
                {10, 0, 35, 25},
                {15, 35, 0, 30},
                {20, 25, 30, 0}
        };

        // Решение полным перебором
        int minCostBrute = TSP.tspBruteForce(graph);
        System.out.println("Метод полного перебора:");
        System.out.println("Минимальная стоимость маршрута: " +
                (minCostBrute == Integer.MAX_VALUE ? "Нет маршрута" : minCostBrute));
    }
}
