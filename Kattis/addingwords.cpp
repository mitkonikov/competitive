#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, int> memo;

    string command;
    while (cin >> command) {
        if (command == "clear") memo.clear();

        if (command == "def") {
            string var;
            int value;
            cin >> var >> value;

            memo[var] = value;
        } else if (command == "calc") {
            int result = 0;
            bool known = true;
            string calculation = "";
            int lastOperator = -1;

            auto calc = [&](string var) {
                auto it = memo.find(var);
                if (it != memo.end()) {
                    if (lastOperator == -1) {
                        result = it->second;
                    } else if (lastOperator == 1) {
                        result = result + it->second;
                    } else if (lastOperator == 2) {
                        result = result - it->second;
                    }
                } else {
                    known = false;
                }
            };

            auto setLastOperator = [&](string op) {
                if (op == "+") lastOperator = 1;
                else lastOperator = 2;
            };

            while (true) {
                string var, operation;
                cin >> var >> operation;

                if (operation == "=") {
                    calc(var);
                    calculation += var;

                    string strResult = "unknown";
                    for (auto it = memo.begin(); it != memo.end(); it++) if (it->second == result) strResult = it->first;

                    if (known) {
                        cout << calculation << " = " << strResult << endl;
                    } else {
                        cout << calculation << " = unknown" << endl;
                    }

                    break;
                } else if (operation == "-") {
                    calculation += var + " " + operation + " ";
                    if (known) calc(var);
                    setLastOperator(operation);
                } else if (operation == "+") {
                    calculation += var + " " + operation + " ";
                    if (known) calc(var);
                    setLastOperator(operation);
                }
            }
        }
    }
    return 0;
}