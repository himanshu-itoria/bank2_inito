#include <iostream>
#include <string>
#include <vector>

// #include "account_details.cpp"

using namespace std;

class Customer_details {
   public:
    int id;
    string ac;
    std::string name;
    std::string email_id;
    std::string phone_no;
    std::string date_of_birth;

    void take_details() {
        cout << "Take name : ";
        cin >> name;
        cout << "Take email_id : ";
        cin >> email_id;
        cout << "Take Phone_no. : ";
        cin >> phone_no;
        cout << "Take date_of_birth " << endl;
        string yyyy, mm, dd;
        cin >> yyyy >> mm >> dd;
        date_of_birth += yyyy;
        date_of_birth += "-";
        date_of_birth += mm;
        date_of_birth += "-";
        date_of_birth += dd;
    }
};

unordered_map<string, Customer_details> personal_details;