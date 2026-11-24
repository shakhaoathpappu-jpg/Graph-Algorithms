#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int ans = 0;
    for(int z = 0; z < 2; z++) {
        reverse(nums.begin(), nums.end());
        for(int i = 2; i < n; i++) {
            ans = max(ans, abs(nums[i] - nums[i-1]) + abs(nums[i] - nums[0]));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc_count;
    cin >> tc_count;
    while(tc_count--) {
        solve();
    }
}
