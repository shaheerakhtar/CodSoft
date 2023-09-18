#include<iostream>
using namespace std;
int main(){
    float num1,num2;
    char cal;
    do
    {
      cout<<endl<<"Enter value 1: ";
      cin>>num1;
      cout<<endl<<"Enter value 2: ";
      cin>>num2;
      cout<<"1. Add (+)"<<endl<<"2. Subtract (-)"<<endl<<"3. Multiplication (*)"<<endl<<"4. Division (/)"<<endl<<"5. Exit"<<endl<<endl<<"Enter Option: ";
      cin>>cal;
      if (cal=='+'||cal=='1')
      {
        cout<<"Ans: "<<num1+num2<<endl;
      }
      else if (cal=='-'||cal=='2')
      {
        cout<<"Ans: "<<num1-num2<<endl;
      }
      else if (cal=='*'||cal=='3')
      {
        cout<<"Ans: "<<num1*num2<<endl;
      }
      else if (cal=='/'||cal=='4')
      {
        cout<<"Ans: "<<num1/num2<<endl;
      }
      else if(cal=='5'){
            break;
      }
      else{
        cout<<endl<<"Invalid Input!"<<endl;
      }
    }while (true);
}