/*
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/


class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        TreeLinkNode* p=pNode;
        if(p==nullptr)
            return nullptr;
        else if(p->right!=nullptr)//有右子树 找右子树中最左侧的节点
        {
            TreeLinkNode* t=p->right;
            while(t->left!=nullptr)
                t=t->left;
            return t;
        }
        while(p->next!=nullptr)//没有右子树
        {
            if(p==p->next->left)//若当前节点是其父节点的左节点
                return p->next;//返回其父节点
            p=p->next;//否则往上继续找一直找到根节点
        }
        return nullptr;//搜索到根节点 返回nullptr
    }
};
