#include <iostream>
#include <vector>
using namespace std;

int N;
int main(){
    vector<pair <int, int> > v;
    int start, end;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> start >> end;
        v.push_back(make_pair(end,start));
    }

    sort(v.begin(),v.end());

    int earliest = 0, selected = 0;
    for(int i=0; i<v.size(); i++){
        int meetingBegin = v[i].second, meetingEnd = v[i].first;

        if(earliest <= meetingBegin){
            earliest = meetingEnd;
            ++selected;
        }
    }

    cout << selected << '\n';
}