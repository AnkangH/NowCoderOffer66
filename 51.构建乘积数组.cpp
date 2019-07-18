/*
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
*/


class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> res;
        if(A.empty())
            return res;//防止A空
        int n=A.size();//元素个数
        res=vector<int>(n,1);//乘积 初值为1
        int temp=1;//乘法初值
        for(int i=0;i<n;i++)
        {
            res[i]*=temp;
            temp*=A[i];
        }
        //A            a0            a1           a2             a3
        //res round1   1             a0          a0*a1        a0*a1*a2
        temp=1;
        for(int i=n-1;i>=0;i--)
        {
            res[i]*=temp;
            temp*=A[i];
        }
        //A            a0            a1           a2             a3
        //res round1   1             a0          a0*a1        a0*a1*a2
        //res round2   a3*a2*a1      a3*a2         a3             1
        //res          a1*a2*a3      a0*a2*a3   a0*a1*a3      a0*a1*a2
        return res;
    }
};
