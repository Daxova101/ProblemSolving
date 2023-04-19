#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int v1, v2, secs, vmv, sum=0, flag=0;
	cin>>v1>>v2>>secs>>vmv;
	if (v1 > v2) swap(v1, v2);
	sum += v1+v2;
	secs-=2;
	for(int i=0;i<secs;i++) {
		if ((secs-i-1)*vmv <= abs((v1+vmv)-v2)-vmv) {
			v1 += vmv - ((abs((v1+vmv)-v2)-vmv)-((secs-i-1)*vmv));
			sum += v1;
		}
		else {
			v1 += vmv;
			sum += v1;
		}
	}
	cout<<sum;
}