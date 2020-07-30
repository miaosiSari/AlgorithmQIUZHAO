class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)
        {
            if(n != 0) return 0;
            else return 0x7fffffff;
        }
        if(x == 1) return 1.0;
        if(n == 0) return 1.0;
        if(n == 0x80000000) return 1.0/(myPow(x, 0x7fffffff) * x); 
        if(n < 0) return 1.0/myPow(x, -n);
        double t = n % 2?x:1;
        double res = myPow(x, n/2);
        return res * res * t;
    }
};
```