/*
 * @Author: fzy
 * @Date: 2019-01-23 14:27:43
 * @LastEditors: Zhenying
 * @LastEditTime: 2019-01-23 14:42:54
 * @Description: 训练营1，C题
 */

/*
 * C题：小a与星际探索
 * 题目地址：https://ac.nowcoder.com/acm/contest/317/C
 * 简单思路：新建一个辅助数组来记录从1号星球到第i号星球的最大耐久度。
 *          从第2号星球开始遍历全部星球，遍历到第i号星球时，
 *          依次判断1到i-1号星球中，哪个星球能到达第i号星球。
 *          若第j号星球可以到达第i号星球，再判断辅助数组中的值是否大于0（大于0意味着可以从1号星球到达该星球）
 *              若辅助数组[j]大于0,此时使用辅助数组[j]与i号星球的能量异或，来使用异或后的值和辅助数组[i]的最大值来更新辅助数组[i]
 *          这样一直遍历到第n号星球，辅助数组[n]即为结果。
 */

#include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main() {
     
    int n;
    cin >> n;
    vector<int> v(n);
    // 辅助数组，记录1号星球到第i号星球的最大能量
    vector<int> h(n, 0);
     
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
     
    h[0] = v[0];
    int res = v[0];

    // 如果星球n的能量指数大于1号星球的能量指数，则不可能到达，直接返回结果 
    if (v[n - 1] >= v[0]) {
        res = -1;
        cout << res << endl;
        return 0;
    }

    // 依次从2号星球开始遍历每个星球，然后得到1号星球到达i号星球的最大耐久度 
    for (int i = 1; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (v[i] < v[j]) {
                // h[j] == 0意味着,从1号星球到达不了j+1号星球。
                if (h[j] == 0) {
                    continue;
                } else {
                    // 若1号星球能到达j+1号星球，则更新1号星球到达i+1号星球的最大耐久度。
                    h[i] = max(h[i], v[i]^h[j]);
                }
                 
            }
        }
    }
     
    if (h[n - 1] <= 0) {
        cout << -1 << endl;
    } else {
        cout << h[n - 1] << endl;
    }
     
    return 0;
}

