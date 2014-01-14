#ifndef EQUAL_HH
#define EQUAL_HH

template <typename T>

struct equal{
	typedef T value;
	T x_;

	equal(const T& x): x_(x){}

	bool operator()(const T& i) const{
		if(x_ == i)
			return true;
		else
			return false;
	}
};

#endif
