/*
题目：给定一个数字n，它的斐波那契数列和。
f(0)=0,f(1)=1,f(k)=f(k-1)+f(k-2)
解析：
使用非递归方法。记录两个变量pre1和pre2分别代表f(k-1)和f(k-2)
判断n-2与0的大小关系 确定加法执行的次数。、
因为f(0)=0,所以对结果没有影响，实际上的初始值是f(1)=1和f(2)=1
n=0   0
n=1   1
n=2   1
n=3   2
n=4   3
n=3时，执行了1+1 一次
n=4时，执行了f(4)=f(3)+f(2)=f(2)+f(1)+f(2) 两次
n=5时，三次  1(pre1)+1(pre2)=2(cur)，pre2=pre1=1,pre1=cur=2
            2(pre1)+1(pre2)=3(cur), pre2=pre1=2,pre1=cur=3
            3(pre1)+2(pre2)=5(cur)
对于任意k，执行了k-2次，返回cur值即为f(k)
...
*/
class Solution {
public:
    int Fibonacci(int n) {
        if(n==0)
            return 0;//f(0)=0
        if(n==1)
            return 1;//f(1)=1
        if(n==2)
            return 1;//f(2)=1
        int pre1=1,pre2=1;
        int res=0;
        while(n-->2)
        {
            res=pre1+pre2;//前两项相加当前项
            pre2=pre1;//前两项移动变前一项
            pre1=res;//前一项移动变当前项
        }
        return res;
    }
};
