/*
 * @lc app=leetcode.cn id=1566 lang=cpp
 *
 * [1566] 重复至少 K 次且长度为 M 的模式
 */

// @lc code=start
class Solution
{
public:
    bool containsPattern(vector<int> &arr, int m, int k)
    {
        int n = arr.size();
        for (int left = 0; left <= n - m * k; left++)
        {
            int offset;
            for (offset = 0; offset < m * k; offset++)
                if (arr[left + offset] != arr[left + offset % m])
                    break;
            if (offset == m * k)
                return true;
        }
        return false;
    }
};
// @lc code=end
