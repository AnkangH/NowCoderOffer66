/*
题目描述
一个非空整数数组，选择其中的两个位置，使得两个位置之间的数和最大。
如果最大的和为正数，则输出这个数；如果最大的和为负数或0，则输出0
输入描述:
3,-5,7,-2,8
输出描述:
13
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> nums;
    while(1)
    {
        int temp;
        cin>>temp;//获取数字
        nums.push_back(temp);//放入数组
        char c;
        cin.get(c);//获取','
        if(c=='\n')
            break;//到达输入末尾 退出
    }
    int sum=0;//当前和
    int res=0;//最大和
    for(auto p:nums)
    {
        sum+=p;//当前和+当前数字
        if(sum<0)
            sum=0;//小于0的当前和减小其后的子串和 所以去掉
        res=max(res,sum);//保存最大和
    }
    if(res<=0)
        cout<<0<<endl;//小于等于0 输出0
    else
        cout<<res<<endl;//输出最大连续和
    return 0;
}
