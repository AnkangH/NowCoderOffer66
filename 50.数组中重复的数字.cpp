/*
题目：
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
解析：
看到出现次数想到哈希表。因此长度n，值在n-1之间，所以使用数组作为哈希表即可。数组大小为length，因为不清楚不重复的数字有几个，但是数组中
不相同的数字最多的情况就是数组中没有重复的数字，因此有n个不相同的数字。
哈希表1，记录每个数字出现的次数。因为数字key值在0-n-1之间，所以将数组索引作为key值，数组索引处储存的值为value，即数字出现的次数。
哈希表2，记录每个数字最早出现的位置，从后往前遍历数组，并更新每个数字出现的位置，则最后哈希表中储存每个数字最早出现的位置。
遍历哈希表1，这里应使用数组中的数字遍历，而不是0-n-1，使用0-n-1遍历，会访问未出现的数字，增加时间复杂度。如果数字出现次数大于1，即数字
重复，那么取哈希表2中查询最早出现的位置，若位置比上一个重复的位置靠前，则更新返回值。
*/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length==0)
            return false;          //new属于动态变量，不初始化时其值为储存地址中的数字，所以是未知的。因此一定要先初始化
        auto pt=new int[length]{0};//哈希表1 记录每个数字出现次数 初值要为0
        auto pe=new int[length]{0};//哈希表2 记录每个数字最早出现的位置 因为每个出现的数字必被更新 所以初值随意
        for(int i=0;i<length;i++)
            pt[numbers[i]]++;//构建哈希表1
        for(int i=length-1;i>=0;i--)
            pe[numbers[i]]=i;//构建哈希表2
        int occur=INT_MAX;//出现位置最大是n-1，这里为了第一个重复的数字可以正常更新 初值要比n-1大
        for(int i=0;i<length;i++)//遍历哈希表1
            if(pt[numbers[i]]>1&&pe[numbers[i]]<occur)//发现重复数字则去哈希表2查找出现次数 若出现次数早
            {
                *duplication=numbers[i];//保存重复数字
                occur=pe[numbers[i]];//保存最早出现位置
            }
        return occur==INT_MAX? false:true;
    }
};
