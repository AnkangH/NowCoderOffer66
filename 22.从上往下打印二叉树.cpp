/*
题目：从上往下打印出二叉树的每个节点，同层节点从左至右打印。
解析：
节点的移动从上往下，从左往右，因为节点的移动顺序是先入先出，
所以采用一个队列来保存每个节点。
1.root-l-r  l左节点 r右节点
2.l-r-ll-lr //ll代表l的左节点，lr代表l的右节点
3.r-ll-lr-rl-rr
4....
每次读取节点的左右节点并push，保存该值，同时pop出首个元素，循环结束条件为队列为空。
*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);//根节点入队列
        TreeNode* front;//队列首节点
        while(!q.empty())
        {
            front=q.front();//读取队列首节点
            res.push_back(front->val);//值保存到返回队列中
            if(front->left!=NULL)
                q.push(front->left);//左节点入队列
            if(front->right!=NULL)
                q.push(front->right);//右节点入队列
            q.pop();//队列首向后移动
        }
        return res;
    }
};
