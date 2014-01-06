#ifndef BOX2D_ITERATOR_HH
#define BOX2D_ITERATOR_HH

#include "point2d.hh"
#include <iostream>

template <typename T>
class box2d_iterator{
public:

	box2d_iterator(T& box): box_(box){
		i_ = -1;
		min_x = box_.get_min().x_;
		min_y = box_.get_min().y_;
		max_x = box_.get_max().x_;
		max_y = box_.get_max().y_;
	}

	void start(){
		i_ = 0;	

		x_ = min_x;
		y_ = min_y;
	}

	bool is_valid() const{
		return i_ < (max_x - min_x +1) * (max_y - min_y +1);
	}

	void next(){
		i_++;
		x_ = i_ / (max_y - min_y + 1) + min_x;
		y_ = i_ % (max_y - min_y + 1) + min_y;
	}

	point2d point() const{
		return point2d(x_,y_);
	}

private:
	T box_;
	unsigned i_, x_, y_, max_x, max_y, min_x, min_y;
};

#endif
