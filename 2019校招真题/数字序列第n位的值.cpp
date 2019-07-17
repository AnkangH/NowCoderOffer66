/*
题目描述
有一个无限长的数字序列1，2，2，3，3，3，4，4，4，4，5，5，5，5，5。。。（数字序列从1开始递增，且数字k在该序列中正好出现k次），求第n项是多少
输入描述:
输入为一个整数n
输出描述:
输出一个整数，即第n项的值
*/


#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int cur=1;//当前数字
    int i=cur;//当前数字的第几个
    int cnt=1;
    while(cnt<n)
    {
        i--;//遍历当前数字出现的每一个
        cnt++;//记录总的遍历个数
        if(i==0)//当前数字遍历完
        {
            cur++;//遍历下个数字
            i=cur;//待遍历数字的个数
        }
    }
    cout<<cur<<endl;
    return 0;
}
