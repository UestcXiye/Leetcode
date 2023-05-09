/*
 * @lc app=leetcode.cn id=2553 lang=cpp
 *
 * [2553] 分割数组中数字的数位
 */

// @lc code=start
class Solution
{
public:
    vector<int> partition(int n)
    {
        vector<int> v;
        while (n)
        {
            v.push_back(n % 10);
            n /= 10;
        }
        reverse(v.begin(), v.end());
        return v;
    }
    vector<int> separateDigits(vector<int> &nums)
    {
        vector<int> ans;
        for (int num : nums)
        {
            vector<int> temp = partition(num);
            for (int i = 0; i < temp.size(); i++)
                ans.push_back(temp[i]);
        }
        return ans;
    }
};
// @lc code=end
