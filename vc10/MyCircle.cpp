#include "MyCircle.h"

using namespace ci;

MyCircle::MyCircle(int x, int y, float radius){
	this->radius_ = radius;
	this->x_ = x;
	this->y_ = y;
}

void MyShape::setup(){

}

void MyShape::update(){

}

void MyShape::draw(){

	Vec2f* center = new Vec2f(this->x_, this->y_);

	gl::drawSolidCircle(*center, ((MyCircle*)this)->radius_,0);
	gl::color(ColorA(0.3,0.5,0.7,0.5)); //arbitrary color
}

//This method checks whether or not a (x,y) point is within
//its bounds and returns true if it is.
bool MyShape::isPointInArea(int x, int y){

	int radius = ((MyCircle*)this)->radius_;

	//check that the x-coord of the point is within our circle's width,
	//then check if the y-coord is within the height. if so: return true
	if((x >= x_ - radius) && (x <= x_ + radius) 
		&& (y >= y_ - radius) && (y <= y_ + radius))
		return true;

	//otherwise return false
		return false;

}