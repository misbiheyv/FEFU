#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <regex>
#include <map>
#include <set>

using namespace std;

template<class T>
struct Node
{
    T data;

    Node<T>* left;
    Node<T>* right;
    Node<T>* parent;

    Node(T value, Node<T>* par = NULL)
    {
        data = value;
        left = NULL;
        right = NULL;
        parent = par;
    }

    bool operator >(Node<T> node)
    {
        return data > node.data;
    }
};

template<class T>
struct BinTree
{
    Node<T>* root;
    int count = 0;

    BinTree()
    {
        root = NULL;
    }

    void Add(T value)
    {
        Node<T>* newNode = new Node<T>(value);

        Node<T>* par = root;
        Node<T>* prevPar = NULL;

        while (par != NULL && par->data != value)
        {
            prevPar = par;

            if (*par > * newNode)
                par = par->left;
            else
                par = par->right;
        }

        if (par != NULL && par->data == value)
        {
            delete newNode;
            return;
        }

        newNode->parent = prevPar;

        if (prevPar == NULL)
        {
            root = newNode;
        }
        else
        {
            if (*prevPar > * newNode)
                prevPar->left = newNode;
            else
                prevPar->right = newNode;
        }
    }

    Node<T>* FindNode(T value)
    {
        Node<T>* temp = root;

        while (temp != NULL && temp->data != value)
            temp = temp->data > value ? temp->left : temp->right;

        return temp;
    }

    Node<T>* FindNextNode(T value)
    {
        return FindNextNode(FindNode(value));
    }

    Node<T>* FindNextNode(Node<T>* temp)
    {
        Node<T>* res;

        if (temp == NULL)
            return NULL;
        if (temp->right != NULL)
            return FindMinNode(temp->right);

        res = temp->parent;

        while (res != NULL && temp == res->right)
        {
            temp = res;
            res = res->parent;
        }

        return res;
    }

    Node<T>* FindMinNode(Node<T>* temp)
    {
        if (temp == NULL)
            throw "Empty tree";

        while (temp->left != NULL)
            temp = temp->left;

        return temp;
    }

    Node<T>* FindMaxNode(Node<T>* temp)
    {
        if (temp == NULL)
            throw "Empty tree";

        while (temp->right != NULL)
            temp = temp->right;

        return temp;
    }

    T Min()
    {
        return FindMinNode(root)->data;
    }

    T Max()
    {
        return FindMaxNode(root)->data;
    }

    Node<T>* DeleteNode(T value)
    {
        return DeleteNode(FindNode(value));
    }

    Node<T>* DeleteNode(Node<T>* node)
    {
        Node<T>* res;
        Node<T>* temp;

        if (node->left == NULL || node->right == NULL)
            res = node;
        else
            res = FindNextNode(node->data);

        if (res->left != NULL)
            temp = res->left;
        else
            temp = res->right;

        if (temp != NULL)
            temp->parent = res->parent;

        if (res->parent == NULL)
            root = temp;
        else
        {
            if (res == (res->parent)->left)
                (res->parent)->left = temp;
            else
                (res->parent)->right = temp;
        }

        if (res != node)
            node->data = res->data;

        return res;
    }

    int GetDepth(Node<T>* h, int d = 0)
    {
        if (h == NULL)
            return 0;

        d++;
        return max(d, max(GetDepth(h->left, d), GetDepth(h->right, d)));
    }

    void Print(int type = 0, char sep = ' ')
    {
        if (type == 0)
            LKP(root, sep);
        else if (type > 0)
            KLP(root, sep);
        else
            LPK(root, sep);
    }

    void LKP(Node<T>* node, char sep)
    {
        if (node->left != NULL)
            LKP(node->left, sep);

        cout << node->data << sep;

        if (node->right != NULL)
            LKP(node->right, sep);
    }

    void KLP(Node<T>* node, char sep)
    {
        cout << node->data << sep;

        if (node->left != NULL)
            KLP(node->left, sep);

        if (node->right != NULL)
            KLP(node->right, sep);
    }

    void LPK(Node<T>* node, char sep)
    {
        if (node->left != NULL)
            LPK(node->left, sep);

        if (node->right != NULL)
            LPK(node->right, sep);

        cout << node->data << sep;
    }
};


int main()
{
    BinTree<int> temp;
    int _;

    cin >> _;

    for (; _ != 0; cin >> _) {
        temp.Add(_);
    }

    cout << temp.GetDepth(temp.root);

    return 0;
}
