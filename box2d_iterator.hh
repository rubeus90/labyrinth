#ifndef BOX2D_ITERATOR_HH
#define BOX2D_ITERATOR_HH

#include "point2d.hh"
#include <iostream>

template <typename T>
class box2d_iterator{
public:

	box2d_iterator(T& box): box_(box){
		i_ = -1;
		max_x = box_.get_max().x_;
		max_y = box_.get_max().y_;
	}

	void start(){
		i_ = 0;	
		x_ = 0;
		y_ = 0;
	}

	bool is_valid() const{
		return i_ < (max_x +1) * (max_y +1) ;
	}

	void next(){
		i_++;
		x_ = i_ / (max_y + 1);
		y_ = i_ % (max_y + 1);
	}

	operator point2d() const{
		return point2d(x_,y_);
	}

	unsigned getX(){
		return x_;
	}
	unsigned getY(){
		return y_;
	}

private:
	T box_;
	unsigned i_, x_, y_, max_x, max_y, min_x, min_y;
};

#endif
