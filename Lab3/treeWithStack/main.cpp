#include <iostream>
#include <stack>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
};
class binaryTree
{
private:
    Node* root;
public:
    binaryTree()
    {
        root = NULL;
    }
    static Node* createNode(int data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    void addNode(Node* newNode)
    {
        if (root == NULL)
        {
            root = newNode;
        }
        else
        {
            Node* current = root;
            Node* parent;
            while(current!= NULL)
            {
                parent = current;
                if(newNode->data > current->data)
                {
                    current = current->right;
                }
                else
                {
                    current = current->left;
                }
            }
            if(newNode->data > parent->data)
            {
                parent->right = newNode;
            }
            else
            {
                parent->left = newNode;
            }
        }
    }
    Node* searchNode(int data)
    {
        Node* nSearch = root;
        while(nSearch != NULL)
        {
            if(nSearch->data == data)
            {
                return nSearch;
            }
            else
            {
                if(nSearch->data > data)
                {
                    nSearch = nSearch->left;
                }
                else
                {
                    nSearch = nSearch->right;
                }
            }
        }
        return NULL;
    }
    Node* getParent(Node* child)
    {
        Node* parent = root;
        while(parent != NULL)
        {
            if(parent->right == child || parent->left == child)
            {
                return parent;
            }
            else if(parent->data > child->data)
            {
                parent = parent->left;
            }
            else
            {
                parent = parent->right;
            }
        }
        return NULL;
    }
    void deleteNode(Node* deletedNode)
    {
        if(deletedNode == root)
        {
            if(deletedNode->left == NULL && deletedNode->right == NULL)
            {
                root = NULL;
            }
            else if(deletedNode->left == NULL)
            {
                root = deletedNode->right;
            }
            else if(deletedNode->right == NULL)
            {
                root = deletedNode->left;
            }
            else
            {
                Node* current;
                current = deletedNode->right;
                while(current->left != NULL)
                {
                    current = current->left;
                }
                current->left = deletedNode->left;
                root = deletedNode->right;
            }
        }
        else
        {
            Node* parent = getParent(deletedNode);
            //target to be the one connected to deleted node parent
            Node* target;
            if(deletedNode->left == NULL && deletedNode->right == NULL)
            {
                target = NULL;
            }
            else if(deletedNode->left == NULL)
            {
                target = deletedNode->right;
            }
            else if(deletedNode->right == NULL)
            {
                target = deletedNode->left;
            }
            //here it has left and right nodes
            else
            {
                Node* current = deletedNode->right;
                while(current != NULL)
                {
                    current = current->left;
                }
                current->left = deletedNode->left;
                target = deletedNode->right;
            }
            //where to connect the target depending on the deleted node if it's in the left or the right
            if(parent->left == deletedNode)
            {
                parent->left = target;
            }
            else
            {
                parent->right = target;
            }
        }
        deletedNode->left = deletedNode->right = NULL;
    }
    /////////////////////////////////////////////////
    void display(Node* displayedNode)
    {
        stack<int> Stack;
        Node* current = displayedNode;
        while(current != NULL || Stack.empty() == true)
        {
            Stack.push(current->data);
            while(current->left != NULL)
            {
                current = current->left;
                Stack.push(current->data);
                cout<<"the left" << current->data <<endl;
            }
            cout << Stack.top()<<endl;
            Stack.pop();
            if(current->right != NULL)
            {
                current = current->right;
            }
            else if(current == getParent(current)->left)
            {
                cout << Stack.top()<<endl;
                Stack.pop();
                current = getParent(current)->right;
            }
            else
            {
                cout << Stack.top()<<endl;
                Stack.pop();
                current = displayedNode->right;
            }
        }
        return;
    }
    void traverse()
    {
        display(root);
    }
};
int main()
{
    binaryTree tree;

    tree.addNode(binaryTree::createNode(19));
    tree.addNode(binaryTree::createNode(17));
    tree.addNode(binaryTree::createNode(16));

    tree.addNode(binaryTree::createNode(18));
    tree.addNode(binaryTree::createNode(30));

    tree.addNode(binaryTree::createNode(27));

    /*
    tree.addNode(binaryTree::createNode(27));
    tree.addNode(binaryTree::createNode(79));
    */
    //tree.traverse();
    tree.traverse();
    return 0;
}
