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
            int base_idx = 1;
            for (auto &c : s)
            {
                ++idx;
                if (letter_2_idx.count(c) > 0 && letter_2_idx[c] >= base_idx)
                {
                    max_len = std::max(max_len, idx - base_idx);
                    base_idx = letter_2_idx[c] + 1;
                }
                letter_2_idx[c] = idx;
            }
            ++idx;
            max_len = std::max(max_len, idx - base_idx);

            return max_len;
        }
};

int main ()
{
    string s{"pwwkew"};
    printf("%d\n", Solution().lengthOfLongestSubstring(s));
    return 0;
}

