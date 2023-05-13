#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>

FILE* p;
int n, max, fuhao, fa, fl, kuohao, file;

void xsys(double y[])     //С�������
{
	int i;
	if (file == 1)
	{
		printf("\n��ȷ�𰸣�\n");
		for (i = 1; i < n + 1; i++)
			printf("(%d) %.2f\n", i, y[i]);
	}
	else
	{
		fprintf(p, "\n��ȷ�𰸣�\n");
		for (i = 1; i < n + 1; i++)
			fprintf(p, "(%d) %.2f\n", i, y[i]);
	}
}

void zsys(int y[])       //���������
{
	int i;
	if (file == 1)      //������ļ�
	{
		printf("\n��ȷ�𰸣�\n");
		for (i = 1; i < n + 1; i++)
			printf("(%d) %d\n", i, y[i]);
	}
	else         //�������Ļ
	{
		fprintf(p, "\n��ȷ�𰸣�\n");
		for (i = 1; i < n + 1; i++)
			fprintf(p, "(%d) %d\n", i, y[i]);
	}
}

void zshusize()  //�����㣬��������������
{
	int i, a, b, x[1000];
	char c;
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % max;    //�������ȡ
		b = rand() % max;
		if (fuhao == 1)
		{
			c = '+';
			x[i] = a + b;
		}
		else if (fuhao == 2)
		{
			c = '-';
			x[i] = a - b;
		}
		else if (fuhao == 3)
		{
			c = '*';
			x[i] = a * b;
		}
		else if (fuhao == 4)
		{
			c = '/';
			while (b == 0)
			{
				b = rand() % max;
			}
			x[i] = a / b;
		}
		if (file == 1)
			printf("(%d) %d%c%d=\n", i, a, c, b);
		else
			fprintf(p, "(%d) %d%c%d=\n", i, a, c, b);
	}
	zsys(x);   //��ȡ��
}

void xssize()  //�����㣬С������������
{
	int i;
	double x[1000], a, b;
	char c;
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % (max * 100) / 100.00;   //�漴С����ȡ
		b = rand() % (max * 100) / 100.00;
		if (fuhao == 1)
		{
			c = '+';
			x[i] = a + b;
		}
		else if (fuhao == 2)
		{
			c = '-';
			x[i] = a - b;
		}
		else if (fuhao == 3)
		{
			c = '*';
			x[i] = a * b;
		}
		else if (fuhao == 4)
		{
			c = '/';
			while (b == 0)
			{
				b = rand() % (max * 100) / 100.00 + 1;
			}
			x[i] = a / b;
		}
		if (file == 1)
			printf("(%d) %.2f%c%.2f=\n", i, a, c, b);
		else
			fprintf(p, "(%d) %.2f%c%.2f=\n", i, a, c, b);
	}
	xsys(x);   //��ȡ��
}

void hhxs()  //������㣨С����
{
	int i;
	double x[1000], a, b, c;
	char d, e;
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % (max * 100) / 100.00 + 1;
		b = rand() % (max * 100) / 100.00 + 1;
		c = rand() % (max * 100) / 100.00 + 1;
		if (i % 4 == 0)    //  a-b*c,(a-b)*c
		{
			d = '-';
			e = '*';
			if (kuohao == 1)   //������
				x[i] = a - b * c;
			else
				x[i] = (a - b) * c;
		}
		else if (i % 3 == 0)    //a+b/c,(a+b)/c
		{
			d = '+';
			e = '/';
			while (b == 0)
			{
				c = rand() % (max * 100) / 100.00 + 1;
			}
			if (kuohao == 1)
				x[i] = a + b / c;
			else
				x[i] = (a + b) / c;
		}
		else if (i % 2 == 0)    //a-b/c,(a-b)/c
		{
			d = '-';
			e = '/';
			while (b == 0)
			{
				b = rand() % (max * 100) / 100.00 + 1;
			}
			if (kuohao == 1)
				x[i] = a - b / c;
			else
				x[i] = (a - b) / c;
		}
		else   //a+b*c,(a+b)*c
		{
			d = '+';
			e = '*';
			if (kuohao == 1)
				x[i] = a + b * c;
			else
				x[i] = (a + b) * c;
		}
		if (file == 1)
		{
			if (kuohao == 1)
				printf("(%d) %.2f%c%.2f%c%.2f=\n", i, a, d, b, e, c);
			else
				printf("(%d) (%.2f%c%.2f)%c%.2f=\n", i, a, d, b, e, c);
		}
		else
		{
			if (kuohao == 1)
				fprintf(p, "(%d) %.2f%c%.2f%c%.2f=\n", i, a, d, b, e, c);
			else
				fprintf(p, "(%d) (%.2f%c%.2f)%c%.2f=\n", i, a, d, b, e, c);
		}
	}
	xsys(x);   //��ȡ��
}

