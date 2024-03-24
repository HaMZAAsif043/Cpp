#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *right;
    Node *left;
};
class BT
{
private:
    Node *root;

public:
    BT()
    {
        root = NULL;
    }
    Node *CreateNode(int d)
    {
        Node *t = new Node;
        t->data = d;
        t->left = NULL;
        t->right = NULL;
        return t;
    }
    Node* getroot()
    {
    	return root;
	}
    Node *insertRecursive(Node *&r, int d)
    {
        if (r == NULL)
        {
            r = CreateNode(d);
        }
        else if (r->data > d)
        {
            r->left = insertRecursive(r->left, d);
        }
        else if (r->data < d)
        {
            r->right = insertRecursive(r->right, d);
        }
        return r;
    }
    Node *Search(Node *&r, int d)
    {
        if(r==NULL)
    {
        return r;
    }
       else if (d == r->data)
        {
            cout << "Element is present in the Tree" << d;
        }
        else if (d > r->data)
        {
            r->right = Search(r->right, d);
        }
        else if (d < r->data)
        {
            r->left = Search(r->left, d);
        }
        else {
        	cout<<"Data is not Found!!"<<endl;
		}
        return r;
    }
    void insert(int d)
    {
        insertRecursive(root, d);
    }
    void search(int d)
    {
        Search(root, d);
    }
    void preorder(Node *r)
    {
                if(r!=NULL){
        cout << r->data<<" ";
        preorder(r->left);
        preorder(r->right);
    }
    }
    void post(Node *r)
    {
                if(r!=NULL){
        post(r->left);
        post(r->right);
        cout << r->data<<" ";
    }
    }
    void inorder(Node *r)
    {
        if(r!=NULL){
        inorder(r->left);
        cout << r->data<<" ";
        inorder(r->right);
        }
    }
    void display()
{
    int d;
    do
    {
        cout << "1:Pre_Order Display:\n2:Post_order\n3:In-Order\n4:Exit\n";
        cin >> d;
        switch (d)
        {
        case 1:
            cout << "Preorder: ";
            preorder(root);
            cout << endl;
            break;
        case 2:
            cout << "Postorder: ";
            post(root);
            cout << endl;
            break;
        case 3:
            cout << "Inorder: ";
            inorder(root);
            cout << endl;
            break;
        case 4:
            break;
        default:
            cout << "Enter the valid value" << endl;
        }

        // Flush the output buffer to ensure the results are printed immediately
        cout << flush;

    } while (d != 4);
}

    void Delete(int d)
{
    Node *nodeToDelete = Search(root, d);

    if (nodeToDelete != NULL)
    {
        // Call a separate function for deletion based on the found node
        deleteNode(nodeToDelete);
    }
    else
    {
        cout << "Element not found in the Tree" << endl;
    }
}

void deleteNode(Node *&node)
{
    if (node->left == NULL)
    {
        Node *temp = node->right;
        delete node;
        node = temp;
    }
    else if (node->right == NULL)
    {
        Node *temp = node->left;
        delete node;
        node = temp;
    }
    else
    {
        Node *successor = findMinValueNode(node->right);
        node->data = successor->data;
        deleteNode(successor);
    }
}

Node *findMinValueNode(Node *node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    return node;
}
};

int main()
{
    BT t;
//    t.insertRecursive(t.getroot(), 10); // Initialize root with a value (e.g., 10)
    int s,n;
    do
    {
        cout << "Enter one of the options to perform operations in Tree\n";
        cout << "1:Insertion in Tree\n2:Search for a Number\n3:Display Tree:\n4:To Delete a Node from the tree\n5:To find the min Value in the Tree\n6:To exit the program\n"<< endl;
        cin>>s;
        switch (s)
        {
        case 1:
            cout << "Enter how many Values do you want to insert in Tree:" << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int value;
                cout<<"Enter the to insert in the tree"<<endl;
                cin>>value;
                t.insert(value);
            }
            break;
        case 2:
            int SearchValue;
            cout << "Enter the value to search:" << endl;
            cin >> SearchValue;
            t.search(SearchValue);
            break;
        case 3:
            t.display();
            break;
        case 4:
        cout<<"Enter the value to Delete :"<<endl;
        cin>>n;
        t.Delete(n);
        break;
        case 5:
        t.findMinValueNode(t.getroot());
        break;
        case 6:
        break;
        default:
            cout<<"Enter the valid value"<<endl;
        }

    } while (s != 6);

    return 0;
}

