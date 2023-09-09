#include <iostream>
#include <memory> 

using namespace std;

namespace mytree
{
    struct Node
    {
        int mData;
        shared_ptr<Node> mpLeft;
        shared_ptr<Node> mpRight;

        Node(int data = 0, shared_ptr<Node> pLeft = nullptr, shared_ptr<Node> pRight = nullptr)
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
    shared_ptr<mytree::Node> mpRoot; 

public:
    BinaryTree()
    {
        mpRoot = nullptr;
    }

    void Insert(int data)
    {
        mpRoot = InsertRec(mpRoot, data);
    }

    shared_ptr<mytree::Node> InsertRec(shared_ptr<mytree::Node> root, int data)
    {
        if (root == nullptr)
        {
            return make_shared<mytree::Node>(data);
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

    void InorderTraversal(shared_ptr<mytree::Node> root)
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
}
