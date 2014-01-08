#include "algo.hh"

int main(){
	image2d<int> image(box2d(point2d(0,0), point2d(3,6)));

	image2d<int> image2(3,6);
	
	image.fill2d(image, 4);
	image.affiche(image);

	image2.fill2d(image2, 0);
	image2(point2d(0,0)) = 1;
	image2.affiche(image2);

	image2d<int> image3 = compute_dmap__SPECIFIC(image2);
	image3.affiche(image3);
}