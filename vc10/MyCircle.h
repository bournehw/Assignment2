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

		MyCircle* child_;

		bool isPointInArea(int x, int y);
		void setChild();
		void removeChild();
};

#endif