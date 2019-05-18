/*
题目：给定一个链表，按照从尾到头的顺序，打印链表节点的值。
解析：单向链表通常只记录链表头，因为每个节点都记录下个节点。因此要
找到链表头，必须遍历链表节点，下个节点为NULL的那个节点即为链表尾。
又从尾到头打印，因此想到利用栈的先入后出原则。
*/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;//结果
        stack<int> s;//辅助栈
	    ListNode* fake = head;//记录当前头，不修改原链表头
        while(fake!=NULL)
        {
            s.push(fake->val);//节点值入栈
            fake=fake->next;//下个节点
        }
        while(s.size()>0)
        {
            res.push_back(s.top());//栈顶元素为节点值
            s.pop();//栈顶出栈
        }
       return res;
    }
};
