#ifndef BOX2D_ITERATOR_HH
#define BOX2D_ITERATOR_HH

#include "point2d.hh"

template <typename T>
class box2d_iterator{
public:
	box2d_iterator(T& box){
		box_  = &box;
		i_ = -1;
	}
	void start(){
		i_ = 0;
		x_ = box_->get_min().x_;
		y_ = box_->get_min().y_;
	}
	bool is_valid() const{
		return (x_ <= box_->get_max().x_ && y_ <= box_->get_max().y_);
	}
	void next(){
		i_++;
	}

	struct point2d point2d() const{
		int x = i_ / box_->get_max().y_ ;
		int y = i_ % box_->get_max().y_ ;
		return point2d(x,y);
	}

private:
	T* box_;
	unsigned i_, x_, y_;
};

#endif
