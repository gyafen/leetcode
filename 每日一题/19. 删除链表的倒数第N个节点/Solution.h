struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *p = head;
        ListNode *q = head;

        for (int i = 0; i < n; ++i)
        {
            p = p->next;
        }
        if (p == nullptr)
        {
            head = head->next;
        }
        else
        {
            while (p->next != nullptr)
            {
                p = p->next;
                q = q->next;
            }
            q->next = q->next->next;
        }
        return head;
    }
};
