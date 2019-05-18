/*
题目：
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，
有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，
正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
解析：
根据空格划分单词，将单词颠倒，并倒序输出即可。
*/
class Solution {
public:
    string ReverseSentence(string str) {
        string res;
        if(str.empty())
            return res;
        int size=str.size();
        string temp;
        for(int i=size-1;i>=0;i--)//倒序
        {
            if(str[i]!=' ')
                temp+=str[i];//获取字母直到空格为止
            if(str[i]==' ')
            {
                reverse(temp.begin(),temp.end());//将单词倒序
                res+=temp;
                res+=' ';
                temp.clear();//储存单元清零
            }
            if(i==0&&str[i]!=' ')//执行到最后一个字符时，即便不是空格，也要倒序并输出
            {
                reverse(temp.begin(),temp.end());
                res+=temp;
                temp.clear();
            }
        }
        return res;
    }
};
