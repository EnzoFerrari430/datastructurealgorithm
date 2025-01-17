
/*
问题描述：
    一只袋鼠要从河这边跳到河对岸，河很宽，但是河中间打了很多桩子，每隔一米就有一个，每个桩子上都有一个弹簧，袋鼠跳到弹簧上就可以跳的更远。
    每个弹簧力量不同，用一个数字代表它的力量，如果弹簧力量为5，就代表袋鼠下一跳最多能够跳5米（最多能跳5米 就表示可以跳1 2 3 4 5），如果为0，就会陷进去无法继续跳跃。
    河流一共N米宽，袋鼠初始位置就在第一个弹簧上面，要跳到最后一个弹簧之后就算过河了，给定每个弹簧的力量，求袋鼠最少需要多少跳能够到达对岸。如果无法到达输出-1

作者思路：
    动态规划问题，和求最大递增序列差不多，每次遍历前面的数看是否能够到达当前位置，遇到则0跳过

    大概就是dp[i]表示到达i位置时的最少步数，而dp[i]又和i前面的位置有关，如果j+num[j]>=i，说明j位置能到达i位置，就更新dp[i]，保存达到i的最少步数
*/
#include<iostream>
#include<vector>
using namespace std;
int GetCount(vector<int>& num)
{
    int n = num.size();  //表示有n个木桩
    vector<int> dp(n + 1, 10000);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 0; j--)  //每次遍历前面的数，看是否能够到达当前位置
        {
            if (num[j] == 0)
                continue;
            if (j + num[j] >= i)
                dp[i] = min(dp[i], dp[j] + 1);  //取步数小的值当做到达该位置的值
        }
    }
    if (dp[n] == 10000)
        return -1;
    else
        return dp[n] - 1;
}

int main()
{
    int N = 0;
    cin >> N;
    vector<int> num(N,0);
    for (int i = 0; i < N; i++)
        cin >> num[i];
    cout << GetCount(num) << endl;
    return 0;
}
