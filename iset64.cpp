#include "iset64.h"
iset64::iset64()
{
	_arr=new int [64];
	for(int i=0;i<64;i++)
	{
		_arr[i]=-99;
	}
	
}
iset64::iset64(const int* x,int size)
{
	_arr=new int [64];
	for(int i=0;i<64;i++)
	{
		_arr[i]=-99;
	}
	for(int j=0;j<size;j++)
	{
		_arr[(x[j])]=x[j];
	}

}
iset64::~iset64()
{
	delete [] _arr;
}
iset64 operator+(const int b,const iset64& d) 
{
	iset64 t(d) ;
	t._arr[b]=b ;
	return t ;
}
iset64 operator+(const iset64& d,const int c)
{
	iset64 t(d);
	t._arr[c]=c;
	return t;
}
iset64 operator+(const iset64& c,const iset64& d)
{
	iset64 x(c);
	for(int i=0;i<64;i++)
	{
		if(c._arr[i]!=-99 || d._arr[i]!=-99)
		{
			x._arr[i]=i;
		}
	}
	return x;
}
iset64 operator*(const iset64& c,const iset64& d)
{
	iset64 x;
	for(int i=0;i<64;i++)
	{
		if(c._arr[i]!=-99 && d._arr[i]!=-99)
		{
			if(c._arr[i] == d._arr[i])
			{
				x._arr[i]=i;
			}
		}
	}
	return x;
}
iset64 operator*(const iset64& a, const int b)
{
	iset64 x(a);
	for(int i=0;i<64;i++)
	{
		if(x._arr[i]==b)
		{
			x._arr[i]=b;
		}
		else
		{
			x._arr[i]=-99;
		}
	}
	return x;
}
iset64 operator*(const int b, const iset64& a)
{
	iset64 x(a);
	for(int i=0;i<64;i++)
	{
		if(x._arr[i]==b)
		{
			x._arr[i]=b;
		}
		else
		{
			x._arr[i]=-99;
		}
	}
	return x;
}
iset64& iset64::operator*=(const iset64& a)
{
	for(int i=0;i<64;i++)
	{
		if(_arr[i]==a._arr[i])
		{
			_arr[i]=a._arr[i];
		}
		else
		{
			_arr[i]=-99;
		}
	}
	return *this;
}
iset64& iset64::operator*=(const int b)
{
	for(int i=0;i<64;i++)
	{
		if(_arr[i]!=b)
		{
			_arr[i]=-99;
		}
	}
	return *this;
}
bool operator==(const iset64& a, const iset64& b)
{

	int count=0;
	for(int i=0;i<64;i++)
	{
		if((a._arr[i]!=-99) ||( b._arr[i]!=-99))
		{
			if(a._arr[i]!=b._arr[i])
			{
				return false;
			}
		}
	}
	return true;
}
iset64& operator++(iset64& x)
{
	iset64 t(x);
	for(int i=63;i>=0;i--)
	{
		if(t._arr[i]!=-99)
		{
			if(i==63)
			{
				x._arr[0]=0;
				x._arr[i]=-99;
			}
			else
			{
				x._arr[i+1]=i+1;
				x._arr[i]=-99;
			}
		}
	}
	return x;
}
iset64 operator++(iset64& a,int b)
{
		iset64 t(a);
		for(int i=63;i>=0;i--)
		{
			if(t._arr[i]!=-99)
			{
			if(i==63)
			{
				a._arr[0]=0;
				a._arr[i]=-99;
			}
			else
			{
				a._arr[i+1]=i+1;
				a._arr[i]=-99;
			}
		}
	}
	return t;

}
iset64& operator--(iset64& x)
{
	iset64 t(x);
	for(int i=63;i>=0;i--)
	{
		if(t._arr[i]!=-99)
		{
			if(i==0)
			{
				x._arr[63]=63;
				x._arr[i]=-99;
			}
			else
			{
				x._arr[i-1]=i-1;
				x._arr[i]=-99;
			}
		}
	}
	return x;
}
iset64 operator--(iset64& a,int b)
{
		iset64 t(a);
		for(int i=63;i>=0;i--)
		{
			if(t._arr[i]!=-99)
			{
			if(i==0)
			{
				a._arr[63]=63;
				a._arr[i]=-99;
			}
			else
			{
				a._arr[i-1]=i-1;
				a._arr[i]=-99;
			}
		}
	}
	return t;
}
bool operator!=(const iset64& a, const iset64& b)
{
	for(int i=0;i<64;i++)
	{
		if(a._arr[i]!=-99 || b._arr[i]!=-99)
		{
			if(a._arr[i]!=b._arr[i])
			{
				return true;
				break;
			}
		}
	}
	return false;
}
iset64& iset64::operator+=(int b) 
{
	_arr[b]=b;
	return *this ;
 }
iset64& iset64::operator+=(const iset64& a)
{
	for(int i=0;i<64;i++)
	{
		if(a._arr[i]!=-99)
		{
			_arr[i]=i;
		}
	}
	return *this;
}
iset64 iset64::operator-(int b) const
{
	iset64 t(*this);
	t._arr[b]=-99;
	return t;
}
iset64 operator-(const iset64& a, const iset64& b)
{
	iset64 t;
	for(int i=0;i<64;i++)
	{
		if(a._arr[i]!=-99 || b._arr[i]!=-99)
		{
			if(a._arr[i]==b._arr[i])
			{
				t._arr[i]=-99;
			}
			else
			{
				t._arr[i]=i;
			}
		}
	}
	return t;
}
iset64 operator-(const int b, const iset64& a)
{
	iset64 t(a);
	t._arr[b]=-99;
	return t;
}
iset64& iset64::operator-=(const iset64& a)
{
	for(int i=0;i<64;i++)
	{
		if(_arr[i]!=-99 && a._arr[i]!=-99)
		{
			_arr[i]=-99;
		}
		else if(a._arr[i]!=-99)
		{
			_arr[i]=i;
		}
	}
	return *this;
}
iset64& iset64::operator-=(const int b)
{
	for(int i=0;i<64;i++)
	{
		if(_arr[i]!=-99 && b==i)
		{
			_arr[i]=-99;
		}
	}
	return *this;
}
iset64& iset64::operator=(const iset64& s)
{
if (this != &s) {
 
	_copy(s) ;
 }
 return *this ;
}
iset64::iset64(const iset64& s) {
	 _arr=new int [64];
	 _copy(s) ;
}

void iset64::_copy(const iset64& s) {

	for(int i=0;i<64;i++)
	{
		_arr[i] = s._arr[i] ;
	}
}
ostream& operator<<(ostream& o, const iset64& x)
{
	bool isEmpty=true;
	o<<"{";
	for(int i=0;i<64;i++)
	{
		if(x._arr[i]!=-99)
		{
			isEmpty=false;
			o << x._arr[i] ;
			o << ",";
		}
	}
	if(isEmpty==true)
	{
		o<<" ";
	}
	o<<"}";
	return o ;
}
iset64 operator~(const iset64& a)
{
	iset64 t(a);
	for(int i=0;i<64;i++)
	{
		if(a._arr[i]!=-99)
		{
			t._arr[i]=-99;
		}
		else if(a._arr[i]==-99)
		{
			t._arr[i]=i;
		}
	}
	return t;
}
iset64::operator bool() const
{
	bool set=false;
	for(int i=0;i<64;i++)
	{
		if(_arr[i]!=-99)
		{
			set=true;
			break;
		}
	}
	return set;
}