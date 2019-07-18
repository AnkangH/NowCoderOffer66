/*
题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
*/


class Solution {
public:
    vector<int> nums;//保存输入数据
    void Insert(int num)
    {
        nums.push_back(num);//插入到末尾 时间复杂度O(1)
    }

    double GetMedian()
    { 
        sort(nums.begin(),nums.end());//排序
        int n=nums.size();//数字个数
        if(n%2==1)//奇数个
            return nums[n/2];//返回中间值
        else//偶数个
            return (double(nums[n/2])+nums[n/2-1])/2;//中间两个数字的平均值
    }
    
};
