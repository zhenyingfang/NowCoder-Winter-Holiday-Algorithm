/*
 * @Author: fzy
 * @Date: 2019-01-23 13:48:21
 * @LastEditors: Zhenying
 * @LastEditTime: 2019-01-23 14:27:29
 * @Description: 训练营1，B题
 */

/*
 * B题：小a与204
 * 题目地址：https://ac.nowcoder.com/acm/contest/317/B
 * 基本思路：使用贪心法。首先得到的是包含0、2、4的一个序列。
 *          依次读入数据，记录序列中0、2、4的个数。
 *          首先，重排后的序列中，第一个元素应该是4，若没4，则应是2，若没2，则全部元素都是0，直接返回0.
 *          其次，对于第二个元素及之后，最优结果应是0和4依次组合，直到0或者4其中一个元素用完，后续用0和2或者4和2相互组合
 */

// 原始代码写的比较复杂，将就看下

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main() {
     
    int n;
    cin >> n;
     
    long long s0 = 0;
    long long s2 = 0;
    long long s4 = 0;

    // 记录输入序列中0、2、4的个数 
    for (int i = 0; i < n; ++i) {
        int t1;
        cin >> t1;
        if (t1 == 0) {
            s0++;
        } else if (t1 == 2) {
            s2++;
        } else {
            s4++;
        }
    }

    // 使用helper数组记录重排后的序列 
    vector<int> helper;
    
    // 判断helper中第一个元素应是什么
    if (s4 > 0) {
        helper.push_back(4);
        s4--;
    } else if (s2 > 0) {
        helper.push_back(2);
        s2--;
    } else {
        return 0;
    }

    // 当序列中2的数量和4的数量都大于0时，依次插入0和4 
    bool flag = true;
    while (s4 > 0 && s0 > 0) {
        if (flag) {
            helper.push_back(0);
            s0--;
            flag = !flag;
        } else {
            helper.push_back(4);
            s4--;
            flag = !flag;
        }
    }

    // 此时0或4中有个元素已经用完， 
    if (s4 > 0) {
        // 若4还有剩余，则将4和2依次交叉插入序列
        while (s4 > 0 && s2 > 0) {
            helper.push_back(4);
            s4--;
            helper.push_back(2);
            s2--;
        }
        while (s4 > 0) {
            helper.push_back(4);
            s4--;
        }
        while (s2 > 0) {
            helper.push_back(2);
            s2--;
        }
    } else {
        // 若0还有剩余，则将0和2依次交叉插入序列
        while (s0 > 0 && s2 > 0) {
            helper.push_back(0);
            s0--;
            helper.push_back(2);
            s2--;
        }
        while (s0 > 0) {
            helper.push_back(0);
            s0--;
        }
        while (s2 > 0) {
            helper.push_back(2);
            s2--;
        }
    }

    // 遍历helper数组，求得结果 
    int res = helper[0] * helper[0];
     
    for (int i = 1; i < helper.size(); ++i) {
        res += abs(helper[i] - helper[i - 1]) * abs(helper[i] - helper[i - 1]);
    }
     
    cout << res << endl;
     
    return 0;
}
