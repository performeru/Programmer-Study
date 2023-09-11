#include "quadtree.h"
using namespace mytree;
using namespace std;

QuadTree::QuadTree() : 
	TopLeft{ Point{} }, BottomRight{ Point{} },
	node {nullptr}, nw{}, ne{}, sw{}, se{}
{

}

QuadTree::QuadTree(Point tl, Point br) : QuadTree()
{
	TopLeft = tl;
	BottomRight = br;
}

bool QuadTree::IsInBound(Point pt)
{
	return pt.x >= TopLeft.x && pt.x <= BottomRight.x &&
		pt.y >= TopLeft.y && pt.y <= BottomRight.y;
}


void QuadTree::Insert(Node* node)
{
	if(node==nullptr)
	{
		return; 
	}

	if (!IsInBound(node->position))
	{
		return;
	}

	if (abs(TopLeft.x - BottomRight.x) <= 1 &&
		abs(TopLeft.y - BottomRight.y) <= 1)
	{
		if (this->node == nullptr)
		{
			this->node.reset(node);
		}
		return;
	}
	
	if((TopLeft.x+BottomRight.x)/2>=node->position.x)
	{
		if(node->position.y <= (TopLeft.y+BottomRight.y)/2)
		{
			if(nw==nullptr)
			{
				nw = make_unique<QuadTree>(TopLeft, 
					Point((TopLeft.x+BottomRight.x)/2,(TopLeft.y+BottomRight.y)/2));
			}
			nw->Insert(node);
		}
		else
		{
			if(sw==nullptr)
			{
				sw = make_unique<QuadTree>(Point(TopLeft.x, (TopLeft.y + BottomRight.y) / 2), 
					Point((TopLeft.x+BottomRight.x)/2,BottomRight.y));
			}
			sw->Insert(node);
		}
	}
	else 
	{
		if(node->position.y <= (TopLeft.y+BottomRight.y)/2)
		{
			if(ne==nullptr)
			{
				ne = make_unique<QuadTree>(Point((TopLeft.x + BottomRight.x) / 2, TopLeft.y),
					Point(BottomRight.x, (TopLeft.y + BottomRight.y) / 2));
			}
			ne->Insert(node);
		}
		else
		{
			if(se==nullptr)
			{
				se = make_unique<QuadTree>(
					Point((TopLeft.x + BottomRight.x) / 2,(TopLeft.y+BottomRight.y)/2),
					BottomRight);
			}
			se->Insert(node);
		}
	}

}

void QTTest()
{
	QuadTree q(Point(0,0),Point(8,8));

	unique_ptr<Node>a = make_unique<Node>(Point(1, 1), 1);
	unique_ptr<Node>b = make_unique<Node>(Point(2, 2), 2);
	unique_ptr<Node>c = make_unique<Node>(Point(3, 3), 3);
	unique_ptr<Node>d = make_unique<Node>(Point(4, 4), 4);

	q.Insert(a.get());
	q.Insert(b.get()); 
	q.Insert(c.get());
	q.Insert(d.get());

}
