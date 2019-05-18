/*
题目：
输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
解析：
因为数组有序，所以使用双指针法。一个指针指向起点（最小值），一个指针指向终点（最大值），根据两个指针的和与S比较大小，确定
这两个数字。同时要注意数组中可能存在多组解。所以要一直遍历到两个指针相遇。
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int size=array.size();
        int l=0,r=size-1;
        int res1=size-1,res2=size-2;//双指针
        int flag=0;
        while(l<r)
        {
            if(array[l]+array[r]==sum)//和为目标值
            {
                if(array[l]*array[r]<array[res1]*array[res2])//保存乘积最小的 这里因为数组增序。所以第一个满足
                                                            //满足乘积的一定满足这一条 从而修改res1和res2
                {                                       
                    res1=array[l];
                    res2=array[r];
                }
                l++;
                flag=1;//标志出现了使两个数字和为S
            }
            else if(array[l]+array[r]<sum)
                l++;
            else
                r--;
        }
        return flag==0? vector<int>{}:vector<int>{res1,res2};
    }
};
