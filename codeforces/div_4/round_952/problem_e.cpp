#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Problem: Codeforces Round 952 (Div. 4), E - Secret Box
// Link: https://codeforces.com/contest/1985/problem/E
//
// Summary:
// Given box dimensions x, y, z and a volume k, choose integer dimensions
// a, b, c such that a * b * c = k and a <= x, b <= y, c <= z. Maximize the
// number of positions where that smaller box can be placed inside the larger box.
//
// Solve:
// Factorize k, then enumerate how its prime powers are distributed among the
// first two dimensions. The third factor is determined by the remaining powers.
// For every valid triple inside the limits, compute
// (x - a + 1) * (y - b + 1) * (z - c + 1), and keep the maximum.
 
long long pow_long(long long b, int a) {
	long long iter = 1;
	for (int i = 0; i < a; i++)
	{
		iter *= b;
	}
	return iter;
}
vector<long long> get_primos(long long k_ref) {
	vector<long long> primos;
	long long  k_aux = k_ref;
	long long sq = sqrt(k_aux);
	for (int i = 2; i <= sq; i++)
	{
		while ((k_aux % i == 0)) {
			primos.push_back(i);
			k_aux = k_aux / i;
		}
	}
	if (k_aux != 1) primos.push_back(k_aux);
	return primos;
}
vector<long long> vect_primos;
vector<int> vect_num;
void traduct_primos(long long k_) {
	vector<long long> v = get_primos(k_);
	vect_primos = { v[0] };
	vect_num = { 1 };
	int pot = 0;
	for (size_t i = 1; i < v.size(); i++)
	{
		if (v[i] == vect_primos[pot]) vect_num[pot]++;
		else {
			vect_primos.push_back(v[i]);
			vect_num.push_back(1);
			pot++;
		}
	}
}
long long max_solution;
long long max_1; long long max_2; long long max_3;
long long valor(long long x, long long y, long long z) {
	return ((1 + max_1 - x) * (1 + max_2 - y) * (1 + max_3 - z));
}
void recursion_2(size_t pt_2, long long fact_1, long long fact_2, vector<int> vect_resto_2, vector<int>& vect_resto_1) {
	if (pt_2 < vect_resto_1.size()) {
		recursion_2(pt_2 + 1, fact_1, fact_2, vect_resto_2, vect_resto_1);
		long long iter = 1;
		for (int i = 1; i <= vect_resto_1[pt_2]; i++)
		{
			iter *= vect_primos[pt_2];
			vect_resto_2[pt_2] -= i;
			recursion_2(pt_2 + 1, fact_1,(fact_2*iter), vect_resto_2, vect_resto_1);
			vect_resto_2[pt_2] += i;
		}
	}
	else {
		if (fact_2 <= max_2) {
			long long fact_3 = 1;
			for (size_t i = 0; i < vect_primos.size(); i++)
			{
				fact_3 *= pow_long(vect_primos[i], vect_resto_2[i]);
			}
			if (fact_3 <= max_3) {
				long long val = valor(fact_1,fact_2,fact_3);
				if (val > max_solution) max_solution = val;
			}
		}
	}
 
}
void recursion_1(size_t pt, long long fact_1, vector<int> vect_resto) {
	if (pt < vect_num.size()) {
		recursion_1(pt + 1, fact_1, vect_resto);
		long long iter = 1;
		for (int i = 1; i <= vect_num[pt]; i++)
		{
			iter *= vect_primos[pt];
			vect_resto[pt] -= i;
			recursion_1(pt + 1, (fact_1*iter), vect_resto);
			vect_resto[pt] += i;
		}
	}
	else {
		if (fact_1 <= max_1) recursion_2(0, fact_1, 1, vect_resto, vect_resto);
	}
}
int main() {
	int t; cin >> t;
	while (t--) {
		cin >> max_1; cin >> max_2; cin >> max_3; long long k; cin >> k;
		if (k != 1) {
			traduct_primos(k);
			max_solution = 0;
			recursion_1(0, 1, vect_num);
		}
		else max_solution = valor(1,1,1);
		cout << max_solution << endl;
	}
	return 0;
}
