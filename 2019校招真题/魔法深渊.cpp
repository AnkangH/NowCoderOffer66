/*
前几个月放映的头号玩家简直火得不能再火了，作为一个探索终极AI的研究人员，月神自然去看了此神剧。
由于太过兴奋，晚上月神做了一个奇怪的梦，月神梦见自己掉入了一个被施放了魔法的深渊，月神想要爬上此深渊。
已知深渊有N层台阶构成（1 <= N <= 1000)，并且每次月神仅可往上爬2的整数次幂个台阶(1、2、4、....)，请你编程告诉月神，月神有多少种方法爬出深渊
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int m;
    cin>>m;
    vector<int> ladder(m);//保存输入的每个台阶数
    int maxLadder=0;//记录最大台阶数 作为递推的终点
    for(int i=0;i<m;i++)
    {
        cin>>ladder[i];//获取输入
        maxLadder=max(maxLadder,ladder[i]);//求最大台阶数
    }
    vector<long> method(maxLadder+1);//用long保存 防止超范围 因为要对10^9取余 而后者为long
    method[0]=1;//作为2的幂台阶数的起点台阶
    for(int i=1;i<=maxLadder;i++)
    {
        int j=1;//最后一次跳的台阶数为1 2 4 ...2^i
        while(j<=i)//j从1开始遍历2的幂直到 2^i>i
        {
            method[i]+=method[i-j];//最后一次跳2^i 则是从第i-2^i阶跳过来的
            j=j<<1;//j*=2 遍历2的幂
        }
        method[i]=method[i]%(long(pow(10,9))+3);//防止超范围 取余
    }
    for(int i=0;i<m;i++)
        cout<<method[ladder[i]]<<endl;//输出输入的台阶数对应的方法数
    return 0;
}
