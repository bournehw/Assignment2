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
	void mouseDrag(MouseEvent event);
	void mouseMove(MouseEvent event);
	void mouseUp(MouseEvent event);
	void update();
	void draw();	
	void prepareSettings(Settings* settings);

private:
	Linklist* circle_list_;
	Linklist* grouped_circles_;
	static const int kAppWidth=800;
	static const int kAppHeight=600;
	bool is_moving_nodes_;
	int index_;
	int mouse_x_;
	int mouse_y_;
	Node* mobile_node;

};

void Assignment2App::prepareSettings(Settings* settings){
	settings->setWindowSize(kAppWidth,kAppHeight);
	settings->setResizable(false);
}

void Assignment2App::setup()
{
	circle_list_ = new Linklist();
	grouped_circles_ = new Linklist();
	is_moving_nodes_ = false;
	index_ = 1;
}

void Assignment2App::mouseMove(MouseEvent event){

	mouse_x_ = event.getX();
	mouse_y_ = event.getY();

}

void Assignment2App::mouseDrag(MouseEvent event){

	if(event.isLeftDown() && is_moving_nodes_ && mobile_node != NULL){
		mouseMove(event);
		mobile_node->shape_->x_ = mouse_x_;
		mobile_node->shape_->y_	= mouse_y_;
	}

}

void Assignment2App::mouseDown( MouseEvent event )
{
	if(is_moving_nodes_){
		mobile_node = circle_list_->getNodeAt(event.getX(),event.getY());
	}
	else if(event.isLeft()){
		//create a new node at the end of the list.
		 
		Node* new_node = new Node(index_);
		new_node->shape_ = new MyCircle(event.getX(), event.getY(), 10*index_);

		circle_list_->insertAfter(new_node, circle_list_->sentinel_);
		index_++;
	}
	else if(event.isRight())
		circle_list_->bringToFront(event.getX(),event.getY());
	
}

void Assignment2App::keyDown( KeyEvent event )
{
	switch(event.getChar()){
	case 'm': 
		is_moving_nodes_ = !is_moving_nodes_;
		break;
	case 'r': 
		circle_list_->reverseOrder();
		break;
	case 'a':
		if(mobile_node != NULL)
			mobile_node->shape_->setChild();
	default:
		break;
		
	}
}

void Assignment2App::update()
{

}

void Assignment2App::mouseUp(MouseEvent event){

}

void Assignment2App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );

	circle_list_->draw();

}

CINDER_APP_BASIC( Assignment2App, RendererGl )
