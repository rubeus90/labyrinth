#include "algo.hh"
#include "superieur.hh"
#include "image_through.hh"
#include "image_if.hh"
#include <assert.h>
#include "traceur.hh"


// void parcour(image2d<int>& depart, image2d<int>& traite){
// 	std::cout << "Les coordonnees des points du chemin : " << std::endl;
	
// 	int x, y = 0;	
// 	//extraire le coordonne de sorti
// 	box2d box = depart.domain();
// 	box2d_iterator<box2d> ite(box);
// 	for (ite.start(); ite.is_valid(); ite.next()){  // marche
// 		if(depart(ite)==3){
// 			x = ite.getX();
// 			y = ite.getY();
// 			break;
// 		}
// 	}
// 	std::cout << "x:" << x << " y: " << y << std::endl;
// 	point2d p(x,y);

// 	int i;
// 	neighb2d_iterator n_ite;
// 	for(i=traite(p); i>=0; i--){
// 		n_ite.center_at(p);
		
// 		for(n_ite.start(); n_ite.is_valid(); n_ite.next()){

// 			if(traite(n_ite) +1 == traite(p)){
// 				p = n_ite;
// 				std::cout << "x:" << p.x_ << " y: " << p.y_ << std::endl;
// 				break;
// 			}
// 		}
// 	}
// }

int main(){
	image2d<int> image2(6,5);
	image2d<point2d> image4(6,5);
	
	image2.fill2d(image2, 0);
	image2(point2d(0,1)) = 2;
	// image2(point2d(0,1)) = 1;
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
	std::cout << "Image d'entree:" << std::endl;
	image2.affiche(image2);

	superieur<int> x(0);

	image_through<image2d<int>, superieur<int> > th(image2, x);
	std::cout << "Image through:" << std::endl;
	th.affiche(th);

	image_if<image2d<int>, image_through<image2d<int>, superieur<int> > > imageTruc(image2, th);
	std::cout << "Image if:" << std::endl;
	imageTruc.affiche(imageTruc);
	

	Traceur<box2d, image2d<point2d> > traceur(image2.domain(),image4);
	image2d<int> image3 = compute_dmap__SPECIFIC(imageTruc, traceur);
	traceur.affiche_coord();
	//image2d<int> image3 = compute_dmap__SPECIFIC(imageTruc);
	//std::cout << "Image sortie de l'algo:" << std::endl;
	//image3.affiche(image3);


	
	//image2d<int> imageFinal = traceur.chemin();
	//std::cout << "Image du chemin pour traverser le labyrinth:" << std::endl;
	//imageFinal.affiche(imageFinal);
	// traceur.affiche2(traceur.chemin(imageTraceur));

	//parcour(image2, image3);
}
