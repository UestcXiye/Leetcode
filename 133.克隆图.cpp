/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// 深度优先搜索

class Solution
{
private:
    unordered_map<Node *, Node *> visited;

public:
    Node *cloneGraph(Node *node)
    {
        // 特判
        if (node == nullptr)
            return nullptr;
        // 如果该节点已经被访问过了，则直接从哈希表中取出对应的克隆节点返回
        if (visited.count(node))
            return visited[node];
        // 克隆节点，注意到为了深拷贝我们不会克隆它的邻居的列表
        Node *cloneNode = new Node(node->val);
        // 哈希表存储
        visited[node] = cloneNode;
        // 遍历该节点的邻居并更新克隆节点的邻居列表
        for (const auto &neighbor : node->neighbors)
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        return cloneNode;
    }
};

// 广度优先遍历

// class Solution
// {
// public:
//     Node *cloneGraph(Node *node)
//     {
//         // 特判
//         if (node == nullptr)
//             return nullptr;
//         unordered_map<Node *, Node *> visited;
//         // 将题目给定的节点添加到队列
//         queue<Node *> q;
//         q.push(node);
//         // 克隆第一个节点并存储到哈希表中
//         visited[node] = new Node(node->val);
//         // 广度优先搜索
//         while (!q.empty())
//         {
//             // 取出队列的头节点
//             Node *n = q.front();
//             q.pop();
//             // 遍历该节点的邻居
//             for (auto &neighbor : n->neighbors)
//             {
//                 if (visited.find(neighbor) == visited.end())
//                 {
//                     // 如果没有被访问过，就克隆并存储在哈希表中
//                     visited[neighbor] = new Node(neighbor->val);
//                     // 将邻居节点加入队列中
//                     q.push(neighbor);
//                 }
//                 // 更新当前节点的邻居列表
//                 visited[n]->neighbors.emplace_back(visited[neighbor]);
//             }
//         }
//         return visited[node];
//     }
// };
// @lc code=end
