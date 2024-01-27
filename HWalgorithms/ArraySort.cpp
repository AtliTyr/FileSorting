#include "ArraySort.h"

int* countSort(int* arr, int n, int max)
{
	int* count = new int[max + 1] {0};
	for (int i = 0; i < n; i++)
	{
		count[arr[i]]++;
	}

	int* output = new int[n];

	int k = 0;
	for (int i = 0; i < max + 1; i++)
		while (count[i] != 0)
		{
			output[k] = i;
			k++;
			count[i]--;
		};

	delete[] count;
	return output;
}