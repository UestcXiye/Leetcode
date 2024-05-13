#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdlib.h>



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