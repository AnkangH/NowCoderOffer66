/*
牛牛去犇犇老师家补课，出门的时候面向北方，但是现在他迷路了。虽然他手里有一张地图，但是他需要知道自己面向哪个方向，请你帮帮他。
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含一个正整数，表示转方向的次数N(N<=1000)。
接下来的一行包含一个长度为N的字符串，由L和R组成，L表示向左转，R表示向右转。
输出描述:
输出牛牛最后面向的方向，N表示北，S表示南，E表示东，W表示西。
示例1
输入
3
LRR
输出
E
*/


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char c;
    vector<char> turn(2);//0左转次数 1右转次数
    for(int i=0;i<n;i++)
    {
        cin>>c;
        if(c=='L')//左转
        {
            if(turn[1]>0)
                turn[1]--;//右转次数不为0 抵消右转次数
            else
                turn[0]++;//右转次数为0 增加左转次数
        }
        else//右转
        {
            if(turn[0]>0)
                turn[0]--;//左转次数不为0  抵消左转次数
            else
                turn[1]++;//左转次数为0  增加右转次数
        }
    }
    int k=turn[0]-turn[1];//左转次数-右转次数
    bool dir=true;//默认左转
    if(k<0)
    {
        dir=false;//右转
        k*=-1;//旋转次数区正
    }
    k=k%4;//同方向每旋转4次回到原点
    if(k==0)
        cout<<"N"<<endl;//未旋转或旋转回到原点
    else if(k==1)//旋转一次
    {
        if(dir)
            cout<<"W"<<endl;//左转一次
        else
            cout<<"E"<<endl;//左转两次
    }
    else if(k==2)//旋转两次
        cout<<"S"<<endl;//同方向旋转两次（左右均可）在S
    else//旋转3次
    {
        if(dir)
            cout<<"E"<<endl;//左转3次
        else
            cout<<"W"<<endl;//右转3次
    }
    return 0;
}
