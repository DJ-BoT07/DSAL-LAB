#include <iostream>
#include <stack>
#include <cwctype>
using namespace std;
/*
                    ALGORITHM
    1. Scan the expression from the back side.
    2. If the character is operand then create it's node and push it into stack.
    3. If the character is operator then pop 2 times. first charcter will be on left and 2nd will be on right.
    4. And push the this node again into the stack.
*/
class Tree
{
public:
    class Node
    {
    public:
        char ch;
        Node *left;
        Node *right;
        Node(char c)
        {
            ch = c;
            right = left = NULL;
        }
    };

    Node *root;
    
    Tree()
    {
        root = NULL;
    }
    
    Node *create(string exp){
        stack<Node* >stack;
        Node *n, *n1, *n2;
        for (int i = 0; i < exp.length(); i++)
        {
            if(isalnum(exp[i]) != 0){
                n = new Node(exp[i]);
                stack.push(n);
            } else{
                n = new Node(exp[i]);
                n1 = stack.top();
                stack.pop();
                n2 = stack.top();
                stack.pop();
                n->left = n1;
                n->right = n2;
                stack.push(n);
            }
        }
        return n;
        
    }

    void inOrder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        inOrder(node->left);
        cout << node->ch;
        inOrder(node->right);
    }

    void deletion(Node *&node)
    {
        if (node != NULL)
        {
            deletion(node->left);
            delete (node);
            deletion(node->right);
        }
    }

    void postOrder(Node *node){
        if(node == NULL){
            return;
        }

        stack<Node*> stack;
        Node* current = node;
        Node* visited = NULL;

        while(!stack.empty() || current != NULL){
            while(current != NULL){
                stack.push(current);
                current = current->left;
            }
            current = stack.top();
            if(current->right != NULL || current->right == visited){
                stack.pop();
                cout<< current->ch << " ";
                visited = current;
            } else{
                current = current->right;
            }
        }
        
    }
};

int main()
{
    Tree tree;
    int choice;
    char ch;
    string str;

    do
    {
        cout << "\t\t*********** MENU ***********" << endl;
        cout << "\t\t1. Create a tree" << endl;
        cout << "\t\t2. Inorder traversal" << endl;
        cout << "\t\t3. Postorder traversal" << endl;
        cout << "\t\t4. Delete the tree" << endl;
        cout << "\t\t5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the string: ";
            cin >> str;
            tree.create(str);
            break;
        case 2:
            cout << "Inorder traversal: ";
            tree.inOrder(tree.root);
            cout << endl;
            break;
        case 3:
            cout << "Postorder traversal: ";
            tree.postOrder(tree.root);
            cout << endl;
            break;
        case 4:
            tree.deletion(tree.root);
            cout << "Tree has been deleted!" << endl;
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }

        cout << "Do you want to continue? (Y/N): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}
