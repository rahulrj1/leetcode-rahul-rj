vector<bool> sieve;
vector<int> prime;

class Solution {
public:
    void createSieve() {
        int n = 5*1e6;
        sieve.resize(n+1);
        for(int i=0; i<=n; i++) sieve[i] = true;
        sieve[0] = false; sieve[1] = false;
        for(int i=2; i*i<=n; i++) {
            if(sieve[i] == false) continue;
            for(int j=i*i; j<=n; j += i) sieve[j] = false;
        }
        prime.resize(n+1); prime[0] = 0; prime[1] = 0; 
        for(int i=2; i<=n; i++) {
            prime[i] = prime[i-1] + sieve[i];
        }
    }
    
    int countPrimes(int n) {
        if(sieve.size() == 0) createSieve();
        if(n == 0) return 0;
        return prime[n-1];
    }
};