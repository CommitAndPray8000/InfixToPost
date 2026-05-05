#include<bits/stdc++.h>
#include "InfixToPost.cpp"
using namespace std;

int main()
{
    string infix_expression;

    cout<<"Welcom to Infix to Postfix converter.\n";
    cout<<"Enter the expression you want to convert to Postfix : ";
    cin>>infix_expression;
    cout<<endl;
    PostFixConverter baad_waala = PostFixConverter(infix_expression);
    cout<<"The converted Expressoin is : " << baad_waala.Converter()<<endl;
    
}