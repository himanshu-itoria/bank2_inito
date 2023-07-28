#include <iostream>
#include <string>
#include <vector>

#include "customer_details.cpp"

// 1#include "account_details.cpp"
#include "transactions.cpp"

using namespace std;

int main() {
    cout << "              ___________Inito Services___________" << endl
         << endl
         << endl;

    cout << "Type of bank account you want to open: " << endl
         << endl
         << "1. Savings" << endl
         << "2. Current" << endl
         //<< "3. Loan " << endl
         << endl;
    int i;
    cin >> i;
    Customer_details cd;
    cd.take_details();

    Transactions acd;
    acd.open_account(i);

    account_records[acd.ac_no] = acd;
    personal_details[acd.ac_no] = cd;
    cout << cd.name << endl
         << cd.email_id << endl
         << cd.phone_no << cd.date_of_birth << endl;
    cout << endl;
    // Account_details ab = account_records[acd.ac_no];
    cout << acd.ac_no << endl
         << acd.balance << endl
         << acd.nrv_value << endl
         << acd.Savings;

    cout << "Carry transactions: " << endl;
    transactions_menu(acd);
    // cout << account_records[acd.ac_no] << endl;
    return 0;
}
