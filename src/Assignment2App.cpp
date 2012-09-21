#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "..\vc10\Linklist.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Assignment2App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void KeyDown(KeyEvent event);
	void update();
	void draw();

	Linklist* circle_list_;

	bool show_message_;
};

void Assignment2App::setup()
{
	circle_list_ = new Linklist();
	show_message_ = true;

}

void Assignment2App::mouseDown( MouseEvent event )
{
	int x = event.getX();
	int y = event.getY();

	if(event.isLeft()){
		//create a new node at the end of the list.

		Linklist::node* new_node;
		//malloc(sizeof(MyShape));
		new_node->shape = (MyShape*)new MyCircle(event.getX(), event.getY(), 25);

		circle_list_->insertBefore(new_node, circle_list_->sentinel_);
	}
	else if(event.isRight())
		circle_list_->bringToFront(x,y);
	
}

void Assignment2App::KeyDown( KeyEvent event )
{
	switch(event.getChar()){
	case '?': show_message_ = !show_message_;
		break;
	case 'r': 
		circle_list_->reverseOrder();
		break;
	default:
		break;
		
	}
}

void Assignment2App::update()
{
}

void Assignment2App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );

	circle_list_->draw();

}

CINDER_APP_BASIC( Assignment2App, RendererGl )
