/*
题目描述
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
*/


class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(pRoot==nullptr)
            return res;//空树返回空
        queue<TreeNode*> q;//辅助队列 用于层序遍历
        q.push(pRoot);
        bool turn=false;//翻转层序的标志位
        while(!q.empty())
        {
            int size=q.size();
            vector<int> temp;//当前层的顺序
            for(int i=0;i<size;i++)//遍历当前层
            {
                auto p=q.front();//当前节点
                q.pop();//访问完出队列 防止重复访问
                temp.push_back(p->val);
                if(p->left!=nullptr)
                    q.push(p->left);//先左
                if(p->right!=nullptr)
                    q.push(p->right);//后右
            }
            if(turn)//偶数层 翻转左右顺序 先右后坐
                reverse(temp.begin(),temp.end());
            res.push_back(temp);//放入最终结果
            turn=!turn;//标志位取反
        }
        return res;
    }
    
};
