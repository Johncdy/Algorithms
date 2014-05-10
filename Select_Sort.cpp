#include <iostream>

using namespace std;

void Selection (int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i+1; j < n; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}

int main(int argc, char *argv[]) {
	int a[] = {1, 3, 10, 18, 7};
	Selection(a, 5);
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
}