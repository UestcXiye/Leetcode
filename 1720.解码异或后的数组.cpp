/*
 * @lc app=leetcode.cn id=1720 lang=cpp
 *
 * [1720] 解码异或后的数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        int n = encoded.size();
        vector<int> arr(n + 1);
        arr[0] = first;
        for (int i = 1; i < arr.size(); i++)
            arr[i] = arr[i - 1] ^ encoded[i - 1];
        return arr;
    }
};
// @lc code=end
