/*
题目：给定一个字符串 将其中的空格全部替换为%20
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
解析：如果不要求不使用额外空间，那么最好使用动态大小的模板来替换字符串。
c-风格字符串不记录大小，因此增加和减少字符需要对整个字符串进行操作。
这里使用一个vector来记录字符串的每个字符。使用push_back，增加字符时不需要修改其后
的所有字符。
*/
class Solution {
public:
    void replaceSpace(char *str,int length) {
        vector<char> res;//辅助向量
        for(int i=0;i<length;i++)
        {
            if(str[i]!=' ')
                res.push_back(str[i]);//遍历字符串 不是空格就赋值给辅助向量
            else
            {
                res.push_back('%');//空格按照指定格式替换
                res.push_back('2');
                res.push_back('0');
            }
        }
        for(int i=0;i<res.size();i++)
            str[i]=res[i];
    }
};
