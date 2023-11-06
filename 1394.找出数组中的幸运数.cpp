/*
 * @lc app=leetcode.cn id=1394 lang=cpp
 *
 * [1394] 找出数组中的幸运数
 */

// @lc code=start
class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        int lucky = INT_MIN;
        unordered_map<int, int> hash;
        for (const int &x : arr)
            hash[x]++;
        for (auto &[num, freq] : hash)
            if (num == freq)
                lucky = max(lucky, num);
        return lucky == INT_MIN ? -1 : lucky;
    }
};
// @lc code=end
