/*
 * @Author: fzy
 * @Date: 2019-01-23 14:42:36
 * @LastEditors: Zhenying
 * @LastEditTime: 2019-01-23 15:23:32
 * @Description: 训练营1，D题
 */

/*
 * D题：小a与黄金街道
 * 题目地址：https://ac.nowcoder.com/acm/contest/317/D
 * 简单思路：emm，搬一下官方的题解，
 *          首先，若gcd(n, x) == 1则gcd(n, n - x) == 1.
 *          若不考虑A，B的初值，则小a从起点终点k的幂为：k^{a}*k^{n-a}*k^{b}*k^{n-b} == k^{Rn}
 *          他们的最终黄金数，为自己的初值*k^{Rn}
 *          可以看出，能在某个位置产生k的幂的数，一定与n互质，则由欧拉函数的性质 https://zh.wikipedia.org/wiki/%E6%AC%A7%E6%8B%89%E5%87%BD%E6%95%B0 中的等式4，
 *          产生这些数的和为：(1/2*n*ola(n))
 *          求得是k的多少次幂之后，用快速幂求解即可。
 */

#include<iostream>
 
using namespace std;
 
typedef long long ll;
#define base 1000000007
 
ll ola(ll n){
    ll ret = 1, i;
    for (i = 2; i * i <= n; i++)
        if (n % i == 0){
            n /= i;
            ret *= i - 1;
            while (n % i == 0)
                n /= i, ret *= i;
        }
    if (n > 1)
        ret *= n - 1;
    return ret;
}
 
ll power(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1){
            b--;
            res = res * a % base;
        }
        b /= 2;
        a = a * a % base;
    }
    return res % base;
}
 
int main()
{
    ll n, k, A, B;
    cin >> n >> k >> A >> B;
    ll t = ola(n) * n / 2 % base;
    cout << (A + B) * power(k, t) % base << endl;
}

