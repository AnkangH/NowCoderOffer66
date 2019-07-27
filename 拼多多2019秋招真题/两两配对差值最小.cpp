/*
给定一个长度为偶数的数组arr，将该数组中的数字两两配对并求和，在这些和中选出最大和最小值，
请问该如何两两配对，才能让最大值和最小值的差值最小？
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    sort(nums.begin(),nums.end());//升序排序数组
    int l=0,r=n-1;//双指针从首尾相向移动
    int minVal=INT_MAX,maxVal=INT_MIN;//记录最大和最小配对和
    while(l<r)
    {
        int temp=nums[l]+nums[r];//最大值+最小值 这样和的差异最小
        minVal=min(minVal,temp);//更新最小和
        maxVal=max(maxVal,temp);//更新最大和
        l++;
        r--;
    }
    cout<<maxVal-minVal<<endl;
    return 0;
}
