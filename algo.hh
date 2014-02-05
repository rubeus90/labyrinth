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
	image2d<point2d> imageTraceur(6,5);


	typename T::p_iterator_type ite(box);

	//On assigne à tous les points valide la valeur max
	for (ite.start(); ite.is_valid(); ite.next()){
		image(ite) = max;
		traceur.init(ite, imageTraceur);
	}

	std::queue<point2d> q;
	neighb2d_iterator n_ite;

	for(ite.start(); ite.is_valid(); ite.next()){
		if(input(ite) == 2){
			image(ite) = 0;
			traceur.setDebut(ite,imageTraceur);
			n_ite.center_at(ite);

			for(n_ite.start(); n_ite.is_valid(); n_ite.next()){
				if(box.has(n_ite) and (input(n_ite) == 1)){
					std::cout << "" << std::endl;
					q.push(ite);
					point2d pointArrive = n_ite;
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
				traceur.follow(p, n_ite, imageTraceur);
				image(n_ite) = image(p) + 1;
				q.push(n_ite);
			}
		}
	}

	traceur.affiche(imageTraceur);
	traceur.affiche2(traceur.chemin(imageTraceur));

	return image;
}

struct Nope{
	void init(point2d point){}
	void follow(point2d point1,point2d point2){}
};

template <typename T>
image2d<typename T::value_type> compute_dmap__SPECIFIC(T& input){
	Nope nope;
	return compute_dmap__SPECIFIC(input, nope);
}

#endif
