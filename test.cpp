#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

class Singleton
{
private:
	static Singleton *instance;
	static mutex m;

	Singleton() {}
	Singleton(const Singleton &) = delete;
	Singleton &operator=(const Singleton &) = delete;

public:
	~Singleton() {}
	static Singleton *getInstance()
	{
		if (instance == nullptr)
		{
			m.lock();
			if (instance == nullptr)
			{
				instance = new Singleton();
			}
			m.unlock();
		}
		return instance;
	}
};

Singleton *Singleton::instance = nullptr;
mutex Singleton::m;

void quickSort(vector<int> &arr, int begin, int end)
{
	if (begin >= end)
		return;
	int left = begin, right = end;
	int pivot = arr[left];

	while (left < right)
	{
		while (left < right && arr[right] >= pivot)
			right--;
		if (left < right)
			arr[left] = arr[right];
		while (left < right && arr[left] <= pivot)
			left++;
		if (left < right)
			arr[right] = arr[left];

		if (left == right)
			arr[left] = pivot;

		quickSort(arr, begin, left - 1);
		quickSort(arr, left + 1, end);
	}
}

int m, n;
int ans = 0;

void backtrace(int level, int score, unordered_set<int> s, vector<vector<int>> &grid)
{
	if (level == m)
	{
		ans = max(ans, score);
		return;
	}
	for (int j = 0; j < n; j++)
	{
		if (s.count(grid[level][j]) == 0)
		{
			s.insert(grid[level][j]);
			score += grid[level][j];
			backtrace(level + 1, score, s, grid);
			score -= grid[level][j];
			s.erase(grid[level][j]);
			backtrace(level + 1, score, s, grid);
		}
	}
}

int maxScore(vector<vector<int>> &grid)
{
	m = grid.size(), n = m ? grid[0].size() : 0;
	unordered_set<int> s;
	backtrace(0, 0, s, grid);
	return ans;
}

int main()
{
	string s;
	getline(cin, s);

	// 事先检查
	for (const char &c : s)
	{
		if (!isdigit(c) && c != ' ' && c != '+' && c != '-')
		{
			cout << 0 << endl;
			return 0;
		}
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '+' || s[i] == '-')
			if (s[i - 1] != ' ' || s[i + 1] != ' ')
			{
				cout << 0 << endl;
				return 0;
			}
	}

	istringstream iss(s);
	char op = '+';
	int res = 0;

	while (iss)
	{
		int num;
		char ch;
		// 读取数字
		if (!(iss >> num))
		{
			cout << 0 << endl;
			return 0;
		}
		if (op == '+')
			res += num;
		else if (op == '-')
			res -= num;
		iss >> ch; // 读取操作符
		if (ch == '+' || ch == '-')
			op = ch;
		else
		{
			cout << 0 << endl;
			return 0;
		}
	}
	cout << res << endl;

	system("pause");
	return 0;
}
