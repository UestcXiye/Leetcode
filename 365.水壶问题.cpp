/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start

// 深度优先搜索

// using PII = pair<int, int>;

// class Solution
// {
// public:
//     bool canMeasureWater(int x, int y, int z)
//     {
//         stack<PII> stk;
//         stk.emplace(0, 0);
//         auto hash_function = [](const PII &o)
//         { return hash<int>()(o.first) ^ hash<int>()(o.second); };
//         unordered_set<PII, decltype(hash_function)> seen(0, hash_function);
//         while (!stk.empty())
//         {
//             if (seen.count(stk.top()))
//             {
//                 stk.pop();
//                 continue;
//             }
//             seen.emplace(stk.top());

//             auto [remain_x, remain_y] = stk.top();
//             stk.pop();
//             if (remain_x == z || remain_y == z || remain_x + remain_y == z)
//             {
//                 return true;
//             }
//             // 把 X 壶灌满。
//             stk.emplace(x, remain_y);
//             // 把 Y 壶灌满。
//             stk.emplace(remain_x, y);
//             // 把 X 壶倒空。
//             stk.emplace(0, remain_y);
//             // 把 Y 壶倒空。
//             stk.emplace(remain_x, 0);
//             // 把 X 壶的水灌进 Y 壶，直至灌满或倒空。
//             stk.emplace(remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y));
//             // 把 Y 壶的水灌进 X 壶，直至灌满或倒空。
//             stk.emplace(remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x));
//         }
//         return false;
//     }
// };

// 数学

class Solution
{
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
    {
        if (jug1Capacity + jug2Capacity < targetCapacity)
            return false;
        int a = max(jug1Capacity, jug2Capacity);
        int b = min(jug1Capacity, jug2Capacity);

        int c = a + b;
        while (c)
        {
            if (c == targetCapacity)
                return true;

            if (c >= b)
                c -= b;
            else
                c += a;
        }

        return false;
    }
};

// @lc code=end
