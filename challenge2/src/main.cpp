#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#define ll long long
#define valid(i, j) 0<=i and i<H and 0<=j and j<W
using namespace std;
const double eps=pow(10,-20);
ll H, W;

void placeRouter(vector<vector<ll>>& closestB, set<pair<ll,ll>>& backbones, vector<vector<set<pair<ll,ll>>>>& dependency, ll r, ll c){
    ll x = r, y = c, i, j;
    while(closestB[x][y] != 0){
        backbones.emplace(x,y);
        i=x-1;
        j=y-1;
        if(valid(i, j) and closestB[i][j]==closestB[x][y]-1){
            x=i;
            y=j;
            continue;
        }

        i=x-1;
        j=y;
        if(valid(i, j) and closestB[i][j]==closestB[x][y]-1){
            x=i;
            y=j;
            continue;
        }

        i=x-1;
        j=y+1;
        if(valid(i, j) and closestB[i][j]==closestB[x][y]-1){
            x=i;
            y=j;
            continue;
        }

        i=x;
        j=y-1;
        if(valid(i, j) and closestB[i][j]==closestB[x][y]-1){
            x=i;
            y=j;
            continue;
        }

        i=x;
        j=y+1;
        if(valid(i, j) and closestB[i][j]==closestB[x][y]-1){
            x=i;
            y=j;
            continue;
        }

        i=x+1;
        j=y-1;
        if(valid(i, j) and closestB[i][j]==closestB[x][y]-1){
            x=i;
            y=j;
            continue;
        }

        i=x+1;
        j=y;
        if(valid(i, j) and closestB[i][j]==closestB[x][y]-1){
            x=i;
            y=j;
            continue;
        }

        i=x+1;
        j=y+1;
        if(valid(i, j) and closestB[i][j]==closestB[x][y]-1){
            x=i;
            y=j;
            continue;
        }

    }
}

int main()
{
    ll R, Pb, Pr, B, br, bc, r, c, i, j, x, y, m;
    double optGain;
    cin >> H >> W >> R >> Pb >> Pr >> B >> br >> bc;
    vector<string> carte(H);
    vector<vector<set<pair<ll,ll>>>> dependency (H, vector<set<pair<ll,ll>>> (W));
    for(i = 0; i<H; ++i)
        cin >> carte[i];
    vector<vector<ll>> closestB (H, vector<ll> (W, -1)), covered_area (H, vector<ll> (W));
    vector<vector<double>> gain (H, vector<double> (W));
    set<pair<ll,ll>> backbones, routers;
    backbones.emplace(br, bc);

/// greedily placing routers (according to covered_area/cost
    while(true){
/// finding the cost to link backbones
        queue<pair<ll,ll>> Q;
        for(auto& p:backbones){
            closestB[p.first][p.second] = 0;
            Q.emplace(p.first*W + p.second, 0);
        }
        while(!Q.empty()){
            x=Q.front().first/W;
            y=Q.front().first%W;
            m=Q.front().second+1;
            Q.pop();
            i=x+1;
            j=y-1;
            if(valid(i, j) and closestB[i][j]==-1){
                closestB[i][j]=m;
                Q.emplace(i*W+j,m);
            }

            i=x+1;
            j=y;
            if(valid(i, j) and closestB[i][j]==-1){
                closestB[i][j]=m;
                Q.emplace(i*W+j,m);
            }

            i=x+1;
            j=y+1;
            if(valid(i, j) and closestB[i][j]==-1){
                closestB[i][j]=m;
                Q.emplace(i*W+j,m);
            }

            i=x;
            j=y-1;
            if(valid(i, j) and closestB[i][j]==-1){
                closestB[i][j]=m;
                Q.emplace(i*W+j,m);
            }

            i=x;
            j=y+1;
            if(valid(i, j) and closestB[i][j]==-1){
                closestB[i][j]=m;
                Q.emplace(i*W+j,m);
            }

            i=x-1;
            j=y-1;
            if(valid(i, j) and closestB[i][j]==-1){
                closestB[i][j]=m;
                Q.emplace(i*W+j,m);
            }

            i=x-1;
            j=y;
            if(valid(i, j) and closestB[i][j]==-1){
                closestB[i][j]=m;
                Q.emplace(i*W+j,m);
            }

            i=x-1;
            j=y+1;
            if(valid(i, j) and closestB[i][j]==-1){
                closestB[i][j]=m;
                Q.emplace(i*W+j,m);
            }
        }

/// finding the maximum gain
        optGain = 0;
        for(ll i = 0; i<H; ++i) for(ll j = 0; j<W; ++j) {
            //covered_area[i][j] = calc_coverage(carte, dependency, i, j);
            gain[i][j] = covered_area[i][j]/(double)(closestB[i][j]*Pb+Pr);
            if(gain[i][j] > optGain and closestB[i][j]*Pb+Pr<=B){
                r = i; c = j; optGain = gain[i][j];
            }
        }
        if(optGain!=0){
            B -= closestB[r][c]*Pb+Pr;
            placeRouter(closestB, backbones, dependency, r, c);
            routers.emplace(r,c);
        }
        else
            break;
    }
/// get a better solution by converging
    ///todo
/// output
    return 0;
}

