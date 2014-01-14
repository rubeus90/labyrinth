#include "algo.hh"
#include "equal.hh"
#include "image_through.hh"
#include <assert.h>


int main(){
	image2d<int> image(box2d(point2d(0,0), point2d(3,6)));

	image2d<int> image2(3,6);
	
	image.fill2d(image, 4);
	image.affiche(image);

	image2.fill2d(image2, 0);
	image2(point2d(0,0)) = 1;
	image2(point2d(1,3)) = 1;
	image2(point2d(1,2)) = 1;
	image2.affiche(image2);

	equal<int> x(3);
	assert(x(3));

	image_through<image2d<int>, equal<int> > th(image2, x);
	th.affiche(th);

	// image_through<image2d<int>, equal<int> > image3 = compute_dmap__SPECIFIC(th);
	// image3.affiche(image3);

	image2d<int> image3 = compute_dmap__SPECIFIC(image2);
	image3.affiche(image3);
}