void  hunheyunsuan1()  //������㣨������
{
	int i, a, b, c;
	int x[1000];
	char d, e;
	for (i = 1; i < n + 1; i++)
	{
		a = rand() % max;
		b = rand() % max;
		c = rand() % max;
		if (i % 4 == 0)    //  a-b*c,(a-b)*c
		{
			d = '-';
			e = '*';
			if (kuohao == 1)   //������
				x[i] = a - b * c;
			else             //������
				x[i] = (a - b) * c;
		}
		else if (i % 3 == 0)    //a+b/c,(a+b)/c
		{
			d = '+';
			e = '/';
			while (c == 0)
			{
				c = rand() % max;
			}
			if (kuohao == 1)
				x[i] = a + b / c;
			else
				x[i] = (a + b) / c;
		}
		else if (i % 2 == 0)    //a-b/c,(a-b)/c
		{
			d = '-';
			e = '/';
			while (c == 0)
			{
				c = rand() % max;
			}
			if (kuohao == 1)
				x[i] = a - b / c;
			else
				x[i] = (a - b) / c;
		}
		else   //a+b*c,(a+b)*c
		{
			d = '+';
			e = '*';
			if (kuohao == 1)
				x[i] = a + b * c;
			else
				x[i] = (a + b) * c;
		}
		if (file == 1)   //�������Ļ
		{
			if (kuohao == 1)
				printf("(%d) %d%c%d%c%d=\n", i, a, d, b, e, c);
			else
				printf("(%d) (%d%c%d)%c%d=\n", i, a, d, b, e, c);
		}
		else //������ļ�
		{
			if (kuohao == 1)
				fprintf(p, "(%d) %d%c%d%c%d=\n", i, a, d, b, e, c);
			else
				fprintf(p, "(%d) (%d%c%d)%c%d=\n", i, a, d, b, e, c);
		}
	}
	zsys(x);   //��ȡ��
}

int main()
{
	printf("\n\n\t\t******************��������������*******************\n\n");

	printf("1.��������Ŀ������");
	scanf("%d", &n);
	printf("\n2.ѡ��������ţ�1.�ӷ�    2.����    3.�˷�    4.����    5.������㣩��");
	scanf("%d", &fuhao);
	printf("\n3.������������ֵ����ʮ���ڡ������ڵȣ���");
	scanf("%d", &max);
	printf("\n4.�������Ƿ���С����1.��   2.�У���");
	scanf("%d", &fl);
	printf("\n5.�������Ƿ������ţ�1.��   2.�У���ע����ѡ����������ʱѡ������ѡ��ѡ1���� ��");
	scanf("%d", &kuohao);
	printf("\n6.�����������ʽ��1.ֱ����ʾ����Ļ��   2.������ļ��� ��");
	scanf("%d", &file);
	if (file == 2)
		printf("\n��������������.txt�ļ�");
	p = fopen("��������.txt", "w");
	printf("\n\n");
	if (fuhao != 5)
	{
		if (fl == 1)
			zshusize();  //�����㣨��С����
		else
			xssize();  //�����㣨��С����
	}
	else
	{
		if (fl == 1)
			hunheyunsuan1();  //������㣨��С�����������ţ�
		else
			hhxs(); //������㣨��С�����������ţ�
	}
	fclose(p);
	printf("\n�Ƿ������������иó���?   <1>��   <2>�˳�\n");
	scanf("%d", &fa);
	if (fa == 1)
	{
		system("cls");  //��������������
		main();
	}
}