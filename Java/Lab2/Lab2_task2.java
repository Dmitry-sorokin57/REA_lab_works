import java.util.*;

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

    // Функция, удаляющая первый элемент списка
    void remove_first() {
        if (is_empty()) return;
        Node p = first;
        first = p.next;
    }

    // Функция, удаляющая последний элемент списка
    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node p = first;
        while (p.next != last) p = p.next;
        p.next = null;
        last = p;
    }

    // Функция, удаляющая элемент списка по значению
    void remove(String _val) {
        if (is_empty()) return;
        if (first.val.equals(_val)) {
            remove_first();
            return;
        }
        else if (last.val.equals(_val)) {
            remove_last();
            return;
        }
        Node cur = first;
        Node fast = cur.next;
        while (fast != null && !fast.val.equals(_val)) {
            fast = fast.next;
            cur = cur.next;
        }
        if (fast == null) {
            System.out.println("This element does not exist");
            return;
        }
        cur.next = fast.next;
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
        l.remove_last();
        l.remove_last();
        l.remove("2");
        l.print();
        System.out.println(l.is_empty());
        l.print();
    }
}
