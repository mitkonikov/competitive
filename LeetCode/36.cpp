#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto stoi = [](char c) {
            return (int)(c - '0');
        };
        for (int i = 0; i < 9; i++) {
            vector<bool> visited(9);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int d = stoi(board[i][j]);
                    if (visited[d]) return false;
                    visited[d] = true;
                }
            }
        }
        for (int j = 0; j < 9; j++) {
            vector<bool> visited(9);
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    int d = stoi(board[i][j]);
                    if (visited[d]) return false;
                    visited[d] = true;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                vector<bool> visited(9);
                for (int k = 0; k < 9; k++) {
                    int x = i * 3 + k % 3;
                    int y = j * 3 + k / 3;
                    if (board[x][y] != '.') {
                        int d = stoi(board[x][y]);
                        if (visited[d]) return false;
                        visited[d] = true;
                    }
                }
            }
        }
        return true;
    }
};