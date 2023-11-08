/*
 * @lc app=leetcode.cn id=2899 lang=cpp
 *
 * [2899] 上一个遍历的整数
 */

// @lc code=start
class Solution
{
public:
    vector<int> lastVisitedIntegers(vector<string> &words)
    {
        vector<int> ans;
        vector<int> nums;
        int k = 0;
        for (const string &word : words)
        {
            if (word == "prev")
            {
                k++;
                if (k > nums.size())
                    ans.push_back(-1);
                else
                    ans.push_back(nums[nums.size() - k]);
            }
            else
            {
                k = 0;
                nums.push_back(stoi(word));
            }
        }
        return ans;
    }
};
// @lc code=end
