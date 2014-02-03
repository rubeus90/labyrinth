#ifndef IMAGE_IF_HH
#define IMAGE_IF_HH

#include "box2d.hh"
#include "domain_if.hh"
#include <iostream>
template <typename I, typename F>
class image_if{
public:
	typedef typename F::value_type value_type;
	typedef domain_if<typename I::domain_type, F> domain_type;
	typedef typename domain_type::p_iterator_type p_iterator_type;

	image_if(I& i, F& f): i_(i), f_(f), domain_(i.domain(), f_) {}

	image_if(const domain_type& domain) {}

	value_type operator()(const point2d& p){
    	if(f_(p))
    		return i_(p);
    	return 0;
  	}
  	value_type operator()(const point2d& p) const{
    	if(f_(p))
    		return i_(p);
		return 0;
  	}

  	domain_type domain(){
	    return domain_;
	}

  	void affiche(image_if& image){
  		int nrows_ = i_.domain().get_max().x_ +1;
	    int ncols_ = i_.domain().get_max().y_ +1;

	    std::cout << "------------------------" << std::endl << std::endl;
	    for(int j=0; j< nrows_; j++){
	      	for(int i=0; i< ncols_; i++){
		        unsigned x = (i+j*ncols_) / ncols_;
		        unsigned y = (i+j*ncols_) % ncols_;
		        point2d p(x,y);
		        if(f_(p)){
		        	std::cout << image(p) << "\t";
		        }
		        else
		        	std::cout << " " << "\t";
		    }
	     	std::cout << std::endl;
	    }
	    std::cout << std::endl << "------------------------" << std::endl;
  	}

private:
	I& i_;
	F& f_;
	domain_type domain_;
};

#endif
