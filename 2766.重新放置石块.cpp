/*
 * @lc app=leetcode.cn id=2766 lang=cpp
 *
 * [2766] 重新放置石块
 */

// @lc code=start

class Solution
{
public:
    vector<int> relocateMarbles(vector<int> &nums, vector<int> &moveFrom, vector<int> &moveTo)
    {
        map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++)
            cnt[nums[i]]++;
        for (int i = 0; i < moveFrom.size(); i++)
        {
            if (cnt[moveFrom[i]] > 0 && moveFrom[i] != moveTo[i])
            {
                cnt[moveTo[i]] += cnt[moveFrom[i]];
                cnt[moveFrom[i]] = 0;
            }
        }
        vector<int> ans;
        for (auto &iter : cnt)
            if (iter.second > 0)
                ans.push_back(iter.first);
        return ans;
    }
};
// @lc code=end
