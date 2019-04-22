/*题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）*/

/*
栈：先入后出 只有栈顶元素可以出栈
从压栈队列开始压入，若与出栈队列相同则出栈，否则只能当所有元素压入完毕后才能出栈。
除去那些入栈时即出栈的元素，而当所有元素压入完毕后，出栈队列必须严格与入栈队列顺序相反。
*/
class Solution {
public:
bool IsPopOrder(vector<int> pushV, vector<int> popV) {
  if(pushV.empty()||popV.empty())
        return false;//有一为空返回false
  stack<int> v;//使用辅助栈 模拟先入后出
	int n = popV.size();
	int i = 0, j = 0;
	for (int i = 0; i < n; i++)
	{
		v.push(pushV[i]);//pushV队列依次入栈
		if (v.top() == popV[j])
		{
			v.pop();//若栈顶元素和出栈队列相同则辅助栈出栈
			j++;//出栈队列索引向后
		}
	}
	for (j; j < n; j++)
	{
		if (v.top() == popV[j])
			v.pop();//剩下的两个队列必须严格先入后出
        else
            break;//有一位不是先入后出关系则剩下的不需再判断，
	}
	if (v.empty())//辅助栈空，则是可能出栈队列
		return true;
	else
		return false;//否则不是
}
};

