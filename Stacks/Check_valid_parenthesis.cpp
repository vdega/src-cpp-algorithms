/*
Check for the valid parenthesis in an expression.
Balanced parenthesis.
Ex: {[3*4()3{}]} - valid parenthesis.
[{}()[] - Not valid Parenthesis.

*/

#include <iostream>
#include<string>
#include<stack>

using namespace std;

int main() {

  stack<char> st;
  string str1("{{[9*7(ab/dc)[(3+4)]}}");
  cout<<"String length : "<<str1.length()<<endl;

  for(int i=0;i<str1.length();i++)
  {

    if(str1.at(i)=='{' || str1.at(i)=='[' || str1.at(i)=='(')
    {
      st.push(str1.at(i));
    }
    else if(str1.at(i)=='}' || str1.at(i)==']' || str1.at(i)==')')
    {
/*Check the stack top and compare with str1[i], to see the proper closing braces occured.
Ex: if stack top is '{' then the str1[i] should be '}' then only its a proper closing.
if stack top is '[' and str1[i] is ')', then its not valid.
- TO AVOID CORNER CASE - [{}()[)] - this still valid but [) is nOK.*/

        st.pop();
    }
    else{}
  }
  if(st.empty())
    cout<<"Valid Parenthesis"<<endl;
  else
    cout<<"Not Valid PArenthesis"<<endl;

}
