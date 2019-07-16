/*
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。
("回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。)
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
输入描述:
输入一个字符串S 例如“aabcb”(1 <= |S| <= 50), |S|表示字符串S的长度。
输出描述:
符合条件的字符串有"a","a","aa","b","c","b","bcb"
所以答案:7
*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();//字符串长度
    vector<vector<bool>> dp(n,vector<bool>(n,0));//dp[i][j] 从i到j的子串是否为回文串
    int res=0;//记录回文子串的个数
    for(int i=n-1;i>=0;i--)//i降序
        for(int j=i;j<n;j++)//j升序 且j>=i
        {
            if(i==j)
                dp[i][j]=true;//一个字母是回文字符串
            else if(j-i==1)//首尾相邻
            {
                if(s[i]==s[j])
                    dp[i][j]=true;//相同为回文
                else
                    dp[i][j]=false;//不同不为回文
            }
            else//首尾不相邻
            {
                if(dp[i+1][j-1]==true&&s[i]==s[j])//中间为回文且首尾相同为回文
                    dp[i][j]=true;
                else
                    dp[i][j]=false;//否则不为回文
            }
            if(dp[i][j]==true)
                res++;//记录回文子串的个数
        }
    cout<<res<<endl;
    return 0;
}
