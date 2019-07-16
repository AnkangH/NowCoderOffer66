/*
小明有26种游戏海报，用小写字母"a"到"z"表示。小明会把游戏海报装订成册（可能有重复的海报），册子可以用一个字符串来表示，
每个字符就表示对应的海报，例如abcdea。小明现在想做一些“特别版”，然后卖掉。特别版就是会从所有海报（26种）中随机选一张，加入到册子的任意一个位置。
那现在小明手里已经有一种海报册子，再插入一张新的海报后，他一共可以组成多少不同的海报册子呢？
*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string str;
    cin>>str;
    vector<int> exist(26,0);//每个小写字母出现的次数
    for(int i=0;i<26;i++)
        for(auto p:str)
            if(p==i+'a')
                exist[i]++;//对应字母出现次数+1
    int size=str.size();
    int res=0;
    for(auto p:exist)
        res+=size+1-p;//size+1为插入位置减去因为重复造成的组合重复
    cout<<res<<endl;
    return 0;
}
