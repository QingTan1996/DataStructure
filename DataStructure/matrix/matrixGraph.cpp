#include<iostream>
#include<stack>
#include<queue>
#define UNVISITED 0
#define VISITED 1
#define MAX -1
int mat[][8] = {0,1,1,MAX,MAX,MAX,MAX,MAX,
				1,0,MAX ,1,1,MAX ,MAX ,MAX,
				1,MAX ,0,MAX ,MAX ,1,1,MAX ,
				MAX,1 ,MAX ,0,MAX ,MAX ,MAX ,1, 
				MAX,1,MAX,MAX,0,MAX,MAX,1,
				MAX,MAX,1,MAX,MAX,0,1,MAX,
				MAX,MAX,1,MAX,MAX,1,0,MAX
				MAX,MAX,MAX,1,1,MAX,MAX,0 };
using namespace std;
class Edge
{
public:
	int start, end;
	int weight;

	Edge():start(-1),end(-1),weight(MAX) {}
	Edge(int s, int e, int w) :start(s), end(e), weight(w) {}

	bool operator >(Edge e);
	bool operator <(Edge e);
};
bool Edge::operator<(Edge e)
{
	return this->weight < e.weight;
}
bool Edge::operator>(Edge e)
{
	return this->weight > e.weight;
}
class matrixGraph
{		
private:
	int **matrix;
public:

	int vertexNumber;
	int edgeNumber;
	int *mark;
public:
	matrixGraph() {}
	matrixGraph(int vertexNumber);
	~matrixGraph();

	Edge firstEdge(int vertex);//返回vertex的第一条边
	Edge nextEdge(Edge edge);//返回下一条边
	
	void setEdge(int start,int end,int weight);//设置边权值
	void delEdge(int start, int end);//删除边

