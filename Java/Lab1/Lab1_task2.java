import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Более компактная инициализация
        List<String> elements = new ArrayList<>(Arrays.asList("a", "1", "b", "2", "c", "3"));
        List<String> letters = new ArrayList<>();
        List<String> numbers = new ArrayList<>();

        // Копируем все элементы в оба списка
        letters.addAll(elements);
        numbers.addAll(elements);
        
        elements.clear(); // очищаем исходный список
        
        // Выводим буквы (элементы с четными индексами)
        for (int i = 0; i < letters.size(); i += 2) {
            System.out.print(letters.get(i));
        }
        System.out.println();
        
        // Выводим числа (элементы с нечетными индексами)
        for (int i = 1; i < numbers.size(); i += 2) {
            System.out.print(numbers.get(i));
        }
    }
}
