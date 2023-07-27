#include <iostream>
#include <string>
#include <vector>

#include "account_details.cpp"
#include "customer_details.cpp"

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

class Loan {
   public:
    string loan_type;
    float interest;

    float select_loan() {
        if (loan_type == "Home") {
            interest = 8;
        } else if (loan_type == "Car") {
            interest = 7;
        } else if (loan_type == "Personal") {
            interest = 9;
        } else if (loan_type == "Business") {
            interest = 11;
        }

        return interest;
    }
};
