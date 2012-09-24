/**
* @file	Assignment2App.cpp
* CSE 274 - Fall 2012
* My solution for HW02.
*
* @author RJ Marcus
* @date 2012-08-27
*
* @note This file is (c) 2012. It is licensed under the
* CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
* which means you are free to use, share, and remix it as long as you
* give attribution. Commercial uses are allowed.
*
* @note This project satisfies goals A (doubly linked circular never empty linkedlist), 
* C (reordering with mouse), D (items moved with mouse), E (reverse order),
* G (transparency), H (indicating depth), I (children objects)
*/

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
	void mouseWheel(MouseEvent event);
	void update();
	void draw();	
	void prepareSettings(Settings* settings);

private:
	Linklist* circle_list_;
	//Linklist* grouped_circles_;
	static const int kAppWidth=800;
	static const int kAppHeight=600;
	bool is_moving_circles_;
	//int index_; //NOTE: I am only using this for debugging purposes. it has no use for the code
	int mouse_x_;
	int mouse_y_;
	int radius_;
	bool radius_is_increasing_;
	MyCircle* active_circle_;

};

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

//grab the mouse coordinates every time it moves
void Assignment2App::mouseMove(MouseEvent event){

	mouse_x_ = event.getX();
	mouse_y_ = event.getY();

}

//scrolling the mousewheel changes the radii of the
//circles drawn. if you press (i) the radii will toggle
//increasing or decreasing
void Assignment2App::mouseWheel(MouseEvent event){
	if(radius_is_increasing_)
		radius_ += abs( event.getWheelIncrement());
	else
		radius_ -= abs( event.getWheelIncrement()) * 5;

	if(radius_ < 1)
		radius_ = 1;
}

//if the 'moving circles' key is toggled (m) and the user has
//selected a circle, allow them to move it on a left click drag
void Assignment2App::mouseDrag(MouseEvent event){

	if(event.isLeftDown() && is_moving_circles_ && active_circle_ != NULL){
		mouseMove(event);
		active_circle_->move(mouse_x_, mouse_y_);
	}

}

//if (m) is toggled, allow user to select circles using left mouse click.
//Otherwise, left clicks create new circles.
//Right click always brings the circle to the front.
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

// m - toggles 'move circles' functionality
// r - reverses the list of circles
// a - adds a child to the selected circle
// i - toggles radii of circles are increasing or decreasing
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
