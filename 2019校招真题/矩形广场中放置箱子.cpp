/*
给定一个mxn的矩形，其中0为空地，1为障碍物，求大小为cxd的箱子能否放置在矩形的空地中。
*/


#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
vector<int> maxLineArea(vector<int> heights);
vector<int> maximalRectangle(vector<vector<char>>& matrix);
int main()
{
	vector<vector<char>> matrix{ 
	{ '1', '0', '1', '0', '0'},
	{ '1', '1', '1', '1', '1' },
	{ '1', '1', '1', '1', '1' },
	{ '1', '0', '0', '1', '0' }};
	vector<int> areaMax = maximalRectangle(matrix);
	cout << "maxArea=" << areaMax[0] << ",maxLength=" << areaMax[1] << ",maxWidth=" << areaMax[2] << endl;
	return 0;
}
vector<int> maxLineArea(vector<int> heights)//计算一行的柱状图高度 返回值{最大面积 最大面积对应的长 高}
{
	heights.push_back(0);
	int n = heights.size();
	stack<int> s;
	int areaMax = 0,lengthMax=0,widthMax=0;
	for (int i = 0; i < n; i++)//单调栈 每个柱子入栈
	{
		while (!s.empty() && heights[s.top()] >= heights[i])//柱子高度小于等于栈顶
		{
			int hCur = heights[s.top()];//上个柱子高度
			s.pop();//出栈
			int areaCur = s.empty() ? hCur * i : hCur * (i - s.top() - 1);//如果栈空 则上个柱子高度*i 否则*i-上上个柱子高度-1
			if (areaCur >= areaMax)
			{
				areaMax = areaCur;
				lengthMax = areaCur / hCur;
				widthMax = hCur;
			}
		}
		s.push(i);//当前柱子入栈
	}
	return {areaMax,lengthMax,widthMax};
}
vector<int> maximalRectangle(vector<vector<char>>& matrix) //计算矩形中1的最大面积 返回值{最大面积 最大面积对应的长 高}
{
	if (matrix.empty() || matrix[0].empty())
		return {0,0,0};
	int m = matrix.size();
	int n = matrix[0].size();
	vector<int> heights(n);
	int areaMax = 0;
	int lengthMax = 0, widthMax = 0;
	for (int i = 0; i < m; i++)//以每一行更新当前柱状图高度
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == '1')
				heights[j]++;//连续的1 高度+1
			else
				heights[j] = 0;//当前为0 则当前柱子高度为0
		}
		vector<int> areaCur = maxLineArea(heights);//当前最大面积
		if (areaCur[0] >= areaMax)
		{
			areaMax = areaCur[0];
			lengthMax = areaCur[1];
			widthMax = areaCur[2];
		}
	}
	return { areaMax,lengthMax,widthMax };
}
