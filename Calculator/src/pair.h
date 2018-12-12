#ifndef pair_h__
#define pair_h__

#include <avr/io.h>

template <class T, class U> class Pair{
	public:
	T a;
	U b;
	
	Pair(){
		a = T();
		b = U();
	};
	
	Pair(T aa, U bb){
		a = aa;
		b = bb;
	};
	
	Pair(const Pair& p){
		a = p.a;
		b = p.b;
	};
	
};

#endif // pair_h__