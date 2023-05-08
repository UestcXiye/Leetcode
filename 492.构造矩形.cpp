/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */

// @lc code=start
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        vector<int> ans;
        int l = sqrt(area);
        while (area % l != 0)
            l++;

        ans.push_back(max(l, area / l));
        ans.push_back(min(l, area / l));
        return ans;
    }
};
// @lc code=end
