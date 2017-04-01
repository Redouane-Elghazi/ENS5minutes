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


ll calc_coverage(vector<string>& carte, vector<vector<set<pair<ll,ll>>>>& dependency, ll x, ll y){
    ll res=0;
    ll minl,maxr,i,j;
    if(carte[x][y]=='.'){
        if(dependency[x][y].empty()){
            ++res;
        }
    } else if(carte[x][y]=='#'){
        return 0;
    }
    //upper
    j=y;
    i=x;
    minl=0;
    maxr=W-1;
    while(i>0){
        --i;
        if(carte[i][j]=='.'){
            if(dependency[i][j].empty()){
                ++res;
            }
        } else if(carte[i][j]=='#'){
            break;
        }
        //upper-left
        j=y;
        while(j>0 and j>minl){
            --j;
            if(carte[i][j]=='.'){
                if(dependency[i][j].empty()){
                    ++res;
                }
            } else if(carte[i][j]=='#'){
                minl=j;
                break;
            }
        }
        //upper-right
        j=y;
        while(j<W-1 and j<maxr){
            ++j;
            if(carte[i][j]=='.'){
                if(dependency[i][j].empty()){
                    ++res;
                }
            } else if(carte[i][j]=='#'){
                maxr=j;
                break;
            }
        }
    }
    //lower
    j=y;
    i=x;
    minl=0;
    maxr=W-1;
    while(i<H-1){
        ++i;
        if(carte[i][j]=='.'){
            if(dependency[i][j].empty()){
                ++res;
            }
        } else if(carte[i][j]=='#'){
            break;
        }
        //lower-left
        j=y;
        while(j>0 and j>minl){
            --j;
            if(carte[i][j]=='.'){
                if(dependency[i][j].empty()){
                    ++res;
                }
            } else if(carte[i][j]=='#'){
                minl=j;
                break;
            }
        }
        //lower-right
        j=y;
        while(j<W-1 and j<maxr){
            ++j;
            if(carte[i][j]=='.'){
                if(dependency[i][j].empty()){
                    ++res;
                }
            } else if(carte[i][j]=='#'){
                maxr=j;
                break;
            }
        }
    }
    return res;
}

void update_dependency(vector<string>& carte, vector<vector<set<pair<ll,ll>>>>& dependency, ll x,ll y){
    ll res=0;
    ll minl,maxr,i,j;
    if(carte[x][y]=='.'){
        dependency[y][x].emplace(x,y);
    } else if(carte[x][y]=='#'){
        return;
    }
    //upper
    j=y;
    i=x;
    minl=0;
    maxr=W-1;
    while(i>0){
        --i;
        if(carte[i][j]=='.'){
            dependency[i][j].emplace(x,y);
        } else if(carte[i][j]=='#'){
            break;
        }
        //upper-left
        j=y;
        while(j>0 and j>minl){
            --j;
            if(carte[i][j]=='.'){
                dependency[i][j].emplace(x,y);
            } else if(carte[i][j]=='#'){
                minl=j;
                break;
            }
        }
        //upper-right
        j=y;
        while(j<W-1 and j<maxr){
            ++j;
            if(carte[i][j]=='.'){
                dependency[i][j].emplace(x,y);
            } else if(carte[i][j]=='#'){
                maxr=j;
                break;
            }
        }
    }
    //lower
    j=y;
    i=x;
    minl=0;
    maxr=W-1;
    while(i<H-1){
        ++i;
        if(carte[i][j]=='.'){
            dependency[i][j].emplace(x,y);
        } else if(carte[i][j]=='#'){
            break;
        }
        //lower-left
        j=y;
        while(j>0 and j>minl){
            --j;
            if(carte[i][j]=='.'){
                dependency[i][j].emplace(x,y);
            } else if(carte[i][j]=='#'){
                minl=j;
                break;
            }
        }
        //lower-right
        j=y;
        while(j<W-1 and j<maxr){
            ++j;
            if(carte[i][j]=='.'){
                dependency[i][j].emplace(x,y);
            } else if(carte[i][j]=='#'){
                maxr=j;
                break;
            }
        }
    }
    return;
}

