#include <iostream>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;
const double eps=pow(10,-20);

ll calc_coverage(vector<string>& carte, vector<vector<set<pair<ll,ll>>>>& dependency, ll x,ll y){
    ll res=0;
    ll minl,maxr,i,j;
    if(carte[y][x]=='.'){
        if(dependency[y][x].empty()){
            ++res;
        }
    } else if(carte[y][x]=='#'){
        return 0;
    }
    //upper
    j=y;
    minl=0;
    maxr=W;
    while(j>0){
        --j;
        if(carte[j][i]=='.'){
            if(dependency[j][i].empty()){
                ++res;
            }
        } else if(carte[j][i]=='#'){
            break;
        }
        //upper-left
        i=x;
        while(i>0 and i>minl){
            i--;
            if(carte[j][i]=='.'){
                if(dependency[j][i].empty()){
                    ++res;
                }
            } else if(carte[j][i]=='#'){
                minl=i;
                break;
            }
        }
        //upper-right
        i=x;
        while(i<W and i<maxr){
            i--;
            if(carte[j][i]=='.'){
                if(dependency[j][i].empty()){
                    ++res;
                }
            } else if(carte[j][i]=='#'){
                maxr=i;
                break;
            }
        }
    }
    //lower
    j=y;
    minl=0;
    maxr=W;
    while(j<H){
        ++j;
        if(carte[j][i]=='.'){
            if(dependency[j][i].empty()){
                ++res;
            }
        } else if(carte[j][i]=='#'){
            break;
        }
        //lower-left
        i=x;
        while(i>0 and i>minl){
            i--;
            if(carte[j][i]=='.'){
                if(dependency[j][i].empty()){
                    ++res;
                }
            } else if(carte[j][i]=='#'){
                minl=i;
                break;
            }
        }
        //lower-right
        i=x;
        while(i<W and i<maxr){
            i--;
            if(carte[j][i]=='.'){
                if(dependency[j][i].empty()){
                    ++res;
                }
            } else if(carte[j][i]=='#'){
                maxr=i;
                break;
            }
        }
    }
    return res;
}

void update_dependency(vector<string>& carte, vector<vector<set<pair<ll,ll>>>>& dependency, ll x,ll y){
    ll minl,maxr,i,j;
    if(carte[y][x]=='.'){
        dependency[y][x].onplace(x,y);
    } else if(carte[y][x]=='#'){
        return;
    }
    //upper
    j=y;
    minl=0;
    maxr=W;
    while(j>0){
        --j;
        if(carte[j][i]=='.'){
            dependency[y][x].onplace(x,y);
        } else if(carte[j][i]=='#'){
            break;
        }
        //upper-left
        i=x;
        while(i>0 and i>minl){
            i--;
            if(carte[j][i]=='.'){
                dependency[y][x].onplace(x,y);
            } else if(carte[j][i]=='#'){
                minl=i;
                break;
            }
        }
        //upper-right
        i=x;
        while(i<W and i<maxr){
            i--;
            if(carte[j][i]=='.'){
                dependency[y][x].onplace(x,y);
            } else if(carte[j][i]=='#'){
                maxr=i;
                break;
            }
        }
    }
    //lower
    j=y;
    minl=0;
    maxr=W;
    while(j<H){
        ++j;
        if(carte[j][i]=='.'){
            dependency[y][x].onplace(x,y);
        } else if(carte[j][i]=='#'){
            break;
        }
        //lower-left
        i=x;
        while(i>0 and i>minl){
            i--;
            if(carte[j][i]=='.'){
                dependency[y][x].onplace(x,y);
            } else if(carte[j][i]=='#'){
                minl=i;
                break;
            }
        }
        //lower-right
        i=x;
        while(i<W and i<maxr){
            i--;
            if(carte[j][i]=='.'){
                dependency[y][x].onplace(x,y);
            } else if(carte[j][i]=='#'){
                maxr=i;
                break;
            }
        }
    }
    return;
}

void main(){}
