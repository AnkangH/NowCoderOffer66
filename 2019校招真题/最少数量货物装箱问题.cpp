/*
有重量分别为3，5，7公斤的三种货物，和一个载重量为X公斤的箱子（不考虑体积等其它因素，只计算重量）
需要向箱子内装满X公斤的货物，要求使用的货物个数尽可能少（三种货物数量无限）

输入描述:
输入箱子载重量X(1 <= X <= 10000)，一个整数。
输出描述:
如果无法装满，输出 -1。
如果可以装满，输出使用货物的总个数。
*/


//回溯法+提前退出
#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<int>& temp,int target,int val);//回溯法
vector<vector<int>> res;//保存组合方法
bool flag=true;//是否已找到方法
int main()
{
    int target;
    cin>>target;
    vector<int> temp;//方法暂存变量
    dfs(temp,target,7);//先7
    dfs(temp,target,5);//后5
    dfs(temp,target,3);//后3
    if(res.empty())
        cout<<"-1"<<endl;//没有方法
    else
        cout<<res[0].size()<<endl;//输出货物最少的方法
    return 0;
}
void dfs(vector<int>& temp,int target,int val)
{
    temp.push_back(val);//当前选取的货物放入方法暂存
    if(target==val)//箱子装满
    {
        res.push_back(temp);//当前方法放入结果
        flag=false;//已找到方法
    }
    //不是3选1 而是优先级 7 5 3 否则有的组合被跳过
    if(target-val>=7&&flag)//当前剩余值大于等于7 
        dfs(temp,target-val,7);//先放7
    if(target-val>=5&&flag)//当前剩余值大于等于5
        dfs(temp,target-val,5);//再放置5
    if(target-val>=3&&flag)//当前剩余值大于等于3
        dfs(temp,target-val,3);//再放置3
    temp.pop_back();//尾回溯 删除本轮添加的货物
}


//dp解法
#include<iostream>
#include<vector>
#include<limits.h>// for INT_MAX
using namespace std;
int main()
{
    int target;
    cin>>target;
    vector<int> dp(target+1,INT_MAX);//dp[i] 装满体积为i的箱子所需最少货物数目
    dp[3]=1;
    dp[5]=1;
    dp[7]=1;
    dp[6]=2;//初始化
    for(int i=8;i<=target;i++)//递推过程
    {
        int a=dp[i-3],b=dp[i-5],c=dp[i-7];//a b c分别代表i-3 i-5 i-7再装一个货物
        if(a==INT_MAX&&b==INT_MAX&&c==INT_MAX)
            dp[i]=INT_MAX;//表示i不能被被装满
        else
            dp[i]=min(min(a,b),c)+1;//最少的货物数目+1
    }
    if(dp[target]==INT_MAX)
        cout<<"-1"<<endl;//不能被被装满
    else
        cout<<dp[target]<<endl;//输出最少货物数目
    return 0;
}
