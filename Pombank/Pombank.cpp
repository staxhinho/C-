#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void SaveToFile(float &accountbalance) {
    ofstream outFile("Pombank/Pombank.txt");

    if (outFile.is_open()) {
        outFile << accountbalance << endl;
        
        outFile.close();
        cout << "Your account balance has been saved!" << endl;
    } else {
        cout << "Error opening file!" << endl;
    }
}

void LoadFromFile(float &accountbalance) {
    ifstream inFile("Pombank/Pombank.txt");

    if (inFile.is_open()) {
        inFile >> accountbalance;
    }
}

int main() {
    float accountbalance = 0;
    string whattodo;
    LoadFromFile(accountbalance);

    cout << "Pombank by staxhinho" << endl;

    while (true) {
        cout << "Select what to do: Deposit, Withdraw or Check Balance" << endl;
        cout << "(depo/draw/blnc)" << endl;
        cin >> whattodo;

        if (whattodo == "depo") {
            cout << "Deposit money: ";
            float deposit;
            cin >> deposit;
            accountbalance += deposit;
        } else if (whattodo == "draw") {
            cout << "Draw money: ";
            float draw;
            cin >> draw;
            if (draw <= accountbalance) {
                accountbalance -= draw;
            } else {
                cout << "Insufficient balance!" << endl;
            }
        } else if (whattodo == "blnc") {
            cout << "Account balance: " << accountbalance << "EUR" << endl;
        } else {
            cout << "Wrong option. Please select 'depo', 'draw' or 'blnc'." << endl;
            continue;
        }
        
        char continueAction;
        cout << "Do you want to perform another action? (y/n): ";
        cin >> continueAction;
        if (continueAction != 'y' && continueAction != 'Y') {
            SaveToFile(accountbalance);
            break;
        }
    }

    system("pause");
    return 0;
}