/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        vector<int> index;
        int n = s.size();
        for (int i = 0; i < n; i++)
            if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U')
                index.push_back(i);
        n = index.size();
        int i = 0;
        int j = n - 1;
        while (i < j)
        {
            char temp = s[index[i]];
            s[index[i]] = s[index[j]];
            s[index[j]] = temp;
            i++;
            j--;
        }
        return s;
    }
};
// @lc code=end
