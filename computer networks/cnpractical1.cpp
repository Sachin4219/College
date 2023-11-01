#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Flag byte Sequence: *\n\n";
    cout << "Escape byte Sequence: #\n\n";
    char flag = '*';
    char escape = '#';
    string oM = "*hello *#Sachin# !*";
    cout << "Message to be sent : " << oM << "\n\n";

    string sM = "f";
    for (int i = 0; i < oM.length(); i++){
        if (oM[i] == flag){
            sM += escape;
            sM += flag;
        }
        else if (oM[i] == escape){
            sM += escape;
            sM += escape;
        }
        else
            sM += oM[i];
    }
    sM += flag;
    cout << "\nencoded message : " << sM <<"\n\n";
    string rM = "";

    for (int i = 1; i <= (sM.length() - 2); i++){
        if (sM[i] == escape){
            if (sM[i + 1] == flag)
                continue;
            else{
                rM += escape;
                i++;
            }
        }
        else
            rM += sM[i];
    }
    cout << "decoded message is: " << rM << endl;
    return 0;
}