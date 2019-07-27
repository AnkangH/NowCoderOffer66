/*
你在玩一个回合制角色扮演的游戏。现在你在准备一个策略，以便在最短的回合内击败敌方角色。在战斗开始时，敌人拥有HP格血量。
当血量小于等于0时，敌人死去。一个缺乏经验的玩家可能简单地尝试每个回合都攻击。但是你知道辅助技能的重要性。
在你的每个回合开始时你可以选择以下两个动作之一：聚力或者攻击。
    聚力会提高你下个回合攻击的伤害。
    攻击会对敌人造成一定量的伤害。如果你上个回合使用了聚力，那这次攻击会对敌人造成buffedAttack点伤害。否则，会造成normalAttack点伤害。
给出血量HP和不同攻击的伤害，buffedAttack和normalAttack，返回你能杀死敌人的最小回合数。
*/


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,k1,k2;
    cin>>n;
    cin>>k1;
    cin>>k2;
    if(n<=k1)
        cout<<1<<endl;//血量小于等于normal 一回合就能结束
    if(k1*2>=k2)//两次normal比一次Buff高 只使用normal攻击
    {
        if(n%k1==0)
            cout<<n/k1<<endl;//整除 返回商
        else
            cout<<n/k1+1<<endl;//否则多攻击一次
    }
    else//buff比两次normal高 优先使用buff攻击 当剩余血量小于normal时 使用一次normal即可解决
    {
        int cnt=0;//记录总次数
        while(n>k1)//优先使用buff攻击
        {
            n-=k2;//剩余血量
            cnt+=2;//当前次数
        }
        if(n>0)
            cnt+=1;//剩余血量小于一次normal攻击 次数+1
        cout<<cnt<<endl;
    }
    return 0;
}
