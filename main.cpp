#include "algo.hh"
#include "superieur.hh"
#include "image_through.hh"
#include "image_if.hh"
#include <assert.h>
#include "traceur.hh"

int main(){
	image2d<int> image(6,5);
	
	image.fill2d(image, 0);
	image(point2d(0,1)) = 2;
	image(point2d(0,2)) = 1;
	image(point2d(0,3)) = 1;
	image(point2d(1,3)) = 1;
	image(point2d(2,3)) = 1;
	image(point2d(2,2)) = 1;
	image(point2d(2,1)) = 1;
	image(point2d(3,1)) = 1;
	image(point2d(4,1)) = 1;
	image(point2d(4,0)) = 1;
	image(point2d(5,1)) = 1;
	image(point2d(5,2)) = 1;
	image(point2d(5,3)) = 1;
	image(point2d(5,4)) = 3;
	image(point2d(3,3)) = 1;
	std::cout << "Image d'entree:" << std::endl;
	image.affiche(image);

	// Prédicat
	superieur<int> x(0);

	//Création image through
	image_through<image2d<int>, superieur<int> > imageThrough(image, x);
	std::cout << "Image through:" << std::endl;
	imageThrough.affiche(imageThrough);

	//Création image_if
	image_if<image2d<int>, image_through<image2d<int>, superieur<int> > > imageIf(image, imageThrough);
	std::cout << "Image if:" << std::endl;
	imageIf.affiche(imageIf);
	

	//Traceur
	image2d<point2d> img(6,5);
	Traceur<image2d<point2d> > traceur(img);

	//Algo
	image2d<int> imageAlgo = compute_dmap__SPECIFIC(imageIf,traceur);
	std::cout << "Image produit par l'algo:" << std::endl;
	imageAlgo.affiche(imageAlgo);

	//On retrace le chemin dans le labyrinth
	traceur.affiche_coord();
	image2d<int> imageTraceur = traceur.chemin();
	std::cout << "Image du chemin:" << std::endl;
	imageTraceur.affiche(imageTraceur);
}
