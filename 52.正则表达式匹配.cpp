/*
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/


class Solution {
public:
    bool match(char* str, char* pattern)
    {
        string s,p;
        while(*str!='\0')
        {
            s+=*str;
            str++;
        }
        while(*pattern!='\0')
        {
            p+=*pattern;
            pattern++;
        }
        int m=s.size();
        int n=p.size();
        cout<<m<<n<<endl;
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;//空字符串匹配
        for(int j=2;j<=n;j++)//dp[0][1]一定不匹配
            if(p[j-1]=='*')
                dp[0][j]=dp[0][j-1]||dp[0][j-2];//删除*或删除*及前一个字母之后是否为空
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='.')
                    dp[i][j]=dp[i-1][j-1];//判断s(i-1)和p(j-1)的匹配关系
                else if(p[j-1]=='*'&&j>=2)
                {
                    if(p[j-2]==s[i-1]||p[j-2]=='.')
                        dp[i][j]=dp[i][j-1]||dp[i][j-2]||dp[i-1][j-1]||dp[i-1][j];//删除1，2个，重复1，2个
                    else
                        dp[i][j]=dp[i][j-2];//删除2个
                }
            }
        return dp[m][n];
    }
};
