#include <iostream>
#include <queue>
using namespace std;

#define inf 1000000
class Graph {
	friend int path(int n, int s, int t, int **c);	
public:
	void ShortestPaths(int);
private:
	int n,				//ͼG�Ķ�����
		*prev,			//ǰ����������
		**c,			//ͼG���ڽӾ���
		*dist;			//��̾�������
};

class MinHeapNode {
	friend class Graph;
public:
	friend bool operator < (MinHeapNode a, MinHeapNode b)
	{
		if(a.length < b.length)	return true;
		else return false;
	}
private:
	int i;			//������
	int length;		//��ǰ·��
};

//��Դ���·����������ȶ��з�֧�޽編
void Graph :: ShortestPaths(int v) 
{
	//�������ȶ���,����Ҫ��С
	priority_queue<MinHeapNode> H;
	//����ԴΪ��ʼ��չ���
	MinHeapNode E;
	E.i = v;
	E.length = 0;
	dist[v] = 0;
	//��������Ľ�ռ�
	while (true) 
	{
		for (int j = 1; j <= n; j++)
			if ((c[E.i][j]<inf) && (E.length+c[E.i][j]<dist[j])) 
			{
				// ����i������j�ɴ���������Լ��
				dist[j]=E.length+c[E.i][j];
				prev[j]=E.i;
				// ����������ȶ���
				MinHeapNode N;
				N.i=j;
				N.length = dist[j];
				H.push(N);
			}
		if (H.empty()) break;	// ���ȶ��п�
		else {
			E = H.top();
			H.pop();			// ȡ��һ��չ���
		}
	}
} 

int path(int n, int s, int t, int **c) 
{
	Graph g;
	g.n = n;
	g.prev = new int [n+1];
	g.dist = new int [n+1];
	memset(g.prev, 0, sizeof(g.prev));
	for (int i=0; i<=n; i++)
		g.dist[i] = inf;
	g.c = c;
	g.ShortestPaths(s);
	int result = g.dist[t];
	delete [] g.prev;
	delete [] g.dist;
	return result;
}

int main() 
{
	int n;
	int edge;
	cin>>n>>edge;
	int *c[n+1];
	for (int i=0; i<=n; i++)
		c[i] = new int [n+1];
	for(int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			c[i][j] = inf;
	int from, to, d;
	for(int i=0; i<edge; i++)
	{
		cin>>from>>to>>d;
		c[from][to] = d;
	}
	int s, t;
	while (cin>>s>>t) 
	{
		int dist = path(n, s, t, c);
		if (dist == inf) cout<<"No path!";
		else cout<<dist;
		cout<<endl;
	}
	for (int i=0; i<=n; i++)
		delete []c[i];
	return 0;
}
