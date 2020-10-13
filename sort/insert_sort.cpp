#include <iostream>
#include <vector>

int main() {
	std::vector<int> arr{5,2,6,1,3,4};

	for (int i = 1; i < arr.size(); ++i){
		int cur = arr[i];
		int j = i - 1;
		while ((arr[j] > cur) && (j >= 0)){
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = cur;
	}

	for (auto a: arr) std::cout << a;
}
