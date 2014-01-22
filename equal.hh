#ifndef EQUAL_HH
#define EQUAL_HH

template <typename T>

struct superieur{
	typedef T value;
	T x_;

	superieur(const T& x): x_(x){}

	bool operator()(const T& i) const{
		if(x_ < i)
			return true;
		else
			return false;
	}
};

#endif
