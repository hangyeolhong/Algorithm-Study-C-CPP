#include <fstream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

vector<vector<int> > CHUNK_COMBO_OPTIONS;
int main(){
    for (auto idx = 0; idx < pow(6, 8); idx++)
    {
        vector<int> vec;
        int j = idx;
        for (auto i = 0; i < 8; ++i)
        {
            auto tmp = j % 6;
            vec.push_back(tmp);
            // cout << tmp << " ";
            j /= 6;
        }
        CHUNK_COMBO_OPTIONS.push_back(vec);
        
    }
    // cout << CHUNK_COMBO_OPTIONS.size();
    
    for(int i=0; i<8; i++)
        cout << CHUNK_COMBO_OPTIONS[66][i] << " ";
}