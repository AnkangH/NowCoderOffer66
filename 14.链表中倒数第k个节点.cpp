/*
题目：
输入一个链表，输出该链表中倒数第k个结点。
解析：
双指针法，一个指针先走k步，一个指针从起点开始，然后两个同时走，
当快指针到达链表尾时，慢指针到达倒数第k个节点。
*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* p=pListHead;
        ListNode* res=pListHead;
        for(int i=0;i<k;i++)
        {
            if(p==NULL)
                return NULL;
            p=p->next;
        }
        while(p!=NULL)
        {
            res=res->next;
            p=p->next;
        }
        return res;
    }
};
