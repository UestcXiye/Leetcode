#
# @lc app=leetcode.cn id=3260 lang=python3
#
# [3260] 找出最大的 N 位 K 回文数
#

# @lc code=start
class Solution:
    def largestPalindrome(self, n: int, k: int) -> str:
        if k == 1:
            return '9' * n
        elif k == 2:
            if n == 1:
                return '8'
                
            '''
            1 8
            2 88
            3 898
            4 8998
            5 89998
            6 899998
            7 8999998
            '''
            return '8' + (n-2) * '9' + '8'
        elif k == 3:
            '''
            1 9
            2 99
            3 999
            4 9999
            5 99999
            6 999999
            7 9999999
            '''
            return '9' * n
        elif k == 4:
            '''
            1 8
            2 88
            3 888
            4 8888
            5 88988
            6 889988
            7 8899988
            8 88999988
            9 889999988
            '''
            if n <= 4:
                return '8' * n
            
            return '88' + (n-4) * '9' + '88'
        # 5995
        elif k == 5:
            if n == 1:
                return '5'
                
            return '5' + (n-2) * '9' + '5'
        elif k == 6:
            '''
            1 6
            2 66
            3 888
            4 8778
            5 89898
            6 897798
            7 8998998
            '''
            if n <= 2:
                return '6' * n
            # 8 9999 8 9999 8
            if n % 2 == 1:
                tmp = (n-3) // 2 
                return '8' + tmp * '9' + '8' + tmp * '9' + '8'
            # 8 99 77 99 8
            else:
                tmp = (n-4) // 2
                return '8' + tmp * '9' + '77' + tmp * '9' + '8'

        elif k == 7:
            '''
            1 7
            2 77
            3 959
            4 9779
            5 99799
            6 999999
            7 9994999
            8 99944999
            9 999969999
            '''
            if n <= 2:
                return '7' * n
            
            if n % 2 == 1:
                tmp = (n-1) // 2
                for m in range(9,-1,-1):
                    s = '9' * tmp + str(m) + '9' * tmp
                    t = 0
                    for w in s:
                        t *= 10
                        t += int(w)
                        t %= k
                    if t == 0:
                        return s
            
            else:
                tmp = (n-2) // 2
                for m in range(9,-1,-1):
                    s = '9' * tmp + str(m)  + str(m) + '9' * tmp
                    t = 0
                    for w in s:
                        t *= 10
                        t += int(w)
                        t %= k
                    if t == 0:
                        return s

            
        elif k == 8:
            '''
            1 8
            2 88
            3 888
            4 8888
            5 88888
            6 888888
            7 8889888
            8 88899888
            9 888999888
            '''
            if n <= 6:
                return '8' * n
            
            return '888' + (n-6) * '9' + '888'
        elif k == 9:
            # 同 3
            return '9' * n
# @lc code=end

