/*
题目描述
给定一个正整数数组，它的第 i 个元素是比特币第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一次），设计一个算法来计算你所能获取的最大利润。
注意你不能在买入比特币前卖出。
输入描述:
正整数数组，为以空格分隔的n个正整数
输出描述:
最大利润
*/


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> nums;
    int temp;
    char c;
    while(1)
    {
        cin>>temp;
        nums.push_back(temp);
        cin.get(c);
        if(c=='\n')
            break;
    }
    int pre=nums[0];//购入价格初始值
    int n=nums.size();//股票数目
    int res=0;//最大利润
    for(int i=1;i<n;i++)//遍历剩余股票
    {
        if(nums[i]>pre)//有利润
            res=max(res,nums[i]-pre);//获取卖出利润的最大值
        else//当前价格小于初始值
            pre=nums[i];////以当前价格购入
    }
    cout<<res<<endl;
    return 0;
}
