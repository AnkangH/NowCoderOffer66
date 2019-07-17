/*
题目描述
整数的倒数
输入描述:
输入一个整数x
输出描述:
把x倒序输出
*/


#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int size=s.size();
    if(s[0]=='-')
    {
        cout<<s[0];
        for(int i=size-1;i>=1;i--)
            cout<<s[i];
    }
    else
    {
        for(int i=size-1;i>=0;i--)
            cout<<s[i];
    }
    cout<<endl;
    return 0;
}
