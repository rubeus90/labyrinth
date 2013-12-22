#ifndef BOX2D_HH
#define BOX2D_HH

#include "box2d_iterator.hh"

class box2d{
public:
	typedef point2d point_type;
	typedef box2d_iterator p_iterator_type;

	box2d(const point2d& min, const point2d& max){
		min_ = min;
		max_ = max;
	}

	box2d(const box2d& b){
		min_ = b.min();
		max_ = b.max();
	}

	point2d get_min(){
		return min_;
	}

	point2d get_max(){
		return max_;
	}

private:
	point_type min_, max_;
};

#endif