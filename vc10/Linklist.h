#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "..\vc10\MyCircle.h"

class Linklist{
  public:
	void setup();
	void update();
	void draw();

	struct node{
		node* next;
		node* prev;
		MyShape* shape;
	};

	node* sentinel_;

	Linklist();

	void reverseOrder();
	void bringToFront(int x, int y);
	void insertAfter(node* new_link, node* target_link);
	void insertBefore(node* new_link, node* target_link);
	node* removeNode(node* target_node);

};

