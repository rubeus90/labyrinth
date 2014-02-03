#ifndef DOMAIN_IF_HH
#define DOMAIN_IF_HH

#include "point2d.hh"
#include "domain_if_iterator.hh"
#include <iostream>

template <typename D, typename F>

class domain_if{
public:
	typedef point2d point_type;
	typedef domain_if_iterator<domain_if> p_iterator_type;

	domain_if(D d, F& f): d_(d), f_(f), min_(d_.get_min()), max_(d.get_max()){}


	point2d get_min() const{
		return min_;
	}

	point2d get_max() const{
		return max_;
	}

	bool has(const point2d& p){
		return (f_(p) == 1) && (p.x_ >= min_.x_ && p.y_ >= min_.y_ && p.x_ <= max_.x_ && p.y_ <= max_.y_); 
	}
private:
	D& d_;
	F& f_;
	point_type min_, max_;
};

#endif
