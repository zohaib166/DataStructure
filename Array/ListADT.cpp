#include <cstdio>
#include <cstdlib>

typedef struct _List {
	int arr[10];
	int capacity = 10;
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
int main() {
	List num;
	printf("Enter the size of the List: ");
	scanf("%d", &num.size); 
	if(num.size>num.capacity) {
		printf("Out of bound error\n");
		return 1;
	}
	printf("Enter %d integers: \n", num.size);
	for(int i=0;i<num.size;i++) {
		scanf("%d", &num.arr[i]);
	}
	
	display(num);
	append(&num, 7);
	display(num);
	printf("%d\n", get(num,3));
	set(&num, 3, 12);
	display(num);
	return 0;
}
