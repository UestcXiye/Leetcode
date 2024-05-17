#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m = 4,n=4;
	int grid[m][n] = {
		{9, 5, 7, 3},
		{8, 9, 6, 1},
		{6, 7, 14, 3},
		{2, 5, 3, 1}};

	int dp[m][n];
	memset(dp, INT_MAX, sizeof(dp));
	int ans = INT_MIN;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			int minGrid = INT_MAX;
			if (i > 0)
				minGrid = min(minGrid, dp[i - 1][j]);
			if (j > 0)
				minGrid = min(minGrid, dp[i][j - 1]);
			ans = max(ans, grid[i][j] - minGrid);
			dp[i][j] = min(grid[i][j], minGrid);
		}
	cout << ans << endl;

	system("pause");
	return 0;
}
