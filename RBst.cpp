#include <iostream>
#include <climits> // for INT_MAX
using namespace std;

class BST
{
private:
    class Node
    {
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

public:
    Node *root;
    BST()
    {
        root = NULL;
    }

    void insertNode(Node *&root, int data)
    {
        if (root == NULL)
        {
            root = new Node(data);
            return;
        }

        if (data < root->data)
        {
            insertNode(root->left, data);
        }
        else
        {
            insertNode(root->right, data);
        }
    }

    void create()
    {
        char ch;
        do
        {
            int data;
            cout << "Enter data to insert: ";
            cin >> data;
            insertNode(root, data);
            cout << "Do you want to continue? (y/n): ";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
    }

    void printInorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }

    void search(Node *root, int data)
    {
        if (root == NULL)
        {
            cout << "Key is not present in the tree." << endl;
            return;
        }

        if (root->data == data)
        {
            cout << "Key is present in the tree." << endl;
        }
        else if (data < root->data)
        {
            search(root->left, data);
        }
        else
        {
            search(root->right, data);
        }
    }

    int longestPath(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return max(longestPath(root->left), longestPath(root->right)) + 1;
    }

    int MinTree(Node *root)
    {
        if (root == NULL)
        {
            return INT_MAX;
        }
        return min(root->data, min(MinTree(root->left), MinTree(root->right)));
    }

    void Mirror(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        Node *temp = root->left;
        root->left = root->right;
        root->right = temp;

        Mirror(root->left);
        Mirror(root->right);
    }
};

int main()
{
    BST bst;
    char choice;
    do
    {
        cout << "\nBinary Search Tree Menu:\n";
        cout << "1. Create BST\n";
        cout << "2. Print Inorder Traversal\n";
        cout << "3. Search Key\n";
        cout << "4. Find Longest Path\n";
        cout << "5. Find Minimum Value in Tree\n";
        cout << "6. Mirror Tree\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            bst.create();
            break;
        case '2':
            cout << "Inorder Traversal: ";
            bst.printInorder(bst.root);
            cout << endl;
            break;
        case '3':
        {
            int key;
            cout << "Enter key to search: ";
            cin >> key;
            bst.search(bst.root, key);
            break;
        }
        case '4':
            cout << "Longest Path in the tree: " << bst.longestPath(bst.root) << endl;
            break;
        case '5':
            cout << "Minimum value in the tree: " << bst.MinTree(bst.root) << endl;
            break;
        case '6':
            bst.Mirror(bst.root);
            cout << "Tree mirrored successfully." << endl;
            break;
        case '7':
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != '7');

    return 0;
}
