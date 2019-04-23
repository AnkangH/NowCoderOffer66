/*
题目：
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
解析：
分三步。
1.每个节点a复制为a1放到a之后。
abcde->aa1bb1cc1dd1ee1
2.复制原链表特殊指针关系
如a指向c，则a1指向c1
3.拆分链表 每隔一个放到不同链表中
并返回指向复制后链表第二个节点也就是拆分后新链表头
*/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
RandomListNode* Clone(RandomListNode* pHead) {
		if (pHead == NULL) {
			return NULL;
		}
		RandomListNode* p = pHead;
		//1、复制每个结点，如复制结点A得到A1，将结点A1插到结点A后面；
		while (p != NULL) {
			RandomListNode* temp=new RandomListNode(p->label);
			RandomListNode* next = p->next;//保存旧的p->next
			p->next = temp;//p指向新增加的节点
			temp->next = next;//新节点指向P的原下一个节点
			p = next;//p移动
		}
		p = pHead;
		//2、重新遍历链表，复制老结点的随机指针给新结点，如A1.random = A.random.next;
		while (p != NULL) {
			p->next->random = p->random == NULL ? NULL : p->random->next;
			p = p->next->next;
		}
		//3、拆分链表，将链表拆分为原链表和复制后的链表
		p = pHead;
		RandomListNode* res = pHead->next;//复制后链表的第二个节点，拆分后是返回链表的第一个节点
		while (p != NULL) {
			RandomListNode* temp = p->next;
			//p->next = p->next==NULL? NULL:temp->next;//为什么可以不判断p->next->next非空？
            p->next=temp->next;
			temp->next = temp->next == NULL ? NULL : temp->next->next;//隔一个拆分
			p = p->next;//p移动
		}
		return res;
	}
};
