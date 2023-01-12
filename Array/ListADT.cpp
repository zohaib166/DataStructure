#include <cstdio>
#include <cstdlib>
#include <cmath>

typedef struct _List {
	int arr[20];
	int capacity = 20;
	int size;
} List;

void fillArray(List *num, int length) {
	if(length > num->capacity) {
		printf("Out of bound error\n");
		return;
	}
	num->size = length;
	for(int i=0;i<num->size;i++) {
		scanf("%d", &num->arr[i]);
	}
}

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

void shift(List *ptr, char direction) {
	if(direction=='l' || direction=='L') {
		for(int i=1; i<ptr->size; i++) {
			ptr->arr[i-1] = ptr->arr[i];
		}
		ptr->arr[ptr->size-1] = 0;
	} else {
		for(int i=ptr->size-1; i>0; i--) {
			ptr->arr[i] = ptr->arr[i-1];
		}
		ptr->arr[0] = 0;
	}
}

void rotate(List *ptr, char direction) {
	if(direction=='l' || direction=='L') {
		int temp = ptr->arr[0];
		for(int i=1; i<ptr->size; i++) {
			ptr->arr[i-1] = ptr->arr[i];
		}
		ptr->arr[ptr->size-1] = temp;
	} else {
		int temp = ptr->arr[ptr->size-1];
		for(int i=ptr->size-1; i>0; i--) {
			ptr->arr[i] = ptr->arr[i-1];
		}
		ptr->arr[0] = temp;
	}
}

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int sum(List num) {
	int sum=0;
	for(int i=0;i<num.size;i++) {
		sum += num.arr[i];
	}
	return sum;
}

int max(List num) {
	int max = num.arr[0];
	for(int i=1;i<num.size;i++) {
		if(max<num.arr[i]) {
			max = num.arr[i];
		}
	}
	return max;
}

int min(List num) {
	int min = num.arr[0];
	for(int i=1;i<num.size;i++) {
		if(min>num.arr[i]) {
			min = num.arr[i];
		}
	}
	return min;
}

double avg(List num) {
	return sum(num)/(double)num.size;
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

void reverse(List *ptr) {
	int i=0, j=ptr->size-1;
	while(i<j) {
		swap(&ptr->arr[i], &ptr->arr[j]);
		i++, j--;
	}
}

void insert_sorted(List *ptr, int value) {
	int i;
	for(i=ptr->size-1; ptr->arr[i]>value; i--) {
		ptr->arr[i+1] = ptr->arr[i];
	}
	i++;
	ptr->arr[i] = value;
	ptr->size++;
} 

int is_sorted(List num) {
	for(int i=1; i<num.size; i++) {
		if(num.arr[i-1] > num.arr[i]) {
			return 0;
		}
	}
	return 1;
}

void arrange_neg_pos(List *ptr) {
	int i = 0, j = ptr->size-1;
	while(i<j) {
		while(ptr->arr[i]<0) {i++;}
		while(ptr->arr[j]>0) {j--;}
		if(i<j) {
			swap(&ptr->arr[i], &ptr->arr[j]);
		}
	}
}

int main() {
	//List num = {{2,4,7,9,10,14,16,18,19,23,35,38,41,67,89},20,15};

	List num = {{-1, 3, 4, -6, 7, -7},20,6};

	// printf("Enter the size of the List: ");
	// int length;
	// scanf("%d", &length); 
	// printf("Enter the %d elements: \n", length);
	// fillArray(&num, length);
	
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

	// printf("%d", binary_search_recur(&num, 0, num.size-1, 19));

	// printf("%.2lf", avg(num));
	// reverse(&num);

	// shift(&num, 'r');
	// rotate(&num, 'l');
	// insert_sorted(&num, 20);
	// if(is_sorted(num)==1) {
	// 	printf("List is sorted");
	// } else {
	// 	printf("List is not sorted");
	// }

	arrange_neg_pos(&num);
	
	display(num);
	return 0;
}
