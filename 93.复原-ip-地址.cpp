/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start

// 回溯

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ans;
        string addr;
        backtracking(ans, s, 0, 0, addr);
        return ans;
    }
    void backtracking(vector<string> &ans, const string &s, int cnt, int index, string &addr)
    {
        if (cnt == 4 || index == s.size())
        {
            if (cnt == 4 && index == s.size())
                ans.push_back(addr.substr(0, addr.size() - 1));
            return;
        }
        for (int i = 1; i <= 3; i++)
        {
            if (index + i > s.size())
                return;
            if (s[index] == '0' && i != 1)
                return;
            if (i == 3 && s.substr(index, i) > "255")
                return;
            addr += s.substr(index, i);
            addr.push_back('.');
            backtracking(ans, s, cnt + 1, index + i, addr);
            addr = addr.substr(0, addr.size() - i - 1);
        }
    }
};
// @lc code=end
