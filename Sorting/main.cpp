#include <iostream>

void swap(int &element1, int &element2){
	int temp_swap_element = 0;
	temp_swap_element = element1;
	element1 = element2;
	element2 = temp_swap_element;
}

//сортировка выбором, сложность O(n^2)
void selection_sort(int *array, int N){
	int unsorted_part_index = 1;
	for (int i = 0;i < N;i++){
		for (int j = unsorted_part_index;j < N;j++){
			if (array[j] < array[i]){
				swap(array[i], array[j]);
			}
		}
		unsorted_part_index++;
	}
}

//сортировка вставками, сложность O(n^2)
void insertion_sort(int *array, int N){
	int unsorted_part_index = 1;
	for(int i = unsorted_part_index; i < N; i++){
		for (int j = 0;j < i;j++){
			if (array[i] < array[j]){
				swap(array[i], array[j]);
			}
		}
		unsorted_part_index++;
	}
}

//сортировка пузырьком, сложность O(n^2)
void bubble_sort(int *array, int N){
	for (int i = 0;i < N;i++){
		for (int j = 0;j < N - 1;j++){
			if (array[j] > array[j + 1]){
				swap(array[j], array[j + 1]);
			}
		}
	}
}

//слияние двух отсортированных подмассивов
void merge(int *array, int left, int middle, int right){
	int n1 = middle - left + 1;
	int n2 = right - middle;
	int *al = new int[n1];
	int *ar = new int[n2];
	for (int i = 0;i < n1;i++){
		al[i] = array[left + i];	
	}
	for (int i = 0; i < n2; i++){
		ar[i] = array[middle + 1 + i];
	}
	int j = 0;
	int i = 0;
	int temp = left;
	while (i < n1 || j < n2){
		if (!(i < n1)){
			array[left] = ar[j];
			j++;
		}
		else if (!(j < n2)){
			array[left] = al[i];
			i++;
		}
		else {
			if (al[i] <= ar[j]){
				array[left] = al[i];
				i++;
			}
			else{
				array[left] = ar[j];
				j++;
			}
		}
		left++;
	}
	delete[] al;
	delete[] ar;
}

//сортировка слиянием, сложность O(n*log(n))
void merge_sort(int *array, int left, int right){
	if (left < right){
		int middle = left + (right - left) / 2;
		merge_sort(array, left, middle);
		merge_sort(array, middle + 1, right);
		merge(array, left, middle, right);
	}
}

int main(){
	int N = 14;
	int array[] = { 38, 27, 43, 3, 9, 82, 10, -1000, 32453, 12, 544, -65, 0, 177};

	array[14] = 5;
	std::cout << N << std::endl;

	std::cout << "Input array:" << std::endl;
	for (int i = 0; i < N; i++){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	//selection_sort(array, N);
	//insertion_sort(array, N);
	//bubble_sort(array, N);
	merge_sort(array, 0, N-1);
	std::cout << "Sorted array:" << std::endl;
	for (int i = 0; i < N; i++){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}