#ifndef NEIGHB2D_ITERATOR_HH
#define NEIGHB2D_ITERATOR_HH

#include "box2d.hh"

class neighb2d_iterator{
public:

	neighb2d_iterator(): p_(0,0){
		i_ = -1;
		delta_.push_back(point2d(-1,0));
		delta_.push_back(point2d(0,-1));
		delta_.push_back(point2d(1,0));
		delta_.push_back(point2d(0,1));
	}

	void center_at(const point2d& p){
		p_ = p;
	}

	void start(){
		i_ = 0;	
	}

	bool is_valid() const{
		return i_ < 4	;
	}

	void next(){
		i_++;
	}

	operator point2d() const{
		int x = p_.x_ + delta_[i_].x_;
		int y = p_.y_ + delta_[i_].y_;

		//Effet de bord
		x = (x==-1) ? 0 : x;
		y = (y==-1) ? 0 :y;

		return point2d(x,y);
	}

private:
	point2d p_;
	unsigned i_;
	std::vector<point2d> delta_;
};

#endif
