#include <queue>
#include <iostream>
using namespace std;

int main()
{
	queue <int> q;
	q.push(1); q.push(2); q.push(3); q.push(9);
	cout<<q.size()<<endl;		//���ض���Ԫ������
	cout<<q.empty()<<endl;		//�ж϶����Ƿ�Ϊ��
	cout<<q.front()<<endl;		//��ȡ����Ԫ��
	cout<<q.back()<<endl;		//��ȡ��βԪ��
	//����Ԫ�س��У���ɾ������Ԫ��
	while(!q.empty())		
	{
		cout<<q.front()<<" ";
		q.pop();				//ɾ������Ԫ��
	}
	return 0;
}  

