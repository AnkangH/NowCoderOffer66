/*
题目：
输入一个链表，反转链表后，输出新链表的表头。
解析：
头插法。从链表第一个节点开始，修改其指向。
在修改前保存当前节点的原下个节点，使遍历继续。
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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* p=pHead;//原链表头，按原链表顺序遍历
        ListNode* pre=NULL;//新链表的下一个节点
        while(p!=NULL)
        {
            ListNode* nxt=p->next;//防止断链，先当前节点的原下个节点
            p->next=pre;//修改指向
            pre=p;//当前节点为新链表下个节点
            p=nxt;//遍历原链表
        }
        return pre;
    }
};
