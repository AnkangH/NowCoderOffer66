/*
题目描述
输入年、月、日，计算该天是本年的第几天。 
输入： 
包括三个整数年(1<=Y<=3000)、月(1<=M<=12)、日(1<=D<=31)。 
输出： 
输入可能有多组测试数据，对于每一组测试数据， 
输出一个整数，代表Input中的年、月、日对应本年的第几天。

输入描述:
输入：1990 9 20
输出描述:
输入：263
*/


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> m={0,31,28,31,30,31,30,31,31,30,31,30,31};
    bool flag=false;
    int year,month,day;
    cin>>year>>month>>day;
    if((year%100==0&&year%400==0)||(year%100!=0&&year%4==0))
        m[2]=29;
    int res=0;
    for(int i=1;i<month;i++)
        res+=m[i];
    res+=day;
    cout<<res<<endl;
    return 0;
}
