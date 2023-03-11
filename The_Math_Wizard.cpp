#include<bits/stdc++.h>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
 
    stack<char> st;
    string result;
 
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
            st.push('(');
        else if (c == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty()
                   && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
 
    return result;
}
double postfix(string s){
    stack <double> st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9'){
           st.push(s[i]-'0');
        }
        else{
            double op1 = st.top();
            st.pop();
            double op2 = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op2+op1);
                break;
            case '-':
                st.push(op2-op1);
                break;
            case '*':
                st.push(op2*op1);
                break;
            case '/':
                st.push(op2/op1);
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}

string getSymbol(string s) {

    if(s.length() == 1) return s;
    if(s == "zero") return "0";
    if(s == "one") return "1";
    if(s == "two") return "2";
    if(s == "three") return "3";
    if(s == "four") return "4";
    if(s == "five") return "5";
    if(s == "six") return "6";
    if(s == "seven") return "7";
    if(s == "eight") return "8";
    if(s == "nine") return "9";
    if(s == "plus") return "+";
    if(s == "substract") return "-";
    if(s == "multiple") return "*";
    if(s == "division") return "/";
    if(s == "equals") return "=";
    return "";
}


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    int a = 1;
    while(t--) {
        string str;
        string equation = "";
        while(1) {
            cin >> str;
            if(str == "equals" || str == "=") break;
             string temp = getSymbol(str);
             equation += temp;
        }
        string word;
        cin >> word;
        double ans = stod(word);
        equation = infixToPostfix(equation);
        double res = postfix(equation);
        cout << "Case #" << a << ": ";
        if(ans == res) cout << "true\n";
        else cout << "false\n";
        a++;
    }
}