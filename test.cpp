#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

// 定义一个结构体来保存菜的总喜欢值和菜的编号
struct Dish
{
	int index;
	int totalLike;
};

// 按照 totalLike 降序排列，totalLike 相同则按照 index 升序排列
bool compareDishes(const Dish &a, const Dish &b)
{
	if (a.totalLike == b.totalLike)
		return a.index < b.index;
	return a.totalLike > b.totalLike;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> likes(n, vector<int>(m)); // 喜欢值矩阵
	vector<Dish> dishes(m);						  // 每道菜的总喜欢值和对应的编号

	// 读取喜欢值并计算每道菜的总喜欢值
	for (int i = 0; i < m; ++i)
		dishes[i].index = i;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> likes[i][j];
			dishes[j].totalLike += likes[i][j];
		}
	}

	// 按照总喜欢值从大到小排序
	sort(dishes.begin(), dishes.end(), compareDishes);

	vector<bool> selected(m, false); // 标记哪些菜已经被选过
	int totalSum = 0;

	// 小兴先点三道菜
	for (int i = 0; i < 3; ++i)
	{
		totalSum += dishes[i].totalLike;
		selected[dishes[i].index] = true;
	}

	// 其他每个人依次选择最喜欢的没被点过的菜
	for (int i = 1; i < n; ++i)
	{
		int bestDish = -1;
		int bestLike = -1;
		for (int j = 0; j < m; ++j)
		{
			if (!selected[j] && likes[i][j] > bestLike)
			{
				bestLike = likes[i][j];
				bestDish = j;
			}
		}
		for (int k = 0; k < n; k++)
			totalSum += likes[k][bestDish];
		selected[bestDish] = true;
	}

	// 输出总喜欢值
	cout << totalSum << endl;

	system("pause");
	return 0;
}