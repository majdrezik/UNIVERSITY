						// Heap_Sort - targeel bayet 2

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//functions declaration.
void print(int a);	//all the printfs.
void create(int arr[], int n);	//build heap.
void Heapify_Down(int arr[], int i, int n);
void exchange(int *a, int *b);	//exchange values.
void heap_sort(int arr[], int n);

int main(void){

	int i, n;
	int *arr;

	//array lengh.
	print(0);
	scanf("%d", &n);

	//check if array lengh is legal.
	while (n <= 0){
		print(1);
		scanf("%d", &n);
	}

	//check allocation.
	if ((arr = (int*)malloc(n*sizeof(int))) == NULL){
		print(2);
		exit(1);	//unsucessful termination.
	}

	//fill the array.
	print(3);
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	//print before sorting.
	print(4);
	printf("				");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

	//sort using heap sort.
	heap_sort(arr, n);

	//print after sorting.
	printf("\n");
	print(5);
	printf("				");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);

	free(arr);
	_getch();	
	return 0;
}

////////////////////////////// functions implementation ////////////////////////

//all the printfs divided into cases.
void print(int a){
	switch (a){
	case 0:
		printf("enter array lengh please: \n");
		break;
	case 1:
		printf("Error! array lengh is illegal.\n try again.\n");
		break;
	case 2:
		printf("Allocation Failed! \n");
		break;
	case 3:
		printf("please fill the array with <int> numbers:\n");
		break;
	case 4:
		printf("\n	array before change:\n");
		break;
	case 5:
		printf("\n	array after sorting:\n");
		break;
	}
}

void heap_sort(int arr[], int n){
	int i;
	create(arr, n);

	for (i = n - 1; i >= 1; i--){
		exchange(&arr[0], &arr[i]);
		n--;
		Heapify_Down(arr, 0, n);
	}
}

void create(int arr[], int n){
	int i;
	for (i = (n / 2) - 1; i >= 0; i--)
		Heapify_Down(arr, i, n);
}

void Heapify_Down(int arr[], int i, int n){
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;

	if (l<n && arr[l]>arr[i])
		largest = l;

	if (r <n && arr[r] > arr[largest])
		largest = r;

	// when i=largest recursion stopps.
	if (largest != i){	 
		exchange(&arr[i], &arr[largest]);
		Heapify_Down(arr, largest, n);
	}
}

//swap two numbers 
void exchange(int *a, int *b){
	int c;

	c = *a;
	*a = *b;
	*b = c;
}