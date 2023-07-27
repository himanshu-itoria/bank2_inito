#include <iostream>
#include <string>
#include <vector>

#include "account_details.cpp"

using namespace std;

int main() {
    cout << "              ___________Inito Services___________" << endl
         << endl
         << endl;

    cout << "Type of bank account you want to open: " << endl
         << endl
         << "1. Savings" << endl
         << "2. Current" << endl
         << "3. Loan " << endl
         << endl;
    int i;
    cin >> i;
    Account_details acd;
    acd.open_account(i);

    account_records[acd.ac_no] = acd;
    cout << endl;
    // Account_details ab = account_records[acd.ac_no];
    cout << acd.ac_no << endl
         << acd.balance << endl
         << acd.nrv_value << endl
         << acd.Savings;
    // cout << account_records[acd.ac_no] << endl;
    return 0;
}
