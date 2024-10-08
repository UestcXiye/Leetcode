#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

vector<vector<int>> res;
vector<int> path;

// 辅函数 - 回溯
void backtrace(vector<int> &arr, int startIdx)
{
	if (path.size() >= 2)
		res.push_back(path);

	unordered_set<int> hashSet;
	for (int i = startIdx; i < arr.size(); i++)
	{
		if ((!path.empty() && arr[i] < path.back()) || hashSet.count(arr[i]))
			continue;

		hashSet.insert(arr[i]);
		path.push_back(arr[i]);
		backtrace(arr, i + 1);
		path.pop_back();
	}
}

int find(vector<int> &arr)
{
	// write code here
	backtrace(arr, 0);
	return res.size();
}

int main()
{
	vector<int> arr = {1, 2, 3};
	cout << find(arr) << endl;

	system("pause");
	return 0;
}