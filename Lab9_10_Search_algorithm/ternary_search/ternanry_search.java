import java.util.Arrays;

public class Main {
    
    /**
     * Тернарный поиск (итеративная версия).
     * Возвращает индекс элемента или -1, если не найден.
     */
    public static int ternarySearchIterative(int[] arr, int target) {
        int left = 0;
        int right = arr.length - 1;
        
        while (left <= right) {
            int mid1 = left + (right - left) / 3;
            int mid2 = right - (right - left) / 3;
            
            if (arr[mid1] == target) {
                return mid1;
            }
            if (arr[mid2] == target) {
                return mid2;
            }
            
            if (target < arr[mid1]) {
                right = mid1 - 1;
            } else if (target > arr[mid2]) {
                left = mid2 + 1;
            } else {
                left = mid1 + 1;
                right = mid2 - 1;
            }
        }
        
        return -1;
    }
    
    /**
     * Тернарный поиск (рекурсивная версия).
     */
    public static int ternarySearchRecursive(int[] arr, int target) {
        return ternarySearchRecursive(arr, target, 0, arr.length - 1);
    }
    
    private static int ternarySearchRecursive(int[] arr, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
        
        if (arr[mid1] == target) {
            return mid1;
        }
        if (arr[mid2] == target) {
            return mid2;
        }
        
        if (target < arr[mid1]) {
            return ternarySearchRecursive(arr, target, left, mid1 - 1);
        } else if (target > arr[mid2]) {
            return ternarySearchRecursive(arr, target, mid2 + 1, right);
        } else {
            return ternarySearchRecursive(arr, target, mid1 + 1, mid2 - 1);
        }
    }
    
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
        int target = 8;
        
        System.out.println("Массив: " + Arrays.toString(arr));
        System.out.println("Поиск элемента " + target);
        
        // Тестирование обеих версий
        int resultIter = ternarySearchIterative(arr, target);
        int resultRec = ternarySearchRecursive(arr, target);
        
        System.out.print("Итеративная версия: элемент ");
        if (resultIter != -1) {
            System.out.println("найден на позиции " + resultIter);
        } else {
            System.out.println("не найден");
        }
        
        System.out.print("Рекурсивная версия: элемент ");
        if (resultRec != -1) {
            System.out.println("найден на позиции " + resultRec);
        } else {
            System.out.println("не найден");
        }
        
        // Тестирование на разных случаях
        int[] testCases = {1, 15, 8, 20, -5};
        System.out.println("\nТестирование итеративной версии:");
        for (int testTarget : testCases) {
            int idx = ternarySearchIterative(arr, testTarget);
            if (idx != -1) {
                System.out.println("Элемент " + testTarget + ": найден на позиции " + idx);
            } else {
                System.out.println("Элемент " + testTarget + ": не найден");
            }
        }
    }
}
