#include <iostream>
#include <string>
#include <vector>

#include "account_details.cpp"

using namespace std;

class Customer_details {
   public:
    int id;
    string ac;
    std::string name;
    std::string email_id;
    std::string phone_no;
    std::string date_of_birth;
};

unordered_map<string, Customer_details> personal_details;