/*
    小明在越南旅游，参加了当地的娱乐活动。小明运气很好，拿到了大奖， 到了最后的拿奖金环节。小明发现桌子上放着一列红包，每个红包上写着奖金数额。
现在主持人给要求小明在这一列红包之间“切”2刀，将这一列红包“切”成3组，并且第一组的奖金之和等于最后一组奖金和（允许任意一组的红包集合是空）。
最终第一组红包的奖金之和就是小明能拿到的总奖金。小明想知道最多能拿到的奖金是多少，你能帮他算算吗。
    举例解释：桌子上放了红包  1, 2, 3, 4, 7, 10。小明在“4,7”之间、“7,10” 之间各切一刀，将红包分成3组 [1, 2, 3, 4]   [7]   [10]，
其中第一组奖金之和=第三组奖金之和=10，所以小明可以拿到10越南盾。
*/


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> nums(n,0);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    int l=0,r=n-1;
    long maxVal=0;
    long lval=0,rval=0;
    bool lf=true,rf=true;
    while(l<r)
    {
        if(lf)
            lval+=nums[l];
        if(rf)
            rval+=nums[r];
        if(lval==rval)
        {
            l++;
            r--;
            lf=true;
            rf=true;
            maxVal=lval;
        }
        else if(lval<rval)
        {
            l++;
            lf=true;
            rf=false;//r没动 右边和不加
        }
        else
        {
            r--;
            rf=true;
            lf=false;//l没动 左边和不加
        }
    }
    cout<<maxVal<<endl;
    return 0;
}
