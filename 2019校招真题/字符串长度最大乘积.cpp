/*
题目描述
已知一个字符串数组words，要求寻找其中两个没有重复字符的字符串，使得这两个字符串的长度乘积最大，输出这个最大的乘积。如：
words=["abcd","wxyh","defgh"], 其中不包含重复字符的两个字符串是"abcd"和"wxyh"，则输出16
words=["a","aa","aaa","aaaa"], 找不到满足要求的两个字符串，则输出0
输入描述:
Input:

["a","ab","abc","cd","bcd","abcd"]
输出描述:
Output:

4
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<string> str;
    string temp;
    char c;
    while(1)
    {
        cin.get(c);//获取一个字符
        if(c-'a'>=0&&c-'a'<26)
            temp+=c;//小写字母放入字符串暂存
        else
        {
            str.push_back(temp);//字母字符串放入数组
            temp.clear();//清空字符串暂存以便继续处理
            if(c=='\n')//到达输入末尾
                break;//退出
        }
    }
    int res=0;
    int size=str.size();
    for(int i=0;i<size;i++)//每个字符串
        for(int j=i+1;j<size;j++)//与其后的字符串
        {
            bool dif=true;
            vector<bool> exist(26,false);//记录出现的字母
            for(auto p:str[i])
                exist[p-'a']=true;//s1出现字母
            for(auto p:str[j])
            {
                if(exist[p-'a']==true)//s2中重复
                {
                    dif=false;
                    break;//退出
                }
            }
            if(dif)//不重复
            {
                int li=str[i].size();
                int lj=str[j].size();
                res=max(res,li*lj);//长度求和
            }
            
        }
    cout<<res<<endl;
    return 0;
}
