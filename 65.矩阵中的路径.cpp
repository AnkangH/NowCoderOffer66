/*
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，
每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        for(int i=0;i<rows;i++)
           for(int j=0;j<cols;j++)
               if(matrix[i*cols+j]==*str)
                   if(dfs(matrix,rows,cols,i,j,str))
                       return true;
        return false;
    }
    bool dfs(char* matrix,int rows,int cols,int r,int c,char* str)
    {
        if(*str=='\0')
            return true;//达到字符结尾 说明找到路径
        if(r<0||r>=rows||c<0||c>=cols||matrix[r*cols+c]!=*(str))
            return false;//边界条件 退出
        //当前字符符合 判断后序字符
        //如果后续字符的后序判断没有返回true 那么当前字符不应设为已读
        char temp=matrix[r*cols+c];//保存当前字符
        matrix[r*cols+c]='*';//
        str++;
        bool path=dfs(matrix,rows,cols,r+1,c,str)||dfs(matrix,rows,cols,r-1,c,str)
            ||dfs(matrix,rows,cols,r,c+1,str)||dfs(matrix,rows,cols,r,c-1,str);
        if(!path)
            matrix[r*cols+c]=temp;
        return path;
    }
};
