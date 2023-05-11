#include <functional>
#include <iostream>

// using namespace std;
using std::cout;
using std::endl;

struct Node {
  int value;
  Node* left;
  Node* right;

  Node(int val) {
    value = val;
    left = nullptr;
    right = nullptr;
  }
};

void printNodeValueGlobal(Node* node) {
  cout << node->value << " ";
}

class BinaryTree {
 private:
  Node* root;

 public:
  BinaryTree() {
    root = nullptr;
  }

  void insert(int value) {
    Node* newNode = new Node(value);
    if (root == nullptr) {
      root = newNode;
    } else {
      Node* current = root;
      while (true) {
        if (value < current->value) {
          if (current->left == nullptr) {
            current->left = newNode;
            break;
          }
          current = current->left;
        } else {
          if (current->right == nullptr) {
            current->right = newNode;
            break;
          }
          current = current->right;
        }
      }
    }
  }

  Node* getRoot() {
    return root;
  }

  void printInorder(Node* node) {
    if (node == nullptr) {
      return;
    }
    printInorder(node->left);
    cout << node->value << " ";
    printInorder(node->right);
  }

  void printInorder() {
    printInorder(root);
  }
  static void printNodeValueClass(Node* node) {
    cout << node->value << " ";
  }

  template <typename Function>
  void postOrderTraversal(Node* node, Function func) {
    if (node == nullptr) {
      return;
    }
    postOrderTraversal(node->left, func);
    postOrderTraversal(node->right, func);
    func(node);
  }
};

int main() {
  BinaryTree tree;
  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(1);
  tree.insert(4);
  tree.insert(6);
  tree.insert(8);

  cout << "Inorder traversal: ";
  tree.printInorder();
  cout << endl;

  cout << "Root " << tree.getRoot()->value << endl;

  cout << "Post-order com print de função global: ";

  // Uma função global como parâmetro
  tree.postOrderTraversal(tree.getRoot(), &printNodeValueGlobal);
  cout << endl;

  cout << "Post-order usando método státic da classe para print: ";

  // Uma método da classe como parâmetro
  tree.postOrderTraversal(tree.getRoot(), &(BinaryTree::printNodeValueClass));
  cout << endl;

  return 0;
}
