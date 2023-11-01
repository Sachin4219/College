#include <iostream> 
using namespace std; 
int main(){ 
	cout << "Enter 0 for Sender Operation. Enter 1 for Reciever Operation" <<endl; 
	bool operation; 
	cin >> operation; 
	if(operation){
		cout << "Enter the recieved data: "; 
		string data; 
		cin >> data; 
		int cnt = 0; 
		for(char ch : data){ 
			if(ch == '1') cnt++; 
		} 
		if(cnt % 2 == 0) cout << "N0 ERROR" << endl; 

		else cout << "ERROR !!" << endl; 
	} 
	else{
		cout << "Enter the data to be sent: "; 
		string data; 
		cin >> data; 
		int cnt = 0; 
		for(char ch : data){ 
			if(ch == '1') cnt++; 
		} 
		if(cnt % 2 != 0) data += '1'; 
		else data += '0'; 
		
		cout << "Data to be sent : " << data << endl; 
	} 
}
