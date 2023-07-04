#include<bits/stdc++.h>
using namespace std;


// It is a number that is divisible by 1 & itself ans has only two factors
// TC - O(N)
void checkPrime() {
	int n = 10;
	int factor = 0;
	for(int i = 1;i<=n;i++) {
		if(n%i == 0) factor++;
	}

	if(factor == 2) cout << "Yes it's Prime";
	else cout << "No it's not";
}

// Optimize version
// TC - O(sqrt(N) * log(N))
// Instead of writing O(sqrt(n)) we can write 
// it as (i*i<=n) it will take time only
// O(sqrt(N))

void checkPrimeOptimized() {
	int n = 13;
	int factor = 0;
	for(int i = 1;i*i<=n;i++) {
		if(n%i == 0) {
			factor++;
			if(n/i != i) factor++;
		}
	}
	if(factor == 2) cout << "Prime";
	else cout << "Not Prime";
}


void sumOfFactors() {
	int n = 24;
	int sum = 0;

	for(int i = 1;i*i<=n;i++) {
		if(n%i == 0) {
			sum += i;
			if(n/i != i) sum += n/i;
		}
	}
	cout << sum;
}

// Question from Codeforces 1294C - Product of Three Numbers
void productOfThree() {
	int n = 30;
	int a = 1, b = 1, c = 1;

	if(n < 24) cout << "No" << "\n";
	else {
		for(int i = 2;i*i<=n;i++) {
			if(n%i == 0) {
				a = i;
				break;
			}
		}

		n = n / a;

		for(int i = a+1;i*i<=n;i++) {
			if(n%i == 0) {
				b = i;
				break;
			}	
		}

		c = n / b;
		if(a == b || b == c || a == c || a == 1 || b == 1 || c == 1) cout << "No" << "\n";

		else {
			cout << "Yes" << "\n";
			cout << a << " " << b << " " << c;
		}
	}	
}

// TC - O(n log(log n))


void createSieve(int N, bool sieve[]) {
	

	for(int i = 2;i<=N;i++) {
		sieve[i] = true;
	}

	for(int i = 2;i*i<=N;i++) {
		if(sieve[i] == true) {
			for(int j = i*i;j<=N;j+=i) {
				sieve[j] = false;
			}
		}
	}
}


// Find the kth Prime number.  K <= 5 * 10^6
// 5 * 10^6 th prime should be greater than this number
// We dont know the exact number so we create sieve of
// 10^8 size of worst case

int N = 100000000;
bool sieve[100000001];

void createSieve() {
	for(int i = 2;i<=N;i++) {
		sieve[i] = true;
	}

	for(int i = 2;i*i<=N;i++) {
		if(sieve[i] == true) {
			for(int j = i*i;j<=N;j++) {
				sieve[j] = false;
			}
		}
	}

	int limit = 5 * 1000000;
	int cnt = 0;
	int size = 1;

	for(int i = 2;;i++) {
		if(sieve[i] == true) {
			cnt++;
		}
		if(cnt == limit) {
			size = i;
			break;
		}
	}

	cout << size << "\n";
}


// Now we know that 5*10^6 th prime is
// 86028121 so now we craete this size sieve



int N = 86028121;
bool sieve[86028122];
vector<int> size;

void createSieve() {
	for(int i = 2;i<=N;i++) {
		sieve[i] = true;
	}

	for(int i = 2;i*i<=N;i++) {
		if(sieve[i] == true) {
			for(int j = i*i;j<=N;j++) {
				sieve[j] = false;
			}
		}
	}


	for(int i = 2;i<=N;i++) {
		if(sieve[i] == true)
			size.push_back(i);
	}
}


// Given [1 - 10^6] range and find how many
// no in this range have min prime-factor as n


int N = 1000000;
int size[1000001];

void createSieve() {
	for(int i = 2;i<=N;i++) {
		sieve[i] = 1;
	}

	for(int i = 2;i*i<=N;i++) {
		if(sieve[i] == 1) {
			for(int j = i*i;j<=N;j++) {
				if(sieve[j] != 0) {
					sieve[i]++;
					sieve[j] = 0;
				}
			}
		}
	}
}


// Given a number n print its prime factorisation

// n = 20
// TC - O(sqrt(n))

void printPrmimeFactors() {
	for(int i = 2;i*i<=n;i++) {
		while(n%i == 0) {
			cout << i << " ";
			n = n / i;
		}
	}

	if(n > 1) cout << n;
}


// Optimize approach
// Print prime factorisation

int N = 1000000;
int size[1000001];
void spf() {
	for(int i = 1;i<=N;i++) {
		spf[i] = i;
	}

	for(int i = 2;i*i<=N;i++) {
		if(spf[i] == i) {
			for(int j = i*i;j<=N;j+=i) {
				if(spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}
}


//SEGMENTED SIEVE

// Print prime between a range[L R] <= 10^12
// [R-L] <= 10^6

int N = 1000000;
bool sieve[1000001];

void createSieve() {
	for(int i = 2;i<=N;i++) {
		sieve[i] = true;
	}

	for(int i = 2;i*i<=N;i++) {
		if(sieve[i] == true) {
			for(int j = i*i;j<=N;j++) {
				sieve[j] = false;
			}
		}
	}
}

vector<int> generatePrimes(int n) {
	vector<int> vec;
	for(int i = 2;i<=N;i++) {
		if(sieve[i] == true) {
			vec.push_back(i);
		}
	}
	return vec;
}


int main() {
	createSieve();
	int t;
	cin >> t;
	while(t--) {
		int l, r;
		cin >> l >> r;

		// step 1: generate all prime till sqrt(r)

		vector<int> primes = generatePrimes(sqrt(r));


		// step 2: create a dummy array of size
		// [r-l+1] and mark with 1

		int dummy[r - l + 1];
		for(int i = 0;i<r-l+1;i++) {
			dummy[i] = 1;
		}


		// step 3: for all prime number
		// mark its multiples as false

		for(auto &pr : primes) {

			int firstMultiple = (l / pr) * pr;
			if(firstMultiple < l) firstMultiple += pr;

			for(int j = max(firstMultiple, pr*pr);j<=r;j+=pr) {
				dummy[j-l] = 0;
			}
		}

		// step 4: get all the primes
		for(int i = l;i<=r;i++) {
			if(dummy[i-l] == 1) {
				cout << i << " ";
			}
		}	
		cout << "\n";
	}
}

