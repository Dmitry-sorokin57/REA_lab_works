import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        String s = "AaBbCcDd";
        List<Character> arr1 = new ArrayList<>();
        List<Character> arr2 = new ArrayList<>();
        
        // Заполняем первый массив заглавными буквами (четные индексы)
        for (int i = 0; i < s.length(); i += 2) {
            arr1.add(s.charAt(i));
        }
        
        // Заполняем второй массив строчными буквами (нечетные индексы)
        for (int i = 1; i < s.length(); i += 2) {
            arr2.add(s.charAt(i));
        }
        
        // Выводим массивы
        for (char c : arr1) {
            System.out.print(c);
        }
        System.out.println();
        
        for (char c : arr2) {
            System.out.print(c);
        }
    }
}
