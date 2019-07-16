/*
请实现一个函数，功能为合并两个升序数组为一个升序数组
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;//以字符串形式保存两个输入
    vector<int> nums1,nums2;//数组
    string temp;//暂存字符串
    for(auto p:s1)//遍历字符串1
    {
        if(p!=',')
            temp+=p;//放入暂存字符串
        else
        {
            nums1.push_back(atoi(temp.c_str()));//字符串转int
            temp.clear();//清空暂存字符串
        }
    }
    if(!temp.empty())//最后一个暂存字符串非空
    {
        nums1.push_back(atoi(temp.c_str()));//放入nums1
        temp.clear();//清空暂存字符串
    }
    if(!s2.empty())//判断字符串2是否空 非空再进行处理
    {
        for(auto p:s2)
        {
            if(p!=',')
                temp+=p;
            else
            {
                nums2.push_back(atoi(temp.c_str()));
                temp.clear();
            }
        }
        if(!temp.empty())
            nums2.push_back(atoi(temp.c_str()));
    }
    int i=0,j=0;//起点
    int size1=nums1.size();//数组1的大小
    int size2=nums2.size();//数组2的大小
    while(i<size1||j<size2)//循环终结 两个指针均到达末尾
    {
        if(i==size1)//数组1遍历完
        {
            cout<<nums2[j];
            if(j!=size2-1)
                cout<<",";//不是最后一个数字
            j++;//遍历数组2
        }
        else if(j==size2)//数组2遍历完
        {
            cout<<nums1[i];
            if(i!=size1-1)
                cout<<",";//不是最后一个数字
            i++;//遍历数组1
        }
        else//两个数组均未遍历完
        {
            if(nums1[i]<nums2[j])//较小值
            {
                cout<<nums1[i];
                if(i+j<size1+size2-1)
                    cout<<",";//不是最后一数字
                i++;
            }
            else
            {
                cout<<nums2[j];
                if(i+j<size1+size2-1)
                    cout<<",";
                j++;
            }
        }
    }
    return 0;
}
