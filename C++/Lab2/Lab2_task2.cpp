#include <iostream>
using namespace std;

// Структура узла
struct Node {                                           
    string val;
    Node* next;
    
    // Конструктор для вызова
    Node(string _val) : val(_val), next(nullptr) {}     
};

// Структура односвязного списка
struct list {                                           
    Node* first;
    Node* last;

    // Базовый конструктор
    list() : first(nullptr), last(nullptr) {}

    // Функция, проверяющая пустоту списка
    bool is_empty() {                                   
        return first == nullptr;
    }

    // Функция, отвечающая за добавление элемента в конец списка
    void push_back(string _val) {                       
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    // Функция, удаляющая первый элемент списка
    void remove_first() {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    // Функция, удаляющая последний элемент списка
    void remove_last() {
        if (is_empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    // Функция, удаляющая элемент списка по значению
    void remove(string _val) {
        if (is_empty()) return;
        if (first->val == _val) {
            remove_first();
            return;
        }
        else if (last->val == _val) {
            remove_last();
            return;
        }
        Node* cur = first;
        Node* fast = cur->next;
        while (fast && fast->val != _val) {
            fast = fast->next;
            cur = cur->next;
        }
        if (!fast) {
            cout << "This element does not exist" << endl;
            return;
        }
        cur->next = fast->next;
        delete fast;
    }

    // Функция для печати элементов списка
    void print() {                                      
        if (is_empty()) return;
        Node* p = first;
        while (p) {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    list l;
    cout << l.is_empty() << endl;
    l.push_back("1");
    l.push_back("2");
    l.push_back("3");
    l.push_back("4");
    l.push_back("5");
    l.remove_last();
    l.remove_last();
    l.remove("2");
    l.print();
    cout << l.is_empty() << endl;
    l.print();
    return 0;
}
