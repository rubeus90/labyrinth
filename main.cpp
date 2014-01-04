#include "image2d.hh"
#include <iostream>

int main(){
	image2d<int>(2,3);
	point2d p1 = point2d(0,0);
    point2d p2 = point2d(2,2);
	image2d<int> image = image2d<int>(box2d(p1,p2));
	
	image.fill2d(image, 1);

	// std::cout << image(point2d(0,0)) << std::endl;
}