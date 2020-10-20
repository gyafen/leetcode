//
// Created by gyafen on 2020/10/20.
//

#ifndef H_SOLUTION_H
#define H_SOLUTION_H

#include <iostream>

using namespace std;

 struct ListNode {
       int val;
       ListNode *next;
       ListNode() : val(0), next(nullptr) {}
       ListNode(int x) : val(x), next(nullptr) {}
       ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    int getLength(ListNode *head)
    {
        int length = 0;
        while(head != nullptr)
        {
            length++;
            head = head->next;
        }
        return length;
    }

    void down(ListNode* &f, ListNode* &r, int mov, int times)
    {
        if(mov == times)
        {
            ListNode *rcd = r->next;
            ListNode* swp = r->next;
            r->next = r->next->next;
            swp->next = f->next;
            f->next = swp;
            if(rcd == r->next)
            {
                r = r->next;
            }
        }
        else
        {
            down(f->next, r, mov+1, times);
            ListNode* swp = r->next;
            r->next = r->next->next;
            swp->next = f->next;
            f->next = swp;
        }
    }

    void reorderList(ListNode* head) {
        ListNode *r = head;
        ListNode *f = head;
        int length = getLength(head);
        int times = length/2;
        for(int i = 0; i < length-times-1; i++)
        {
            r = r->next;
        }
        if(length > 1)
        {
            down(f, r, 1, times);
        }
        while(head != nullptr)
        {
            cout << head->val << endl;
            head = head->next;
        }
    }
};


#endif //H_SOLUTION_H
