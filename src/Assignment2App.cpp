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
	void keyDown(KeyEvent event);
	void update();
	void draw();	
	void prepareSettings(Settings* settings);
	

private:
	Linklist* circle_list_;
	static const int kAppWidth=800;
	static const int kAppHeight=600;
	
	int index_;
};

void Assignment2App::prepareSettings(Settings* settings){
	settings->setWindowSize(kAppWidth,kAppHeight);
	settings->setResizable(false);
}

void Assignment2App::setup()
{
	circle_list_ = new Linklist();

	index_ = 1;
}

void Assignment2App::mouseDown( MouseEvent event )
{
	int x = event.getX();
	int y = event.getY();

	if(event.isLeft()){
		//create a new node at the end of the list.
		 
		Node* new_node = new Node(index_);
		new_node->shape_ = new MyCircle(event.getX(), event.getY(), 10*index_);

		circle_list_->insertAfter(new_node, circle_list_->sentinel_);
		index_++;
	}
	else if(event.isRight())
		circle_list_->bringToFront(x,y);
	
}

void Assignment2App::keyDown( KeyEvent event )
{
	switch(event.getChar()){
	case '?': 
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
