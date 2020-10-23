 
  struct ListNode {
      int val;
      ListNode  *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };

class Solution {
public:
	bool isPalindrome(ListNode *head) {
		ListNode *backup = new ListNode(0);
		ListNode *mov = head;
		ListNode *movB = backup;

		//备份
		while (mov)
		{
			ListNode *newNode = new ListNode(mov->val);
			movB->next = newNode;
			movB = movB->next;
			mov = mov->next;
		}
		backup = backup->next;

		//反转
		ListNode *move = backup;
		ListNode *q = nullptr;
		ListNode *p = nullptr;
		while (move != nullptr)
		{
			q = move->next;
			move->next = p;
			p = move;
			move = q;
		}
		backup = p;

		//比对
		while (head!=nullptr && backup!=nullptr)
		{
			if (head->val != backup->val)
			{
				return false;
			}
			head = head->next;
			backup = backup->next;
		}
		if (head != nullptr || backup != nullptr)
		{
			return false;
		}

		return true;
	}
};
