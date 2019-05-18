/*
题目：
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
解析：
斐波那契数列问题。
n=1时，只有一种。
n=2时，有两种。（横竖两种方法）
n=3，第一层为横+第一层为竖
第一层为横时，剩2*3-2*1=2*2=f(2)
第一层为竖时，剩2*3-2*2=2*1=f(1)
所以f(3)=f(2)+f(1)
n=4 第一层为横+第一层为竖
同理 f(4)=f(3)+f(2)
...
*/
class Solution {
public:
    int rectCover(int number) {
        int fib1=1;
        int fib2=2;
        int fib;
        if(number==0)
            return 0;
        else if(number==1)
            return 1;
        else if(number==2)
            return 2;
        else for(int i=3;i<=number;i++)
        {
            fib=fib1+fib2;
            fib1=fib2;
            fib2=fib;
        }
        return fib;
    }
};
