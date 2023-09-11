#pragma once
#include <memory>
using namespace std;

namespace mytree
{
	struct Point
	{
		int x;
		int y;
		Point() : x(0), y(0) {}
		Point(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
	};

	struct Node
	{
		Point position;
		int data;

		Node() : position(), data(0) {}
		Node(Point p, int data)
		{
			this->position = p;
			this->data = data;
		}
	};

	class QuadTree
	{
		Point TopLeft;
		Point BottomRight;

		unique_ptr<Node> node;
		unique_ptr<QuadTree> nw;
		unique_ptr<QuadTree> ne;
		unique_ptr<QuadTree> sw;
		unique_ptr<QuadTree> se;
	private:
		bool IsInBound(Point pt);
	public:
		QuadTree();
		QuadTree(Point tl, Point br);
		void Insert(Node* node);

	};
}

void QTTest();
