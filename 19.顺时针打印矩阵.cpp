/*
题目
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，
如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 
则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
解析
1.vector<vector<int>> v
v包含K的元素，每个元素为vector<int>
这里由于是矩阵，所以每个vector<int>包含的int个数相同
矩阵行数为v.size(),矩阵列数为v[0].size()
2.将一圈作为打印的基本动作，顺序为右，下，左，上
则一圈包括两行两列，考虑到最后一圈可能不完整，因此打印次数n=(min(r,c)+1)/2
或(min(r,c)-1)/2+1
3.考虑每一圈中的右，下，左，上四个打印过程
右：列增加，行不变。起点=左上角元素，行=列=i，因此j=i;终点最右元素，c-1-i，因此j<c-i
start(i,i) end(i,c-1-i)
下：行增加，列不变。起点=行+1，行=i,即j=i+1；终点：r-1-i，因此j<r-i
start(i+1,c-1-i) end(r-1-i,c-1-i)
左：列减少，行不变。起点：c-2-i，终点i，且要求此行和向右打印的非同一行
start(r-1-i,c-2-i) end(r-1-i,i)
上：列不变，行减少。起点：r-2-i，终点i+1，且要求此列后上下打印非同一列
start(r-2-i,i) end(i+1,i)
*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if(matrix.empty())
            return res;
        int r=matrix.size();
        int c=matrix[0].size();
        int n=(min(r,c)+1)/2;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<c-i;j++)
                res.push_back(matrix[i][j]);
            for(int j=i+1;j<r-i;j++)
                res.push_back(matrix[j][c-1-i]);
            for(int j=c-2-i;(j>=i)&&(r-1-i!=i);j--)
                res.push_back(matrix[r-1-i][j]);
            for(int j=r-2-i;(j>i)&&(c-1-i!=i);j--)
                res.push_back(matrix[j][i]);
        }
        return res;
    }
};

