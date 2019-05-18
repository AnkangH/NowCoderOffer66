/*
题目：
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
解析：
使用辅助栈。栈顶元素保存依当前栈中的最小元素。如栈空，则入栈，否则当元素小于最小栈
栈顶元素时再入栈。
出栈时，若栈顶元素与最小栈顶元素相同。则最小栈也出栈。
注意等号时，最小值栈也要入栈。否则原栈中的出栈时，将最小值栈的数字出栈。
但是原栈中还有该数字，而最小值栈中缺失该数字。
*/
class Solution {
public:
    void push(int value) {
        s.push(value);
        if(smin.empty())//栈空
            smin.push(value);
        else
            if(value<=smin.top())//小于等于最小栈栈顶元素
                smin.push(value);
    }
    void pop() {
        if(s.top()==smin.top())//相等时，最小栈也要出栈
        {
            s.pop();
            smin.pop();
        }
        else
            s.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return smin.top();
    }
private:
    stack<int> s;
    stack<int> smin;
};
