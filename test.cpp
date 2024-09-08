#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <cstdlib>
using namespace std;

// 回溯算法
void backtrack(int N, vector<int> &current, vector<int> &best, int &minCount, int start)
{
	int currentSum = 0;
	for (int num : current)
	{
		currentSum += num * num * num;
	}

	if (currentSum > N)
		return;
	if (currentSum == N)
	{
		if (current.size() < minCount)
		{
			minCount = current.size();
			best = current;
		}
		return;
	}

	for (int i = start; i * i * i <= N; ++i)
	{
		current.push_back(i);
		backtrack(N, current, best, minCount, i);
		current.pop_back();
	}
}

vector<int> findMinKIntegers(int N)
{
	vector<int> best, current;
	int minCount = INT_MAX;
	backtrack(N, current, best, minCount, 1);
	return best;
}

int main()
{
	int N;
	cin >> N;

	vector<int> result = findMinKIntegers(N);

	for (int num : result)
	{
		cout << num << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
