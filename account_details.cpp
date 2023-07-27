#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include "transactions.cpp"

using namespace std;

string generate_string(int len) {
    string id;
    for (int i = 0; i < len; i++) {
        id += to_string(rand() % 10);
    }
    return id;
}

class Account_details {
   public:
    string ac_no;
    float nrv_value;
    float balance;
    bool Savings;
    bool Current;
    bool Loan;

   public:
    string generate_ac_no() {
        return generate_string(12);
    }

    void open_account(int i) {
        Account_details acd;

        if (i == 1) {
        line1:
            Savings = 1;
            cout << "Deposit min 10,000 to open : " << endl;
            float dep;
            cin >> dep;
            if (dep >= 10000) {
                cout << " Savings account opened!" << endl;
                cout << "Account no is : " << endl;
                ac_no = generate_ac_no();
                balance = dep;
                cout << ac_no << endl;
            } else {
                cout << "not enough amount, enter the amount again " << endl;
                goto line1;
            }
            cout << "Deposit NRV " << endl;
            float it;
            cin >> it;
            nrv_value = it;
        } else if (i == 2) {
        line0:

            Current = 1;
            cout << "Deposit min 100,000 to open : " << endl;
            float dep;
            cin >> dep;
            if (dep >= 100000) {
                cout << " Current account opened!" << endl;
                cout << "Account no is : " << endl;
                ac_no = generate_ac_no();
                balance = dep;
                cout << ac_no << endl;
            } else {
                cout << "not enough amount , enter the amount again " << endl;
                cout << "go back to main menu: press 1" << endl;
                // goto linei;
                goto line0;
            }
            cout << "Deposit NRV " << endl;
            float it;
            cin >> it;
            nrv_value = it;
        }
    }
};

class atm : public Account_details {
   public:
    string card_no;
    int cvv;
    string expiry_date;
};

unordered_map<string, Account_details> account_records;