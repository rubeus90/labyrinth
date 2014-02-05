#ifndef TRACEUR_HH
#define TRACEUR_HH

#include "image2d.hh"

template <typename D, typename F>

class Traceur{
public:
	Traceur(D domain): domain_(domain), image_(6,5) {}

	void init(point2d pointInit){
		image_(pointInit) = 4;
	}

	void follow(point2d pointDepart, point2d pointArrive){
		//std::cout << "I give you everything my love !" << std::endl;
		//image_(pointArrive) = pointDepart;
	}

private:
	D domain_;
	F image_;
};

#endif
