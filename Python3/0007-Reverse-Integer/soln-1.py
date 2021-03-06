class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        sign = -1 if x < 0 else +1
        x = abs(x)
        res = 0
        while x:
            res = res * 10 + x % 10
            x //= 10
        res *= sign
        return res if (-1<<31) <= res <= (1<<31) - 1 else 0