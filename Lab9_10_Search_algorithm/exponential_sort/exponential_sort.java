import java.util.Arrays;

public class Main {
    
    /**
     * Вспомогательная функция бинарного поиска.
     */
    private static int binarySearch(int[] arr, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    
    /**
     * Экспоненциальный поиск в отсортированном массиве.
     * Возвращает индекс элемента или -1, если не найден.
     */
    public static int exponentialSearch(int[] arr, int target) {
        int n = arr.length;
        if (n == 0) return -1;
        
        // Если элемент в начале массива
        if (arr[0] == target) return 0;
        
        // Находим диапазон для бинарного поиска
        int i = 1;
        while (i < n && arr[i] <= target) {
            i *= 2;
        }
        
        // Выполняем бинарный поиск в найденном диапазоне
        int left = i / 2;
        int right = Math.min(i, n - 1);
        return binarySearch(arr, left, right, target);
    }
    
    public static void main(String[] args) {
        int[] arr = {2, 3, 4, 10, 15, 18, 20, 23, 35, 40, 55, 60, 78, 90};
        int target = 35;
        
        System.out.println("Массив: " + Arrays.toString(arr));
        System.out.println("Поиск элемента " + target);
        
        int result = exponentialSearch(arr, target);
        if (result != -1) {
            System.out.println("Элемент найден на позиции " + result);
        } else {
            System.out.println("Элемент не найден");
        }
        
        // Тестирование на разных случаях
        int[] testCases = {2, 90, 15, 100, -1};
        System.out.println("\nТестирование:");
        for (int testTarget : testCases) {
            int idx = exponentialSearch(arr, testTarget);
            if (idx != -1) {
                System.out.println("Элемент " + testTarget + ": найден на позиции " + idx);
            } else {
                System.out.println("Элемент " + testTarget + ": не найден");
            }
        }
    }
}
