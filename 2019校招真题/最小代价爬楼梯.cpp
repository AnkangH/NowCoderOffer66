/*
题目描述
你需要爬上一个N层的楼梯，在爬楼梯过程中， 每阶楼梯需花费非负代价，第i阶楼梯花费代价表示为cost[i]， 一旦你付出了代价，
你可以在该阶基础上往上爬一阶或两阶。
你可以从第 0 阶或者 第 1 阶开始，请找到到达顶层的最小的代价是多少。
N和cost[i]皆为整数，且N∈[2,1000]，cost[i]∈ [0, 999]。
输入描述:
输入为一串半角逗号分割的整数，对应cost数组，例如
10,15,20
输出描述:
输出一个整数，表示花费的最小代价
*/


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> costs;
    int temp;
    char c;
    while(1)
    {
        cin>>temp;//获取一个数字
        costs.push_back(temp);//放入数组
        cin.get(c);//获取字符
        if(c=='\n')//如果为换行符
            break;//退出
    }
    int n=costs.size();//总的台阶数目
    vector<int> dp(n+1,0);//跳上第n阶（从0开始）所需的最小代价
    //dp[0]=0 从0阶出发
    //dp[1]=0 从1阶出发 初始值在初始化dp数组时可以一并赋值
    for(int i=2;i<=n;i++)
        dp[i]=min(dp[i-1]+costs[i-1],dp[i-2]+costs[i-2]);//由第i-1或i-2阶跳
    cout<<dp[n]<<endl;//输出跳上第n+1阶所需最小代价
    return 0;
}
