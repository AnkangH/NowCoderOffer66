/*
题目：
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
分析：
从小到大排序后，输出前k个数字即可。这里数字没有相同的，否则要进行相同数字剔除的操作。
要判断k是否比n大。
*/
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(),input.end());
        vector<int> res;
        int size=input.size();
        if(k>size)
            return res;
        for(int i=0;i<k;i++)
            res.push_back(input[i]);
        return res;
    }
};
