#include "image2d.hh"

int main(){
	point2d p1 = point2d(0,0);
    point2d p2 = point2d(2,2);
	image2d<point2d>(box2d(p1,p2));
	image2d<point2d>(2,3);
}
