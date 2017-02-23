#include <iostream>
#include <vector>
#define ll long long

using namespace std;


int main()
{
    ll v, e, r, c, x;
    cin >> v >> e >> r >> c >> x;
    vector<ll> S(v), L(e), Rv(r), Re(r), Rn(r);
    vector<vector<ll>> E(e, vector<ll> (c,0)), LE(e, vector<ll> (c,0));
//    vector<vector<ll>> adjE(e), adjLE(e), adjC(c), adjLC(c);
    for(ll i = 0; i<v; ++i)
        cin >> S[i];
    for(ll i = 0; i<e; ++i){
        cin >> L[i];
        ll K;
        cin >> K;
        for(ll j = 0; j<K; ++j){
            ll c2, l;
            cin >> c2 >> l;
            E[i][c2]=1;
            LE[i][c2]=l;
        }
    }
    for(ll i = 0; i<r; ++i){
        cin >> Rv[i] >> Re[i] >> Rn[i];
    }
    vector<vector<double>> Gain(c, vector<double> (v,0));
    vector<vector<ll>> Time(e, vector<ll> (v));
    vector<vector<ll>> Req(e, vector<ll> (v,0)), T(e, vector<ll> (v,0));
    for(ll i = 0; i<r; ++i){
        Req[Re[i]][Rv[i]]+=Rn[i];
    }
    for(ll i = 0; i<e; ++i) for(ll j = 0; j<v; ++j) {
        T[i][j] = L[i];
        Time[i][j] = Req[i][j]*T[i][j];
    }
    for(ll i = 0; i<e; ++i) for(ll j = 0; j<c; ++j) for(ll k = 0; k<v; ++k) {
        if(E[i][j] and T[i][k] > LE[i][j]){
//            cout << "ok" << T[i][k] << " " << LE[i][j] << " " << Req[i][k] << endl;
            Gain[j][k] += ((T[i][k] - LE[i][j])*Req[i][k]);///(double)S[k];
//            cout << Gain[j][k] << endl;
        }
    }
    for(ll i = 0; i<c; ++i) {
        for(ll j = 0; j<v; ++j) {
            cout << Gain[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

