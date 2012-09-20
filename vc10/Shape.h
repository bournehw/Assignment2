#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

class Shape{
	public:
		
		//origin of circles = center,
		//			rect	= top left,
		//			triang  = bottom left
		Vec2f origin_;

		Color8u color_;
};

