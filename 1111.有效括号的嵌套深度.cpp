/*
 * @lc app=leetcode.cn id=1111 lang=cpp
 *
 * [1111] 有效括号的嵌套深度
 */

// @lc code=start
class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        int n = seq.length();
        int depthA = 0, depthB = 0;
        vector<int> answer(n);
        // ( 给深度低的，) 给深度高的
        for (int i = 0; i < n; i++)
        {
            if (seq[i] == '(')
            {
                if (depthA > depthB)
                {
                    depthB++;
                    answer[i] = 1;
                }
                else
                {
                    depthA++;
                    answer[i] = 0;
                }
            }
            else if (seq[i] == ')')
            {
                if (depthA > depthB)
                {
                    depthA--;
                    answer[i] = 0;
                }
                else
                {
                    depthB--;
                    answer[i] = 1;
                }
            }
        }
        return answer;
    }
};
// @lc code=end
