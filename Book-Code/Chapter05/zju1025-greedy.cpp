#include <iostream> 
#include <stdio.h> 
#include <memory.h> 
#include <algorithm> 
using namespace std;

#define maxN 5001
struct stick 
{ 
	int l; 
	int w; 
}; 

int greedy(int n, stick a[]) 
{
	bool visited[maxN] = {0};	//ѡ�еĻ����
	int count = 0;			//���������
	int preEnd = 0;			//���һ�μ��뵽����visited�Ļ
	do
	{
		//ÿһ��ѭ��������Ӧ�û����������㷨
		for (int i = preEnd; i < n; i++)
			if (visited[i] == 0)
				if (a[i].w >= a[preEnd].w)
					visited[preEnd=i] = 1;
		count++;		//�õ�һ����������
		//�ҵ�δ���Ż�ĵ�һ��
		for (preEnd = 0; visited[preEnd]; preEnd++);
	} while(preEnd != n);
	return count;
} 

int cmp(stick a, stick b) 
{ 
	if(a.l == b.l) 
		return a.w < b.w; 
	else if (a.l < b.l) return true;
	return false;
} 

int main() 
{ 
	stick data[maxN];
	int i,k; 
	int test; 
	scanf("%d", &test); 
	for (k = 0; k < test; ++k) 
	{ 
		int n; 
		scanf("%d", &n); 
		for (i = 0; i < n; ++i) 
			scanf("%d%d", &data[i].l, &data[i].w); 
		sort(data, data+n, cmp);
		printf("%d\n", greedy(n, data)); 
	} 
	return 0; 
}
