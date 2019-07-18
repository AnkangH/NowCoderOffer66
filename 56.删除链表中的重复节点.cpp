/*
题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/


/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==nullptr)
            return pHead;//边界条件 否则下面访问pHead->next会出错
        ListNode* newHead=new ListNode(1);//用一个新链表头 防止原链表头节点重复
        ListNode* p=newHead;//新链表的构造节点 即当前节点
        ListNode* pre=pHead;//原链表的前节点
        ListNode* cur=pHead->next;//原链表的当前节点
        while(cur!=nullptr)//遍历原链表
        {
            if(cur->val!=pre->val)//当前节点值不与原链表相同
            {
                p->next=pre;//放入新链表
                p=p->next;//新链表的构造节点后移
            }
            else//值相同
            {
                while(cur!=nullptr&&cur->val==pre->val)
                    cur=cur->next;//后移直到不与前节点的值相同
                if(cur==nullptr)//最后是连续的重复数字
                {
                    p->next=nullptr;//此时新链表的最后一个节点要连接nullptr 否则会将原链表最后的重复部分引入
                    return newHead->next;
                }
            }
            pre=cur;//前节点更新
            cur=cur->next;//当前节点后移
        }
        p->next=pre;//因为循环退出后 pre为链表最后一个不重复的值 且pre->next==nullptr
        return newHead->next;//新链表头多一个1 所以返回第二个开始的链表
    }
};
