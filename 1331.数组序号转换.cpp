/*
 * @lc app=leetcode.cn id=1331 lang=cpp
 *
 * [1331] 数组序号转换
 */

// @lc code=start
class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> sortedArr = arr;
        unordered_map<int, int> ranks; // <value, rank>
        vector<int> ans(arr.size(), 0);
        sort(sortedArr.begin(), sortedArr.end());
        int curRank = 1;
        for (const int &num : sortedArr)
            if (!ranks.count(num))
                ranks[num] = curRank++;
        for (int i = 0; i < arr.size(); i++)
            ans[i] = ranks[arr[i]];
        return ans;
    }
};
// @lc code=end
