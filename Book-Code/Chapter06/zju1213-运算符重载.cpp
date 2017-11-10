#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

struct stBoard
{
	int number, length;
	stBoard () {number = 1000;}	//ľ������������ֵ����ֵΪ��
} back[4096];	//���ڻ��ݵ�����
bool operator < (const stBoard &op1, const stBoard &op2)
{
	if(op1.number == op2.number)
		return op1.length > op2.length;
	return op1.number < op2.number;
}
int part[13];	//Ҫ�и��ľ��
int board, saw;	//ľ��ĳ��ȣ���Ŀ��
int n;			//ľ�ϵ�����

void backtrack(int a)
{	//�����ľ���Ѿ����Ź�������ʽ������
	if(back[a].number >= 0) return;
	stBoard best, now;
	//�������е�ľ��
	for(int i = 0; i < n; i++)
		//��i��ľ����δ����
		if(a & 1 << i)
		{	//��1��������i��ľ�ϣ�^��������㣩
			int index = a ^ 1 << i;
			//��2���ݹ���ݣ���������ľ��
			backtrack(index);
			//��3����ð�������ľ����Ҫľ�������
			now.number = back[index].number;
			// ��4�����ʣ�೤��back[index].length�ܹ����ŵ�i��ľ�ϣ�
			if(back[index].length >= part[i])
				//����ʣ��ľ�ϵĳ���
				now.length = back[index].length-part[i];
			else	//���ܰ��ŵ�i��ľ��
			{	//����1��ľ��
				now.number++;
				now.length = board-part[i];
			}
			//����ʣ��ľ�ϵĳ���
			now.length = max(now.length - saw, 0);
			//��5����������ֵ
			best = min(best, now);
		}
	back[a] = best;	//��������ֵ
}

int main()
{
	printf("Problem 7 by team x\n");
	char c;
	while(scanf("%d", &board) != EOF)	//��ȡľ��ĳ���
	{	
		memset(back, 255, sizeof(back));
		scanf("%d", &saw);				//��ȡľ��Ŀ��
		n = 0;
		while ((c = getc(stdin)) != '\n')
		{	
			ungetc(c, stdin);	//���ַ�c�˻ػ�����
			scanf("%d", part+n++);
		}
		back[0].number = back[0].length = 0;
		backtrack((1<<n) - 1);
		printf("\n");
		printf("Board length            =%6d\n", board);
		printf("Saw width               =%6d\n", saw);
		printf("Number of boards needed =%6d\n", back[(1<<n) - 1].number);
	}
	printf("End of problem 7 by team x\n");
	return 0;
}
