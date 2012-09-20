#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Circle.h"

using namespace ci;

Circle::Circle(Vec2f* center, float radius){
	radius_ = radius;
	origin_ = center;
}