/*
通过键盘输入一串小写字母(a~z)组成的字符串。
请编写一个字符串归一化程序，统计字符串中相同字符出现的次数，并按字典序输出字符及其出现次数。
例如字符串"babcc"归一化后为"a1b2c2"
*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string str;
    cin>>str;
    vector<int> bucket(26,0);//26个桶 记录每个小写字母出现的次数
    for(auto p:str)
        bucket[p-'a']++;//记录
    for(int i=0;i<26;i++)
        if(bucket[i]!=0)//出现的字母
        {
            cout<<char('a'+i);//输出字母
            cout<<bucket[i];//输出出现次数
        }
    return 0;
}
