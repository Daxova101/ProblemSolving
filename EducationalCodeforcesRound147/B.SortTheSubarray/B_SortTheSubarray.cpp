#include<iostream>
using namespace std;

int main() {
	int testcases;
	cin>>testcases;
	while (testcases > 0) {
		int n;
		cin>>n;
		int arr1[n], arr2[n], l=-1, r=-1, OL=-1, OR=-1;
		for(int i=0;i<n;i++) {
			cin>>arr1[i];
		}
		for(int i=0;i<n;i++) {
			cin>>arr2[i];
		}
		for(int i=0;i<n;i++) {
			if (arr1[i] != arr2[i] && l==-1) l=i;
			else if (arr1[i] != arr2[i] && l!=-1) r=i;
			else if (arr1[i] != arr2[i] && i==n-1) r=i;
			else if (arr1[i] == arr2[i] && r!=-1) {
				int x;
				for(x=l;x>0;x--) {
					if (arr2[x] < arr2[x-1]) break;
				}
				l=x;
				for(x=r;x<n-1;x++) {
					if (arr2[x] > arr2[x+1]) break;
				}
				r=x;
				if (OL == -1 || OR-OL < r-l) {
					OL = l;
					OR = r;
				}
				l=-1;
				r=-1;
			}
		}
		int x;
		for(x=l;x>0;x--) {
			if (arr2[x] < arr2[x-1]) break;
		}
		l=x;
		if (OL == -1 || OR-OL < r-l) {
			OL = l;
			OR = r;
		}
		cout<<OL+1<<" "<<OR+1<<"\n";
		testcases--;
	}
}