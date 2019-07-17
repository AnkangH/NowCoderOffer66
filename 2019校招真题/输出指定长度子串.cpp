/*
题目描述
给定一个字符串，输出所有指定长度为n的子串，没有则输出-1
输入描述:
输入第一行一个字符串，如：“1234567890”

输入第二行一个数字是n，如5
输出描述:
输出所有长度为n的子串，如“12345”，“23456”，“34567”，“45678”，“56789”
*/


#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    int n;
    cin>>s;
    int size=s.length();
    cin>>n;
    if(size<n||n<1)
        cout<<-1<<endl;
    else
    for(int i=0;i<=size-n;i++)
    {
        cout<<s.substr(i,n);
        if(i<size-n)
            cout<<" ";
        else
            cout<<endl;
    }
    return 0;
}
