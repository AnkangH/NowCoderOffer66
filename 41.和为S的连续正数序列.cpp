/*
输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序。序列至少包含两个数字。
*/

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        for(int i=1;i<=sum/2;i++)//连续和 所以最大的组合为sum/2开始，如100时，若50+51不满足 则其后的均不满足。
            dfs(res,{},sum,i);//从i开始dfs连续数字
        return res;
    }
    void dfs(vector<vector<int>>& res,vector<int> temp,int sum,int index)
    {
        if(index>sum)
            return;//全为正数 当前和若大于sum 则其后必不满足
        temp.push_back(index);//index<=sum 当前数字放入组合
        if(index==sum)//满足连续和
        {
            int size=temp.size();
            if(size<=1)//题目要求至少两个数
                return;//排除掉一个数等于sum的情况
            res.push_back(temp);
            return;
        }
        dfs(res,temp,sum-index,index+1);//不满足连续和 继续找相邻数字
    }
};
