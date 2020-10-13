#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<int> left_arr(arr.begin() + p, arr.begin() + q + 1);
	std::vector<int> right_arr(arr.begin() + q + 1, arr.begin() + r + 1);
	
	int i = 0;
	int j = 0;
	int k = p;
	while (i < n1 && j < n2){
		if (left_arr[i] < right_arr[j]){
			arr[k] = left_arr[i];
			++i;
		} else {
			arr[k] = right_arr[j];
			++j;
		}
		++k;
	}

	while (i < n1){
		arr[k] = left_arr[i];
		++k;
		++i;
	}

	while (j < n2){
		arr[k] = right_arr[j];
		++k;
		++j;
	} 
}

void mergeSort(std::vector<int>& arr, int p, int q)
{
	if (p < q){
		int tmp = (p + q) / 2;
		mergeSort(arr, p, tmp);
		mergeSort(arr, tmp + 1, q);
		merge(arr, p , tmp, q);
	}
}



int main()
{
	std::vector<int> test_arr{7, 6, 3, 2, 4, 5, 1};
	mergeSort(test_arr, 0, test_arr.size() - 1);
	for (auto a: test_arr) std::cout << a;
}
