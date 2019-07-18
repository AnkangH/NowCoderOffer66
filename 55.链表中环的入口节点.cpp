/*
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*/


//哈希表解法
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* p=pHead;//头节点
        unordered_map<ListNode*,bool> m;//哈希表记录走过的节点
        while(p!=nullptr)//遍历链表每个节点
        {
            if(m.count(p)==0)//第一次到达该节点
                m[p]=true;//记录
            else//第二次到达
                break;//退出 此时p即为链表环的入口
            p=p->next;//遍历
        }
        return p;
    }
};


//双指针解法
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* f=pHead;//快指针
        ListNode* s=pHead;//慢指针
        while(f!=nullptr&&f->next!=nullptr)//找环的循环条件 快指针不到链表尾且快指针的下一个节点不到链表尾
        {
            f=f->next->next;//快指针每次都两步
            s=s->next;//慢指针每次走一步
            if(f==s)//有环
            {
                s=pHead;//慢指针从头出发
                while(s!=f)//找环的入口循环条件
                {
                    s=s->next;//慢指针每次走一步
                    f=f->next;//快指针每次走一步
                }
                return s;//返回环的入口
            }
        }
        return nullptr;//没有环 返回nullptr
    }
};
