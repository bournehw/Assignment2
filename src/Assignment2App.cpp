#include "Assignment2App.hpp"

//borrowed this from Dr. Brinkman:
void Assignment2App::prepareSettings(Settings* settings){
	settings->setWindowSize(kAppWidth,kAppHeight);
	settings->setResizable(false);
}

void Assignment2App::setup()
{
	circle_list_ = new Linklist();
	//grouped_circles_ = new Linklist();
	active_circle_ = NULL;
	is_moving_circles_ = false;
	radius_is_increasing_ = true;
	radius_ = 25;
	//index_ = 1;
}

void Assignment2App::mouseMove(MouseEvent event){
	mouse_x_ = event.getX();
	mouse_y_ = event.getY();
}

void Assignment2App::mouseWheel(MouseEvent event){
	if(radius_is_increasing_)
		radius_ += abs((int)(event.getWheelIncrement()));
	else
		radius_ -= abs((int)(event.getWheelIncrement()))*5;

	if(radius_ < 1)
		radius_ = 1;
}

void Assignment2App::mouseDrag(MouseEvent event){
	if(event.isLeftDown() && is_moving_circles_ && active_circle_ != NULL){
		mouseMove(event);
		active_circle_->move(mouse_x_, mouse_y_);
	}
}

void Assignment2App::mouseDown( MouseEvent event )
{
	if(is_moving_circles_ && event.isLeft()){
		active_circle_ = circle_list_->getCircleAt(event.getX(),event.getY());
	}
	else if(event.isLeft()){
		//create a new node at the end of the list.
		 
		Node* new_node = new Node();
		new_node->shape_ = new MyCircle(event.getX(), event.getY(), radius_);

		circle_list_->insertAfter(new_node, circle_list_->sentinel_);
		circle_list_->updateAlpha();
	}
	else if(event.isRight()){
		circle_list_->bringToFront(event.getX(),event.getY());
		circle_list_->updateAlpha();
	}
}

void Assignment2App::keyDown( KeyEvent event )
{
	switch(event.getChar()){
	case 'm': 
		is_moving_circles_ = !is_moving_circles_;
		break;
	case 'r': 
		circle_list_->reverseOrder();
		circle_list_->updateAlpha();
		break;
	case 'a':
		if(active_circle_ != NULL)
			active_circle_->setChild();
	case 'i':
		radius_is_increasing_ = !radius_is_increasing_;
	default:
		break;	
	}
}

void Assignment2App::update()
{
	//umm... 
}

void Assignment2App::draw()
{
	// clear out the window with black
	gl::clear( Color( 1, 1, 1 ) );

	circle_list_->draw();

}

CINDER_APP_BASIC( Assignment2App, RendererGl )
