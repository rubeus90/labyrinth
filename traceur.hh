#ifndef TRACEUR_HH
#define TRACEUR_HH

#include "image2d.hh"

template <typename I>

class Traceur{
public:
	typedef typename I::point_type point_type;

	Traceur(I& image): image_(image), fin_(0,0), debut_(0,0){} //Obligatoire d'initialiser fin et debut

	//Initialisation des valeurs de l'image
	void init(point_type point){
		//On initialise l'image		
		point2d p(0,0);
		image_.fill2d(image_, p);

		//On marque le point de départ
		debut_ = point;
		image_(debut_)= point2d(-1,-1);
	}

	//Remplissage de l'image avec les coordonnées du précédent
	void follow(point_type pointDepart,point_type pointArrive){
		image_(pointArrive) = pointDepart;
		fin_ = pointArrive;
	}

	//Créé l'image solution
	typename I::image_traceur_type chemin(){
		//Création image de sorti
		typename I::domain_type box = image_.domain();
		image2d<int> final(box);
		final.fill2d(final,0);

		point2d p(fin_.x_,fin_.y_);	
		
		while(p.x_ != -1 && p.y_ != -1){		
			final(p) = 1;
			p = image_(p);
		}
		
		return final;
	}

	//Methode pour afficher une image contenant des point2d
  	void affiche_coord(){
  		int nrows_ = image_.domain().get_max().x_ +1;
	    int ncols_ = image_.domain().get_max().y_ +1;

	    std::cout << "Image des coordonnees des points precedents:" << std::endl;
	    std::cout << "------------------------" << std::endl << std::endl;
	    for(int j=0; j< nrows_; j++){
	      	for(int i=0; i< ncols_; i++){
		        unsigned x = (i+j*ncols_) / ncols_;
		        unsigned y = (i+j*ncols_) % ncols_;
		        point2d p(x,y);
		       	std::cout << image_(p).x_ << " " << image_(p).y_ << "\t";
		    }
	     	std::cout << std::endl;
	    }
	    std::cout << std::endl << "------------------------" << std::endl;
  	}

private:
	point_type fin_, debut_;
	I& image_;
};

#endif
