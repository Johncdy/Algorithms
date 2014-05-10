#include <iostream>

using namespace std;

void Insertion(int a[], int n) {
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && a[j] < a[j-1]; j--) {
			swap(a[j], a[j-1]);
		}
	}
}

int main(int argc, char *argv[]) {
	int a[] = {1, 3, 10, 18, 7};
	Insertion(a, 5);
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
}