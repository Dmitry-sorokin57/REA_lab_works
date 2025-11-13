import java.util.*;

public class Main {

    public static double[] bucketSort(double[] arr) {
        if (arr.length == 0) return arr;

        // Находим минимальное и максимальное значения
        double minVal = arr[0];
        double maxVal = arr[0];
        for (double num : arr) {
            if (num < minVal) minVal = num;
            if (num > maxVal) maxVal = num;
        }

        // Создаем корзины
        int bucketCount = arr.length;
        List<List<Double>> buckets = new ArrayList<>();
        for (int i = 0; i < bucketCount; i++) {
            buckets.add(new ArrayList<>());
        }

        // Распределяем элементы по корзинам
        for (double num : arr) {
            int index = (int) ((num - minVal) / (maxVal - minVal) * (bucketCount - 1));
            buckets.get(index).add(num);
        }

        // Сортируем каждую корзину и объединяем результат
        double[] sortedArr = new double[arr.length];
        int index = 0;
        for (List<Double> bucket : buckets) {
            Collections.sort(bucket);
            for (double num : bucket) {
                sortedArr[index++] = num;
            }
        }

        return sortedArr;
    }

    // Пример использования
    public static void main(String[] args) {
        double[] arr = {0.42, 0.32, 0.33, 0.52, 0.37, 0.47, 0.51};

        System.out.print("Исходный массив: ");
        for (double num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();

        double[] sortedArr = bucketSort(arr);

        System.out.print("Отсортированный массив: ");
        for (double num : sortedArr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }
}
