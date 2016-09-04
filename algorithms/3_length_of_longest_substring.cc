#include <stdio.h>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> letter_2_idx;

            int max_len = 0;
            int idx = 0;
            for (auto &c : s)
            {
                ++idx;
                if (letter_2_idx.count(c) > 0)
                {
                    max_len = std::max(max_len, idx - letter_2_idx[c]);
                }
                letter_2_idx[c] = idx;
            }

            return max_len;
        }
};

int main ()
{
    string s{"pwwkew"};
    printf("%d\n", Solution().lengthOfLongestSubstring(s));
    return 0;
}

