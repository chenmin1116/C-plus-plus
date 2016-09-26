#include<iostream>
#include<vector>
#include<cassert>
#include<string>
using namespace std;

template <class T>
struct Triple
{
	size_t  _row;
	size_t  _col;
	T  _value;

	Triple<T>::Triple(size_t row=0,size_t col=0,const T& value=T())
	:_row (row)
	,_col(col)
	,_value(value)
{}
};

template <class T>
class SpareMarix
{
protected:
	size_t _linesize;
	size_t _columnsize;
	vector<Triple<T>> _martix;
	T _invalid;
public:
	 SpareMarix(size_t linesize,size_t columnsize ,const T& invalid)
		 :_linesize(linesize)
		 ,_columnsize(columnsize)
		 ,_invalid(invalid)
	 {}
    SpareMarix(size_t linesize,size_t columnsize, T* martix ,const T& invalid)
		:_linesize(linesize)
		,_columnsize(columnsize)
		,_invalid(invalid)
	{
		for(size_t i=0;i<linesize;i++)
		{
			for(size_t j=0;j<columnsize;j++)
			{
				if(martix[i*columnsize+j] != invalid)
				{
					Triple<T> t(i,j,martix[i*columnsize+j]);
					_martix.push_back(t);
				}
			}
		}
	}
	void Display();
	SpareMarix<T> Ttransport();
	SpareMarix<T> FastTransport();
};

template <class T>
void SpareMarix<T>::Display()
{
	int index=0;
	for(size_t i=0;i<_linesize;i++)
	{
		for(size_t j=0;j<_columnsize;j++)
		{
			if((i == _martix[index]._row) && (j == _martix[index]._col) && (index < _martix.size()))
			{
				cout<<_martix[index]._value<<" ";
							index++;
			}
			else
			{
				cout<<_invalid<<" ";
			}

			
		}
		cout<<endl;
	}
	cout<<endl;

}
template <class T>
SpareMarix<T> SpareMarix<T>:: Ttransport()  //列优先
{
	SpareMarix<int> sm(_columnsize,_linesize,_invalid);
	for(size_t i=0;i<this->_columnsize;i++)  //列
	{
		size_t index = 0;
		while(index < _martix.size())
		{
			if(_martix[index]._col == i)
		  {
			Triple<T> t(_martix[index]._col,_martix[index]._row,_martix[index]._value);
			sm._martix.push_back (t);
		  }
					
		 index++;
		}

	}
	return sm;
}


template<class T>
SpareMarix<T> SpareMarix<T>:: FastTransport()
{
   SpareMarix<int> sm(_columnsize,_linesize,_invalid);
   int *rowCount= new int[_linesize];
   memset(rowCount,0,sizeof(int) * _linesize);
   size_t index=0;
   while(index < _martix.size())
   {
	   rowCount[_martix[index]._col];
	   index++;
   }
   int *rowStart=new int[_linesize];
   rowStart[0] = 0;
   for(size_t i=0;i<_linesize;i++)
   {
	   rowStart[i] =rowStart[i-1]+rowCount[i-1];
   }

   index=0;
   sm._martix.resize(_martix.size());
   while(index<_martix.size())
   {
	   size_t _row = _martix[index]._col;
	   size_t& start = (size_t&)rowStart[_row];

	   Triple<T> t(_martix[index]._col,_martix[index]._row,_martix[index]._value);
	   sm._martix[start] = t;
	   ++start;
	   ++index;
   }
   delete[]  rowCount;
   delete[]  rowStart;
   return sm;

}