void placeRouter(vector<string>& carte, vector<vector<ll>>& closestB, set<pair<ll,ll>>& backbones, vector<vector<set<pair<ll,ll>>>>& dependency, ll r, ll c){
    update_dependency(carte, dependency, r, c);
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
    vector<vector<ll>> covered_area (H, vector<ll> (W));
    vector<vector<double>> gain (H, vector<double> (W));
    set<pair<ll,ll>> backbones, routers;
    backbones.emplace(br, bc);

/// greedily placing routers (according to covered_area/cost
    while(true){
/// finding the cost to link backbones
        vector<vector<ll>> closestB (H, vector<ll> (W, -1));
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
            covered_area[i][j] = calc_coverage(carte, dependency, i, j);
            gain[i][j] = covered_area[i][j]/(double)(closestB[i][j]*Pb+Pr);
            if(gain[i][j] > optGain and closestB[i][j]*Pb+Pr<=B){
                r = i; c = j; optGain = gain[i][j];
            }
        }
        if(optGain!=0){
            B -= closestB[r][c]*Pb+Pr;
            placeRouter(carte, closestB, backbones, dependency, r, c);
            routers.emplace(r,c);
        }
        else
            break;
    }
/// get a better solution by converging
    ///todo
/// output
    vector<vector<ll>> backcarte (H, vector<ll> (W, -1));
    vector<pair<ll,ll> backout;
    queue<pair<ll,ll>> Q;
    Q.emplace(br,bc)
    for(auto& p:backbones){
        backcarte[p.first][p.second] = 0;
    }
    while(!Q.empty()){
        x=Q.front().first;
        y=Q.front().first;
        Q.pop();
        i=x-1;
        j=y-1;
        if(valid(i, j) and backcarte[i][j]==0){
            backcarte[i][j]=-1;
            Q.emplace(i,j);
            backout.emplace_back(i,j);
        }

        i=x-1;
        j=y;
        if(valid(i, j) and backcarte[i][j]==0){
            backcarte[i][j]=-1;
            Q.emplace(i,j);
            backout.emplace_back(i,j);
        }

        i=x-1;
        j=y+1;
        if(valid(i, j) and backcarte[i][j]==0){
            backcarte[i][j]=-1;
            Q.emplace(i,j);
            backout.emplace_back(i,j);
        }

        i=x;
        j=y-1;
        if(valid(i, j) and backcarte[i][j]==0){
            backcarte[i][j]=-1;
            Q.emplace(i,j);
            backout.emplace_back(i,j);
        }

        i=x;
        j=y+1;
        if(valid(i, j) and backcarte[i][j]==0){
            backcarte[i][j]=-1;
            Q.emplace(i,j);
            backout.emplace_back(i,j);
        }

        i=x+1;
        j=y-1;
        if(valid(i, j) and backcarte[i][j]==0){
            backcarte[i][j]=-1;
            Q.emplace(i,j);
            backout.emplace_back(i,j);
        }

        i=x+1;
        j=y;
        if(valid(i, j) and backcarte[i][j]==0){
            backcarte[i][j]=-1;
            Q.emplace(i,j);
            backout.emplace_back(i,j);
        }

        i=x+1;
        j=y+1;
        if(valid(i, j) and backcarte[i][j]==0){
            backcarte[i][j]=-1;
            Q.emplace(i,j);
            backout.emplace_back(i,j);
        }

    }
    cout << backout.size() << endl;
    for(auto& p:backout)
        cout << p.first << " " << p.second << endl;
    cout << routers.size() << endl;
    for(auto& p:routers)
        cout << p.first << " " << p.second << endl;
    return 0;
}
