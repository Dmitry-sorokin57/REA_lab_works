#include <iostream>
using namespace std;

struct Node {                                           // Структура узла
    string val; 
    Node* next;

    Node(string _val) : val(_val), next(nullptr) {}     // Конструктор для вызова
};

struct list {                                           // Структура односвязного списка
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}           // Базовый конструктор

    bool is_empty() {                                   // Функция, проверяющая пустоту списка
        return first == nullptr;
    }

    void push_back(string _val) {                       // Функция, отвечающая за добавление элемента в конец списка
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void print() {                                      // Функция для печати элементов списка
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
    cout << l.is_empty() << endl;
    l.print();
    return 0;
}
