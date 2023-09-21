/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 模拟

// class Solution
// {
// public:
//     bool findTarget(TreeNode *root, int k)
//     {
//         vector<int> nums;
//         inOrder(root, nums);
//         // int n = nums.size();
//         // for (int i = 0; i < n; i++)
//         //     for (int j = i + 1; j < n; j++)
//         //         if (nums[i] + nums[j] == k)
//         //             return true;
//         int i = 0, j = nums.size() - 1;
//         while (i < j)
//         {
//             if (nums[i] + nums[j] == k)
//                 return true;
//             else if (nums[i] + nums[j] > k)
//                 j--;
//             else
//                 i++;
//         }
//         return false;
//     }
//     // 辅函数 - 中序遍历，并记录值
//     void inOrder(TreeNode *root, vector<int> &nums)
//     {
//         if (root == nullptr)
//             return;
//         inOrder(root->left, nums);
//         nums.push_back(root->val);
//         inOrder(root->right, nums);
//     }
// };

// 深度优先搜索 + 哈希

class Solution
{
private:
    unordered_set<int> hashTable;

public:
    bool findTarget(TreeNode *root, int k)
    {
        if (root == nullptr)
            return false;
        if (hashTable.count(k - root->val))
            return true;
        hashTable.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};

// 广度优先搜索 + 哈希

// class Solution
// {
// public:
//     bool findTarget(TreeNode *root, int k)
//     {
//         unordered_set<int> hashTable;
//         queue<TreeNode *> q;
//         q.push(root);
//         while (!q.empty())
//         {
//             TreeNode *node = q.front();
//             q.pop();
//             if (hashTable.count(k - node->val))
//                 return true;
//             hashTable.insert(node->val);
//             if (node->left)
//                 q.push(node->left);
//             if (node->right)
//                 q.push(node->right);
//         }
//         return false;
//     }
// };

// 迭代 + 中序遍历 + 双指针

// class Solution
// {
// public:
//     // 主函数
//     bool findTarget(TreeNode *root, int k)
//     {
//         TreeNode *leftNode = root, *rightNode = root;
//         stack<TreeNode *> leftStack, rightStack;
//         leftStack.push(leftNode);
//         while (leftNode->left != nullptr)
//         {
//             leftStack.push(leftNode->left);
//             leftNode = leftNode->left;
//         }
//         rightStack.push(rightNode);
//         while (rightNode->right != nullptr)
//         {
//             rightStack.push(rightNode->right);
//             rightNode = rightNode->right;
//         }
//         while (leftNode != rightNode)
//         {
//             if (leftNode->val + rightNode->val == k)
//                 return true;
//             else if (leftNode->val + rightNode->val < k)
//                 leftNode = getLeft(leftStack);
//             else
//                 rightNode = getRight(rightStack);
//         }
//         return false;
//     }
//     // 辅函数
//     TreeNode *getLeft(stack<TreeNode *> &stk)
//     {
//         TreeNode *root = stk.top();
//         stk.pop();
//         TreeNode *node = root->right;
//         while (node != nullptr)
//         {
//             stk.push(node);
//             node = node->left;
//         }
//         return root;
//     }
//     TreeNode *getRight(stack<TreeNode *> &stk)
//     {
//         TreeNode *root = stk.top();
//         stk.pop();
//         TreeNode *node = root->left;
//         while (node != nullptr)
//         {
//             stk.push(node);
//             node = node->right;
//         }
//         return root;
//     }
// };
//   @lc code=end
