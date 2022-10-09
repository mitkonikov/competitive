#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
 
int N, M, K;
void pushL(vector<string>& arr) {
    for(int i = 0; i < N; ++i){
        int idx = 0;
        for(int j = 0; j < M; ++j) {
            if(arr[i][j] != '.') {arr[i][idx] = arr[i][j];++idx;}
            
        }
        for(int j = idx; j < M; ++j) {
            arr[i][j] = '.';
        }
    }
}
 
void pushR(vector<string>& arr) {
    for(int i = 0; i < N; ++i){
        int idx = M - 1;
        for(int j = M - 1; j >= 0; --j) {
            if(arr[i][j] != '.') {arr[i][idx] = arr[i][j];             --idx;}
 
        }
        for(int j = 0; j <= idx; ++j) {
            arr[i][j] = '.';
        }
    }
}
 
void pushU(vector<string>& arr) {
    for(int j = 0; j < M; ++j) {
        int idx = 0;
        for(int i = 0; i < N; ++i){
            if(arr[i][j] != '.') {arr[idx][j] = arr[i][j]; ++idx;}
            
        }
        for(int i = idx; i < N; ++i) {
            arr[i][j] = '.';
        }
    }
}
 
void pushD(vector<string>& arr) {
    for(int j = 0; j < M; ++j) {
        int idx = N - 1;
        for(int i = N - 1; i >= 0; --i){
            if(arr[i][j] != '.') {arr[idx][j] = arr[i][j]; --idx;}
            
        }
        for(int i = 0; i <= idx; ++i) {
            arr[i][j] = '.';
        }
    }
}
int main(){
    cin >> N >> M >> K;
    vector<string> arr(N);
 
    cin.ignore();
    string s;
    getline(cin, s);
 
    for(int i = 0; i < N; ++i){
        cin >> arr[i];
    }
 
    for(auto& ch: s) {
        switch(ch) {
            case 'D': pushD(arr); break;
            case 'U': pushU(arr); break;
            case 'L': pushL(arr); break;
            case 'R': pushR(arr); break;
        }
    }
 
    for(int i = 0; i < N; ++i){
        cout << arr[i] << '\n' ;
    }
 
    return 0;
}