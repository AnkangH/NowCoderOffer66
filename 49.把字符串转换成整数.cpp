/*
题目：
将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，但是string不符合数字要求时返回0)，要求不能使用字符串转换整数的库函数。
数值为0或者字符串不是一个合法的数值则返回0。
输入描述:
输入一个字符串,包括数字字母符号,可以为空
输出描述:
如果是合法的数值表达则返回该数字，否则返回0
示例1
输入
+2147483647
    1a33
输出
2147483647
    0
解析：
共分为4种情况：
1.首字符为‘+’ 
2.首字符为‘-’
3.首字符为‘1’-‘9’
4.首字符为‘0’或不合法。
当数组非空时，判断首字符。若为正，则从第二个字符开始，判断字符是否为数字，若为数字
res+=str[i]*pow(10,size-1-i)；若不为数字，说明不合法，直接返回0，退出循环。
若为负同首字符为正的操作，但是最终结果乘-1。若为数字1-9,同上面的操作，但是循环从第一个字符开始
计算res的值。
这里因为非法字符也是返回0，所以排除掉了数字0和非法0判断，简便很多。
*/
class Solution {
public:
    int StrToInt(string str) {
        if(str.empty())//空字符串非法
            return 0;
        int size=str.size();
        if(str[0]=='+')//判断首字符为+
        {
            int res=0;
            for(int i=1;i<size;i++)
            {
                if(isNum(str[i]))
                    res+=(str[i]-'0')*pow(10,size-1-i);//从第二位起，计算数值*幂
                else
                    return 0;//有一位不为数字说明不合法，直接返回0
            }
            return res;
        }
        else if(str[0]=='-')//首字符为-
        {
            int res=0;
            for(int i=1;i<size;i++)
            {
                if(isNum(str[i]))
                    res+=(str[i]-'0')*pow(10,size-1-i);
                else
                    return 0;
            }
            return res*(-1);//同首字符为+，但是最后结果取相反数
        }
        else if(isNumFirst(str[0]))//首字符为1-9
        {
            int res=0;
            for(int i=0;i<size;i++)//从首字符开始计算十进制结果
            {
                if(isNum(str[i]))
                    res+=(str[i]-'0')*pow(10,size-1-i);
                else
                    return 0;
            }
            return res;
        }
        else//首字符为0或其他不合法字符，均返回0这里'0'合法和‘01121’不合法均返回0 所以简便很多
            return 0;
    }
    bool isNumFirst(char a)//判断首字符是否为1-9
    {
        if((a-'0')>0&&(a-'0')<=9)//1-9
            return true;
        else
            return false;
    }
    bool isNum(char a)//判断字符是否为0-9
    {
        if(a-'0'>=0&&a-'0'<=9)//0-9
            return true;
        else
            return false;
    }
};
