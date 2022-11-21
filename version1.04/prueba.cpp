
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <pair<string,string>> vec={
        {"Manuel","Spiderman"}
    };//Initializing a vector of pairs
    
    vec.push_back(make_pair("Juan","Toy Story"));//Adding a pair to the vector 
    cout<<"Vector contains pairs: ";
    for(int i =0;i<vec.size();i++)
    {
        cout<<"("<<vec[i].first<<","<<vec[i].second<<")"<<" ";
    }
    cout<<endl;
    
    return 0;
}