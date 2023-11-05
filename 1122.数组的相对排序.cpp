/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
// class Solution
// {
// public:
//     vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
//     {
//         unordered_map<int, int> hash;
//         set<int> set(arr2.begin(), arr2.end());
//         vector<int> remain;
//         for (const int &num : arr1)
//         {
//             if (set.count(num))
//                 hash[num]++;
//             else
//                 remain.push_back(num);
//         }
//         vector<int> ans;
//         for (const int &num : arr2)
//         {
//             if (hash.count(num))
//                 for (int i = 0; i < hash[num]; i++)
//                     ans.push_back(num);
//         }
//         // 未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾
//         sort(remain.begin(), remain.end());
//         for (int i = 0; i < remain.size(); i++)
//             ans.push_back(remain[i]);
//         return ans;
//     }
// };

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        int upper = *max_element(arr1.begin(), arr1.end());
        vector<int> freq(upper + 1, 0);
        for (const int &num : arr1)
            freq[num]++;
        vector<int> ans;
        for (const int &num : arr2)
        {
            for (int i = 0; i < freq[num]; i++)
                ans.push_back(num);
            freq[num] = 0;
        }
        for (int num = 0; num <= upper; num++)
            for (int i = 0; i < freq[num]; i++)
                ans.push_back(num);
        return ans;
    }
};

// @lc code=end
