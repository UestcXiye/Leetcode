/*
 * @lc app=leetcode.cn id=3265 lang=cpp
 *
 * [3265] 统计近似相等数对 I
 */

// @lc code=start
class Solution
{
public:
    int countPairs(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (check(to_string(nums[i]), to_string(nums[j])))
                    ans++;
        return ans;
    }
    // 辅函数
    bool check(string s1, string s2)
    {
        if (stoi(s1) == stoi(s2))
            return true;
        int len2 = s2.length();
        for (int i = 0; i < len2 - 1; i++)
            for (int j = i + 1; j < len2; j++)
            {
                swap(s2[i], s2[j]); // 交换数位
                if (stoi(s1) == stoi(s2))
                    return true;
                else
                {
                    // 记得复原
                    swap(s2[i], s2[j]);
                }
            }
        return false;
    }
};
// @lc code=end
