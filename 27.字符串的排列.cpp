/*
题目:
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
解析：将题目划分，1是要将出现字符的所有可能排列求出 2是要对所有排列按照ascii码排序并删除重复元素
将输入字符串进行全排列，将所有全排列字符串按照ascii码排序，删除重复元素。
*/

//方法一
class Solution {
public:
    vector<string> Permutation(string str)
    {
        int size=str.size();
        vector<string> res;
        if(size==0)//空字符串返回空
            return res;
        if(size==1)//单字符字符串
            return vector<string>{str};
        permutation(str,res,0,size);//求全排列
        radixSortStr(res);//全排列按照ascii排序
        auto start=unique(res.begin(),res.end());//将重复元素放到arr末尾并
                                                 //返回第一个重复元素的位置
        res.erase(start,res.end());//删除重复元素
        return res;
    }
    void permutation(string str,vector<string>& res,int start,int end)
    {
        if(start==end)
        {
            res.push_back(str);
            return;
        }
        for(int i=start;i<end;i++)
        {
            swap(str[start],str[i]);
            permutation(str,res,start+1,end);
            swap(str[start],str[i]);
        }
    }
    void radixSortStr(vector<string>& arr)
    {
        int size=arr.size();
        int bucketSize=256;
        vector<vector<string>>bucket(bucketSize);
        int n=arr[0].size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<size;j++)
                bucket[arr[j][i]].push_back(arr[j]);
            arr.clear();
            for(int j=0;j<bucketSize;j++)
            {
                int size=bucket[j].size();
                for(int k=0;k<size;k++)
                    arr.push_back(bucket[j][k]);
                bucket[j].clear();
            }
        }
    }
};
