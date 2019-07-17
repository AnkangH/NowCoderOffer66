/*
题目描述
括号配对问题
输入描述:
给定一个字符串S，请检查该字符串的括号是否配对，只含有"[", "]", "(", ")"
输出描述:
配对，返回true

不配对，返回false
*/


#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stack<char> st;//辅助栈
    bool res=true;//返回值
    for(auto p:s)//遍历字符串
    {
        if(p=='('||p=='[')
            st.push(p);//左括号入栈
        else if(p==')')//右括号
        {
            if(st.empty())
                res=false;//栈空 不匹配
            else if(st.top()!='(')
                res=false;//栈顶不为左括号 不匹配
            else
                st.pop();//匹配 左括号出栈
        }
        else if(p==']')//右括号
        {
            if(st.empty())
                res=false;//栈空 不匹配
            else if(st.top()!='[')
                res=false;//栈顶不为左括号 不匹配
            else
                st.pop();//匹配 左括号出栈
        }
    }
    if(!st.empty())
        res=false;//栈非空 说明有未匹配的左括号
    if(res)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
