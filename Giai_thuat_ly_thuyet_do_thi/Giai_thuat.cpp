#include<iostream>
#include<math.h>

using namespace std;


int CheckPrimeNumber(int x) {
	if(x < 2) {
		return false;
	}
	
	for(int i = 2 ; i<= sqrt(x); i++) {
		if(x%i == 0) {
			return false;
		}
	}
	
	return true;
}

int bai4() {
 // dem cac so lan lap trong mot mang roi in ra key value
	int n;
    if (!(cin >> n)) return 0;

    map<int, int> countMap;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        countMap[x]++; 
    }

    for (auto const& [val, count] : countMap) {
        cout << val << " - " << count << "; ";
    }

}

int Bai3() {
	int x, k, a[1000], n;
	// nhap mot day so va loc ra cac so nguyen to
	cout<< "nhap so luong";
	cin >> n;
	
	for(int i = 0 ; i< n ; i++) {
		cin >> a[i];
	}
	
    
	for(int i = 0 ; i < n ; i++) {
		if(CheckPrimeNumber(a[i])) {
			cout << a[i] << " ";
		}
	}
	return 0;
}


int Bai2() {
	int x, k, a[1000], n;
	cout<< "nhap so luong";
	cin >> n;
	
	for(int i = 0 ; i< n ; i++) {
		cin >> a[i];
	}
	cout<< "nhap k";
	cin >> k ;
	
	for(int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    
	for(int i = 0 ; i < n ; i++) {
		cout << a[i] << " ";
	}
	return 0;
}

int Bai1() {
	
//Nhap vao mot so nguyen duong n, va n so nguyen lan luot la cac phan tu trong day a. Tiep theo nhap vao hai so nguyen la k va x (0 = k = n).
//Hay chen phan tu co gia tri x vao day a, o truoc phan tu co chi so k va sau phan tu co chi so k-1. In mang ket qua ra man hinh, moi so cach nhau boi mot khoan trang.
	int x, k, a[1000], n;
	cout<< "nhap so luong";
	cin >> n;
	
	for(int i = 0 ; i< n ; i++) {
		cin >> a[i];
	}
	cout<< "nhap x va k";
	cin >> x >> k ;
	
	for(int i = n ; i >= k+1; i--) {
		a[i] = a[i-1];
	}
	
	a[k] = x ;
	n++;
	
	for(int i = 0 ; i<n ; i++) {
		cout << a[i];
	}
	
}

int main( )
{
	cout << Bai3() ;
}
