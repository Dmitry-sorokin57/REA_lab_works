public class Main {

    public static void insertionSort(int[] array) {
        // Проходим по всем элементам массива, начиная со второго
        for (int i = 1; i < array.length; i++) {
            int key = array[i];  // Текущий элемент, который нужно вставить
            int j = i - 1;       // Индекс предыдущего элемента

            // Перемещаем элементы array[0..i-1], которые больше key
            // на одну позицию вперед
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
            }

            // Вставляем key на правильное место
            array[j + 1] = key;
        }
    }

    public static void printArray(int[] array) {
        for (int value : array) {
            System.out.print(value + " ");
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        int[] array = {12, 11, 13, 5, 6};

        System.out.println("Исходный массив:");
        printArray(array);

        insertionSort(array);

        System.out.println("Отсортированный массив:");
        printArray(array);
    }
}

// Начальный массив: [12, 11, 13, 5, 6]
// Массив после первой итерации: [11, 12, 13, 5, 6]
// Итоговый массив: [5, 6, 11, 12, 13]
