#ifndef IMAGE2D_HH
# define IMAGE2D_HH

#include "box2d.hh"
// #include "point2d.hh"
#include <vector>

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
    data_[(domain_.get_max().x_ - domain_.get_min().x_) * (domain_.get_max().y_ - domain_.get_min().y_)];
  }

  image2d(unsigned nrows, unsigned ncols) : domain_(point2d(0,0), point2d(nrows,ncols)) {
    data_[nrows*ncols];
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
  template <typename point2d>
  void fill2d(image2d<point2d>& image, const T& v){
    box2d_iterator<point2d> i(image.domain());
    for(i.start(); i.valid(); i.next()){
      point2d p = i.point();
      image(p) = v;
    }
  }

private:
  domain_type domain_;
  std::vector<T> data_;
  };

#endif
