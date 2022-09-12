#include <iostream>
#include <vector>
using namespace std;
#define COUNT 10

class BST {
public:
    int value;
    BST *left;
    BST *right;

    explicit BST(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }

    // AVERAGE: O(log(n)) time | O(1) space
    // WORST: O(n) time | O(1) space
    BST &insert(int value) {
        BST *current = this;// O(1) time | O(1) space
        while(current != nullptr) {// AVERAGE: O(log(n)) time, WORST: O(n) time
            if(value < current->value) {// O(1) time
              if(current->left == nullptr) {// O(1) time
                  current->left = new BST(value);// O(1) time | O(1) space
                  break;
              } else {// O(1) time
                  current = current->left;// O(1) time
              }
            } else {// O(1) time
                if(current->right == nullptr) {// O(1) time
                    current->right = new BST(value);// O(1) time | O(1) space
                    break;
                } else {// O(1) time
                    current = current->right;// O(1) time
                }
            }
        }
        return *this;// O(1) time
    }

    // AVERAGE: O(log(n)) time | O(1) space
    // WORST: O(n) time | O(1) space
    bool contains(int value) {
        BST *current = this;// O(1) time | O(1) space
        while(current != nullptr) {// AVERAGE: O(log(n)) time, WORST: O(n) time
            if(value < current->value) {// O(1) time
                current = current->left;// O(1) time
            } else if(value > current->value) {// O(1) time
                current = current->right;// O(1) time
            } else {// O(1) time
                return true;// O(1) time
            }
        }
        return false;// O(1) time
    }

    // AVERAGE: O(log(n)) time | O(1) space
    // WORST: O(n) time | O(1) space
    BST &remove(int value, BST *parent = nullptr) {
        BST *current = this;// O(1) time | O(1) space
        while(current != nullptr) {// AVERAGE: O(log(n)) time, WORST: O(n) time
            if(value < current->value) {// O(1) time
                parent = current;// O(1) time
                current = current->left;// O(1) time
            } else if(value > current->value) {// O(1) time
                parent = current;// O(1) time
                current = current->right;// O(1) time
            } else {// O(1) time
                if(current->left != nullptr && current->right != nullptr) {// O(1) time
                    current->value = current->right->getMin();    // O(length of left-subtree) time | O(1) space
                    current->right->remove(current->value, current);// AVERAGE: O(log(n)) time, WORST: O(n) time | O(1) space
                } else if(parent == nullptr) {// O(1) time
                    if(current->left != nullptr) {// O(1) time
                        current->value = current->left->value;// O(1) time
                        current->right = current->left->right;// O(1) time
                        current->left = current->left->left;// O(1) time
                    } else if(current->right != nullptr) {// O(1) time
                        current->value = current->right->value;// O(1) time
                        current->left = current->right->left;// O(1) time
                        current->right = current->right->right;// O(1) time
                    }
                } else if(parent->left == current) {// O(1) time
                    parent->left = (current->left != nullptr) ? current->left : current->right;// O(1) time
                } else if(parent->right == current) {// O(1) time
                    parent->right = (current->left != nullptr) ? current->left : current->right;// O(1) time
                }
                break;
            }
        }
        return *this;// O(1) time
    }

    // O(length of left-subtree) time | O(1) space
    int getMin() {
        if(left == nullptr) {// O(1) time
            return value;// O(1) time
        } else {
            return left->getMin();// O(length of left-subtree) time | O(1) space
        }
    }

    // DISPLAYS THE TREE SIDEWAYS FROM LEFT --> RIGHT
    // O(n) time | O(1) space
    void displayTree(BST *root, int space) {
        if(root == nullptr) {
            return;
        }
        space += COUNT;
        displayTree(root->right, space);

        cout << endl;
        for(int i = COUNT; i < space; i++) {
            cout << " ";
        }
        cout << root->value << "\n";
        displayTree(root->left, space);
    }

    // O(n) time | O(1) space
    void displayTree() {
        displayTree(this, 0);
    }
};



int main() {
    BST root(10);
    root.insert(5);
    root.insert(3);
    root.insert(4);
    root.insert(2);
    root.insert(1);
    root.insert(8);
    root.insert(6);
    root.insert(7);
    root.insert(9);
    root.insert(15);
    root.insert(13);
    root.insert(14);
    root.insert(12);
    root.insert(11);
    root.insert(18);
    root.insert(16);
    root.insert(17);
    root.insert(19);
    root.displayTree();
}
