#include <iostream>
#define ll long long

using namespace std;


int main()
{
    ll v, e, r, c, x;
    cin >> v >> e >> r >> c >> x;
    vector<ll> S(v), L(e), Rv(r), Re(r), Rn(r);
    vector<vector<ll>> adjE(e), adjLE(e), adjC(c), adjLC(c);
    for(ll i = 0; i<v; ++i)
        cin >> S[i];
    for(ll i = 0; i<e; ++i){
        cin >> L[i];
        ll K;
        cin >> K;
        for(ll j = 0; j<K; ++j){
            ll c, l;
            cin >> c >> l;
            adjE[i].push_back(c);
            adjLE[i].push_back(l);
            adjC[c].push_back(i);
            adjLC[c].push_back(l);
        }
    }
    for(ll i = 0; i<r; ++i){
        cin >> Rv[i] >> Re[i] >> Rn[i];
    }
    vector<vector<double>> Gain(c, vector<double> (v));
    vector<vector<ll>> Time(e, vector<ll> (v));
    vector<vector<ll>> Req(e, vector<ll> (v,0));
    for(ll i = 0; i<r; ++i){
        Req[Re[i]][Rv[i]]+=Rn[i];
    }
    for(ll i = 0; i<e; ++i) for(ll j = 0; j<v; ++j) {
        Time[i][j] = Req[i][j]*L[i];
    }

    return 0;
}

