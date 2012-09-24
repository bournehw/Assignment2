#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "..\vc10\MyCircle.h"
#include "..\vc10\Node.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Linklist{
  public:
	void setup();
	void update();
	void draw();

	Node* sentinel_;

	Linklist();

	void reverseOrder();
	void bringToFront(int x, int y);
	void insertAfter(Node* new_link, Node* target_link);
	void insertBefore(Node* new_link, Node* target_link);
	Node* removeNode(Node* target_node);
	MyCircle* getCircleAt(int x, int y);
	Node* getNodeAt(int x, int y);
	void updateAlpha();

};

#endif