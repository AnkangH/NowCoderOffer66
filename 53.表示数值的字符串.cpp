/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/


class Solution {
public:
    bool isNumeric(char* str)
    {
        string s;
        while(*str!='\0')
        {
            s+=*str;
            str++;
        }
        bool numSeen=false;//已有数字
        bool pointSeen=false;//已有小数点
        bool eSeen=false;//已有e E
        bool numAfterE=true;//数字后有e
        int size=s.size();
        for(int i=0;i<size;i++)//遍历
        {
            if(s[i]-'0'>=0&&s[i]-'0'<=9)//数字
            {
                numSeen=true;//已有数字
                numAfterE=true;//数字在e之后
            }
            else if(s[i]=='e'||s[i]=='E')//e或E
            {
                if(eSeen||!numSeen)
                    return false;//e前有e或无数字 非法
                numAfterE=false;//e之后无数字
                eSeen=true;//有e
            }
            else if(s[i]=='.')//小数点
            {
                if(eSeen||pointSeen)
                    return false;//之前有e或小数点 非法
                pointSeen=true;//已有小数点
            }
            else if(s[i]=='+'||s[i]=='-')//正负号
            {
                if(i!=0&&(s[i-1]!='e'&&s[i-1]!='E'))//不在首位且 前面不是e或E 
                    return false;//非法
            }
            else 
                return false;//其他字符非法
        }
        return numAfterE&&numSeen;//有数字且e之后有数字
    }
};
