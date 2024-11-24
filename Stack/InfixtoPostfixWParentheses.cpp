#include <iostream>
#include <stack>
#include <vector>
#include <cctype>

using namespace std;

int preced(char ch) {
   if(ch == '+' || ch == '-') {
      return 1;              //Precedence of + or - is 1
   }else if(ch == '*' || ch == '/') {
      return 2;            //Precedence of * or / is 2
   }else if(ch == '^') {
      return 3;            //Precedence of ^ is 3
   }else {
      return 0;
   }
}

int main()
{
    string infix = "A/(B+(C-D))*E";
    vector<char> postfix;
    stack<char> s;
    for(int i=0;i<infix.length();i++)
    {
        char curr = infix[i];
        if(isalnum(curr))
        {
            postfix.push_back(curr);
        } else {
            
            if(curr == '(') {
                s.push(curr);
            } else if(curr == ')') {
                while(!s.empty() && s.top()!='(') {
                    postfix.push_back(s.top());
                    s.pop();
                }
                s.pop();
            } else {
                while(!s.empty() && preced(curr) <= preced(s.top())) {
                    if(curr=='^' && s.top()=='^')
                        break;
                    postfix.push_back(s.top());
                    s.pop();
                }
                s.push(curr);
            }
        }
        
    }
    while(!s.empty()) {
        postfix.push_back(s.top());
        s.pop();
    }
    
    for(auto x:postfix) 
        cout << x << " ";
}