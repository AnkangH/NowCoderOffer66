/*
题目：
从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
     1
   2   3
 4  5 6  7
输出vector<vector<int>>{{1},{2,3},{4,5,6,7}};
解析：
对于二叉树的按层遍历，应使用队列，每次循环时，队列中节点个数即为每一层的节点个数。根节点入队列，此时第一层，节点个数为1；
之后根节点的两个子节点如队列。此时队列大小为2，有两个子节点。则对这两个子节点均执行相同的操作，保存当前节点值，子节点入队列。
round   queue                                            vector
0       1 (1)       当前序列中有1个节点 结束时有2个         1
1       2 3 (2)     当前序列中有2个节点 结束时有4个         2 3
2       4 5 6 7(4)  当前序列中有4个节点 结束时有0个         4 5 6 7
以序列是否为空为每一层的结束条件，每一层循环的次数为上一层的子节点个数。
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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> res;//返回值
            queue<TreeNode*> que;//辅助队列
            if(pRoot==nullptr)
                return res;//空树返回空集合
            TreeNode* p=pRoot;//保存当前头
            que.push(p);//根节点入队列
            while(!que.empty())
            {
                vector<int> temp;//每次循环开始 temp为空 保存一层的节点值
                int size=que.size();//当前层的节点个数
                for(int i=0;i<size;i++)
                {
                    TreeNode* t=que.front();//当前节点
                    que.pop();//队列首出队列 遍历当前层
                    temp.push_back(t->val);//当前节点值
                    if(t->left!=nullptr)
                        que.push(t->left);//下一层左节点入队列
                    if(t->right!=nullptr)
                        que.push(t->right);//下一层右节点入队列
                }
                res.push_back(temp);//保存每一层的节点值
            }
            return res;
        }
};
