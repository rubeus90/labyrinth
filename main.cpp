#include "image2d.hh"
#include <iostream>

int main(){
	image2d<int> image(box2d(point2d(1,3), point2d(3,6)));

	// image2d<int> image2(3,6);
	
	image.fill2d(image, 4);
	image.affiche(image);

	// image2.fill2d(image2, 16);
	// image2.affiche(image2);
}