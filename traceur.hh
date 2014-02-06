#ifndef TRACEUR_HH
#define TRACEUR_HH

#include "image2d.hh"

template <typename D>

class Traceur{
public:
	Traceur(D domain): domain_(domain), fin_(0,0), debut_(0,0){} //Obligatoire d'initialiser fin et debut

	template <typename T>
	void init(point2d pointInit, image2d<T>& image){
		image(pointInit) = pointInit;
	}

	//Methode qui sert a initialiser le premier
	template <typename T>
	void setDebut(point2d point,image2d<T>& image){
		debut_.x_ = point.x_;
		debut_.y_ = point.y_;
		image(debut_)= point2d(-1,-1);
	}

	template <typename T>
	void follow(point2d pointDepart, point2d pointArrive, image2d<T>& image){
		image(pointArrive) = pointDepart;
		fin_ = pointArrive;
	}

	template <typename T>
	image2d<int> chemin(image2d<T>& image){

		//Création image de sorti
		box2d box = image.domain();
		image2d<int> final(box);
		final.fill2d(final,0);

		//Remonter le chemin
		//On part du dernier
		point2d p(fin_.x_,fin_.y_);

		
		while(p.x_ != -1 && p.y_ != -1){		
			final(p) = 1;
			int x = image(p).x_;
			int y = image(p).y_;
			p.x_ = x;
			p.y_ = y;
		}
		
		return final;
	}

	//Methode pour afficher une image contenant des point2d
	template <typename T>
  	void affiche_coord(image2d<T>& image){
  		int nrows_ = image.domain().get_max().x_ +1;
	    int ncols_ = image.domain().get_max().y_ +1;

	    std::cout << "Image des coordonnees des points precedents:" << std::endl;
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

	//Methode pour afficher image de fin
	void affiche2(image2d<int> image){
  		int nrows_ = image.domain().get_max().x_ +1;
	    int ncols_ = image.domain().get_max().y_ +1;

	    std::cout << "Image du chemin pour traverser le labyrinth:" << std::endl;
	    std::cout << "------------------------" << std::endl << std::endl;
	    for(int j=0; j< nrows_; j++){
	      	for(int i=0; i< ncols_; i++){
		        unsigned x = (i+j*ncols_) / ncols_;
		        unsigned y = (i+j*ncols_) % ncols_;
		        point2d p(x,y);
		        std::cout << image(p) << "\t";
		    }
	     	std::cout << std::endl;
	    }
	    std::cout << std::endl << "------------------------" << std::endl;
  	}

private:
	D domain_;
	point2d fin_;
	point2d debut_;
};

#endif
