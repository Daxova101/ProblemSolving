#include<iostream>
using namespace std;

int binarySearch (int arr[], int first, int last, int find) {
	if (first <= last) {
		int mid = (first+last)/2;
		if (arr[mid] == find) {
			return mid;
		}
		else if (arr[mid] < find) {
			return binarySearch(arr, mid+1, last, find);
		}
		return binarySearch(arr, first, mid-1, find);
	}
	else {
		return -2;
	}
}

int main() {
	int num, searchNum;
	cin>>num;
	int nums[num];
	for(int i=0;i<num;i++) {
		cin>>nums[i];
	}
	cin>>searchNum;
	for(int i=0;i<searchNum;i++) {
		int x;
		cin>>x;
		cout<<binarySearch(nums, 0, num, x)+1<<"\n";
	}
}