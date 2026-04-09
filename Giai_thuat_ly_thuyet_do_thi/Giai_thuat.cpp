#include<iostream>
using namespace std;



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
	cout << Bai1() ;
    return 0; 
}
