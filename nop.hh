#ifndef TRACEUR_HH
#define TRACEUR_HH

#include "image2d.hh"

template <typename D>

class Traceur{
public:
	Traceur(D& domain): domain_(domain), image(domain_) {
	}

	void init(point2d pointInit){
		//On met une valeur speciale pour le point de depart
		image(pointInit) = point2d(0, 0);
	}

	void follow(point2d pointDepart, point2d pointArrive){
		image(pointArrive) = pointDepart;
	}

private:
	D& domain_;
	image2d<point2d> image;
};

#endif