/*
我们定义字符串包含关系：字符串A=abc，字符串B=ab，字符串C=ac，则说A包含B，A和C没有包含关系。
输入描述:
两个字符串，判断这个两个字符串是否具有包含关系，测试数据有多组，请用循环读入。
输出描述:
如果包含输出1，否则输出0.
*/


#include<iostream>
#include<string>
using namespace std;
bool isSame(string s1,string s2);
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        int size1=s1.size();
        int size2=s2.size();
        int res=0;
        if(size1>=size2)//s1较长
        {
            for(int i=0;i<=size1-size2;i++)//以s2长度分割s1
                if(s1.substr(i,size2)==s2)//判断每个字串是否与s2相同
                {
                    res=1;
                    break;
                }
        }
        else//s2较长
        {
            for(int i=0;i<=size2-size1;i++)//以s1长度分割s2
                if(s2.substr(i,size1)==s1)//判断每个子串是否与s1相同
                {
                    res=1;
                    break;
                }
        }
        cout<<res<<endl;//输出结果
    }
    return 0;
}
