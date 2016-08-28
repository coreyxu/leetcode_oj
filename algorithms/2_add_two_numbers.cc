#include <stdio.h>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *left = l1;
        ListNode *right = l2;
        ListNode *result = NULL;
        ListNode **pl = &result;
        int c = 0;
        while ((left != NULL) || (right != NULL) || (c == 1))
        {
            int x = 0;
            int y = 0;

            if (left != NULL)
            {
                x = left->val;
                left = left->next;
            }

            if (right != NULL)
            {
                y = right->val;
                right = right->next;
            }

            int z = x + y + c;
            c = 0;
            if (z > 9)
            {
                c = 1;
                z -= 10;
            }

            *pl = new ListNode(z);
            pl = &(*pl)->next;
        }
        
        return result;
    }
};

void InitListNode(ListNode **head, const std::vector<int> &v)
{
    ListNode **p = head;
    for (auto &i : v)
    {
        *p = new ListNode(i);
        p = &(*p)->next;
    }
}

int main()
{
    ListNode *l1;
    ListNode *l2;
    InitListNode(&l1, {2, 4, 6});
    InitListNode(&l2, {5, 6, 4});

    ListNode *result = Solution().addTwoNumbers(l1, l2);
    while(result != NULL)
    {
        printf("%d\n", result->val);
        result = result->next;
    }

    return 0;
}
