/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> left(26, 0);
        for (char &c : s)
            left[c - 'a']++;

        string ans;
        vector<bool> inAns(26, false);
        for (char &c : s)
        {
            left[c - 'a']--;
            if (inAns[c - 'a'])
                continue;
            while (!ans.empty() && c < ans.back() && left[ans.back() - 'a'] > 0)
            {
                // 设 x = ans.back()
                // 如果 c < x，且右边还有 x，那么可以把 x 去掉
                inAns[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(c);
            inAns[c - 'a'] = true;
        }
        return ans;
    }
};
// @lc code=end
