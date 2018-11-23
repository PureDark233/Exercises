#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 1000
#define N 127

typedef struct
{
	int weight;
	int parent;
	int lchild;
	int rchild;
	char ch;
} HuffmanTree;

struct CodeNode
{
	char ch;
	char bits[N + 1];
};
typedef CodeNode HuffmanCode;

void CharSetHuffmanEncoding(HuffmanTree T[], HuffmanCode H[], int n);
void CreateHuffmanTree(HuffmanTree T[MaxSize], int n);

int main()
{
	FILE* fp;
	char ch;
	int n=0, i;
	int count[N] = { 0 };
	HuffmanTree F[MaxSize];
	HuffmanCode G[N];
	fp = fopen("test.txt", "r");
	if (fp)
		while (fscanf(fp, "%c", &ch) != EOF)
		{
			count[ch]++;
			printf("%c", ch);
		}
	fclose(fp);

	printf("\n");

	for (i = 0; i < N; i++)
	{
		if (count[i] != 0)
		{
			F[n].weight = count[i];
			F[n].ch = i;
			F[n].lchild = -1;
			F[n].rchild = -1;
			F[n].parent = 0;
			printf("字符  %c  出现了%d次\n", F[n].ch, F[n].weight);
			n++;
		}
	}
	for (i = n; i < 2 * n - 1; i++)
	{
		F[i].parent = 0;
		F[i].lchild = -1;
		F[i].rchild = -1;
		F[i].weight = -1;
		F[i].ch = '\0';
	}
	printf("\n一共%d个字符\n", n);

	CreateHuffmanTree(F, n);
	CharSetHuffmanEncoding(F, G, n);

	for (i = 0; i < n; i++)
	{
		printf("字符  %c  的哈夫曼码是%s\n", G[i].ch, G[i].bits);
	}

	system("pause");
	return 0;
}

void CharSetHuffmanEncoding(HuffmanTree T[], HuffmanCode H[], int n)
{
	int c, p, i;
	char cd[52 + 1];
	int start;
	cd[n] = '\0';

	for (i = 0; i < n; i++)
	{
		H[i].ch = T[i].ch;
		start = n;
		c = i;
		p = T[c].parent;
		while (p != 0)
		{
			start--;
			if (T[p].lchild == c)
			{
				cd[start] = '0';
			}
			else
			{
				cd[start] = '1';
			}
			c = p;
			p = T[p].parent;
		}
		strcpy(H[i].bits, &cd[start]);
	}	
	
}

void CreateHuffmanTree(HuffmanTree T[MaxSize], int n)
{
	int i, p1, p2, m, j, s1, s2;

	m = 2 * n - 1;

	for (i = n; i < m; i++)
	{
		s1 = s2 = 10000;
		p1 = p2 = 0;
		
		for (j = 0; j<i; j++)
			if (T[j].parent == 0)
				if (T[j].weight<s1)
				{
					s2 = s1;
					s1 = T[j].weight;
					p2 = p1;
					p1 = j;
				}
				else
					if (T[j].weight<s2)
					{
						s2 = T[j].weight;
						p2 = j;
					}
		T[p1].parent = i;
		T[p2].parent = i;
		T[i].lchild = p1;
		T[i].rchild = p2;
		T[i].weight = T[p1].weight + T[p2].weight;
	}
}
