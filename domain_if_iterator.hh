#ifndef DOMAIN_IF_ITERATOR_HH
#define DOMAIN_IF_ITERATOR_HH

#include "point2d.hh"
#include <iostream>

template <typename T>
class domain_if_iterator{
public:

	domain_if_iterator(T& domain): domain_(domain){
		i_ = -1;
		max_x = domain_.get_max().x_;
		max_y = domain_.get_max().y_;
		std::cout << "coucou" << std::endl;
	}

	void start(){
		i_ = 0;	
		x_ = 0;
		y_ = 0;
		while(!domain_.has(point2d(x_,y_))){	
			i_++;	
			x_ = i_ / (max_y + 1);
			y_ = i_ % (max_y + 1);		
			std::cout << "hey" << std::endl;		
		}
		x_ = i_ / (max_y + 1);
		y_ = i_ % (max_y + 1);
		std::cout << "fin start" << std::endl;
	}

	bool is_valid() const{
		return i_ < (max_x +1) * (max_y +1);
	}

	void next(){
		i_++;
		while(!domain_.has(point2d(x_,y_))){	
			i_++;					
		}
		x_ = i_ / (max_y + 1);
		y_ = i_ % (max_y + 1);
		std::cout << "fin next" << std::endl;
	}

	operator point2d() const{
		return point2d(x_,y_);
	}

private:
	T domain_;
	unsigned i_, x_, y_, max_x, max_y;
};

#endif