
#include <iostream>
#include <string>
#include <vector>

// #include "account_type.cpp"
#include "loan_type.cpp"
#include "timestamps.cpp"
// #include "transactions.cpp"

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
    string card_no;
    string cvv;
    string expiry_date;
    string date_of_opening;

   public:
    string generate_ac_no() {
        return generate_string(12);
    }
    string generate_atm_id() {
        return generate_string(16);
    }
    string generate_atm_cvv() {
        return generate_string(3);
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

        line10:
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
        cout << endl
             << "Need an atm card?" << endl
             << "1. Yes             2. No " << endl;
        ;
        int choice;
        cin >> choice;
        if (choice == 1) {
            string atm_id = generate_atm_id();
            string atm_cvv = generate_atm_cvv();
            cout << "ATM card no. : " << atm_id << endl
                 << "CVV : " << atm_cvv << endl;

        } else {
            cout << "No atm card required" << endl;
        }
        date_of_opening = getCurrentDate();
        cout << endl
             << endl
             << "Account opened @ : " << date_of_opening << endl;
    }
};

// class Atm {
//    public:
//     string card_no;
//     int cvv;
//     string expiry_date;

// };

// unordered_map<string, Transactions> account_records;