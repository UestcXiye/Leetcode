#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdlib.h>
// 递归生成环形数组的所有可能组合
void generateCircularArrays(int n, int m, std::vector<int> &current, std::unordered_set<std::vector<int>> &uniqueArrays)
{
	if (current.size() == m)
	{
		uniqueArrays.insert(current);
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		// 如果当前元素不在环形数组中，添加当前元素并继续递归生成下一个位置的元素
		if (std::find(current.begin(), current.end(), i) == current.end())
		{
			current.push_back(i);
			generateCircularArrays(n, m, current, uniqueArrays);
			current.pop_back();
		}
	}
}

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
