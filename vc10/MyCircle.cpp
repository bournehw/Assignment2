#include "MyCircle.h"
#include "cinder/Rand.h"

using namespace ci;

MyCircle::MyCircle(int x, int y, float radius){
	this->radius_ = radius;
	this->x_ = x;
	this->y_ = y;

	//make the shape a random color:
	Rand random;
	random.seed(x);
	this->color_ = Color8u(random.nextInt(0,256),
		random.nextInt(0,256),random.nextInt(0,256));
}

void MyCircle::draw(){

	Vec2f* center = new Vec2f(this->x_, this->y_);

	gl::color(this->color_);
	gl::drawSolidCircle(*center, this->radius_,0);
	
}

//This method checks whether or not a (x,y) point is within
//its bounds and returns true if it is.
bool MyCircle::isPointInArea(int x, int y){

	int radius = this->radius_;

	//check that the x-coord of the point is within our circle's width,
	//then check if the y-coord is within the height. if so: return true
	if((x >= x_ - radius) && (x <= x_ + radius) 
		&& (y >= y_ - radius) && (y <= y_ + radius))
		return true;

	//otherwise return false
		return false;

}