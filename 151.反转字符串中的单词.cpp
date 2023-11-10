/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
// class Solution
// {
// public:
//     string reverseWords(string s)
//     {
//         istringstream iss(s);
//         vector<string> words;
//         string word, ans;
//         while (iss >> word)
//             words.push_back(word);
//         for (int i = words.size() - 1; i >= 0; i--)
//         {
//             ans += words[i];
//             if (i)
//                 ans += " ";
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size();
        int idx = 0;
        // 反转整个字符串
        reverse(s.begin(), s.end());
        for (int start = 0; start < n; start++)
        {
            if (s[start] != ' ')
            {
                // 填一个空白字符然后将 idx 移动到下一个单词的开头位置
                if (idx != 0)
                    s[idx++] = ' ';
                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ')
                    s[idx++] = s[end++];
                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);
                // 更新 start，去找下一个单词
                start = end;
            }
        }
        //删除 s 尾部的空白字符
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};

// @lc code=end
