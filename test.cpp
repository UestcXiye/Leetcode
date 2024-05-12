#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdlib.h>

class Solution
{
public:
	int maxPointsInsideSquare(vector<vector<int>> &points, string s)
	{
		vector<pair<int, char>> combined;
		for (int i = 0; i < points.size(); i++)
		{
			int mx = max(abs(points[i][0]), abs(points[i][1]));
			combined.push_back(mx, s[i]);
		}
		sort(combined.begin(), combined.end(),
			 [&](const pair<int, char> &p1, const pair<int, char> &p2)
			 {
				 return p1.first < p2.first;
			 });
		unordered_set<char> set;
		int bound = 0, ans = 0;
		for (auto &entry : combined)
		{
			if (entry.first > k)
			{
				k = entry.first;
				ans = set.size();
			}
			if (set.count(entry.second) == 0)
				set.push(entry.second);
			else
				break;
		}
		return ans;
	}
};

int main()
{
	int n, m;

	std::cin >> n;

	std::cin >> m;

	std::vector<int> current;
	std::unordered_set<std::vector<int>> uniqueArrays;

	// 生成环形数组的所有可能组合
	generateCircularArrays(n, m, current, uniqueArrays);

	// 输出不同的环形数组数量
	std::cout << "有 " << uniqueArrays.size() << " 种不同的环形数组。" << std::endl;
	system("pause");
	return 0;
}
