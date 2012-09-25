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
 
//Folder structure is totally screwed up. I tried to fix it but it's just too broken.
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "..\vc10\Linklist.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Assignment2App : public AppBasic {
  public:
	void setup();

	//grab the mouse coordinates every time it moves
	void mouseMove(MouseEvent event);

	//scrolling the mousewheel changes the radii of the
	//circles drawn. if you press (i) the radii will toggle
	//increasing or decreasing
	void mouseWheel(MouseEvent event);
		
	//if the 'moving circles' key is toggled (m) and the user has
	//selected a circle, allow them to move it on a left click dra
	void mouseDrag(MouseEvent event);

	//if (m) is toggled, allow user to select circles using left mouse click.
	//Otherwise, left clicks create new circles.
	//Right click always brings the circle to the front.
////selecting a cricle is buggy. It keeps creating a new circle 
////when i want to select one.
	void mouseDown( MouseEvent event );

	// m - toggles 'move circles' functionality
	// r - reverses the list of circles
	// a - adds a child to the selected circle
	// i - toggles radii of circles are increasing or decreasing
	void keyDown(KeyEvent event);

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