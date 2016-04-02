#include "../util/util.h"
class iset64
{
	private:
		int* _arr;
		void _copy(const iset64& rhs) ;
	public:
		iset64();
		iset64(const int* x,int size);
		~iset64();
		friend iset64 operator+(const int b,const iset64& c);
	   	friend iset64 operator+(const iset64& c,const iset64& d);
		friend iset64 operator+(const iset64& d,const int c);
		iset64& operator+=(const int b);
		iset64& iset64::operator+=(const iset64& a);
		iset64 operator-(const int b) const;
		friend iset64 operator-(const iset64& a, const iset64& b);
		friend iset64 operator-(const int b, const iset64& a);
		iset64& iset64::operator-=(const iset64& a);
		iset64& iset64::operator-=(const int b);
		friend iset64 operator*(const iset64& c,const iset64& d);
		friend iset64 operator*(const iset64& a, const int b);
		friend iset64 operator*(const int b, const iset64& a);
		iset64& iset64::operator*=(const iset64& a);
		iset64& iset64::operator*=(const int b);
		iset64(const iset64& x) ;
		iset64& operator=(const iset64& x) ;
		friend iset64& operator++(iset64& a);
		friend iset64 operator++(iset64& a,int b);
		friend iset64& operator--(iset64& x);
		friend iset64 operator--(iset64& a,int b);
		friend iset64 operator~(const iset64& a);
		friend bool operator==(const iset64& x,const iset64& y);
		friend bool operator!=(const iset64& a, const iset64& b);
		operator bool() const;
		friend ostream& operator<<(ostream& o, const iset64& x) ;
};
