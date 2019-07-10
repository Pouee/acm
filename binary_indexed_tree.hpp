#include "cstring"
/*
	FN comparator
	MAX the size of array
	T the type of operation
*/
template<typename FN,int MAX,typename T>
struct binary_indexed_tree{
	binary_indexed_tree(){
		zero(); // clear all data 
	}
	static T lowbit(const T& x)
	{
		return (x)&(-x);                  
	}
	// start with 1
	void modify(T i, const T& d)
	{
		while (i <= MAX)
		{
			c[i] = f(c[i],d);
			i += lowbit(i);
		}
	}
	// calculate 1-i
	T sum(T i)
	{
		T ret = 0;
		while (i){
			ret = f(c[i], ret);
			i -= lowbit(i);
		}
		return ret;
	}
	// clear all
	void zero()
	{
		memset(c, 0, sizeof(c));
	}
	T c[MAX];
private:
	FN f;
};