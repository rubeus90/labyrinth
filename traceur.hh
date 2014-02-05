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

	template <typename T>
	void follow(point2d pointDepart, point2d pointArrive, image2d<T>& image){
		image(pointArrive) = pointDepart;
	}

	template <typename T>
  	void affiche(image2d<T>& image){
  		int nrows_ = image.domain().get_max().x_ +1;
	    int ncols_ = image.domain().get_max().y_ +1;

	    std::cout << "------------------------" << std::endl << std::endl;
	    for(int j=0; j< nrows_; j++){
	      	for(int i=0; i< ncols_; i++){
		        unsigned x = (i+j*ncols_) / ncols_;
		        unsigned y = (i+j*ncols_) % ncols_;
		        point2d p(x,y);
		       	std::cout << image(p).x_ << " " << image(p).y_ << "\t";
		    }
	     	std::cout << std::endl;
	    }
	    std::cout << std::endl << "------------------------" << std::endl;
  	}

private:
	D domain_;
};

#endif
