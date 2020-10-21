#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *mov = head;
		ListNode *q = nullptr;
		ListNode *p = nullptr;

		while (mov != nullptr)
		{
			q = mov->next;
			mov->next = p;
			p = mov;
			mov = q;
		}
		return p;
	}
};
