#include <stdio.h>

int find(int target, int* arr, int size)
{
		int end = size - 1; 
		int init = 0;

		int mid;
	
		while(init <= end)
		{
		    mid = init + (end - init) / 2; 
			if(arr[mid] == target) return arr[mid];
			else if(arr[mid] < target) init = mid + 1;
			else if(arr[mid] > target) init = mid - 1; 
				printf("mid pos %d\n", mid);
		}

		return -1;
}

int main()
{
		int input;
		printf("find number: ");
		scanf("%d", &input);	
		
		int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		int arr_size = sizeof(arr) / sizeof(arr[0]);
	
		int ret = find(input, arr, arr_size);
		printf("result: [%d]\n", ret);
}
