#include "MyCircle.h"
#include "cinder/Rand.h"

using namespace ci;

MyCircle::MyCircle(int x, int y, float radius){
	this->x_ = x;
	this->y_ = y;
	this->child_ = NULL;
	this->anchor_x_ = x;
	this->anchor_y_ = y;
	this->bound_ = 0;
	this->alpha_level_ = 0;

	//make sure the radius isn't too large
	if(radius > 100)
		this->radius_ = 100;
	else
		this->radius_ = radius;

	//make the shape a random color:
	Rand random;
	random.seed(x);
	this->color_ = Color8u(random.nextInt(0,256),
		random.nextInt(0,256),random.nextInt(0,256));

	this->work_color_ = color_;
}

void MyCircle::setChild(){
	this->child_ = new MyCircle(this->x_, this->y_, this->radius_ / 2);
	//bound should equal the radius of the outer circle minus the radius
	//of the inner circle.
	this->child_->bound_ = abs(this->radius_ - this->child_->radius_);
	
	this->updateAlpha(this->alpha_level_);
}

//void MyCircle::removeChild(){
//	delete this->child_;
//}

void MyCircle::draw(){

	Vec2f* center = new Vec2f(this->x_, this->y_);

	gl::color(this->work_color_);
	gl::drawSolidCircle(*center, this->radius_,0);
	
	if(this->child_ != NULL)
		this->child_->draw();
	
}

//This method checks whether or not a (x,y) point is within
//its bounds and returns a pointer to the circle. (if false return null)
MyCircle* MyCircle::findCircleWithPoint(int x, int y){

	int radius = this->radius_;

	//check that the x-coord of the point is within our circle's width,
	//then check if the y-coord is within the height.
	if((x >= x_ - radius) && (x <= x_ + radius) 
		&& (y >= y_ - radius) && (y <= y_ + radius)){
			
			//if circle has a child, recursively call to see if the point
			//is within the child's circle.
			if(this->child_ != NULL){
				MyCircle* active_child = this->child_->findCircleWithPoint(x,y);
				if(active_child != NULL)
					//you found that the point is contained in a child
					return active_child;
				else
					//no point was contained in a child
					return this;
			}
			else
				return this;
		
	}
	//otherwise return false
		return NULL;

}

//this function moves a circle's coordinates and all of its children.
void MyCircle::move(int x, int y){

	//if the circle is bounded, we must check that its center doesn't
	//go past the bound (outer circle radius) minus its own radius
	if(this->bound_ != 0){
		if((x < this->anchor_x_ + this->bound_ && x > this->anchor_x_ - this->bound_) 
			&& (y < this->anchor_y_ + this->bound_ && y > this->anchor_y_ - this->bound_)){
			this->x_ = x;
			this->y_ = y;
		}
	}
	else{
		this->x_ = x;
		this->y_ = y;
	}

	if(this->child_ != NULL){
		int offset_x = this->child_->x_ - this->child_->anchor_x_;
		int offset_y = this->child_->y_ - this->child_->anchor_y_;

		this->child_->anchor_x_ = x;
		this->child_->anchor_y_ = y;
		this->child_->bound_ = 0; //we have to take of the bounds while we're moving the whole stack

		this->child_->move(x + offset_x, y + offset_y);
		this->child_->bound_ = abs(this->radius_ - this->child_->radius_);
	}
}

void MyCircle::updateAlpha(float alpha_level){

	this->alpha_level_ = alpha_level;

	//this method assumes a white background
	this->work_color_.r = (this->color_.r) * (1-alpha_level) + 255 * alpha_level;
	this->work_color_.g = (this->color_.g) * (1-alpha_level) + 255 * alpha_level;
	this->work_color_.b = (this->color_.b) * (1-alpha_level) + 255 * alpha_level;

	if(this->child_ != NULL)
		this->child_->updateAlpha(alpha_level);

}