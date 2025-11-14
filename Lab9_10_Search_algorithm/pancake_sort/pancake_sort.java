import java.util.Arrays;

public class Main {
    
    // Переворачивает массив от 0 до i
    private static void flip(int[] arr, int i) {
        int start = 0;
        while (start < i) {
            int temp = arr[start];
            arr[start] = arr[i];
            arr[i] = temp;
            start++;
            i--;
        }
    }
    
    // Находит индекс максимального элемента в массиве до n-го элемента
    private static int findMaxIndex(int[] arr, int n) {
        int maxIndex = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }
    
    // Основная функция блинной сортировки
    public static void pancakeSort(int[] arr) {
        int n = arr.length;
        
        // Начинаем с полного массива и уменьшаем размер на 1 на каждой итерации
        for (int currSize = n; currSize > 1; currSize--) {
            // Находим индекс максимального элемента в несортированной части
            int maxIndex = findMaxIndex(arr, currSize);
            
            // Если максимальный элемент не на своем месте
            if (maxIndex != currSize - 1) {
                // Переворачиваем массив до максимального элемента
                if (maxIndex != 0) {
                    flip(arr, maxIndex);
                }
                
                // Переворачиваем весь несортированный массив
                flip(arr, currSize - 1);
            }
        }
    }
    
    // Пример использования
    public static void main(String[] args) {
        int[] arr = {23, 10, 20, 11, 12, 6, 7};
        
        System.out.print("Исходный массив: ");
        System.out.println(Arrays.toString(arr));
        
        int[] sortedArr = arr.clone();
        pancakeSort(sortedArr);
        
        System.out.print("Отсортированный массив: ");
        System.out.println(Arrays.toString(sortedArr));
        
        // Демонстрация с шагами
        System.out.println("\nДемонстрация процесса сортировки:");
        int[] arr2 = {3, 1, 4, 2};
        demonstratePancakeSort(arr2);
    }
    
    // Демонстрация блинной сортировки с выводом шагов
    public static void demonstratePancakeSort(int[] arr) {
        System.out.println("Начальный массив: " + Arrays.toString(arr));
        int n = arr.length;
        
        for (int currSize = n; currSize > 1; currSize--) {
            int maxIndex = findMaxIndex(arr, currSize);
            
            if (maxIndex != currSize - 1) {
                if (maxIndex != 0) {
                    System.out.print("Переворачиваем до индекса " + maxIndex + ": ");
                    flip(arr, maxIndex);
                    System.out.println(Arrays.toString(arr));
                }
                
                System.out.print("Переворачиваем до индекса " + (currSize - 1) + ": ");
                flip(arr, currSize - 1);
                System.out.println(Arrays.toString(arr));
            }
        }
    }
}
