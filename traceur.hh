#ifndef TRACEUR_HH
#define TRACEUR_HH

#include "image2d.hh"

template <typename D, typename I>

class Traceur{
public:
	Traceur(D domain,I& image): domain_(domain), image_(image), fin_(0,0), debut_(0,0){} //Obligatoire d'initialiser fin et debut

	void init(point2d pointInit){
		image_(pointInit) = pointInit;
	}

	//Methode qui sert a initialiser le premier
	void setDebut(point2d point){
		debut_.x_ = point.x_;
		debut_.y_ = point.y_;
		image_(debut_)= point2d(-1,-1);
		std::cout << debut_.x_ << " " << debut_.y_ << std::endl;
	}

	void follow(point2d pointDepart, point2d pointArrive){
		image_(pointArrive) = pointDepart;
		fin_.x_ = pointArrive.x_;
		fin_.y_ = pointArrive.y_;
		std::cout << fin_.x_ << " " << fin_.y_ << std::endl;
	}

	image2d<int> chemin(){

		//Création image de sorti
		box2d box = image_.domain();
		image2d<int> final(box);
		final.fill2d(final,0);

		//Remonter le chemin
		//On part du dernier
		point2d p(fin_.x_,fin_.y_);
		
		
		while(p.x_ != -1 && p.y_ != -1){		
			final(p) = 1;
			int x = image_(p).x_;
			int y = image_(p).y_;
			std::cout << x << " " << y << std::endl;
			p.x_ = x;
			p.y_ = y;
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
		std::cout << fin_.x_ << " " << fin_.y_ << std::endl;
		std::cout << debut_.x_ << " " << debut_.y_ << std::endl;
  	}

private:
	D domain_;
	point2d fin_;
	point2d debut_;
	I& image_;
};

#endif
