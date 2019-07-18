/*
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==nullptr)
            return true;//空树是对称的
        queue<TreeNode*> q1;//用于层序遍历左子树
        queue<TreeNode*> q2;//用于层序遍历右子树
        q1.push(pRoot->left);//左节点作为根节点入队列
        q2.push(pRoot->right);//右节点作为根节点入队列
        while(!q1.empty())//遍历全部节点
        {
            int size=q1.size();
            for(int i=0;i<size;i++)//每一层
            {
                auto p1=q1.front();//左子树当前节点
                auto p2=q2.front();//右子树当前节点
                q1.pop();//遍历过后出队列
                q2.pop();//遍历过后出队列
                if(p1==nullptr&&p2!=nullptr||p1!=nullptr&&p2==nullptr)
                    return false;//一个为空 一个非空 不是镜像
                if(p1!=nullptr&&p2!=nullptr&&p1->val!=p2->val)
                    return false;//都非空 但是值不相等 不是镜像
                if(p1!=nullptr)//非空节点 放入子节点
                {
                    q1.push(p1->left);//左子树先左
                    q1.push(p1->right);//后右模拟镜像
                }
                if(p2!=nullptr)//非空节点 放入子节点
                {
                    q2.push(p2->right);//右子树先右
                    q2.push(p2->left);//后坐 模拟镜像
                }
            }
        }
        return true;//是对称二叉树
    }

};
