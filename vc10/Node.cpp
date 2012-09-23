#include "..\vc10\Node.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Node::Node(int index){
	index_ = index;
	next_ = NULL;
	prev_ = NULL;
	shape_ = NULL;
}