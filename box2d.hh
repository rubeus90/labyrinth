#ifndef BOX2D_HH
#define BOX2D_HH

#include "box2d_iterator.hh"
// #include "point2d.hh"

class box2d{
public:
	typedef point2d point_type;
	typedef box2d_iterator<box2d> p_iterator_type;

	box2d(const point2d& min, const point2d& max){
		min_ = min;
		max_ = max;
	}

	box2d(const box2d& b){
		min_ = b.get_min();
		max_ = b.get_max();
	}

	point2d get_min() const{
		return min_;
	}

	point2d get_max() const{
		return max_;
	}

private:
	point_type min_, max_;
};

#endif
