#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Linklist.h"
#include "Shape.h"

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

	bool show_message_;
};

void Assignment2App::setup()
{
}

void Assignment2App::mouseDown( MouseEvent event )
{
}

void Assignment2App::KeyDown( KeyEvent event )
{
	switch(event.getChar()){
	case '?': show_message_ = !show_message_;
		break;
	case 'r': 
		for(int i = 0; i < listLength_; i++){

		}

	}
}

void Assignment2App::update()
{
}

void Assignment2App::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( Assignment2App, RendererGl )
