//Write a program non-recursive and recursive program to calculate fibonacci numbers and analyze their time and space complexity
// CSD - 66


#include<iostream>
using namespace std;

void fibo_without_recurr(int n)
{   int a=0,b=1,c,i;
    for(int i=2; i<=n; i++)
    {
        c = a + b;
        cout<<" "<<c<<" ";
        a=b;
        b=c;
    }
    cout<<endl;
   
  
}

 void Fibo_with_recurr(int n){    
        static int n1=0, n2=1, n3;    
        if(n>0){    
             n3 = n1 + n2;    
             n1 = n2;    
             n2 = n3;    
     cout<<n3<<" ";    
             Fibo_with_recurr(n-1);    
        }    
        cout<<endl;
    }    
    
int main()
{   
    int n,ch;
    char Y;
    
   do
   {
    cout<<"1. Fibonacci series without recurssion"<<endl;
    cout<<"2. Fibonacci series with recurssion"<<endl;
    cout<<"Enter your choice"<<endl;
    
    cin>>ch;
    
     cout<<"Enter how many many  terms :-"<<endl;
    cin>>n;
    
    if(ch<=2)
    {
    
    switch(ch)
    {
        case 1 : 
        cout<<"Fibonacci Series without recurrsion: "<<endl;
        fibo_without_recurr(n);
                 break;
                 
        case 2 : 
        cout<<"/Fibonacci Series with recurrsion: "<<endl;    
        cout<<"0 "<<"1 ";  
        Fibo_with_recurr(n-2);  
        break;
    }
    }
    else{
    break;
    }
    
    }while(ch<3);
}


//output :
/**
1. Fibonacci series without recurssion
2. Fibonacci series with recurssion
Enter your choice
1
Enter how many many  terms :-
5
Fibonacci Series without recurrsion: 
 1  2  3  5 
1. Fibonacci series without recurssion
2. Fibonacci series with recurssion
Enter your choice
2
Enter how many many  terms :-
10
/Fibonacci Series with recurrsion: 
0 1 1 2 3 5 8 13 21 34 

Time complexity for non-recursive function :
O(n)

Space complexity for non-recursive function :
O(1)

Time complexity for recursive function :
O(n)

Space complexity for recursive function :
O(n)

****/



 
    
