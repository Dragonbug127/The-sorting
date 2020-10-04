
#include <iostream>
using namespace std;

void insert();

int main()
{
	int base[10] = { 58,55,64,89,42,57,84,14,24,46 };
	int choose = 0;
	while (1)
	{
		system("cls");
		cout << "选择排序算法\n";
		cout << "快速排序\n";

		cin >> choose;
		switch (choose)
		{
		case 1:insert(base); break;
		default:
			break;
		}
	}
	
}
void insert(int* h)
{

		if (h == NULL) return;
		if (left >= right) return;

		//防止有序队列导致快速排序效率降低
		srand((unsigned)time(NULL));
		int len = right - left;
		int kindex = rand() % (len + 1) + left;
		Swap(h[left], h[kindex]);

		int key = h[left], i = left, j = right;
		while (i < j)
		{
			while (h[j] >= key && i < j) --j;
			if (i < j) h[i] = h[j];
			while (h[i] < key && i < j) ++i;
			if (i < j) h[j] = h[i];
		}

		h[i] = key;

		//QuickSort(&h[left],0,i-1);
		//QuickSort(&h[j+1],0,right-j-1);

		QuickSort(h, left, i - 1);
		QuickSort(h, j + 1, right);
	}
}

void see()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		cout << base[i];
	}
	cout << endl;
}