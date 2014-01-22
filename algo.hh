#ifndef ALGO_HH
#define ALGO_HH

#include "image2d.hh"
#include "neighb2d_iterator.hh"
#include <queue>
#include <climits>
#include <iostream>

// typedef int bool_t;
template <typename T>


// image2d<unsigned> compute_dmap__SPECIFIC(const image2d<bool_t>& input){

image2d<typename T::value_type> compute_dmap__SPECIFIC(T& input){
	typename T::domain_type box = input.domain();
	const unsigned max = UINT_MAX; //D.npoints();
	image2d<typename T::value_type> image(box);


	typename T::p_iterator_type ite(box);
	for (ite.start(); ite.is_valid(); ite.next()){
		image(ite) = max;
	}

	// image.fill2d(image, max);

	std::queue<point2d> q;
	neighb2d_iterator n_ite;

	for(ite.start(); ite.is_valid(); ite.next()){
		std::cout << "were" << std::endl;
		if(input(ite) == 2){
			image(ite) = 0;
			n_ite.center_at(ite);
			for(n_ite.start(); n_ite.is_valid(); n_ite.next()){
				if(box.has(n_ite.point()) and input(n_ite.point()) == false){
					q.push(ite);
					break;
				}
			}
		}
	}

	while(not q.empty()){
		std::cout << "coming" << std::endl;
		point2d p(q.front());
		q.pop();
		n_ite.center_at(p);
		for(n_ite.start(); n_ite.is_valid(); n_ite.next()){
			if(box.has(n_ite.point()) and image(n_ite.point()) == max){
				image(n_ite.point()) = image(p) + 1;
				q.push(n_ite.point());
			}
		}
	}

	return image;
}

#endif