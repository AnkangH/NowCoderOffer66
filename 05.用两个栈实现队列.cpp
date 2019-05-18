class Solution
{
public:
    void push(int node) {
        stack1.push(node);//s1保存入栈序列
    }

    int pop() {
        if(stack2.empty())//只有s2空，才将s1的入栈，否则会出现顺序冲突
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
         int x=stack2.top();//如果s2非空，那么栈顶元素就是队列首元素
         stack2.pop();//先保存栈顶元素 再出栈
         return x;
    }

private:
    stack<int> stack1;//入队列顺序
    stack<int> stack2;//出队列顺序
};
