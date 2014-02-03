#ifndef IMAGE_THROUGH_HH
#define IMAGE_THROUGH_HH

#include "box2d.hh"

template <typename I, typename F>
class image_through{
public:
	typedef typename F::value value_type;
	typedef typename I::domain_type domain_type;
	typedef typename I::p_iterator_type p_iterator_type;

	image_through(I& i, F& f): i_(i), f_(f) {}

	image_through(const box2d& domain) {}

	value_type operator()(const point2d& p){
    	return f_(i_(p));
  	}
  	value_type operator()(const point2d& p) const{
    	return f_(i_(p));
  	}

  	box2d domain(){
	    return i_.domain();
	}

  	void affiche(image_through& image){
  		int nrows_ = i_.domain().get_max().x_ +1;
	    int ncols_ = i_.domain().get_max().y_ +1;

	    std::cout << "------------------------" << std::endl << std::endl;
	    for(int j=0; j< nrows_; j++){
	      for(int i=0; i< ncols_; i++){
	        unsigned x = (i+j*ncols_) / ncols_;
	        unsigned y = (i+j*ncols_) % ncols_;
	        point2d p(x,y);
	        std::cout << image(p) << "\t";
	      }
	      std::cout << std::endl;
	    }
	    std::cout << std::endl << "------------------------" << std::endl;
  }

private:
	I& i_;
	F& f_;
};

#endif
