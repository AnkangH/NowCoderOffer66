/*
题目：一只青蛙每次可以跳一阶或两阶台阶，问青蛙跳上n阶台阶共有多少种跳法。
解析：斐波那契数列问题。
n     f(n)
1       1
2       2   (11  2)
3       3   (111 21 12)             f(2)+f(1)最后一次跳一阶+最后一次跳两阶
4       5   (1111 211 121 112 22)   f(3)+f(2)最后一次跳一阶+最后一次跳两阶
...
对于任意的k，有f(k)=f(k-1)+f(k-2)，因为无论n为多少都只有两种情况，最后一次跳一阶和
最后一次跳两阶，这两种情况都可以由<n的情况推出。
*/
class Solution {
public:
    int jumpFloor(int number) {
        if(number==0)
            return 0;//0阶
        if(number==1)
            return 1;//1阶
        if(number==2)
            return 2;//2阶
        int res=0;
        int pre1=2,pre2=1;//递推初值
        while(number-->2)
        {
            res=pre1+pre2;//更新当前值
            pre2=pre1;//更新前两个值
            pre1=res;//更新前一个值
        }
        return res;
    }
};
