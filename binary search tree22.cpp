#include <iostream>
using namespace std;

template <class T>
class BST
{
    struct Node
    {
        T data;
        Node *left, *right;

        Node(T value)
        {
            data = value;
            left = right = NULL;
        }
    };

    Node *root;

    Node* insert(Node *p, T value)
    {
        if (p == NULL)
            return new Node(value);

        if (value < p->data)
            p->left = insert(p->left, value);
        else if (value > p->data)
            p->right = insert(p->right, value);

        return p;
    }

    bool search(Node *p, T value)
    {
        if (p == NULL)
            return false;

        if (p->data == value)
            return true;

        if (value < p->data)
            return search(p->left, value);

        return search(p->right, value);
    }

    Node* remove(Node *p, T value)
    {
        if (p == NULL)
            return NULL;

        if (value < p->data)
            p->left = remove(p->left, value);
        else if (value > p->data)
            p->right = remove(p->right, value);
        else
        {
            if (p->left == NULL)
            {
                Node *temp = p->right;
                delete p;
                return temp;
            }

            if (p->right == NULL)
            {
                Node *temp = p->left;
                delete p;
                return temp;
            }

            Node *temp = p->right;

            while (temp->left != NULL)
                temp = temp->left;

            p->data = temp->data;
            p->right = remove(p->right, temp->data);
        }

        return p;
    }

    void inorder(Node *p)
    {
        if (p != NULL)
        {
            inorder(p->left);
            cout << p->data << " ";
            inorder(p->right);
        }
    }

    void preorder(Node *p)
    {
        if (p != NULL)
        {
            cout << p->data << " ";
            preorder(p->left);
            preorder(p->right);
        }
    }

    void postorder(Node *p)
    {
        if (p != NULL)
        {
            postorder(p->left);
            postorder(p->right);
            cout << p->data << " ";
        }
    }

    void clear(Node *p)
    {
        if (p != NULL)
        {
            clear(p->left);
            clear(p->right);
            delete p;
        }
    }

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        clear(root);
    }

    void insert(T value)
    {
        root = insert(root, value);
    }

    bool search(T value)
    {
        return search(root, value);
    }

    void remove(T value)
    {
        root = remove(root, value);
    }

    void inorder()
    {
        inorder(root);
    }

    void preorder()
    {
        preorder(root);
    }

    void postorder()
    {
        postorder(root);
    }
};

int main()
{
    BST<int> tree;
    int choice, value;

    do
    {
        cout << "\n\n--- BINARY SEARCH TREE ---";
        cout << "\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Delete";
        cout << "\n4. In-Order";
        cout << "\n5. Pre-Order";
        cout << "\n6. Post-Order";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                tree.insert(value);
                cout << "Inserted!";
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;

                if (tree.search(value))
                    cout << "Found!";
                else
                    cout << "Not Found!";
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                tree.remove(value);
                cout << "Deleted!";
                break;

            case 4:
                cout << "In-Order: ";
                tree.inorder();
                break;

            case 5:
                cout << "Pre-Order: ";
                tree.preorder();
                break;

            case 6:
                cout << "Post-Order: ";
                tree.postorder();
                break;

            case 7:
                cout << "Thank you!";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 7);

    return 0;
}
