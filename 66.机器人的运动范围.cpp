/*
题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，
但是不能进入行坐标和列坐标的数位之和大于k的格子。 
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），
因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/


class Solution {
public:
    int movingCount(int k, int rows, int cols)
    {
        int res=0;
        vector<vector<bool>> dp(rows,vector<bool>(cols,false));//dp[i][j] 代表第i，j个格子能否到达
        dp[0][0]=true;//出发点可达
        for(int i=0;i<rows;i++)
            for(int j=0;j<cols;j++)
            {
                if(add(i,j)>k)
                    dp[i][j]=false;//位和>k 不可达到
                else//否则可能到达 需要判断上下左右四个格子是否可达
                {
                    if(i-1>=0)
                        dp[i][j]=dp[i][j]||dp[i-1][j];//上侧格子存在 可达性等于上侧格子
                    if(i+1<rows)
                        dp[i][j]=dp[i][j]||dp[i+1][j];//下侧格子存在 可达性等于上侧格子
                    if(j-1>=0)
                        dp[i][j]=dp[i][j]||dp[i][j-1];//左侧格子存在 可达性等于上侧格子
                    if(j+1<cols)
                        dp[i][j]=dp[i][j]||dp[i][j+1];//右侧格子存在 可达性等于上侧格子
                }
                if(dp[i][j])
                    res++;//如果当前格子可达 记录可达格子的数目
            }
        return res;//返回所有可达格子的数目
    }
    int add(int a,int b)//求十进制数字a和b的位和 即每一位数字之和
    {
        int res=0;
        while(a>0||b>0)//a的各位之和+b的各位之和
        {
            res+=a%10;
            res+=b%10;
            a/=10;
            b/=10;
        }
        return res;
    }
};
