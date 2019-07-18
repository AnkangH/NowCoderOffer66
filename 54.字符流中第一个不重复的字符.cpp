/*
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
*/


class Solution
{
public:
    int cnt=0;//索引
    unordered_map<char,int> first;//记录出现一次的字符 最后的出现索引
    unordered_map<char,bool> second;//记录出现两次的字符
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(second.count(ch)==0)//当前出现次数小于两次
        {
            if(first.count(ch)==0)//第一次出现
                first[ch]=cnt;//记录索引
            else//第二次出现
            {
                second[ch]=true;//记录该字符出现两次
                first.erase(ch);//从出现一次的哈希表中删除该字符
            }
        }
        cnt++;//索引更新
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        if(first.empty())
            return '#';//没有只出现一次的字符
        char res;//结果
        int minVal=INT_MAX;//记录出现的最小索引 即出现最早的字符
        for(auto p:first)//遍历只出现一次的字符
        {
            if(p.second<minVal)//出现靠前
            {
                minVal=p.second;//保留较小的索引
                res=p.first;//保留较小索引的字符
            }
        }
        return res;//返回索引最小的字符
    }
};
