/*
题目：输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)
解析：根本思想是DFS深度优先搜索，在二叉树中DFS等同于先序遍历。
采用递归方法，先左后右，直到和满足且到达叶节点。
判断节点值与target是否相等，若不等，递归，递归中的新target为节点值与旧target的差值
比如   1
     2  3   target为5
1加入path，和不满足，且左右子树存在，进入左子树递归
2加入path，和不满足，左右子树不存在，2被pop出队列
此时递归进入1的右子树，3入队列，和不满足，3被pop出队列
此时程序运行到第一次递归的pop，1被pop出队列
从而可以实现对整个二叉树的遍历
为了使每次递归都能保存path，path和path的集合要为全局变量。
*/
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
    vector<vector<int>> res;//路径集合
    vector<int> path;//某一条路径
    void find(TreeNode* t,int target)
    {
        path.push_back(t->val);//当前节点加入path
        if(t->val==target&&t->left==NULL&&t->right==NULL)
            res.push_back(path);//满足条件
        if(t->left!=NULL)
            find(t->left,target-t->val);//递归左子树
        if(t->right!=NULL)
            find(t->right,target-t->val);//递归右子树
        path.pop_back();//注意这里要把path中最后一个节点删除
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==NULL)
            return res;//空树判断
        find(root,expectNumber);//进入递归
        return res;
    }
};
