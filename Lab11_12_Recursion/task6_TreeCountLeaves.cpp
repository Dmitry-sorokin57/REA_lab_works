#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;
    
    // Рекурсивная функция подсчета листьев
    int countLeavesRecursive(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }
        
        return countLeavesRecursive(node->left) + countLeavesRecursive(node->right);
    }
    
    // Рекурсивное удаление дерева
    void deleteTree(TreeNode* node) {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BinaryTree() : root(nullptr) {}
    
    ~BinaryTree() {
        deleteTree(root);
    }
    
    // Публичный метод для подсчета листьев
    int countLeaves() {
        return countLeavesRecursive(root);
    }
    
    // Функция для создания тестового дерева
    void createSampleTree() {
        /*
               1
             /   \
            2     3
           / \   /
          4   5 6
             /
            7
        */
        root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right->left = new TreeNode(6);
        root->left->right->left = new TreeNode(7);
    }
    
    // Обход дерева в ширину для вывода
    void printTree() {
        if (root == nullptr) {
            cout << "Дерево пустое" << endl;
            return;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        cout << "Дерево (уровневой обход): ";
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            cout << current->data << " ";
            
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
    
    // Ручное создание дерева
    void manualCreate() {
        root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        // Листья: 4, 5, 3
    }
};

int main() {
    BinaryTree tree;
    tree.createSampleTree();
    
    cout << "Структура дерева:" << endl;
    tree.printTree();
    
    int leaves = tree.countLeaves();
    cout << "Количество листьев: " << leaves << endl;
    
    return 0;
}
