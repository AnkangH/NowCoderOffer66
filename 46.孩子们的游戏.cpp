/*
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,自然也准备了一些小游戏。
其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....
这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
*/


class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n==0||m==0)
            return -1;//边界条件 n==0 或m==0非法
        vector<int> que(n);//代表n个小朋友
        for(int i=0;i<n;i++)
            que[i]=i;//每个小朋友的索引 因为使用迭代器遍历 索引必须要额外增加索引属性
        int res=0;//当前被选中的小朋友 初值任意
        auto itr=que.begin();//第一轮从第一个小朋友开始
        while(!que.empty())//仍有小朋友没有被选中
        {
            int cnt=1;//当前轮的m次循环
            int size=que.size();
            int cur=m%size;
            if(cur==0)
                cur=size;
            while(cnt<cur)
            {
                cnt++;//计数值增加
                itr++;//指向下一个小朋友
                if(itr==que.end())
                    itr=que.begin();//构成圈 最后一个小朋友再从第一个小朋友开始
            }
            res=*itr;//记录当前被选中的小朋友索引
            itr=que.erase(itr);//删除当前小朋友
            if(itr==que.end()&&que.size()!=0)//要检查此时数组是否空
                itr=que.begin();//如果删除的是最后一个小朋友 那么下次从第一个小朋友开始
        }
        return res;//返回最后一个小朋友
    }
};
