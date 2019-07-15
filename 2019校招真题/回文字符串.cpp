/*
题目描述
最大回文子串是被研究得比较多的一个经典问题。最近月神想到了一个变种，对于一个字符串，如果不要求子串连续，那么一个字符串的最大回文子串的最大长度是多少呢。
输入描述:
每个测试用例输入一行字符串（由数字0-9，字母a-z、A-Z构成），字条串长度大于0且不大于1000.
输出描述:
输出该字符串的最长回文子串的长度。（不要求输出最长回文串，并且子串不要求连续）
示例1
输入
adbca
输出
3
说明
因为在本题中，不要求回文子串连续，故最长回文子串为aba(或ada、aca)
备注:
因为不要求子串连续，所以字符串abc的子串有a、b、c、ab、ac、bc、abc7个
*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int res=0;
    int n=s.size();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=n-1;i>=0;i--)
        for(int j=i;j<n;j++)
        {
            if(i==j)//相等
                dp[i][j]=1;
            else if(j-i>=2)//不相邻
            {
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1]+2;//因为只考虑中间的最大长度和
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);//分别不包含左右的最大回文子序列长度
            }
            else//相邻
            {
                if(s[i]==s[j])
                    dp[i][j]=2;//相同为2
                else
                    dp[i][j]=1;//不同为1
            }
            res=max(res,dp[i][j]);//记录最大回文子序列长度
        }
    cout<<res<<endl;
    return 0;
}
