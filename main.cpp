#include "image2d.hh"
#include <iostream>

int main(){
	
	point2d p1 = point2d(1,3);
    point2d p2 = point2d(3,6);
	image2d<int> image = image2d<int>(box2d(p1,p2));

	image2d<int> image2 = image2d<int>(3,6);
	
	image.fill2d(image, 4);
	image.affiche(image);
}