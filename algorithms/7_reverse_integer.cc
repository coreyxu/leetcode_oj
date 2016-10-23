#include <string>
#include <stdlib.h>
#include <limits.h>

class Solution {
    public:
        int reverse(int x) {
            int sign = 1;
            int res = 0;
            if (x < 0)
            {
                sign = -1;
            }

            x = abs(x);
            while (x > 0)
            {
                if (res > (INT_MAX - x % 10) / 10)
                {
                    return 0;
                }

                res = res * 10 + x % 10;
                x /= 10;
            }

            return res * sign;
        }
};

int main()
{
    Solution s;
    printf("%d\n", s.reverse(1534236469));
    return 0;
}

