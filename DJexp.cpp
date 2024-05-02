#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class TreeNode {
public:
    char value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : value(val), left(NULL), right(NULL) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};

class Stack {
private:
    struct Node {
        TreeNode* data;
        Node* next;
        Node(TreeNode* val) : data(val), next(NULL) {}
    };

    Node* topNode;

public:
    Stack() : topNode(NULL) {}
    
    void push(TreeNode* val) {
        Node* newNode = new Node(val);
        if (topNode == NULL) {
            topNode = newNode;
        } else {
            newNode->next = topNode;
            topNode = newNode;
        }
    }

    TreeNode* pop() {
        if (topNode == NULL) {
            return NULL;
        }
        Node* temp = topNode;
        topNode = topNode->next;
        TreeNode* val = temp->data;
        delete temp;
        return val;
    }

    bool isEmpty() {
        return topNode == NULL;
    }
};

class ExpressionTree {
private:
    TreeNode* root;

public:
    ExpressionTree() : root(NULL) {}

    void constructTree(const string& prefixExpression) {
        Stack st;

        for (int i = prefixExpression.size() - 1; i >= 0; --i) {
            char c = prefixExpression[i];

            TreeNode* node = new TreeNode(c);
            if (isOperator(c)) {
                node->left = st.pop();
                node->right = st.pop();
            }
            st.push(node);
        }

        root = st.pop();
    }

    void postOrderTraversal() {
        Stack st;
        TreeNode* current = root;
        TreeNode* lastVisited = NULL;

        while (current || !st.isEmpty()) {
            if (current) {
                st.push(current);
                current = current->left;
            } else {
                TreeNode* peekNode = st.pop();
                if (peekNode->right && lastVisited != peekNode->right) {
                    st.push(peekNode);
                    current = peekNode->right;
                } else {
                    cout << peekNode->value << " ";
                    lastVisited = peekNode;
                }
            }
        }
    }

    void prettyDisplay() {
        prettyDisplay(root, 0);
    }

    void deleteTree() {
        delete root;
        root = NULL;
    }

private:
    void prettyDisplay(TreeNode* node, int level) {
        if (node == NULL) {
            return;
        }

        prettyDisplay(node->right, level + 1);

        if (level != 0) {
            for (int i = 0; i < level - 1; i++) {
                cout << "|\t";
            }
            cout << "|------->" << node->value << endl;
        } else {
            cout << node->value << endl;
        }
        
        prettyDisplay(node->left, level + 1);
    }

    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
};

int main() {
    string prefixExpression = "+--a*bc/def";
    ExpressionTree tree;
    tree.constructTree(prefixExpression);

    cout << "Expression Tree:" << endl;
    tree.prettyDisplay();

    cout << endl << "Post-order traversal: ";
    tree.postOrderTraversal();
    cout << endl;

    tree.deleteTree();
    

    cout << "Tree deleted." << endl;

    return 0;
}

