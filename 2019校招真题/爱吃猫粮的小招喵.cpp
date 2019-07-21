/*
题目描述
小招喵喜欢吃喵粮。这里有 N 堆喵粮，第 i 堆中有 p[i] 粒喵粮。喵主人离开了，将在 H 小时后回来
小招喵可以决定她吃喵粮的速度 K （单位：粒/小时）。每个小时，她将会选择一堆喵粮，从中吃掉 K 粒。如果这堆喵粮少于 K 粒，她将吃掉这堆的所有喵粮，
然后这一小时内不会再吃更多的喵粮。  
小招喵喜欢慢慢吃，但仍然想在喵主人回来前吃掉所有的喵粮。
返回她可以在 H 小时内吃掉所有喵粮的最小速度 K（K 为整数）。
输入描述:
第一行输入为喵粮数组，以空格分隔的N个整数

第二行输入为H小时数
输出描述:
最小速度K
*/


#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int main()
{
    vector<int> nums;
    int temp,n;
    char c;
    while(1)
    {
        cin>>temp;
        nums.push_back(temp);
        cin.get(c);
        if(c=='\n')
            break;
    }
    cin>>n;
    int l=1,r=INT_MIN;//最小速度为1
    for(auto p:nums)
        r=max(r,p);//最大速度为max(nums) 大于此速度 时间均为nums数组的元素个数
    while(l<r)
    {
        int mid=(r-l)/2+l;
        int h=0;
        for(auto p:nums)
        {
            if(p%mid==0)
                h+=p/mid;//能整除的 吃整数除法次
            else
                h+=p/mid+1;//否则多吃一次
        }
        if(h<=n)
            r=mid;//吃的太快了 减小速度
        else
            l=mid+1;//吃的太慢了 增大速度
    }
    cout<<l<<endl;
    return 0;
}
