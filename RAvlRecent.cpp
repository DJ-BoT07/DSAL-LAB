#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Dictionary
{
private:
    class Node
    {
    public:
        string keyword;
        string meaning;
        Node *left;
        Node *right;
        Node(string keyword, string meaning)
        {
            this->keyword = keyword;
            this->meaning = meaning;
        }
    };

    Node *root;

public:
    Dictionary()
    {
        root = NULL;
    }

    int height(Node *node)
    {
        if (node == NULL)
        {
            return -1;
        }
        return node->height;
    }

    Node *rightRotate(Node *p)
    {
        Node *c = p->left;
        Node *t = c->right;

        c->left = p;
        p->right = t;

        p->height = max(height(p->left), height(p->right)) + 1;
        c->height = max(height(c->left), height(c->right)) + 1;

        return c;
    }

    Node *leftRotate(Node *c)
    {
        Node *p = c->left;
        Node *t = p->right;

        p->left = c;
        c->right = t;

        p->height = max(height(p->left), height(p->right)) + 1;
        c->height = max(height(c->left), height(c->right)) + 1;

        return p;
    }

    Node *insert(Node *root, string keyword, string meaning)
    {
        if (root == NULL)
        {
            return new Node(keyword, meaning);
        }
        if (root->keyword > keyword)
        {
            root->left = insert(root->left, keyword, meaning);
        }
        else if (root->keyword < keyword)
        {
            root->right = insert(root->right, keyword, meaning);
        }
        else
        {
            root->keyword = meaning;
            return node;
        }

        root->height = max(height(root->left), height(root->right)) + 1;
        int balanceFactor = height(root->left) - height(root->right);

        // Left Heavy Tree
        if (balance > 1)
        {
            // Left Left Case
            if (keyword < root->left->keyword)
            {
                return rightRotate(root);
            }
            else
            {
                // Left Right Case
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
            // Right Heavy
        }
        else if (balance < -1)
        {
            // Right Right Case
            if (keyword > root->right->keyword)
            {
                return leftRotate(root);
            }
            else
            {
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
        }
        return node;
    }

    void insert(string keyword, string meaning)
    {
        insert(root, keyword, meaning);
    }

    void displayAscending()
    {
        displayAscending(root);
    }

    void displayAscending(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        displayAscending(node->left);
        cout << "Keyword: " << node->keyword << ", Meaning: " << node->meaning << endl;
        displayAscending(node->right);
    }

    void displayDescending()
    {
        displayDescending(root);
    }

    void displayDescending(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        displayDescending(node->right);
        cout << "Keyword: " << node->keyword << ", Meaning: " << node->meaning << endl;
        displayDescending(node->left);
    }

    string search(string keyword)
    {
        Node *current = root;
        while (current != nullptr)
        {
            if (keyword == current->keyword)
            {
                return current->meaning;
            }
            else if (keyword < current->keyword)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return "Keyword not found!";
    }

    int maxComparisions(string keyword)
    {
        Node *current = root;
        int comparisions = 0;
        while (current != NULL)
        {
            comparisions++;
            if (keyword == current->keyword)
            {
                return comparisions;
            }
            else if (keyword < current->keyword)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        return comparisions;
    }

    Node *remove(Node *root, string keyword)
    {
        if (root == NULL)
        {
            return root;
        }

        if (keyword < root->keyword)
        {
            root->left = remove(root->left, keyword);
        }
        else if (keyword > root->keyword)
        {
            root->right = remove(root->right, keyword);
        }
        else
        {
            // Node with only one child or no Child
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // Node with 2 Childs, get inorder successor
            Node *temp = minValueNode(root->right);

            root->keywords = temp->keywords;
            root->meaning = temp->meaning;

            // Delete Inorder Successor
            root->right = remove(root->right, temp->keyword);
            // Update height of the current node
            node->height = 1 + max(height(node->left), height(node->right));

            // Check balance factor and balance the node
            int balance = height(node->left) - height(node->right);

            // Left Heavy
            if (balance > 1)
            {
                // Left Left Case
                if (height(node->left->left) >= height(node->left->right))
                {
                    return rightRotate(node);
                }
                // Left Right Case
                else
                {
                    node->left = leftRotate(node->left);
                    return rightRotate(node);
                }
            }
            // Right Heavy
            else if (balance < -1)
            {
                // Right Right Case
                if (height(node->right->right) >= height(node->right->left))
                {
                    return leftRotate(node);
                }
                // Right Left Case
                else
                {
                    node->right = rightRotate(node->right);
                    return leftRotate(node);
                }
            }

            return node;
        }
    }
    void remove(string keyword)
    {
        root = remove(root, keyword);
    }
};
