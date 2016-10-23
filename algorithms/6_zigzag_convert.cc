#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            if (numRows == 1)
            {
                return s;
            }

            vector<string> stub_string(numRows);

            size_t length = s.size();
            int idx = -1;
            int step = 1;
            for (int i = 0; i < length; ++i)
            {
                idx += step;
                stub_string[idx].push_back(s[i]);

                if (idx == numRows - 1)
                {
                    step = -1;
                }
                else if (idx == 0)
                {
                    step = 1;
                }

            }

            string result = "";
            for (size_t i = 0; i < stub_string.size(); ++i)
            {
                result += stub_string[i];
            }

            return result;
        }
};

int main ()
{
    Solution s;
    printf("%s\n", s.convert(string("AB"), 1).c_str());

    return 0;
}

