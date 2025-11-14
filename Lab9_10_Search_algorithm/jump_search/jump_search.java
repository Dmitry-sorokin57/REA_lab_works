import java.util.Arrays;

public class Main {
    /**
     * Поиск скачками в отсортированном массиве.
     * Возвращает индекс элемента или -1, если не найден.
     */
    public static int jumpSearch(int[] arr, int target) {
        int n = arr.length;
        if (n == 0) return -1;
        
        // Определяем размер шага
        int step = (int) Math.sqrt(n);
        
        // Поиск блока, где может находиться элемент
        int prev = 0;
        while (arr[Math.min(step, n) - 1] < target) {
            prev = step;
            step += (int) Math.sqrt(n);
            if (prev >= n) return -1;
        }
        
        // Линейный поиск в найденном блоке
        for (int i = prev; i < Math.min(step, n); i++) {
            if (arr[i] == target) return i;
            if (arr[i] > target) break;
        }
        
        return -1;
    }
    
    public static void main(String[] args) {
        int[] arr = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144};
        int target = 34;
        
        System.out.println("Массив: " + Arrays.toString(arr));
        System.out.println("Поиск элемента " + target);
        
        int result = jumpSearch(arr, target);
        if (result != -1) {
            System.out.println("Элемент найден на позиции " + result);
        } else {
            System.out.println("Элемент не найден");
        }
    }
}
