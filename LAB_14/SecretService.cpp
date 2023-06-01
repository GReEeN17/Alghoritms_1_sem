#include <iostream>
#include <regex>
using namespace std;

class SecretService{
private:
    vector<string> data;
public:
    void newData(string dataPerson) {
        data = {};
        string temp = {};
        for (int i = 0; i < dataPerson.size(); i++) {
            if (dataPerson[i] == ' ') {
                data.push_back(temp);
                temp = {};
            } else {
                temp.push_back(dataPerson[i]);
            }
        }
        data.push_back(temp);
    }

    bool checkCorrect() {
        if (data.size() != 8) return false;
        regex fio("^([A-Z])([a-z]*)$");
        if (!regex_match(data[0], fio))  return false;
        if (!regex_match(data[1], fio)) return false;
        if (!regex_match(data[2], fio)) return false;
        regex age("^[0-9]{2}$");
        if (!regex_match(data[3], age)) return false;
        regex phone_number(R"(^((8|\+7)[\- ]?)?(\(?\d{3}\)?[\- ]?)?[\d\- ]{7,10}$)");
        if (!regex_match(data[4], phone_number)) return false;
        regex city("^(g.)[A-Z][A-Z][A-Z],$");
        if (!regex_match(data[5], city)) return false;
        regex street("^(ul.)[A-Z]([a-z]*),$");
        if (!regex_match(data[6], street)) return false;
        regex house("^(d.)([0-9]+)$");
        if (!regex_match(data[7], house)) return false;
        return true;
    }
};

int secretService() {
    int M;
    cin >> M;
    SecretService sec;
    string trash;
    getline(cin, trash);
    for (int i = 0; i < M; i++) {
        string data = {};
        getline(cin, data);
        sec.newData(data);
        cout << (sec.checkCorrect() ? "YES" : "NO") << "\n";
    }
    return 0;
}
