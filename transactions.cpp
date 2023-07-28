#include <iostream>
#include <string>
#include <vector>

#include "account_details.cpp"
// #include "account_type.cpp"
using namespace std;

class Transactions : public Account_details {
   public:
    string sender_ac, receiver, type_of_transaction, transaction_time_stamp, date_transaction;

    bool transact_possible(float balance, float amount, string ac) {
        return balance >= amount;
    }

    void credit(string ac, float amount, float balance) {
        balance += amount;
    }

    void debit(string ac, float amount, float balance) {
        if (transact_possible(balance, amount, ac)) {
            balance -= amount;
        }
    }
    void send_receive(string ac_sender, string ac_receiver, float bal, float amount) {
        // float bal, amount;
        //  if(account_records.find(ac_receiver)==account_records.end())
        //  {
        //      cout << "Invalid credentials" << endl;
        //      return ;
        //  }

        if (transact_possible(bal, amount, ac_sender)) {
            debit(ac_sender, amount, bal);
            credit(ac_receiver, amount, bal);
        } else {
            cout << "Not sufficient balance" << endl;
        }
    }

    void interest_credit(string ac_no, float amount, float interest_rate, float balance) {
        float age = calculateAge(date_of_opening);
        credit(ac_no, amount * (1 + (age * (interest_rate)*0.01)), balance);
    }

    void card_debit(string card_id, float amount, float balance, string ac_no) {
        if (transact_possible(balance, amount, ac_no)) {
            debit(ac_no, amount, balance);
        }
    }
    void nrv_deduction(float bal, string ac_no, int ac_type) {
        switch (ac_type) {
            case 1:
                if (bal < 10000) {
                    cout << "NRV 10,000 has to be maintained,1000 deducted " << endl;
                    bal -= 1000;
                }
                break;

            case 2:
                if (bal < 50000) {
                    cout << " NRV 50,000 has to maintained, 5000 deducted " << endl;
                    bal -= 5000;
                }
                cout << "Invalid entry" << endl;
                break;
        }
    }
    void atm_withdraw(string card_no, string cvv, float amount1) {
        // float amount1;
        // cin >> amount1;
        debit(ac_no, amount1, balance);
    }
};

void transactions_menu(Transactions td) {
line1:
    cout << "____________________Menu___________________" << endl
         << endl
         << endl
         << endl
         << endl;

    cout << "   Choose Transactions   " << endl
         << endl
         << endl
         << endl
         << endl;
    cout << "1. Withdraw" << endl
         << "2. Deposit" << endl
         << "3. Send to" << endl
         << "4.atm withdrawal" << endl
         << "5. Open a loan account" << endl
         << "6. Pay emis" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "enter amount:" << endl;
        float amount;
        cin >> amount;
        td.debit(td.ac_no, td.balance, amount);

        vector<Transactions> record;
        td.transaction_time_stamp = getCurrentTimestamp();
        td.date_transaction = getCurrentDate();
        record.push_back(td);
        transactions_records[td.ac_no] = record;

    } else if (choice == 2) {
        cout << "enter amount:" << endl;
        float amount;
        cin >> amount;
        td.credit(td.ac_no, amount, td.balance);
        vector<Transactions> record;
        td.transaction_time_stamp = getCurrentTimestamp();
        td.date_transaction = getCurrentDate();
        record.push_back(td);
        transactions_records[td.ac_no] = record;

    } else if (choice == 3) {
        cout << "enter amount: & receiver_account_no." << endl;
        string receiver_ac_no1;
        cin >> receiver_ac_no1;
        float amount;
        cin >> amount;
        td.send_receive(td.ac_no, receiver_ac_no1, amount, td.balance);
        vector<Transactions> record;
        td.transaction_time_stamp = getCurrentTimestamp();
        td.date_transaction = getCurrentDate();
        record.push_back(td);
        transactions_records[td.ac_no] = record;

    } else if (choice == 4) {
        cout << "enter amount & card_no & vv:" << endl;
        string card_no1, cvv1;
        float amount;
        cin >> card_no1;
        cin >> cvv1;
        cin >> amount;
        td.atm_withdraw(card_no1, cvv1, amount);
        vector<Transactions> record;
        td.transaction_time_stamp = getCurrentTimestamp();
        td.date_transaction = getCurrentDate();
        record.push_back(td);
        transactions_records[td.ac_no] = record;
    } else if (choice == 5) {
        LoanGrant lg;

        if (td.Current || td.Savings) {
            string abc = td.generate_ac_no();
            lg.open_loan_account(abc);
            vector<LoanGrant> vc;
            vc.push_back(lg);
            loanRecords[abc] = vc;
        }

    } else if (choice == 6) {
        cout << "Loan account no. : " << endl;
        string abd;
        cin >> abd;
        LoanGrant ab;
        cout << "Amount paying : " << endl;
        float amt;
        cin >> amt;
        ab.emi_paying(amt, abd);
        vector<LoanGrant> dc;
        dc.push_back(ab);
        loanRecords[abd] = dc;
    }
    goto line1;
}

unordered_map<string, vector<Transactions> > transactions_records;

unordered_map<string, Transactions> account_records;

// switch (choice) {
//     case 1:
//         float amount1 ;
//         cin >>amount1;
//         td.debit(td.ac_no,td.balance,amount1);
//         break;

//     case 2:
//         float amount2;
//         cin >>amount2;
//         td.credit(td.ac_no,amount2,td.balance);
//         break;
//     case 3:
//         string receiver_ac_no1 ;
//         cin >> receiver_ac_no1;
//         float amount3;
//         cin >> amount3;
//         td.send_receive(td.ac_no, receiver_ac_no1,amount3,td.balance);
//         break;
//     case 4:
//        string card_no1, cvv1;
//        float amount4;
//        cin >> card_no1;
//        cin >> cvv1;
//        cin >> amount4;
//        td.atm_withdraw(card_no1,cvv1,amount4);
//         break;

//     default:
//         break;
// } =>> variable bypass error