	bool isEdge(Edge e);//是否为边
	int startVertex(Edge e);//返回边始点
	int endVertex(Edge e);//返回边终点
	int weightEdge(Edge e);//返回边权值
	//递归
	void DFS(int vertex);//深度优先遍历
	void DFSTraver();
	void BFS(int vertex);//广度优先遍历
	void BFSTraver();
	//非递归
	void normalDFS();
	void normalBFS();
};
matrixGraph::matrixGraph(int vertexN)
{
	vertexNumber = vertexN;
	edgeNumber = 0;
	//邻接矩阵
	matrix = new int*[vertexNumber];
	for (int i = 0;i < vertexNumber;i++)
		matrix[i] = new int[vertexNumber];
	//是否被访问标记
	mark = new int[vertexNumber];
	//赋初值
	for (int i = 0;i < vertexNumber;i++)
		mark[i] = UNVISITED;
	for (int i = 0;i < vertexNumber;i++)
		for (int j = 0;j < vertexNumber;j++)
			matrix[i][j]=mat[i][j];
	//赋边初值
	/*for (int i = 0;i < vertexNumber;i++)
		for (int j = i+1;j < vertexNumber;j++)
			if (matrix[i][j] != MAX)
				edgeNumber++;*/
	for (int i = 0;i < vertexNumber;i++)
		for (int j = 0;j < vertexNumber;j++)
			if (matrix[i][j] != MAX&&matrix[i][j] != 0)
				edgeNumber++;
	edgeNumber /= 2;
}
matrixGraph::~matrixGraph()
{
	delete[] mark;
	for (int i = 0;i < vertexNumber;i++)
		delete[] matrix[i];
	delete[] matrix;
}
Edge matrixGraph::firstEdge(int vertex)
{
	Edge res;
	for (int i = 0;i < vertexNumber;i++)
	{
		if (matrix[vertex][i] != 0 && matrix[vertex][i] != MAX)
		{
			res.start = vertex;
			res.end = i;
			res.weight = matrix[vertex][i];
			break;
		}
	}
	return res;
}
Edge matrixGraph::nextEdge(Edge e)
{
	Edge res;
	for (int i = e.end+1;i < vertexNumber;i++)
	{
		if (matrix[e.start][i] != 0 && matrix[e.start][i] != MAX)
		{
			res.start = e.start;
			res.end = i;
			res.weight = matrix[e.start][i];
			break;
		}
	}
	return res;
}
void matrixGraph::setEdge(int s, int e, int w)
{
	matrix[s][e] = w;
}
void matrixGraph::delEdge(int s, int e)
{
	if(edgeNumber)
		edgeNumber--;
	matrix[s][e] = MAX;
}
bool matrixGraph::isEdge(Edge e)
{
	//if ((matrix[e.start][e.end] != 0) && (matrix[e.start][e.end] != MAX))
	if(e.weight!=MAX)
		return true;
	else
		return false;
}
int matrixGraph::startVertex(Edge e)
{
	return e.start;
}
int matrixGraph::endVertex(Edge e)
{
	return e.end;
}
int matrixGraph::weightEdge(Edge e)
{
	return e.weight;
}
void matrixGraph::DFS(int vertex)
{
	mark[vertex] = VISITED;
	cout << vertex << " ";
	for (Edge e = firstEdge(vertex);isEdge(e);e = nextEdge(e))
	{
		int en = endVertex(e);
		if (mark[en] == UNVISITED)
			DFS(en);
	}
}
void matrixGraph::DFSTraver()
{

	for (int i = 0;i < vertexNumber;i++)
		mark[i] = UNVISITED;
	for (int i = 0;i < vertexNumber;i++)
		if (mark[i] == UNVISITED)
			DFS(i);
}
void matrixGraph::normalDFS()
{
	stack<int> node;
	for (int i = 0;i < vertexNumber;i++)
		mark[i] = UNVISITED;
	for (int i = 0;i < vertexNumber;i++)
	{
		if (mark[i] == UNVISITED)
		{
			node.push(i);
			cout << i << " ";
			mark[i] = VISITED;
			while (!node.empty())
			{
				int s = node.top();
				node.pop();
				for (Edge e = firstEdge(s);isEdge(e);e = nextEdge(e))
				{
					int en = endVertex(e);
					if (mark[en] == UNVISITED)
					{
						node.push(en);
						cout << en << " ";
						mark[en] = VISITED;
					}
				}
			}
		}
	}
}
void matrixGraph::BFS(int vertex)
{
	queue<int> node;
	mark[vertex] = VISITED;
	cout << vertex << " ";
	node.push(vertex);
	while (!node.empty())
	{
		int s = node.front();
		node.pop();
		for (Edge e = firstEdge(s);isEdge(e);e = nextEdge(e))
		{
			int en = endVertex(e);
			if (mark[en] == UNVISITED)
			{
				cout << en << " ";
				node.push(en);
				mark[en] = VISITED;
			}
		}
	}

}
void matrixGraph::BFSTraver()
{
	for (int i = 0;i < vertexNumber;i++)
		mark[i] = UNVISITED;
	for (int i = 0;i < vertexNumber;i++)
		if (mark[i] == UNVISITED)
			BFS(i);
}
void matrixGraph::normalBFS()
{
	queue<int> node;
	for (int i = 0;i < vertexNumber;i++)
		mark[i] = UNVISITED;
	for (int i = 0;i < vertexNumber;i++)
	{
		if (mark[i] == UNVISITED)
		{	
			cout << i << " ";
			node.push(i);		
			mark[i] = VISITED;
			while (!node.empty())
			{
				int s = node.front();
				node.pop();
				for (Edge e = firstEdge(s);isEdge(e);e = nextEdge(e))
				{			
					int en = endVertex(e);
					if (mark[en] == UNVISITED)
					{
						cout << en << " ";
						node.push(en);
						mark[en] = VISITED;
					}
				}
			}
		}
	}
}
int main()
{
	matrixGraph m(8);
	cout << m.edgeNumber << endl;
	m.DFSTraver();
	return 0;
}