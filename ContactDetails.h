#ifndef CONTACTDETAILS_H
#define CONTACTDETAILS_H
#include <iostream>
#include <string>

using namespace std;

class Details{
    string email;
    string phoneNumber;
    string address;
public:
    Details():email("Null"),phoneNumber("-1"),address("Null"){}
    Details(string eml,string phoneNo,string addrs):email(eml),phoneNumber(phoneNo),address(addrs){}
    friend ostream& operator<<(ostream&os ,const Details & obj){
        os<<obj.email<<" - "<<obj.phoneNumber<<" - "<<obj.address<<endl;
        return os;
    }
};
#endif