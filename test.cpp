#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(vector<int> &vec);

int getFirstTargetIndex(vector<int> &nums, int target)
{
	if (nums.empty())
		return -1;
	int left = 0, right = nums.size() - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
		{
			if ((mid > 0 && nums[mid - 1] != target) || mid == 0)
				return mid;
			else
				right = mid - 1;
		}
		else if (nums[mid] > target)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}

int main()
{
	cout << "hello world" << endl;
	vector<int> arr = {2, 3, 3, 4, 5};
	int target = 3;
	int firstIdx = getFirstTargetIndex(arr, target);
	cout << firstIdx << endl;

	system("pause");
	return 0;
}

void PrintVector(vector<int> &vec)
{
	for (int &v : vec)
		cout << v << " ";
	cout << endl;
}

