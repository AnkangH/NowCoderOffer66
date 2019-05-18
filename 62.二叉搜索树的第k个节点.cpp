/*
题目：
给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。
解析：
二叉搜索树的节点值各异，左节点的值<根节点的值<右节点的值
所以二叉搜索树的中序遍历（左根右）即是二叉搜索树的有序序列。有序序列的第k-1个元素即为二叉搜索树第k小节点的值。
由于要求返回该节点，因为节点值唯一，所以使用任意遍历方法，找出节点值为这个值的节点即可。这里使用辅助队列进行
层次遍历。
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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL)
            return NULL;
        vector<int> arr;
        preOrder(pRoot,arr);//中序遍历获取第k小的节点值
        int size=arr.size();
        if(k>size)
            return NULL;//检测可k值是否合理
        int k_val=arr[k-1];//获取该节点的值
        queue<TreeNode*> q;//辅助队列
        q.push(pRoot);
        while(!q.empty())//层次遍历，找到节点值等于上面的值 即为要找的节点
        {
            TreeNode* t=q.front();
            q.pop();
            if(t->val==k_val)
                return t;//找到该节点
            if(t->left!=NULL)
                q.push(t->left);
            if(t->right!=NULL)
                q.push(t->right);
        }
        return NULL;
    }
    void preOrder(TreeNode* head,vector<int>& arr)//中序遍历
    {
        if(head==NULL)
            return;
        preOrder(head->left,arr);
        arr.push_back(head->val);
        preOrder(head->right,arr);
    }
};
