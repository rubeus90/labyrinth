#ifndef TRACEUR_HH
#define TRACEUR_HH

#include "image2d.hh"

template <typename I>

class Traceur{
public:
	typedef typename I::point_type point_type;

	Traceur(I& image): image_(image), fin_(0,0), debut_(0,0){} //Obligatoire d'initialiser fin et debut

	void init(point_type pointInit){
		image_(pointInit) = pointInit;
	}

	//Initialisation des valeurs de l'image
	void setDebut(point_type point){
		debut_ = point;
		image_(debut_)= point2d(-1,-1);
	}

	//Remplissage de l'image avec les coordonnées du précédent
	void follow(point_type pointDepart,point_type pointArrive){
		image_(pointArrive) = pointDepart;
		fin_ = pointArrive;
	}

	//Créé l'image solution
	image2d<int> chemin(){
		//Création image de sorti
		box2d box = image_.domain();
		image2d<int> final(box);
		final.fill2d(final,0);

		point2d p(fin_.x_,fin_.y_);	

		while(p.x_ != -1 && p.y_ != -1){		
			final(p) = 1;
			int x = image_(p).x_;
			int y = image_(p).y_;
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
	point2d fin_;
	point2d debut_;
	I& image_;
};

#endif
