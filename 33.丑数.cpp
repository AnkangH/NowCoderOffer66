/*
题目描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/


class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index==0)
            return 0;//弱智边界条件
        vector<int> ugly(index,1);//丑数数组 第一个丑数为1
        vector<int> idx(3,0);//2 3 5应该乘的丑数索引
        for(int i=1;i<index;i++)//递推n-1次 最后为第n个丑数
        {
            int a=ugly[idx[0]]*2;//乘2
            int b=ugly[idx[1]]*3;//乘3
            int c=ugly[idx[2]]*5;//乘5
            int cur=min(a,min(b,c));//取当前乘积最小的作为当前丑数 即第i+1个丑数
            if(a==cur)
                idx[0]++;//防止重复
            if(b==cur)
                idx[1]++;//防止重复
            if(c==cur)
                idx[2]++;//防止重复
            ugly[i]=cur;//更新当前丑数
        }
        return ugly[index-1];//返回第n个丑数
    }
};
