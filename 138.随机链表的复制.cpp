/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // 特判
        if (head == nullptr)
            return nullptr;
        Node *curNode = head;
        unordered_map<Node *, Node *> hash; // <原结点，新结点>
        // 复制各节点，建立 “原节点 -> 新节点” 的哈希映射
        while (curNode)
        {
            hash[curNode] = new Node(curNode->val);
            curNode = curNode->next;
        }
        curNode = head;
        // 构建新链表
        while (curNode)
        {
            hash[curNode]->next = hash[curNode->next];
            hash[curNode]->random = hash[curNode->random];
            curNode = curNode->next;
        }
        // 返回新链表的头节点
        return hash[head];
    }
};
// @lc code=end
