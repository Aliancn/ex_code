#include <cstdio>
#include <cstdlib>
typedef long long lolong;

int mod;
lolong I_mul_I; // 虚数单位的平方

struct complex {
	lolong real, imag;
	complex(lolong real = 0, lolong imag = 0): real(real), imag(imag) { }
};
inline bool operator == (complex x, complex y) {
	return x.real == y.real and x.imag == y.imag;
}
inline complex operator * (complex x, complex y) {
	return complex((x.real * y.real + I_mul_I * x.imag % mod * y.imag) % mod,
			(x.imag * y.real + x.real * y.imag) % mod);
}

complex power(complex x, int k) {
	complex res = 1;
	while(k) {
		if(k & 1) res = res * x;
		x = x * x;
		k >>= 1;
	}
	return res;
}

bool check_if_residue(int x) {
	return power(x, (mod - 1) >> 1) == 1;
}

void solve(int n, int p, int &x0, int &x1) {
	mod = p;

	lolong a = rand() % mod;
	while(!a or check_if_residue((a * a + mod - n) % mod))
		a = rand() % mod;
	I_mul_I = (a * a + mod - n) % mod;

	x0 = int(power(complex(a, 1), (mod + 1) >> 1).real);
	x1 = mod - x0;
}