#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Shape.h"

class Linklist{
  public:
	void setup();
	void update();

	struct node{
		node* next;
		node* prev;
		Shape shape;
	};

	node* sentinel_;

	Linklist();
	Linklist(Shape* shape, node* next, node* prev);
	
	Shape shape_;

	void reverseOrder(Linklist* list);

	void insertAfter(node* target_link);
	void insertBefore(node* target_link);

};

