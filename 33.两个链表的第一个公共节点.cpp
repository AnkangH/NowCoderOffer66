/*
题目：
输入两个链表，找出它们的第一个公共结点。
解析：
a1 a2
      c1 c2 c3
   b1
假设链表A=a1 a2 c1 c2 c3
链表B=b1 c1 c2 c3
公共部分为C=c1 c2 c3 
则a+c+b=b+c+a即A+b=B+a
两个指针pa，pb分别从A和B出发遍历A和B，若pa遍历到A的尾部
则从B开始，同理pb遍历到B的尾部从A开始。直到两个节点相等。
若存在公共节点，则必有pa=pb，且第一个pa=pb即是第一个公共节点。
若不存在公共节点，则pa，pb最后遍历到链表结尾，均为NULL。因为A+B=B+A,
最后pa在B的尾，pb在A的尾
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL||pHead2==NULL)
            return NULL;
        ListNode* p1=pHead1;
        ListNode* p2=pHead2;
        while(p1!=p2)
        {
            if(p1==NULL)
                p1=pHead2;
            else
                p1=p1->next;
            if(p2==NULL)
                p2=pHead1;
            else
                p2=p2->next;
        }
        return p1;
    }
};
