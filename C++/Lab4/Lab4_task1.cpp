#include <iostream>

// Класс вершины дерева
class TNode {
public:
    TNode(int key)
            : Key(key) { }
    int Key;
    TNode* Left = nullptr;
    TNode* Right = nullptr;
};

// Класс дерева
class TTree {
public:
    // Базовый конструтор
    TTree()
            : Root(nullptr)
    {
    }
    // Деструктор для удаления вершин при уничтожении дерева
    ~TTree() {
        DestroyNode(Root);
    }

    // Метод для добавления узла в дерево
    void Insert(int x);
    // Метод для печати дерева In-order обход
    void PrintInOrder(TNode* node);
    void PrintInOrder();

private:
    // Метод для уничтожения узла
    static void DestroyNode(TNode* node) {
        if (node) {
            DestroyNode(node->Left);
            DestroyNode(node->Right);
            delete node;
        }
    }
private:
    TNode* Root;
};

// Метод для добавления узла в дерево
void TTree::Insert(int x) {
    TNode** cur = &Root;
    while (*cur) {
        TNode& node = **cur;
        if (x < node.Key) {
            cur = &node.Left;
        } else if (x > node.Key) {
            cur = &node.Right;
        } else {
            return;
        }
    }
    *cur = new TNode(x);
}

// Метод для Print-order обхода
void TTree::PrintInOrder(TNode* node) {
    if (node == nullptr) return;

    PrintInOrder(node->Left);
    std::cout << node->Key << " ";
    PrintInOrder(node->Right);
}

void TTree::PrintInOrder() {
    std::cout << "In-Order: ";
    PrintInOrder(Root);
    std::cout << std::endl;
}

int main() {

    TTree tree;

    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);
    tree.Insert(10);
    tree.Insert(25);
    tree.Insert(35);
    tree.Insert(45);
    tree.PrintInOrder();
    return 0;
}
