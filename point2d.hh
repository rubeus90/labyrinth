#ifndef POINT2D_HH
#define POINT2D_HH

struct point2d{
	int x_, y_;
	
	point2d(const unsigned x, const unsigned y){
		x_ = x;
		y_ = y;
	}

	point2d(){
		x_ = 0;
		y_ = 0;
	}
};

#endif
