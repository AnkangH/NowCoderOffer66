/*
题目：
给定一个无序数组，数组长度为n，求数组连续子序列的最大和。
如[1,-2,-6,9,1,-2,4] 则最大和为9+1-2+4=12
解析：
这里需要保存两个量，一是i是否包含在前i个数字的最大连续子序列中，二是前i个数字的最大连续子序列是多少，
之后出现的有没有比这个和更大的连续子序列。
方法一：BruteFore 
O（N*N*N）将数组所有子序列的可能结果求和，并求最大值。有优化为O（N*N）的算法
方法二：使用两个变量，max记录前i个数字的最大连续子序列和，sum记录包含i的连续子序列和。
只要sum不小于0，就保存，因为后面arr[i+1]为正，那么+sum（>0）肯定比不加sum大。如果sum<0
令sum=0，即前面的子序列和为负，不使用，将前面的子序列扔掉。
max=max(sum[i-1],sum[i])
sum+=arr[i],if(sum<0)sum=0
方法三：动态规划
这道题目不能使用标准动态规划法求解。
dp[i]如果指前i个数字的连续子序列最大和 那么如果这个连续子序列不包括arr[i]，则出现推导中断，
因为dp[i]！=dp[i-1]+arr[i]。如果dp[i]是指包含arr[i]的连续子序列的最大和，那么推断出错，因为
最大子序列可能不包含i。
这里做出修正，dp[i]指前i个数字的最大连续子序列和，但是因为dp[i]要参与递推，所以当dp[i]<0时，dp[i]=0
这样的话，求最大值时的比较要在修改dp[i]数值之前。否则当数组全为负数时，0一定是最大值。
*/

//方法一
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int res=INT_MIN;
        int temp=0;
        int size=array.size();
        for(int i=0;i<size;i++)
            for(int j=i;j<size;j++)
            {
                for(int k=i;k<=j;k++)
                {
                    temp+=array[k];//sum(arr[k]),k=[i,j];
                }
                res=max(res,temp);//求最大和
                temp=0;//下一轮求和，和置0
            }
        return res;
    }
};

//方法二
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int size=array.size();
        int sum=array[0];//记录当前和
        int res=array[0];//记录最大和
        for(int i=1;i<size;i++)
        {
            sum+=array[i];//求和
            if(sum>res)//或res=max(res,sum);
                res=sum;//先确定当前和与最大和的大小 因为下面会修改sum的值 当sum<0时，不一定不是最大值。
            if(sum<0)
                sum=0;//sum<0说明后面的数字一定不能再加sum 否则和一定变小 那么将前面的子序列全部扔掉 求后面的子序列的和
        }
        return res;
    }
};

//方法三
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int size=array.size();
        vector<int>dp(size,0);//递推结果保存
        dp[0]=array[0];//dp初值
        int res=dp[0];//最大和初值
        for(int i=1;i<size;i++)
        {
            dp[i]=dp[i-1]+array[i];//求和
            res=max(res,dp[i]);//保存最大和
            if(dp[i]<0)
                dp[i]=0;//和修正
        }
        return res;
    }
};
