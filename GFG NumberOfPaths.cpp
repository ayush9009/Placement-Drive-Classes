
class Solution
{
    public:
    long long gcdExtended(long long a, long long b, long long* x, long long* y)
    {
        if (a == 0) {
            *x = 0, *y = 1;
            return b;
        }
        long long x1, y1;
        long long gcd = gcdExtended(b % a, a, &x1, &y1);
        *x = y1 - (b / a) * x1;
        *y = x1;
     
        return gcd;
    }
    long long modInverse(long long A, long long M)
    {
        long long x, y;
        long long g = gcdExtended(A, M, &x, &y);
        long long res = (x % M + M) % M;
        return res;
    }
    long long  numberOfPaths(int M, int N)
    {
        long long path = 1,mod=1e9+7;
        for (long long i = N; i < (M + N - 1); i++) {
            path = (path*i)%mod;
            long long inv=modInverse(i-N+1,mod);
            path = (path*inv)%mod;
        }
        return path;
    }
};
