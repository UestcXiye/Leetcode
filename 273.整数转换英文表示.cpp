/*
 * @lc app=leetcode.cn id=273 lang=cpp
 *
 * [273] 整数转换英文表示
 */

// @lc code=start
class Solution
{
private:
    vector<string> s1 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> s2 = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> s3 = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> s4 = {"", "Thousand", "Million", "Billion"};

public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";

        string res;
        int u = 1e9;
        for (int i = 3; i >= 0; i--)
        {
            int curNum = num / u;
            if (curNum != 0)
            {
                num -= curNum * u;
                string str;
                dfs(str, curNum);
                res += str + s4[i] + " ";
            }
            u /= 1000;
        }

        while (res.back() == ' ')
            res.pop_back();
        return res;
    }
    // 辅函数 - 递归
    void dfs(string &s, int curNum)
    {
        if (curNum == 0)
            return;
        if (curNum < 10)
            s = s + s1[curNum] + " ";
        else if (curNum < 20)
        {
            int curPos = curNum - 10;
            s = s + s2[curPos] + " ";
        }
        else if (curNum < 100)
        {
            int curPos = curNum / 10;
            curNum -= curPos * 10;
            s = s + s3[curPos] + " ";
            dfs(s, curNum);
        }
        else
        {
            int curPos = curNum / 100;
            s = s + s1[curPos] + " " + "Hundred ";
            dfs(s, curNum % 100);
        }
    }
};
// @lc code=end
