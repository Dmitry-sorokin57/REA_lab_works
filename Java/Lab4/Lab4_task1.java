// Класс вершины дерева
class TNode {
    public int Key;
    public TNode Left = null;
    public TNode Right = null;

    public TNode(int key) {
        this.Key = key;
    }
}

// Класс дерева
class TTree {
    private TNode Root;

    // Базовый конструктор
    public TTree() {
        Root = null;
    }

    // Метод для добавления узла в дерево
    public void Insert(int x) {
        // В Java мы используем ссылки по-другому
        if (Root == null) {
            Root = new TNode(x);
            return;
        }

        TNode current = Root;
        TNode parent = null;

        while (current != null) {
            parent = current;
            if (x < current.Key) {
                current = current.Left;
            } else if (x > current.Key) {
                current = current.Right;
            } else {
                return; // элемент уже существует
            }
        }

        // Создаем новый узел и прикрепляем к родителю
        if (x < parent.Key) {
            parent.Left = new TNode(x);
        } else {
            parent.Right = new TNode(x);
        }
    }

    // Метод для Print-order обхода
    private void PrintInOrder(TNode node) {
        if (node == null) return;

        PrintInOrder(node.Left);
        System.out.print(node.Key + " ");
        PrintInOrder(node.Right);
    }

    public void PrintInOrder() {
        System.out.print("In-Order: ");
        PrintInOrder(Root);
        System.out.println();
    }

}

// Главный класс
public class Main {
    public static void main(String[] args) {
        TTree tree = new TTree();

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

    }
}
