#ifndef ALGO_HH
#define ALGO_HH

#include "image2d.hh"
#include "neighb2d_iterator.hh"
#include <queue>
#include <climits>
#include <iostream>
#include "traceur.hh"

template <typename T, typename N>
image2d<typename T::value_type> compute_dmap__SPECIFIC(T& input, N traceur){

	typename T::domain_type box = input.domain();
	const unsigned max = 4444; 
	image2d<typename T::value_type> image(box);


	typename T::p_iterator_type ite(box);

	//On assigne à tous les points valide la valeur max
	for (ite.start(); ite.is_valid(); ite.next()){
		image(ite) = max;
		traceur.init(ite);
	}

	std::queue<point2d> q;
	neighb2d_iterator n_ite;

	for(ite.start(); ite.is_valid(); ite.next()){
		if(input(ite) == 2){
			image(ite) = 0;
			traceur.setDebut(ite);
			n_ite.center_at(ite);

			for(n_ite.start(); n_ite.is_valid(); n_ite.next()){
				if(box.has(n_ite) and (input(n_ite) == 1)){
					std::cout << "" << std::endl;
					q.push(ite);
					break;
				}
				
			}
		}
	}

	while(not q.empty()){
		point2d p(q.front());
		q.pop();
		n_ite.center_at(p);
		for(n_ite.start(); n_ite.is_valid(); n_ite.next()){
			if(box.has(n_ite) and image(n_ite) == max){
				traceur.follow(p, n_ite);
				image(n_ite) = image(p) + 1;
				q.push(n_ite);
			}
		}
	}

	return image;
}

struct Nope{
	template <typename T>
	void init(point2d pointInit, image2d<T>& image){}
	template <typename T>
	void follow(point2d pointDepart, point2d pointArrive, image2d<T>& image){}
	template <typename T>
	void setDebut(point2d point,image2d<T>& image){}
	template <typename T>
	image2d<int> chemin(image2d<T>& image){}
	template <typename T>
	void affiche_coord(image2d<T>& image){}
	// void affiche2(image2d<int> image){}
};

template <typename T>
image2d<typename T::value_type> compute_dmap__SPECIFIC(T& input){
	Nope nope;
	return compute_dmap__SPECIFIC(input, nope);
}

#endif
