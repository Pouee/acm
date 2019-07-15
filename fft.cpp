#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<complex>
#define SIZE 10000
#define PI 3.14159265354
using namespace std;


void FFT(complex<double> *a, int *r, int f, int n){
	for (int i = 0; i<n; i++)if (i<r[i])swap(a[i], a[r[i]]);
	for (int i = 1; i<n; i <<= 1){
		complex<double> wn(cos(PI / i), f*sin(PI / i));
		for (int p = i << 1, j = 0; j<n; j += p){
			complex<double> w(1, 0);
			for (int k = 0; k<i; k++, w *= wn){
				complex<double> x = a[j + k], y = w*a[j + k + i];
				a[j + k] = x + y; a[j + k + i] = x - y;
			}
		}
	}
}
void polyMul(complex<double> *a, complex<double> *b, int n, int m, int *r){
	int l = 0;
	m += n; for (n = 1; n <= m; n <<= 1)l++;
	for (int i = 0; i<n; i++)r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	FFT(a, r, 1, n); FFT(b, r, 1, n);
	for (int i = 0; i <= n; i++)a[i] = a[i] * b[i];
	FFT(a, r, -1, n);
	for (int i = 0; i <= m; i++)a[i]._Val[0] /= n;
}
int horner_rule(complex<double> arr[], int n, int x)
{
	int i, ans = 0;
	for (i = n; i>=0; --i)
	{
		ans = (int)(arr[i].real()/n + 0.5) + x*ans;
	}
	return ans;
}
int R[SIZE];
complex<double> A[SIZE];
complex<double> B[SIZE];
long long int F[30];
void Init(){
	int i = 1; F[0] = 1;
	for (int i = 1; i <= 30; ++i){
		F[i] = F[i-1] * i;
	}

}
int main()
{
	Init();


	int n, m,num,P = 0;
	while (scanf("%d%d",&n,&m) == 2){
		memset(A, 0, sizeof(A));
		for (int i = 0; i < n; ++i){
			scanf("%d", &num);
			if (i == 0) A[0] = 1, P = 0;
			memset(B, 0, sizeof(B));
			for (int j = 0; j <= num; ++j){
				B[j] = 1.0 / F[j];
			}
			polyMul(A, B, P, num, R);
			P += num;
			
		}
		cout << (int)(A[m].real() *F[m] +0.5)  << endl;
	}
	return 0;
}
