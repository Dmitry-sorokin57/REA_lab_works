// Структура узла
class Node {
    String val;
    Node next;

    // Конструктор для вызова
    Node(String _val) {
        val = _val;
        next = null;
    }
}

// Структура односвязного списка
class List {
    Node first;
    Node last;

    // Базовый конструктор
    List() {
        first = null;
        last = null;
    }

    // Функция, проверяющая пустоту списка
    boolean is_empty() {
        return first == null;
    }

    // Функция, отвечающая за добавление элемента в конец списка
    void push_back(String _val) {
        Node p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last.next = p;
        last = p;
    }

    // Функция для печати элементов списка
    void print() {
        if (is_empty()) return;
        Node p = first;
        while (p != null) {
            System.out.print(p.val + " ");
            p = p.next;
        }
        System.out.println();
    }
}

public class Main {
    public static void main(String[] args) {
        List l = new List();
        System.out.println(l.is_empty());
        l.push_back("1");
        l.push_back("2");
        l.push_back("3");
        l.push_back("4");
        l.push_back("5");
        System.out.println(l.is_empty());
        l.print();
    }
}
