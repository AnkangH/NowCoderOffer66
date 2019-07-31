/*
功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）
最后一个数后面也要有空格
*/


#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
bool isPrime(long x);
int main()
{
    long num;
    cin>>num;
    vector<long> prime;//质数表
    if(isPrime(num))//输入的数字为质数
    {
        cout<<num<<" ";
        return 0;
    }
    for(long i=2;i<=num;i++)//从小到大遍历数字
        if(isPrime(i))
            prime.push_back(i);//构建质数表
    while(num>1)
    {
        for(auto p:prime)//遍历质数表
        {
            if(num%p==0)//能整除当前质数
            {
                cout<<p<<" ";
                num/=p;//作为当前质因数 更新商
                break;
            }
        }
    }
    return 0;
}
bool isPrime(long x)
{
    /*
    //判断一个数是否为质数 合数必有一个因数在开方左侧 一个在右侧
    if(x<=3)
        return x>1;
    long end=sqrt(x);
    for(long i=2;i<=end;i++)
        if(x%i==0)
            return false;
    return true;*/
    //使用6x判断质数
    if(x<=3)
        return x>1;
    if(x%6!=1&&x%6!=5)
        return false;
    int end=sqrt(x);
    for(int i=5;i<=end;i+=6)
        if(x%i==0||x%(i+2)==0)
            return false;
    return true;
}
