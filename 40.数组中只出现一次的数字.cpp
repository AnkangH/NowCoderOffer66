/*
题目：
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
解析：
哈希表方法。
*/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        unordered_map<int,int> m;
        int size=data.size();
        for(int i=0;i<size;i++)
            m[data[i]]++;
        int flag=1;//这里两个返回值，为了区分所以使用一个变量
        for(int i=0;i<size;i++)
            if(m.find(data[i])->second==1)
            {
                if(flag)
                {
                    *num1=data[i];
                    flag=0;
                }
                else
                    *num2=data[i];
            }
    }
};
