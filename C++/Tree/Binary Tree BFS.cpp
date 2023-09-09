#include <iostream>
#include <queue> 

using namespace std;

namespace mytree
{
    struct Node
    {
        int mData;
        Node* mpLeft;
        Node* mpRight;

        Node(int data = 0, Node* pLeft = nullptr, Node* pRight = nullptr)
        {
            mData = data;
            mpLeft = pLeft;
            mpRight = pRight;
        }
    };
}

class BinaryTree
{
private:
    mytree::Node* mpRoot;

public:
    BinaryTree()
    {
        mpRoot = nullptr;
    }

    mytree::Node* CreateNode(int data, mytree::Node* pLeft = nullptr, mytree::Node* pRight = nullptr)
    {
        return new mytree::Node(data, pLeft, pRight);
    }

    void Insert(int data)
    {
        mpRoot = InsertRec(mpRoot, data);
    }

    mytree::Node* InsertRec(mytree::Node* root, int data)
    {
        if (root == nullptr)
        {
            return CreateNode(data);
        }

        if (data < root->mData)
        {
            root->mpLeft = InsertRec(root->mpLeft, data);
        }
        else if (data > root->mData)
        {
            root->mpRight = InsertRec(root->mpRight, data);
        }

        return root;
    }

    void InorderTraversal(mytree::Node* root)
    {
        if (root == nullptr)
        {
            return;
        }

        InorderTraversal(root->mpLeft);
        cout << root->mData << " ";
        InorderTraversal(root->mpRight);
    }

    void PrintInorder()
    {
        InorderTraversal(mpRoot);
        cout << endl;
    }

    void PreorderTraversal(mytree::Node* root)
    {
        if (root == nullptr)
        {
            return;
        }

        cout << root->mData << " ";
        PreorderTraversal(root->mpLeft);
        PreorderTraversal(root->mpRight);
    }

    void PrintPreorder()
    {
        PreorderTraversal(mpRoot);
        cout << endl;
    }

    void BFS()
    {
        if (mpRoot == nullptr)
        {
            return;
        }

        queue<mytree::Node*> q;
        q.push(mpRoot);

        cout << "BFS Traversal: ";

        while (!q.empty())
        {
            mytree::Node* current = q.front();
            q.pop();

            cout << current->mData << " ";

            if (current->mpLeft)
            {
                q.push(current->mpLeft);
            }

            if (current->mpRight)
            {
                q.push(current->mpRight);
            }
        }

        cout << endl;
    }
};

int main()
{
    BinaryTree tree;

    tree.Insert(1);
    tree.Insert(2);
    tree.Insert(3);
    tree.Insert(4);
    tree.Insert(5);
    tree.Insert(6);
    tree.Insert(7);

    tree.PrintInorder();
    tree.PrintPreorder();
    tree.BFS(); 

}
