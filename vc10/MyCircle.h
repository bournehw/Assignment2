#ifndef _MYCIRCLE_H_
#define _MYCIRCLE_H_

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MyCircle{
	public:
		void draw();

		MyCircle(int x, int y, float radius);

		//origin of circles = center
		int x_;
		int y_;
		int radius_;
		Color8u color_;
		Color8u work_color_;

		//these variables help keep track of the
		//boundaries for children circles.
		int anchor_x_;
		int anchor_y_;
		int bound_;
		float alpha_level_;

		MyCircle* child_;

		MyCircle* findCircleWithPoint(int x, int y);
		void setChild();
	//	void removeChild();
		void move(int x, int y);
		void updateAlpha(float alpha_level);
};

#endif