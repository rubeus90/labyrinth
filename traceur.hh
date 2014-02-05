#ifndef TRACEUR_HH
#define TRACEUR_HH

#include "image2d.hh"

template <typename D>

class Traceur{
public:
	Traceur(D domain): domain_(domain){}

	template <typename T>
	void init(point2d pointInit, image2d<T>& image){
		image(pointInit) = pointInit;
	}

	void follow(point2d pointDepart, point2d pointArrive){
	}

private:
	D domain_;
};

#endif
