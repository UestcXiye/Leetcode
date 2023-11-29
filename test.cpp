#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> &vec);

// template <typename T>
// class print
// {
// public:
// 	void operator()(const T &elem)
// 	{
// 		cout << elem << ' ';
// 	}
// };

template <class T>
struct plus
{
	T operator()(const T &x, const T &y) const
	{
		return x + y;
	}
};

template <class T>
struct minus
{
	T operator()(const T &x, const T &y) const
	{
		return x - y;
	}
};

int main()
{
	// int ia[6] = {0, 1, 2, 3, 4, 5};
	// vector<int> iv(ia, ia + 6);
	// for_each(iv.begin(), iv.end(), print<int>());

	plus<int> plus_obj;
	minus<int> minus_obj;

	cout << plus_obj(3, 5) << endl;
	cout << minus_obj(3, 5) << endl;

	// cout << plus<int>()(1, 2) << endl;
	// cout << minus<int>()(1, 2) << endl;

	system("pause");
	return 0;
}

void PrintVector(vector<int> &vec)
{
	for (int &v : vec)
		cout << v << " ";
	cout << endl;
}
