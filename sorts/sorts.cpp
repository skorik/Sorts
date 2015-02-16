#include <iostream>
#include <time.h>
using namespace std;

//bubble sort
template < typename Type >
void bubble(Type* a, int n)
{
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j<i; j++)
		{
			if (a[j] > a[j + 1])
			{
				float tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
}

//selection sort
template < typename Type >
void selection(Type* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		int pos = i;
		Type tmp = a[i];
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < tmp)
			{
				pos = j;
				tmp = a[j];
			}
		}
		a[pos] = a[i];
		a[i] = tmp;
	}
}

//insert sort
template < typename Type >
void insert(Type* a, int n)
{	
	for (int i = 0, j; i < n; ++i)
	{
		Type tmp = a[i];
		for (j = i - 1; j >= 0 && a[j] > tmp; --j)
			a[j + 1] = a[j];
		a[j + 1] = tmp;    
	}
}

//quick sort
template < typename Type >
void quick(Type* a, int n)
{
	int i = 0, j = n;
	Type temp, p;

	p = a[n >> 1];

	do {
		while (a[i] < p) i++;
		while (a[j] > p) j--;

		if (i <= j) {
			temp = a[i]; a[i] = a[j]; a[j] = temp;
			i++; j--;
		}
	} while (i <= j);
 
	if (j > 0) quick(a, j);
	if (n > i) quick(a + i, n - i);
}

//heapsort
template < typename Type >
void downHeap(Type* a, int k, int n)
{
	Type new_elem;
	int child;
	new_elem = a[k];

	while (k <= n / 2)
	{
		child = 2 * k;

		if (child < n && a[child] < a[child + 1])
			child++;
		if (new_elem >= a[child])
			break; 
		a[k] = a[child];
		k = child;
	}
	a[k] = new_elem;
}

template < typename Type >
void heapsort(Type* a, int n)
{
	int i;
	Type temp;
	for (i = n / 2 - 1; i >= 0; --i)
		downHeap(a, i, n - 1);

	for (i = n - 1; i > 0; --i)
	{
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		downHeap(a, 0, i - 1);
	}
}


int main()
{
	int size = 140000;
	int d = size;
	clock_t t;
	cout << "-----------------for INT-----------------" << endl;
	for (size=size; d/8 <= size; size = size/2)
	{

		int * vals1 = new int[size];
		for (int i = 0; i < size; i++)
			vals1[i] = 1 + rand() % size;
		int * vals2 = new int[size]; memcpy(vals2, vals1, sizeof(int)*size);
		int * vals3 = new int[size]; memcpy(vals3, vals1, sizeof(int)*size);
		int * vals4 = new int[size]; memcpy(vals4, vals1, sizeof(int)*size);
		int * vals5 = new int[size]; memcpy(vals5, vals1, sizeof(int)*size);

		cout << "for N=" << size << ":" << endl;
		cout << "Sorts algoritms N^2:" << endl;
		t = clock();
		bubble(vals1, size);
		t = clock() - t;
		cout << "Bubble method took: " << ((float)t) / CLOCKS_PER_SEC << " sec" << endl;

		t = clock();
		selection(vals2, size);
		t = clock() - t;
		cout << "Selection method took: " << ((float)t) / CLOCKS_PER_SEC << " sec" << endl;
		
		t = clock();
		insert(vals3, size);
		t = clock() - t;
		cout << "Insert method took: " << ((float)t) / CLOCKS_PER_SEC << " sec" << endl << endl;

		cout << "Sorts algoritms N*lolgN:" << endl;
		t = clock();
		quick(vals4, size);
		t = clock() - t;
		cout << "Quick method took: " << ((float)t) / CLOCKS_PER_SEC << " sec" << endl;

		t = clock();
		heapsort(vals5, size);
		t = clock() - t;
		cout << "Heapsort method took: " << ((float)t) / CLOCKS_PER_SEC << " sec" << endl << endl;
	}
	cout << "-----------------for FLOAT-----------------" << endl;
	size = d;
	for (size; d / 8 <= size; size = size / 2)
	{

		float * vals1 = new float[size];
		for (int i = 0; i < size; i++)
			vals1[i] = (float)rand() / (float)(RAND_MAX / 10000);
		float * vals2 = new float[size]; memcpy(vals2, vals1, sizeof(float)*size);
		float * vals3 = new float[size]; memcpy(vals3, vals1, sizeof(float)*size);
		float * vals4 = new float[size]; memcpy(vals4, vals1, sizeof(float)*size);
		float * vals5 = new float[size]; memcpy(vals5, vals1, sizeof(float)*size);

		cout << "for N=" << size << ":" << endl;
		cout << "Sorts algoritms N^2:" << endl;
		t = clock();
		bubble(vals1, size);
		t = clock() - t;
		cout << "Bubble method took: " << ((float)t) / CLOCKS_PER_SEC << " sec" << endl;

		t = clock();
		selection(vals2, size);
		t = clock() - t;
		cout << "Selection method took: " << ((float)t) / CLOCKS_PER_SEC << " sec" << endl;

		t = clock();
		insert(vals3, size);
		t = clock() - t;
		cout << "Insert method took: " << ((float)t) / CLOCKS_PER_SEC << " sec" << endl << endl;

		cout << "Sorts algoritms N*lolgN:" << endl;
		t = clock();
		quick(vals4, size);
		t = clock() - t;
		cout << "Quick method took: " << ((float)t) / CLOCKS_PER_SEC << " sec" << endl;

		t = clock();
		heapsort(vals5, size);
		t = clock() - t;
		cout << "Heapsort method took: " << ((float)t) / CLOCKS_PER_SEC << " sec" << endl << endl;
	}


	return 0;
}