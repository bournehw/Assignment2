#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MyShape{
	public:
		void draw();
		void setup();
		void update();

		bool isPointInArea(int x, int y);


		//origin of circles = center,
		//			rect	= top left,
		//			triang  = bottom left
		int x_;
		int y_;
		int width_;
		int height_;
		int radius_;
		Color8u color_;


};

