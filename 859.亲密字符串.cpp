/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 */

// @lc code=start
class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {

        if (s.size() != goal.size())
            return false;
        int cnt = 0;
        int diff1 = -1, diff2 = -1;
        vector<int> chars(26, 0);
        bool valid_no_diff = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != goal[i])
            {
                cnt++;
                if (cnt > 2)
                    return false;
                if (cnt == 1)
                    diff1 = i;
                if (cnt == 2)
                    diff2 = i;
            }
            chars[s[i] - 'a']++;
            if (chars[s[i] - 'a'] >= 2)
                valid_no_diff = true;
        }
        if (cnt == 0 && valid_no_diff)
            return true; // 两个串一摸一样，需要有两个以上相同字母出现
        if (cnt == 2 && s[diff1] == goal[diff2] && s[diff2] == goal[diff1])
            return true; // 两个串有两个位置不同，需要正好可以互换

        return false;
    }
};
// @lc code=end
