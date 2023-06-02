/*
 * @lc app=leetcode.cn id=1672 lang=cpp
 *
 * [1672] 最富有客户的资产总量
 */

// @lc code=start
class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int maxAsset = 0;
        for (vector<int> &account : accounts)
        {
            int asset = accumulate(account.begin(), account.end(), 0);
            maxAsset = max(maxAsset, asset);
        }
        return maxAsset;
    }
};
// @lc code=end
