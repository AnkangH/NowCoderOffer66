/*
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/


class Solution {
public:
    bool res=true;
    bool IsBalanced_Solution(TreeNode* pRoot) {
        height(pRoot);
        return res;
    }
    int height(TreeNode* t)
    {
        if(t==nullptr)
            return 0;//空节点 深度为0
        int l=height(t->left);//左子树深度
        int r=height(t->right);//右子树深度
        if(abs(l-r)>1)
            res=false;//非平衡二叉树
        return max(l,r)+1;//返回左右子树深度较大值+1
    }
};
