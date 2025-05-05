

#include<bits/stdc++.h>
using namespace std;

pair<string,int> minMatCal(vector<int>& arr,vector<vector<pair<string,int>>> &memo, int i,int j ){


    if(i == j)
    {
string temp(1, 'A' + i);
        return {temp,0};
    }
    if(memo[i][j].second!= -1)
        return memo[i][j];

    int res = INT_MAX;
    string str;
    for(int k =i+1;k<=j;k++){
            pair<string,int> left = minMatCal(arr,memo,i,k-1);
            pair<string,int> right =  minMatCal(arr,memo,k,j);
        int cur = left.second + right.second+ arr[i]*arr[k]*arr[j];

        if(res>cur){
            res = cur;
            str = "(" +left.first + right.first+")";
        }
    }
    return memo[i][j] = {str,res};


}

int main()
{

    int n;
    vector<int> arr;
    cin >> n;
    for(int i =0; i<n; i++)
        {
            int x;cin >> x;
        arr.push_back(x);
        }
    vector<vector<pair<string, int>>> memo(n, vector<pair<string, int>>(n, {"", -1}));
    cout << minMatCal(arr,memo,0,n-1).first;


    return 0;
}
