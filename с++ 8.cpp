#include <iostream>
#include <locale>

using namespace std;

template<typename T, typename S>
class Mat
{
private:
	 T value;
	 S valuee;
public:
	
	Mat(T value, S valuee)
	{
		this->value = value;
		this->valuee = valuee;
	}

	int Func()
	{
		int** ptrarray = new int * [value]; 
			for (int count = 0; count < value; count++)
				ptrarray[count] = new int[valuee];

			for (int count_row = 0; count_row < value; count_row++)
					for (int count_column = 0; count_column < valuee; count_column++)
						ptrarray[count_row][count_column] = 100 ;
			for (int count_row = 0; count_row < value; count_row++)
				for (int count_column = 0; count_column < valuee; count_column++)
					ptrarray[count_row][count_column] -= count_column;
			int z=0, str = valuee, res = 0, l = 0;
			for (int count_row = 0; count_row < value; count_row++)
			{
				for (int count_column = 0; count_column < valuee; count_column++) 
				{
					cout << ptrarray[count_row][count_column] << "   ";
					if (ptrarray[count_row][count_column] > ptrarray[count_row][count_column + 1]) {
						z++;
					}
					if (z == str)
						res++;
				}
				cout << endl;
					z = 0;
			}

				for (int count = 0; count < value; count++)
					delete[]ptrarray[count];
				delete[] ptrarray;

				cout << endl << "Строк: " << res;
		return 0;
	}

};


int main()
{
	setlocale(LC_ALL, "Rus");

	Mat<int, int> c(2, 3);
	c.Func();
}
