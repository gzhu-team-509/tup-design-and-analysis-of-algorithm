#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

string lexicon1[2000];	// ��֦����ֵ�
int n1;					// ��֦���ֵ����Ŀ��
string word[20];		// �����еĵ���
string phrase;			// ���ԭʼ�ģ�
string oldphrase;		// ���������Ķ���
int letters[26];		// ��������ĸ���ֵ�Ƶ��

//���ֵ���м�֦�Ż�������������ַ����������ֵ��ĳ����Ŀ�����ֵ��и���Ŀ�Ϳ��Ա���֦
bool inclusive(string &str, int *alpha)
{
	memset(alpha, 0, sizeof(alpha[0])*26);
	for(int j = 0; j < str.length(); j++)
	{
		int a = str[j] - 'A';
		//һ����Ŀ����ĸ��Ƶ�������˶����е���ĸƵ����������ϵ��Ч
		if(++alpha[a] > letters[a]) return false;
	}
	return true;
}

//�β�index���ֵ�����Ŀ����ţ�anagram�Ǳ�λ���ַ���
void findAnagram(int index, string anagram)
{
	int i;
	for(i = 0; i < 26 && letters[i] == 0; i++);
	//��ĸ�Ѿ������ˣ��ҵ���һ���λ��
	if(i == 26)
	{
		//�����λ���ַ�����ԭʼ������������ͬ������һ����Ч�ı�λ��
		if(anagram != phrase)
			cout << oldphrase << " = " << anagram << endl;
		return;
	}
	//��ĸ��û�����꣬������������
	//���ֵ�ĵ�index����Ŀ������
	int alpha[26];
	for(i = index; i < n1; i++)
		if(inclusive(lexicon1[i], alpha))
		{ 	// ���ڰ�����ϵ�����������
			int j;
			//������Ŀ�ĵ�������ȥ
			for (j = 0; j < 26; j++)
				letters[j] -= alpha[j];
			//������Ŀ���뵽��λ���ַ�����
			string anagram1 = anagram;
			if(anagram != "")
				anagram1 += ' ';
			anagram1 += lexicon1[i];
			findAnagram(i, anagram1); // �ݹ�����
			// �ָ��ֳ�
			for (j = 0; j < 26; j++)
				letters[j] += alpha[j];
		}
}

void concatenate(int m, string &str)
{
	str = "";
	for(int i = 0; i < m; i++)
		str += word[i] + " ";
	str.erase(str.length()-1, str.length());
}

int main()
{
	string lexicon[2000];
	int n = 0, m = 0;
	while(cin >> lexicon[n] && lexicon[n] != "#")
		n++;
	while(cin >> word[m] && word[m++] != "#")
		if(cin.get() == '\n')
		{
			int i;
			concatenate(m, oldphrase);
			sort(word, word + m);
			concatenate(m, phrase);

			memset(letters, 0, sizeof(letters));
			for(i = 0; i < phrase.length(); i++)
				if(phrase[i] != ' ')
					letters[phrase[i]-'A']++;

			n1 = 0;
			int alpha[26];
			for(i = 0; i < n; i++)
				if(inclusive(lexicon[i], alpha))
					lexicon1[n1++] = lexicon[i];
			findAnagram(0, "");
			m = 0;
		}
	return 0;
}

