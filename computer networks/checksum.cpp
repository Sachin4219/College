#include<bits/stdc++.h>
using namespace std;

string sum(string a,string b){
	string r1=a;
	reverse(r1.begin(), r1.end());
	string r2=b;
	reverse(r2.begin(), r2.end());
	int i=0,j=0;
	int sum=0,carry=0;
	string ans="";
	while(i<r1.size() && j<r2.size()){
		if(carry==0){
			if((r1[i]=='0'&& r2[j]=='1') || (r1[i]=='1'&&r2[j]=='0')){	
				ans+='1';	
				carry=0;	
			}	
			else if((r1[i]=='0' && r2[j]=='0')){	
				ans+='0';	
				carry=0;	
			}
			else{	
				ans+='0';	
				carry=1;	
			}
		}
		else{
			if((r1[i]=='0'&& r2[j]=='1') || (r1[i]=='1' && r2[j]=='0')){
				ans+='0';
				carry=1;
			}
			else if((r1[i]=='0' && r2[j]=='0')){
				ans+='1';
				carry=0;
			}
			else{
				ans+='1';
				carry=1;
			}
		}
		i++; j++;
	}
	if(carry==1){
		int i=0;
		while(carry==1){
			if(i==ans.size()){
				i=0;
			}
			if(ans[i]=='1'){
				ans[i]='0';
				carry=1;
			}
			else{
				ans[i]='1';
				carry='0';
			}
			i++;
		}
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int main(){
	int n;
	cout<<"Enter number of strings"<<endl;
	cin>>n;
	vector<string>vi(n);
	cout<<"Enter strings"<<endl;
	for(int i=0;i<n;i++){
		cin>>vi[i];
	}
	string sum_util=sum(vi[0],vi[1]);
	for(int i=2;i<n;i++){
		sum_util=sum(sum_util,vi[i]);
	}
	string res="";
	for(int i=0;i<sum_util.size();i++){
		if(sum_util[i]=='1'){
			res+='0';
		}
		else{
			res+='1';
		}
	}
	cout<<"Checksum : "<<res<<"\n";
}