#include<iostream>
#include<math.h>
#include<String>
#include<stack>
#include<queue>
#include <map>
#include <vector>
#include <algorithm>

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

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int superPrimeNumber() {
	queue<int> q;
    int n;
    cin >> n ;
    for(int i = 2 ; i < n , i< 10 ; i++) {
        if(isPrime(i)) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        for(int i = 1 ; i <=9 ; i++) {
            int k = q.front()*10+i;
            if ( k <= n && isPrime(k)){
                q.push(q.front()*10 + i);
            }
        }
    cout << q.front() << " ";
    q.pop();
    }
}

int bai18() {
	int n;
    if (!(cin >> n)) return 0; 

    queue<int> q;
    vector<int> res;

    for (int i = 2; i <= 9; i++) {
        if (isPrime(i) && i <= n) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        res.push_back(current);

        for (int i = 1; i <= 9; i += 2) {
            long long nextNum = (long long)current * 10 + i; 

            if (nextNum <= n && isPrime(nextNum)) {
                q.push(nextNum);
            }
        }
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << (i == res.size() - 1 ? "" : " ");
    }

    return 0;
}

int bai17() {
	// bai tap ve stack
	int n , k ;
	queue<int> qu;
	cin >> n >> k ;
	for(int i = 0 ; i < n ; i++) {
		int temp ; 
		cin >> temp ;
		qu.push(temp) ;
	}
	
	for(int i = 0 ; i < k ; i++) {
		int to = qu.front();
		qu.push(to);
		qu.pop();
	}
	
	while(!qu.empty()) {
		cout << qu.front() << " ";
		qu.pop();
	}

}

int bai13() {
	// bai tap ve stack
	string St;
	cin >> St;
	stack<char> stack;
	for(int i = 0 ; i < St.length() ; i++) {
		stack.push(St[i]);
	} 
	
	while(!St.empty()) {
		cout << stack.top();
		stack.pop();
	}
}

int bai10() {
	// sum mang 2 chieu 
	int m , n ;
    cin >> m >> n ;
    int a[m][n];
    int sum = 0 ;
    for(int i=0 ; i< m ; i++) {
        for(int j=0; j < n ; j++) {
            cin >> a[i][j];
        }
    }

    for(int i=0 ; i< m ; i++) {
        for(int j=0; j < n ; j++) {
            sum = sum + a[i][j];
        }
    }

    cout << sum ;
}

int bai8(){
	
	// kiem tra co phai la day don dieu hay khong ?
	int n , a[1000] ;
    cin >> n; 
    for(int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }
    
    if (n <= 1) {
        cout << "YES";
        return 0;
    }
    
    bool isIncreasing = true;
    bool isDecreasing = true;
    
    for(int i = 0 ; i < n ; i++) {
        for(int j = i+1 ; j < n ; j++) {
        	if(a[i]<=a[j] ) {
        		    isIncreasing = false;
			} else if(a[i]>=a[j])
			{
				    isDecreasing = false;
			}
    	}
    }
    
    if(isIncreasing || isDecreasing ) {
        cout << "YES" ;
    } else {
        cout << "NO";
    }
    
}

int bai7() {
	int n , a[1000] ;
    cin >> n;
    
    //Nhap va mot so nguyen duong n, tiep theo la n so nguyen duong lan luot la 
	//cac phan tu cua mot day so, hay dem tan so (so lan xuat hien) cua cac so trong day va 
	//in no ra man hinh duoi dang sau: "a1 - t1; a2 - t2; ... an - tn; ", 
	//trong do t1 la so lan xuat hien cua so a1, t2 la so lan xuat hien cua a2, ... a1, a2, .. an 
	//khong trung nhau va duoc sap xep tang dan (xem vi du de ro hon)
	// Input: 4 2 2 5 6 5  --- Output : 2 - 2; 4 - 1; 5 - 2; 6 - 1;
	for(int i = 0 ; i< n ; i++) {
		cin >> a[i];
	}

    for(int i = 0 ; i<n ; i++) {
        for(int j = i+1 ; j < n ; j++) {
            if(a[i] > a[j]) {
                int temp = a[j] ;
                a[j] = a[i] ;
                a[i] = temp;
            }
        }
    }

    for(int i = 0 ; i<n ; i++) {

        int count = 1 ;
        while((i+1) < n && a[i]==a[i+1]) {
            count++;
            i++;
        }

        cout << a[i] << " - " << count << "; ";
    }

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

	//for (auto const& x : countMap) {
    //      cout << x.first << " - " << x.second << "; ";
   // }
	
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
	cout << bai17() ;
}
