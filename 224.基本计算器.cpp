/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
// class Solution
// {
// public:
//     int calculate(string s)
//     {
//         stack<int> ops;
//         ops.push(1);
//         int sign = 1;

//         int ret = 0;
//         int n = s.length();
//         int i = 0;
//         while (i < n)
//         {
//             if (s[i] == ' ')
//                 i++;
//             else if (s[i] == '+')
//             {
//                 sign = ops.top();
//                 i++;
//             }
//             else if (s[i] == '-')
//             {
//                 sign = -ops.top();
//                 i++;
//             }
//             else if (s[i] == '(')
//             {
//                 ops.push(sign);
//                 i++;
//             }
//             else if (s[i] == ')')
//             {
//                 ops.pop();
//                 i++;
//             }
//             else
//             {
//                 long num = 0;
//                 while (i < n && isdigit(s[i]))
//                 {
//                     num = num * 10 + s[i] - '0';
//                     i++;
//                 }
//                 ret += sign * num;
//             }
//         }
//         return ret;
//     }
// };

class Solution
{
public:
    struct Data
    {
        bool is_number{false};
        long long number{0};
        char op{'\0'};
        Data(bool set_is_number, long long set_number, char set_op) : is_number(set_is_number), number(set_number), op(set_op){};
    };

    int calculate(string s)
    {
        // 去除所有空格
        std::string new_s1;
        for (char c : s)
        {
            if (c != ' ')
            {
                new_s1 += c;
            }
        }

        // (-n) -> (0-n)
        // (+n) -> (0+n) (本题没有，忽略)
        // 开头的-n -> 0-n
        // 开头的+n -> 0+n (本题没有，忽略)
        std::string new_s2;
        int n = new_s1.length();
        for (int i = 0; i < n; ++i)
        {
            if (new_s1[i] == '-' && (i == 0 || new_s1[i - 1] == '('))
            {
                new_s2 += "0-";
            }
            else
            {
                new_s2 += new_s1[i];
            }
        }

        // 中缀表达式 -> 后缀表达式
        // 操作符优先级:：^（本题没有，忽略） > *、/（本题没有，忽略） > +、-
        // 左括号、右括号的优先级单独计算，因为无论定义左括号优先级最高，右括号优先级最低，还是左括号优先级最低，右括号优先级最高，在具体计算的不同逻辑中都无法统一处理
        // 相同优先级条件下，先出现的优先级更高(即，均是+、-，则先出现的比后出现的优先级级高，即相同优先级的运算符，先出现的先计算)
        // 转换过程：
        // 中缀表达式从前向后遍历过程中，保证op_stack的栈顶是当前操作符优先级最高的
        // 即，如果栈为空，或者当前操作符比栈顶操作符优先级高，则入栈
        // 遇到(，则认为优先级最高，无脑入栈
        // 遇到)，则认为优先级最低，不断弹栈到后缀表达式结果datas中，直到遇到(，操作符)不会入栈
        // 如果栈不为空，且当前操作符比栈顶操作符优先级低或相同(优先级相同时，先出现的优先级更高，需要先进行计算)，则不断弹栈到后缀表达式结果datas中，直到弹到栈为空，或当前操作符优先级比栈顶操作符元素的优先级高，或遇到(，弹栈后，将当前操作符压栈，即，该操作符入栈前，一定要保证所有优先级大于等于该操作符(实际等于时，先出现的优先级也要更高，要先计算)的操作符，都要先输出到后缀表达式结果datas中

        // 存储后缀表达式
        std::vector<Data> datas;
        // 存储操作符op的栈
        std::stack<char> op_stack;

        // 中缀表达式 -> 后缀表达式
        // has_number是为了知道最后是否还有数字元素没有加入到datas中，因为每次遇到操作符才将cur_number写入，但是最后结尾有可能是数字，有可能是操作符)，而且数字可能为0，可能非0，无法判断，所以只能引入额外变量标记
        bool has_number = false;
        long long cur_number = 0;
        for (char c : new_s2)
        {
            if (c >= '0' && c <= '9')
            {
                // 数字
                has_number = true;
                cur_number = cur_number * 10 + c - '0';
            }
            else
            {
                // 操作符
                if (has_number)
                {
                    // 将上一个数字输出到后缀表达式结果datas中
                    datas.emplace_back(true, cur_number, '\0');
                    cur_number = 0;
                    has_number = false;
                }

                if (c == '(')
                {
                    // 遇到(，无脑入栈
                    op_stack.emplace(c);
                }
                else if (c == ')')
                {
                    // 遇到)，不断弹栈到后缀表达式结果datas中，直到遇到(，操作符)不会入栈
                    while (!op_stack.empty() && op_stack.top() != '(')
                    {
                        char op = op_stack.top();
                        op_stack.pop();
                        datas.emplace_back(false, 0, op);
                    }

                    // 将'('弹栈
                    op_stack.pop();
                }
                else if (c == '+' || c == '-')
                {
                    if (op_stack.empty() || op_stack.top() == '(')
                    {
                        // 如果栈为空，或者当前操作符比栈顶操作符优先级高，则入栈
                        op_stack.emplace(c);
                    }
                    else
                    {
                        // 如果栈不为空，且当前操作符比栈顶操作符优先级低或相同(优先级相同时，先出现的优先级更高，需要先进行计算)，则不断弹栈到后缀表达式结果datas中，直到弹到栈为空，或当前操作符优先级比栈顶操作符元素的优先级高，或遇到(，弹栈后，将当前操作符压栈，即，该操作符入栈前，一定要保证所有优先级大于等于该操作符(实际等于时，先出现的优先级也要更高，要先计算)的操作符，都要先输出到后缀表达式结果datas中
                        while (!op_stack.empty() && (op_stack.top() == '+' || op_stack.top() == '-'))
                        {
                            // 这里如果遇到(就不要再弹了，说明这些都是在一组()内处理的部分
                            char op = op_stack.top();
                            op_stack.pop();
                            datas.emplace_back(false, 0, op);
                        }

                        // 将当前操作符压栈
                        op_stack.emplace(c);
                    }
                }
            }
        }
        if (has_number)
        {
            // 如果原中缀表达式最后一个字符不是)，则最后一个数字还没有输出到后缀表达式结果datas中
            datas.emplace_back(true, cur_number, '\0');
        }
        while (!op_stack.empty())
        {
            // 将栈中剩余操作符依次弹栈到后缀表达式结果datas中
            char op = op_stack.top();
            op_stack.pop();
            datas.emplace_back(false, 0, op);
        }

        // 计算后缀表达式
        // 此时后缀表达式结果datas中，只包括数字、+、-，不会再存在括号

        // 存储操作数num的栈
        std::stack<long long> num_stack;

        for (const Data &data : datas)
        {
            if (data.is_number)
            {
                // 如果是数字，就压栈
                num_stack.emplace(data.number);
            }
            else
            {
                // 如果是操作符，就进行相应计算
                // 先弹栈的是右操作数，后弹栈的是左操作数
                long long a = num_stack.top();
                num_stack.pop();
                long long b = num_stack.top();
                num_stack.pop();
                if (data.op == '+')
                {
                    num_stack.emplace(b + a);
                }
                else if (data.op == '-')
                {
                    num_stack.emplace(b - a);
                }
            }
        }

        return num_stack.top();
    }
};
// @lc code=end
