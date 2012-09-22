#ifndef _MYCIRCLE_H_
#define _MYCIRCLE_H_

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "..\vc10\MyShape.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MyCircle : MyShape{
	public:
		void draw();

		MyCircle(int x, int y, float radius);
		
		

};

#endif