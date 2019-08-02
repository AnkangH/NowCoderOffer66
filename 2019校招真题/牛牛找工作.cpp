/*
为了找到自己满意的工作，牛牛收集了每种工作的难度和报酬。牛牛选工作的标准是在难度不超过自身能力值的情况下，牛牛选择报酬最高的工作。在牛牛选定了自己的工作后，牛牛的小伙伴们来找牛牛帮忙选工作，牛牛依然使用自己的标准来帮助小伙伴们。牛牛的小伙伴太多了，于是他只好把这个任务交给了你。
输入描述:
每个输入包含一个测试用例。
每个测试用例的第一行包含两个正整数，分别表示工作的数量N(N<=100000)和小伙伴的数量M(M<=100000)。
接下来的N行每行包含两个正整数，分别表示该项工作的难度Di(Di<=1000000000)和报酬Pi(Pi<=1000000000)。
接下来的一行包含M个正整数，分别表示M个小伙伴的能力值Ai(Ai<=1000000000)。
保证不存在两项工作的报酬相同。
输出描述:
对于每个小伙伴，在单独的一行输出一个正整数表示他能得到的最高报酬。一个工作可以被多个人选择。
示例1
输入
复制
3 3 
1 100 
10 1000 
1000000000 1001 
9 10 1000000000
输出
复制
100 
1000 
1001
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> work(n);
    for(int i=0;i<n;i++)
        cin>>work[i].second>>work[i].first;//{报酬 难度}
    sort(work.begin(),work.end(),greater<pair<int,int>>());//先报酬降序 再难度降序
    vector<int> person(m);//每个人的能力值
    for(int i=0;i<m;i++)
        cin>>person[i];
    vector<int> personOriginal=person;//保存排序前的能力值顺序
    sort(person.begin(),person.end(),greater<int>());//能力值降序
    unordered_map<int,int> res;//记录每个能力能获得的最大报酬
    int start=0;//每次搜索起点 起始值为0即搜索所有工作
    for(int i=0;i<m;i++)//每个小伙伴
    {
        if(res.count(person[i])==1)
            continue;//该能力值已求最大报酬 跳过
        for(int j=start;j<n;j++)//搜索剩余工作
        {
            if(work[j].second<=person[i])
            {
                res[person[i]]=work[j].first;//当前能力的最大报酬
                start=j;//下次搜索起点 因为下一个能力值<=当前能力值
                break;//退出
            }
        }
    }
    for(auto p:personOriginal)//按照原顺序打印报酬值
        cout<<res[p]<<endl;
    return 0;
}
