#ifndef _NODE_H_
#define _NODE_H_

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "..\vc10\MyCircle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Node{
  public:
	void setup();
	void update();
	void draw();

	Node* next_;
	Node* prev_;
	MyCircle* shape_;
	int index_;

	Node(int index);

};

#endif