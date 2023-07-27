#include <iostream>
#include <string>
#include <vector>

// #include "account_details.cpp"
using namespace std;

class Transactions /*:public Account_details*/ {
   public:
    string sender_ac, receiver_ac, type_of_transaction, transaction_time_stamp;

    bool transact_possible(float balance, float amount, string ac) {
        return balance >= amount;
    }

    void credit(string ac, float amount, float balance) {
        balance += amount;
    }

    void debit(string ac, float amount, float balance) {
        balance -= amount;
    }
    void send_receive(string ac_sender, string ac_receiver) {
        float bal, amount;
        if (transact_possible(bal, amount, ac_sender)) {
            debit(ac_sender, amount, bal);
            credit(ac_receiver, amount, bal);
        } else {
            cout << "Not sufficient balance" << endl;
        }
    }

    void interest_credit(string ac, float amount, float interest_rate, float balance) {
        credit(ac, amount * (interest_rate)*0.02, balance);
    }

    void card_debit(string card_id, float amount, float balance, string ac_no) {
        if (transact_possible(balance, amount, ac_no)) {
            debit(ac_no, amount, balance);
        }
    }
};

unordered_map<string, vector<Transactions> > transactions_records;
