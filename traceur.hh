#ifndef TRACEUR_HH
#define TRACEUR_HH

#include "image2d.hh"

template <typename D>

class Traceur{
public:
	Traceur(D domain): domain_(domain), image_(6,5) {
	}

	void init(point2d pointInit){
		// std::cout << image(pointInit).x_ << "        HEYYYYYYY" << std::endl;
		image_(pointInit) = 1;
		// image(point2d(0,0)) = point2d(0,0);
	}

	void follow(point2d pointDepart, point2d pointArrive){
		// image_(pointArrive) = pointDepart;
	}

private:
	D domain_;
	image2d<int> image_;
};

#endif