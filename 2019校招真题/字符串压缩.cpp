/*
对字符串进行RLE压缩，将相邻的相同字符，用计数值和字符值来代替。例如：aaabccccccddeee，则可用3a1b6c2d3e来代替。
*/


#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int cnt=1;//当前计数值
    char c=s[0];//当前字母
    int size=s.size();
    for(int i=1;i<size;i++)//遍历字符串
    {
        if(s[i]==c)//重复字母
            cnt++;//增加计数
        else
        {
            cout<<cnt<<c;//打印上个字母及重复次数
            c=s[i];//更新当前字母
            cnt=1;//更新当前重复次数
        }
    }
    cout<<cnt<<c;//打印最后一个字母及其重复次数
    return 0;
}
