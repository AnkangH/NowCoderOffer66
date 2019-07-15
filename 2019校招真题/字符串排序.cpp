/*
月神拿到一个新的数据集，其中每个样本都是一个字符串（长度小于100），样本的的后六位是纯数字，月神需要将所有样本的后六位数字提出来，
转换成数字，并排序输出。
月神要实现这样一个很简单的功能确没有时间，作为好朋友的你，一定能解决月神的烦恼，对吧。
*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string str;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        int size=str.size();
        str=str.substr(size-6,6);//取后6位
        arr.push_back(atoi(str.c_str()));//string转int
    }
    sort(arr.begin(),arr.end());//排序
    for(auto p:arr)
        cout<<p<<endl;//输出排序后的数字
    return 0;
}
