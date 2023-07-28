#include <iostream>
#include <string>
#include <vector>

// #include "account_details.cpp"
// #include "customer_details.cpp"
#include "timestamps.cpp"

using namespace std;

// class Account_type {
//    public:
//     bool Savings;
//     bool Current;
//     bool Loan;

//     string account_opening(int i)
//     {

//     }
// };

class LoanGrant {
   public:
    string loan_type, loan_granted_on, loan_ac_no, ;
    float interest, max_emi_payable, std_emi, loan_grantable, mature_loan_payable, current_loan_total, aged, years_remaining, bal;

    void select_loan(float balance) {
        if (loan_type == "Home") {
            interest = 8;
        } else if (loan_type == "Car") {
            interest = 7;
        } else if (loan_type == "Personal") {
            interest = 9;
        } else if (loan_type == "Business") {
            interest = 11;
        }

        loan_granted(balance);
    }

    void loan_granted(float balance) {
        loan_granted_on = getCurrentDate();
        loan_grantable = 0.4 * balance;
        mature_loan_payable = loan_grantable * (1 + (0.01 * interest * 12));
        current_loan_total = loan_grantable;

        // max_emi_payable = loan_grantable * (1 + (0.01 * interest)) / 10;
        // min_emi = mature_loan_payable / 144;
    }

    void current_loan_amount() {
        aged = calculateAge(loan_granted_on);
        years_remaining = 12 - aged;
        current_loan_total = loan_grantable * (1 + (aged * 0.01 * interest));
        max_emi_payable = current_loan_total * (1 + ((aged + (10 / 12)) * interest * 0.01)) / 10;
    }

    void emi_paying(float amount, string accountNo) {
        if (loanRecords.find(accountNo) != loanRecords.end()) {
            current_loan_amount();
            if (bal >= amount && amount < max_emi_payable) {
                current_loan_total -= amount;

            } else {
                cout << "Insufficient funds, put some balance " << endl;
                float amt;
                cin >> amt;
                deposit();
            }
        }
    }
    void deposit() {
        float amount;
        cout << "enter amount" << endl;
        cin >> amount;
        bal += amount;
    }
    void open_loan_account(string abc) {
        loan_ac_no = abc;
        float dc;
        cin >> dc;
        bal = dc;
        // loat balance;

        deposit();
        select_loan(bal);
    }
};
unordered_map<string, vector<LoanGrant> > loanRecords;