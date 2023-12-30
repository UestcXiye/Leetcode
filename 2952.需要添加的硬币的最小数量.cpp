/*
 * @lc app=leetcode.cn id=2952 lang=cpp
 *
 * [2952] 需要添加的硬币的最小数量
 */

// @lc code=start
class Solution
{
public:
    int minimumAddedCoins(vector<int> &coins, int target)
    {
        sort(coins.begin(), coins.end());
        // 一开始只能取得 [1, s−1] 的所有数
        int s = 1;
        int index = 0;
        int ans = 0;
        while (s <= target)
        {
            if (index < coins.size() && coins[index] <= s)
            {
                // 可取得的区间从 [1, s−1] 扩展到 [1, s+coins[index]−1]
                s += coins[index];
                index++;
            }
            else
            {
                // 可取得的区间从 [1, s−1] 扩展到 [1, 2s-1]
                s *= 2;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
