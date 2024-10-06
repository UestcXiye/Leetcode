/*
 * @lc app=leetcode.cn id=3311 lang=cpp
 *
 * [3311] 构造符合图结构的二维矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>> &edges)
    {
        // 建图并记录节点度数
        vector<vector<int>> grid(n);
        vector<int> degree(n, 0);
        for (vector<int> &edge : edges)
        {
            grid[edge[0]].push_back(edge[1]);
            grid[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        int minDegree = *min_element(degree.begin(), degree.end());
        int maxDegree = *max_element(degree.begin(), degree.end());

        // 先求出矩阵最左边一列
        vector<int> vec;
        if (minDegree == 1)
        {
            // 情况 1：一行的矩阵
            for (int i = 0; i < n; i++)
                if (degree[i] == 1)
                {
                    vec.push_back(i);
                    break;
                }
        }
        else
        {
            int S;
            for (int i = 0; i < n; i++)
                if (degree[i] == 2)
                {
                    S = i;
                    break;
                }
            vec.push_back(S);
            if (maxDegree <= 3)
            {
                // 情况 2：两行的矩阵
                vec.push_back(degree[grid[S][0]] == 2 ? grid[S][0]
                                                      : grid[S][1]);
            }
            else
            {
                // 情况 3：矩阵至少三行
                int now = grid[S][0], last = S;
                while (degree[now] != 2)
                {
                    vec.push_back(now);
                    for (int &fn : grid[now])
                        if (degree[fn] <= 3 && fn != last)
                        {
                            last = now;
                            now = fn;
                            break;
                        }
                }
                vec.push_back(now);
            }
        }

        int row = vec.size(), col = n / row;
        vector<vector<int>> ans(row, vector<int>(col, 0));
        vector<bool> visited(n, false);
        for (int i = 0; i < row; i++)
        {
            ans[i][0] = vec[i];
            visited[vec[i]] = true;
        }
        // 每次枚举一列，找出每个元素还不在矩阵里的邻居放在右边
        for (int j = 0; j + 1 < col; j++)
            for (int i = 0; i < row; i++)
                for (int &fn : grid[ans[i][j]])
                    if (!visited[fn])
                    {
                        ans[i][j + 1] = fn;
                        visited[fn] = true;
                    }
        return ans;
    }
};
// @lc code=end
