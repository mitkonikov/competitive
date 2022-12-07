#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> sizes;

struct file {
    ll sum = 0;
    string name;
    vector<file*> files;
    file* parent = nullptr;
    ll size = 0;
    void create(string name, int size = 0) {
        file* new_dir = new file({ size, name });
        new_dir->parent = this;
        files.push_back(new_dir);
    }
    file* moveToDir(string name) {
        for (int i = 0; i < files.size(); i++) {
            if (files[i]->name == name) {
                return files[i];
            }
        }
        return nullptr;
    }
    ll dfs() {
        ll count = 0;
        ll child_size = 0;
        for (int i = 0; i < files.size(); i++) {
            count += files[i]->dfs();
            child_size += files[i]->size;
        }

        size = child_size + sum;
        if (files.size()) sizes.push_back(size);
        return (count + (files.size() > 0 && size <= 100000 ? size : 0));
    }
};

int main() {
    int n;
    cin >> n;
    file* root = new file({ 0, "/" });
    root->parent = root;
    file* current = root;
    bool read_ls = false;
    for (int i = 0; i < n; i++) {
        string what;
        cin >> what;
        if (what == "$") {
            if (read_ls) {
                read_ls = false;
            }

            string command;
            cin >> command;
            if (command == "cd") {
                string where;
                cin >> where;
                if (where == "/") {
                    current = root;
                } else if (where == "..") {
                    current = current->parent;
                } else {
                    current = current->moveToDir(where);
                    assert(current != nullptr);
                }
            } else if (command == "ls") {
                read_ls = true;
            } else {
                cout << "Unknown command at line " << i + 1 << endl;
                return 0;
            }
        } else if (read_ls) {
            if (what == "dir") {
                string name;
                cin >> name;
                current->create(name);
            } else {
                string name;
                cin >> name;
                current->create(name, stoll(what));
            }
        }
    }
    cout << "Count : " << root->dfs() << endl;
    sort(sizes.begin(), sizes.end());
    for (int i = 0; i < sizes.size(); i++) {
        if (70000000 - root->size + sizes[i] >= 30000000) {
            cout << "Delete: " << sizes[i] << endl;
            return 0;
        }
    }
    return 0;
}