/*
 * @lc app=leetcode.cn id=2511 lang=cpp
 *
 * [2511] 最多可以摧毁的敌人城堡数目
 */

// @lc code=start
class Solution
{
public:
    int captureForts(vector<int> &forts)
    {
        int n = forts.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (forts[i] == 1)
            {
                // 向左遍历
                int left = i - 1;
                while (left >= 0 && forts[left] == 0)
                    left--;
                if (left >= 0 && forts[left] == -1)
                    ans = max(ans, i - left - 1);
                // 向右遍历
                int right = i + 1;
                while (right < n && forts[right] == 0)
                    right++;
                if (right < n && forts[right] == -1)
                    ans = max(ans, right - i - 1);
            }
        }
        return ans;
    }
};
// @lc code=end
