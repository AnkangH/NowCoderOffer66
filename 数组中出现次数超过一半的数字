/*
题目：
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
解析：
先将数组排序（如从小到大）
然后从数组第一个元素开始，记录相同值出现的次数，如果次数超过数组个数的一般就
输出这个元素，否则输出0
注意数组元素个数为0（根据题意设置）和为1（数组比较时会超索引）时的边界问题
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;//空数组返回0
        if(numbers.size()==1)
            return numbers[0];//只有一个元素时，比较元素会超数组索引
        sort(numbers.begin(),numbers.end());//从小到大排序
        int size=numbers.size();//记录数组元素个数
        int n=1;//初值个数
        int res=numbers[0];//判断数值出现次数的临时变量
        for(int i=1;i<size;i++)
        {
            if(res==numbers[i])
                n++;//若相同，出现次数+1
            else
            {
                res=numbers[i];//判断下一个数字的出现次数
                n=1;//个数恢复初始值
            }
            if(n>size/2)
                return res;//若存在出现次数超过数组个数一半的元素，输出该元素
        }
        return 0;//否则输出0
    }
};
