/*
题目：输入一个二维行列有序数组及一个数字 判断数组中是否包含这个数字
解析：
因为行列有序 所以每一行的最后一个元素是这一行中的最大元素。从第一行的最后一个元素出发，
如果arr[i][j]<target 那么i++应该向下（数字增大）
如果arr[i][j]>target那么 j--应该向左（数字减小）
因为数组行列有序，只能从数组的右上或者左下出发，这样大小都有不同的移动方向。
如果从左上或者右下出发，那么无论向哪个方向移动，数字的大小变化是相同的。
*/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty()||array[0].empty())
            return false;//预判断
        int m=array.size();//行数
        int n=array[0].size();//列数
        int i=0,j=n-1;
        while(i<m&&j>=0)//行列索引
        {
            if(array[i][j]==target)
                return true;
            else if(array[i][j]<target)//小的话向下移动变大
                i++;
            else
                j--;//反之 大的话向左移动变小
        }
	return false;//遍历后如果未输出true，则输出false
    }
};
