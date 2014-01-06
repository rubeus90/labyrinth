#ifndef IMAGE2D_HH
# define IMAGE2D_HH

#include "box2d.hh"
#include <vector>
#include <limits.h>
#include <iostream>

template <typename T>
class image2d
{
public:
  typedef T value_type;
  typedef box2d domain_type;
  typedef typename domain_type::point_type point_type;
  typedef typename domain_type::p_iterator_type p_iterator_type;
  //typedef typename domain_type::n_iterator_type n_iterator_type;

  template <typename U>
  struct width_value_type{
    typedef image2d<U> ret;
  };

  //Constructeurs
  image2d(const domain_type& domain): domain_(domain) {
    nrows_ = domain.get_max().x_ - domain.get_min().x_ +1;
    ncols_ = domain.get_max().y_ - domain.get_min().y_ +1;
    data_.resize(nrows_*ncols_);
  }

  image2d(unsigned nrows, unsigned ncols) : domain_(point2d(0,0), point2d(nrows-1,ncols-1)) {
    nrows_ = nrows;
    ncols_ = ncols;
    data_.resize(nrows_*ncols_);
  }

  //Acceder a la valeur du pixel
  T& operator()(const point_type& p){
    return data_[domain_.get_max().y_ * p.x_ + p.y_];
  }
  T operator()(const point_type& p) const{
    return data_[domain_.get_max().y_ * p.x_ + p.y_];
  }

  //Domaine de l'image
  box2d domain(){
    return domain_;
  }

  //Remplir l'image
  void fill2d(image2d<T>& image, const T& v){
    box2d_iterator<box2d> i(domain_);
    for(i.start(); i.is_valid(); i.next()){
      point2d p = i.point();
      image(p)=v;
      // std::cout << image(p) << std::endl;
    }
  }

  void affiche(image2d<T>& image){
    unsigned min_x = domain_.get_min().x_;
    unsigned min_y = domain_.get_min().y_;

    std::cout << "------------------------" << std::endl << std::endl;
    for(int j=0; j< nrows_; j++){
      for(int i=0; i< ncols_; i++){
        unsigned x = i / ncols_ + min_x;
        unsigned y = i % ncols_ + min_y;
        std::cout << image(point2d(x,y)) << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl << "------------------------" << std::endl;
  }

private:
  domain_type domain_;
  std::vector<T> data_;
  unsigned nrows_, ncols_;
};

#endif
