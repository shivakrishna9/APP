#include<bits/stdc++.h>
using namespace std;

long long solve (long long steps, long long k) {
    int result[k+1]={0},sum=1,foo=steps+1;
    result[0] = 1;
    for(int i=1;i<=steps;i++)
    {
        for(int j=1;j<=i;j++)
            result[i]+= result[i-j];
        sum+=result[i];
    }
    for(int i=foo;i<=k;i++)
    {
        result[i] = sum-result[i-foo];
        sum = sum+result[i]-result[i-foo];
    }
    return result[k];
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        long long N;
        cin >> N;
        long long K;
        cin >> K;

        long long out_;
        out_ = solve(K, N);
        cout << out_;
        cout << "\n";
    }
}
