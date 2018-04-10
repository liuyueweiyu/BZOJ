#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int MAXSIZE = 6;
typedef long long LL;
const int _m = 100003;

LL ksm(LL base, LL order) {	//快速幂,base为基数,order为阶数
	LL ans = 1;
	while (order!=0)
	{
		if (order & 1 != 0)
			ans *= base;
		base *= base;
		base %= _m;
		order >>= 1;
		ans %= _m;
	}
	return ans;
}

int main() {
	LL n, m,ans;
	scanf_s("%lld %lld", &m, &n);
	m %= _m;	//一直AC不了是漏了这句话
	ans = (ksm(m, n) - ((ksm(m - 1, n - 1)*m % _m)) + _m) % _m;
	printf("%lld\n", ans);
	system("PAUSE");
	return 0;
}
