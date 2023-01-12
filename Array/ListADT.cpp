#include <cstdio>
#include <cstdlib>
#include <cmath>

typedef struct _List {
	int arr[20];
	int capacity;
	int size;
} List;

void display(List a) {
	for(int i=0;i<a.size;i++) {
		printf("%d ", a.arr[i]);
	}
	printf("\n");
}

void append(List *ptr, int x) {
	if(ptr->size==ptr->capacity) {
		printf("Capacity already filled\n");
		return;
	}
	ptr->arr[ptr->size] = x;
	ptr->size++;
}

void set(List *ptr, int index, int new_val) {
	if(index>=0 && index<=9)
		ptr->arr[index] = new_val;
}

int get(List a, int index) {
	return a.arr[index];
}

int linear_search(List *ptr, int value) {
	int i;
	for(i=0; i<ptr->size; i++) {
		if(ptr->arr[i] == value) {
			return i;
		}
	}
	return -1;
}

void insert(List *ptr, int index, int value) {
	int i;
	for(i=ptr->size; i>index; i--) {
		ptr->arr[i] = ptr->arr[i-1];
	}
	ptr->arr[i] = value;
	ptr->size++;
}

void remove(List *ptr, int index) {
	int i;
	for(i=index; i<ptr->size-1; i++) {
		ptr->arr[i] = ptr->arr[i+1];
	}
	ptr->size--;
}

int binary_search_iter(List *ptr, int value) {
	int low=0, high=(ptr->size-1);
	int mid = floor((low+high)/2);
	while(low<=high) {
		if(ptr->arr[mid] == value) {
			return mid;
		} else if(ptr->arr[mid] < value) {
			low = mid+1;
		} else {
			high = mid-1;
		}
		mid = floor((low+high)/2);
	} 
	return -1;
}

int binary_search_recur(List *ptr, int low, int high, int value) {
	int mid; ;
	if(low<=high) {
		mid = (low+high)/2;
		if(ptr->arr[mid] > value) {
			return binary_search_recur(ptr, low, mid-1, value);
		} else if (ptr->arr[mid] < value) {
			return binary_search_recur(ptr, mid+1, high, value);
		} else if (ptr->arr[mid] == value){
			return mid;
		}
	}
	return -1;
}

int main() {
	List num = {{2,4,7,9,10,14,16,18,19,23,35,38,41,67,89},20,15};
	// printf("Enter the size of the List: ");
	// scanf("%d", &num.size); 
	// if(num.size>num.capacity) {
	// 	printf("Out of bound error\n");
	// 	return 1;
	// }
	// printf("Enter %d integers: \n", num.size);
	// for(int i=0;i<num.size;i++) {
	// 	scanf("%d", &num.arr[i]);
	// }
	
	display(num);
	// append(&num, 7);
	// display(num);
	// printf("%d\n", get(num,3));
	// set(&num, 3, 12);
	// display(num);

	// insert(&num, 0, 99);
	// remove(&num, 3);
	// display(num);
	// printf("%d", linear_search(&num, 2));
	// printf("%d", binary_search_iter(&num, 7));

	printf("%d", binary_search_recur(&num, 0, num.size-1, 19));
	return 0;
}
