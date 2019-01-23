/*
 * @Author: fzy
 * @Date: 2019-01-23 12:09:50
 * @LastEditors: Zhenying
 * @LastEditTime: 2019-01-23 13:48:01
 * @Description: 训练营1，A题
 */

/*
 * A题：小a的计算器。
 * 题目地址：https://ac.nowcoder.com/acm/contest/317/A
 * 基本思路：直接根据最终的数以及操作序列还原到原始值即可
*/

#include <iostream>
#include <stack>
#include <algorithm>
 
using namespace std;
 
int main() {
    long long n, X;
    cin >> n;
    cin >> X;
     
    // 用来记录进行的运算类型 
    stack<long long> s1;
    // 记录每次运算使用的值
    stack<long long> s2;
     
    for (long long i = 0; i < n; ++i) {
        long long t1, t2;
        cin >> t1;
        cin >> t2;
        s1.push(t1);
        s2.push(t2);
    }
     
    long long res = X;

    // 依次从栈中读取操作的类型，和操作的数据，对最终结果进行还原 
    while (!s1.empty()) {
        long long t1 = s1.top(); s1.pop();
        long long t2 = s2.top(); s2.pop();
         
        if (t1 == 1) {
            res -= t2;
        } else if (t1 == 2) {
            res += t2;
        } else if (t1 == 3) {
            res /= t2;
        } else {
            res *= t2;
        }
         
    }
     
    cout << int(res) << endl;
}
