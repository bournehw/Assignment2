#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Shape.h"

using namespace ci;

class Circle : Shape{
	public:
		void setup();
		void update();
		void draw();

		Circle(Vec2f* center, float radius);
		
		Vec2f* origin_;
		float radius_;
		
		Color8u color_;

};