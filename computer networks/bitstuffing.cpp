#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
void bitStuffing(int N, int arr[]){
    int brr[30];
 
    int i, j, k;
    i = 0;
    j = 0;
 
    while (i < N) {
        if (arr[i] == 1) {
            int count = 1;
            brr[j] = arr[i];
            for (k = i + 1;
                 arr[k] == 1 && k < N && count < 5; k++) {
                j++;
                brr[j] = arr[k];
                count++;
                if (count == 5) {
                    j++;
                    brr[j] = 0;
                }
                i = k;
            }
        }
        else {
            brr[j] = arr[i];
        }
        i++;
        j++;
    }
    for (i = 0; i < j; i++)
        cout << brr[i];
    cout<<"\n";
}
int main()
{
    int N = 6;
    int arr[] = { 1, 1, 1, 1, 1, 1 };
    cout<<"Test string : ";
    for(int i=0;i<N;i++){
        cout<<arr[i];
    }
    cout<<"\n\n Result string : ";
    bitStuffing(N, arr);
    return 0;
}