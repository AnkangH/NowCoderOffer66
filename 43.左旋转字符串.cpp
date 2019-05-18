/*
题目：
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，
即“XYZdefabc”。是不是很简单？OK，搞定它！
解析：
使用拼接法。将字符串分为first和last。指代左移后前后两个字符串。
first由右侧左移而来。last由左侧左移放到右侧而来。由于循环移位，所以不改变两个部分中的字符相对位置。
当移位次数k不大于字符串长度时。左起k个字符为last，剩下的部分为first
则新字符串为first+last。
当k大于字符串长度时，由于是循环移位。移位k%size即可。
*/
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(n==0)
            return str;
        if(n<0||str.empty())
            return "";
        int size=str.size();
        if(n>size)
            n=n%size;
        string last=str.substr(0,n);//移位后的字符串后半部分由原字符串前部分组成
        string first=str.substr(n,size-n);//移位后的字符串前部分由原字符串后部分组成
        return first+last;
    }
};
