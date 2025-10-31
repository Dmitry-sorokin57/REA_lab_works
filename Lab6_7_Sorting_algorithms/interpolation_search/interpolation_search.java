public class Main {
    
    public static int interpolationSearch(int[] arr, int lo, int hi, int x) {
        if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
            // Вычисляем позицию с помощью интерполяционной формулы
            int pos = lo + (((hi - lo) * (x - arr[lo])) / (arr[hi] - arr[lo]));
            
            // Если элемент найден
            if (arr[pos] == x) {
                return pos;
            }
            
            // Если x больше, x находится в правом подмассиве
            if (arr[pos] < x) {
                return interpolationSearch(arr, pos + 1, hi, x);
            }
            
            // Если x меньше, x находится в левом подмассиве
            if (arr[pos] > x) {
                return interpolationSearch(arr, lo, pos - 1, x);
            }
        }
        return -1;
    }
    
    // Итеративная версия интерполяционного поиска
    public static int interpolationSearchIterative(int[] arr, int x) {
        int lo = 0;
        int hi = arr.length - 1;
        
        while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
            // Вычисляем позицию с помощью интерполяционной формулы
            int pos = lo + (((hi - lo) * (x - arr[lo])) / (arr[hi] - arr[lo]));
            
            // Если элемент найден
            if (arr[pos] == x) {
                return pos;
            }
            
            // Если x больше, x находится в правом подмассиве
            if (arr[pos] < x) {
                lo = pos + 1;
            } 
            // Если x меньше, x находится в левом подмассиве
            else {
                hi = pos - 1;
            }
        }
        return -1;
    }
}
