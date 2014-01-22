#include "algo.hh"
#include "equal.hh"
#include "image_through.hh"
#include "image_if.hh"
#include <assert.h>


int main(){
	image2d<int> image2(6,5);
	
	image2.fill2d(image2, 0);
	image2(point2d(0,0)) = 2;
	image2(point2d(0,1)) = 1;
	image2(point2d(0,2)) = 1;
	image2(point2d(0,3)) = 1;
	image2(point2d(1,3)) = 1;
	image2(point2d(2,3)) = 1;
	image2(point2d(2,2)) = 1;
	image2(point2d(2,1)) = 1;
	image2(point2d(3,1)) = 1;
	image2(point2d(4,1)) = 1;
	image2(point2d(4,0)) = 1;
	image2(point2d(5,1)) = 1;
	image2(point2d(5,2)) = 1;
	image2(point2d(5,3)) = 1;
	image2(point2d(5,4)) = 3;
	image2(point2d(3,3)) = 1;
	image2.affiche(image2);

	superieur<int> x(0);

	image_through<image2d<int>, superieur<int> > th(image2, x);
	th.affiche(th);

	image_if<image2d<int>, image_through<image2d<int>, superieur<int> > > imageTruc(image2, th);
	imageTruc.affiche(imageTruc);

	image2d<int> image3 = compute_dmap__SPECIFIC(imageTruc);
	image3.affiche(image3);
}