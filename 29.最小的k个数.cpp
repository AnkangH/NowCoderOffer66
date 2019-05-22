/*
题目：
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
分析：
方法一：从小到大排序后，输出前k个数字即可。这里数字没有相同的，否则要进行相同数字剔除的操作。要判断k是否比n大。
方法二：以数组前4个元素创建一个大小为4的大顶堆，数字从第5个数字开始入堆，并删除堆顶元素，则最后堆中是最小的4个数字。
*/
//方法一
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        sort(input.begin(),input.end());//增序排序
        vector<int> res;
        int size=input.size();
        if(k>size)
            return res;//输入不合法 返回空
        for(int i=0;i<k;i++)
            res.push_back(input[i]);//输入合法 返回数组前k个元素
        return res;
    }
};
//方法二
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int> queMax;//大顶堆 删除堆顶最大值 因此留下来的是小的值
        int size=input.size();
        vector<int> res;
        if(k>size)
            return res;//k输入不合法 返回空集
        else
        {
            for(int i=0;i<size;i++)//遍历输入数组
            {
                if(i<k)//前k个直接入堆
                    queMax.push(input[i]);
                else//维持堆的大小为k
                {
                    queMax.push(input[i]);//入堆 现在堆的大小是k+1
                    queMax.pop();//堆顶是k+1个值中的最大值，因此弹出堆顶
                }
            }
            while(!queMax.empty())//堆中保存了最小的k个值
            {
                res.push_back(queMax.top());//依次弹出堆顶 获得最小k个值的降序排列 这里case不考虑返回值的排序问题 只要是最小的k个值即可
                queMax.pop();
            }
        }
        return res;
    }
};
