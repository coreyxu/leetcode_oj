#include <stdio.h>
#include <string>
#include <limits.h>
#include <stdlib.h>

using namespace std;

class Solution {
    public:
        string strip(string str)
        {
            size_t start = 0;
            while(start < str.size())
            {
                if (str[start] == ' ' || str[start] == '\t')
                {
                    ++start;
                }
                else
                {
                    break;
                }
            }

            size_t end = str.size() - 1;
            while(end >= start)
            {
                if (str[end] == ' ' || str[end] == '\t')
                {
                    --end;
                }
                else
                {
                    break;
                }
            }

            return str.substr(start, end - start + 1);
        }

        int addNTimes(int base, int n)
        {
            int res = 0;
            if (base > 0)
            {
                for (int i = 0; i < n; ++i)
                {
                    res += base;
                    if (res < base)
                    {
                        return INT_MAX;
                    }
                }
            }
            if (base < 0)
            {
                for (int i = 0; i < n; ++i)
                {
                    res += base;
                    if (res > base)
                    {
                        return INT_MIN;
                    }
                }
            }

            return res;
        }

        int myAtoi(string str) {
            str = strip(str);
            int sign;
            int start;
            if (str[0] == '-')
            {
                sign = -1;
                start = 1;
            }
            else if (str[0] == '+')
            {
                sign = 1;
                start = 1;
            }
            else
            {
                sign = 1;
                start = 0;
            }
            int end = start;

            string numbers;
            numbers.resize(str.size());
            while (end < str.size())
            {
                if (str[end] >= '0' && str[end] <= '9')
                {
                    ++end;
                }
                else
                {
                    break;
                }
            }

            numbers = str.substr(start, end - start);
            if (numbers.size() == 0)
            {
                return 0;
            }

            int res = 0;
            for (auto &item : numbers)
            {
                int num = item - '0';
                int old = res;
                res = addNTimes(old, 10);

                int delta = num * sign;

                printf("%d->%d\n", old, res);
                if ((sign > 0 && (res + delta) < res))
                {
                    return INT_MAX;
                }

                if (sign < 0 && (res + delta) > res)
                {
                    return INT_MIN;
                }

                res += delta;
            }

            return res;
        }
};

int main()
{
    Solution s;
    printf("%s\n", s.strip("  ").c_str());
    printf("%d\n", s.myAtoi("    10522545459"));
    //printf("%d\n", s.myAtoi("-2147483648"));
    //printf("%d\n", s.myAtoi("2147483648"));
    printf("%d\n", atoi("-2147483648"));
    printf("%d\n", atoi("2147483648"));
    return 0;
}

