/*
题目描述
请编写一段代码，实现两个单向有序链表的合并
输入描述:
第一行一个链表，如1 2 3 4 5

第二行一个链表，如2 3 4 5 6
输出描述:
输出：1 2 2 3 3 4 4 5 5 6
*/


#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
    vector<int> num1,num2;
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    string temp;
    for(auto p:s1)
    {
        if(p!=' ')
            temp+=p;
        else
        {
            num1.push_back(atoi(temp.c_str()));
            temp.clear();
        }
    }
    if(!temp.empty())
    {
        num1.push_back(atoi(temp.c_str()));
        temp.clear();
    }
    for(auto p:s2)
    {
        if(p!=' ')
            temp+=p;
        else
        {
            num2.push_back(atoi(temp.c_str()));
            temp.clear();
        }
    }
    if(!temp.empty())
    {
        num2.push_back(atoi(temp.c_str()));
        temp.clear();
    }
    int size1=num1.size();
    int size2=num2.size();
    int i=0,j=0;
    while(i<size1||j<size2)
    {
        if(i==size1)
        {
            cout<<num2[j];
            if(j<size2)
                cout<<" ";
            j++;
        }
        else if(j==size2)
        {
            cout<<num1[i];
            if(i<size1)
                cout<<" ";
            i++;
        }
        else 
        {
            if(num1[i]<num2[j])
            {
                cout<<num1[i];
                if(i+j<size1+size2-1)
                    cout<<" ";
                i++;
            }
            else
            {
                cout<<num2[j];
                if(i+j<size1+size2-1)
                    cout<<" ";
                j++;
            }
        }
    }
    cout<<endl;
    return 0;
}
