#include<iostream>
#include<cstring>
#include<stdlib.h>

using namespace std;

class set {
public:
	void reset();
	int lena; //储存每一次更新的集合长度

	int* operator*(set t) //交集
	{
		int len = m > t.m ? m : t.m;
		int* c = (int*)malloc(sizeof(int) * len);
		int d = 0;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < t.m; j++)
			{
				if (a[i] == t.a[j])
				{
					c[d++] = a[i];
				}
			}
		}
		lena = d;
	return c;
	}
	int* operator+(set t) //并集
	{
		int k = m, es = 1;
		int* c = (int*)malloc(sizeof(int) * (m + t.m));
		for (int i = 0; i < m; i++)
		{
			c[i] = a[i];
		}
		for (int i = 0; i < t.m; i++)
		{
			es = 1;
			for (int j = 0; j < m; j++)
			{

				if (t.a[i] == c[j])
				{
					es = 0;
				}
			}
			if (es)
			{
				c[k] = t.a[i];
				k++;
			}
		}
		lena = k;
		return c;
	}
	int* operator-(set t)
	{
		int k = 0;
		int* c = (int*)malloc(sizeof(int) * m);
		for (int i = 0; i < m; i++)
		{
			c[i] = a[i];
		}
		for (int i = 0; i < t.m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (t.a[i] == c[j])
				{
					for (k = j; k < m; k++)
					{
						c[k] = c[k + 1];
						m--;
						break;
					}
				}
			}
		}
		lena = m;
		return c;
	}
private:
	int* a;
	int m;
};

void set::reset()
{
	cout << "输入集合的长度:" << endl;
	cin >> m;
	a = (int*)malloc(sizeof(int) * m);
	cout << "输入集合a:" << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i];
	}
}

int main()
{
	set s1;
	set s2;
	s1.reset();
	s2.reset();

	int* s3;

	s3 = s1 * s2;
	cout << "两个集合的并集为：" << endl;
	for (int i = 0; i < s1.lena; i++)
		cout << s3[i] << " ";
	cout << endl;

	s3 = s1 + s2;
	cout << "两个集合的交集为：" << endl;
	for (int i = 0; i < s1.lena; i++)
		cout << s3[i] << " ";
	cout << endl;

	s3 = s1 - s2;
	cout << "s1对s2的差集为：" << endl;
	for (int i = 0; i < s1.lena; i++)
	{
		cout << s3[i] << " ";
	}
	cout << endl;

	return 0;
}
