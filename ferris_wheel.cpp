#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 2e5 + 10;
const string CRLF = "\n";
bool got_gondola[maxn];

void solve() {
    int no_of_children = 0;
    int max_weight = 0;
    cin >> no_of_children >> max_weight;
    int weights[maxn];
    int light = 0;
    int heavy = 0;
    int gondolas = 0;
    for (int i = 0; i < no_of_children; i++) {
        cin >> weights[i];
    }
    sort(weights, weights + no_of_children);
    heavy = no_of_children - 1;
    while (light < heavy) {
        if (weights[light] + weights[heavy] > max_weight) 
            heavy--;
        else {
            gondolas++;
            got_gondola[light] = true;
            got_gondola[heavy] = true;
            light++;
            heavy--;
        }
    }
    for (int i = 0; i < no_of_children; i++) {
        gondolas += got_gondola[i] == false;
    }
    cout << gondolas;
    cout << CRLF;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}