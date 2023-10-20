/*
 * @lc app=leetcode.cn id=2861 lang=cpp
 *
 * [2861] 最大合金数
 */

// @lc code=start

// 二分查找

class Solution
{
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost)
    {
        int ans = 0;
        int mx = *min_element(stock.begin(), stock.end()) + budget;
        for (vector<int> &com : composition)
        {
            auto check = [&](long long num) -> bool
            {
                long long money = 0;
                for (int i = 0; i < n; i++)
                {
                    if (stock[i] < com[i] * num)
                    {
                        money += (com[i] * num - stock[i]) * cost[i];
                        if (money > budget)
                            return false;
                    }
                }
                return true;
            };
            int left = 0, right = mx + 1;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (check(mid))
                {
                    ans = max(ans, mid);
                    left = mid + 1;
                }
                else
                    right = mid;
            }
        }
        return ans;
    }
};
// @lc code=end
