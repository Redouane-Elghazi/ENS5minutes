#include <iostream>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;
const double eps=pow(10,-20);

void max(vector<vector<double>>& Gain, ll& i, ll& j, vector<ll>& Cap, vector<ll>& S){
    double m=0;
    for(ll a = 0; a<Gain.size(); ++a){
        for(ll b = 0; b<Gain[0].size(); ++b){
            if(Gain[a][b] > m and S[b] <= Cap[a]){
                i = a;
                j = b;
                m = Gain[a][b];
            }
        }
    }
}

int main()
{
    ll v, e, r, c, x;
    cin >> v >> e >> r >> c >> x;
    vector<ll> S(v), L(e), Rv(r), Re(r), Rn(r), Cap(c,x);
    vector<vector<ll>> E(e, vector<ll> (c,0)), LE(e, vector<ll> (c,0)), Res(c);
    for(ll i = 0; i<v; ++i){
        cin >> S[i];
    }
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
        if(E[i][j] and Req[i][k] and T[i][k] > LE[i][j]){
            Gain[j][k] += ((T[i][k] - LE[i][j])*Req[i][k])/(double)S[k];
        }
    }

    while(true){
        ll cm=-1, vm=-1;
        max(Gain, cm, vm, Cap, S);
        if(cm == -1 or Gain[cm][vm]<eps)
            break;
        Cap[cm]-=S[vm];
        Res[cm].push_back(vm);
        for(ll i = 0; i<e; ++i) {
            if(E[i][cm] and T[i][vm] > LE[i][cm])
                T[i][vm] = LE[i][cm];
        }
        for(ll j = 0; j<c; ++j){
            Gain[j][vm] = 0;
        }
        for(ll i = 0; i<e; ++i) for(ll j = 0; j<c; ++j) {
            if(E[i][j] and Req[i][vm] and T[i][vm] > LE[i][j]){
                Gain[j][vm] += ((T[i][vm] - LE[i][j])*Req[i][vm])/(double)S[vm];
            }
        }
    }
    cout << c << endl;
    for(ll i = 0; i<c; ++i){
        cout << i << " ";
        for(ll j:Res[i])
            cout << j << " ";
        cout << endl;
    }
    return 0;
}

