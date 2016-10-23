#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    public:
        string longestPalindrome(string s) {
            size_t length = s.size();
            vector<int> dp1(length);
            vector<int> dp2(length);

            int max_length = -1;
            int start = 0;
            int end = 0;
            for (int i = length - 1; i >= 0; --i)
            {
                fill(dp2.begin(), dp2.end(), 0);
                int j = i;
                dp1[j] = 1;
                if ((j + 1) < length)
                {
                    if (s[j] == s[j + 1])
                    {
                        dp1[j + 1] = 2;
                    }
                    else
                    {
                        dp1[j + 1] = 0;
                    }
                }

                for (; j < length; ++j)
                {
                    if ((i - 1) >= 0 && (j + 1) < length)
                    {
                        if (dp1[j] > 0 && s[i - 1] == s[j + 1])
                        {
                            dp2[j + 1] = dp1[j] + 2;
                        }
                    }

                    if (dp1[j] > max_length)
                    {
                        max_length = dp1[j];
                        start = i;
                        end = j;
                    }
                }
                dp1.swap(dp2);
            }

            return s.substr(start, end - start + 1);
        }
};
int main()
{

    Solution s;
    string test{"civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth"};
    string res = s.longestPalindrome(test);
    printf("%s\n", res.c_str());
    return 0;
}
