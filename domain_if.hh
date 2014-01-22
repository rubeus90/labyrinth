#ifndef DOMAIN_IF_HH
#define DOMAIN_IF_HH

#include "point2d.hh"
#include "domain_if_iterator.hh"
#include <iostream>

template <typename D, typename F>

class domain_if{
public:
	typedef domain_if_iterator<domain_if> p_iterator_type;
	// typedef box2d_iterator<domain_if> p_iterator_type;

	domain_if(D d, F& f): d_(d), f_(f){
	}

	// domain_if(const domain_if& domain): d_(d), f_({
	// }

	point2d get_min() const{
		return d_.get_min();
	}

	point2d get_max() const{
		return d_.get_max();
	}

	bool has(const point2d& p){
		return (f_(p) == 1) && (d_.has(p)); 
	}
private:
	D& d_;
	F& f_;
};

#endif