#include <iostream>
#include <vector>
using namespace std;


int FindSum(string str);

string FindParent(string str, int &i, int pa){
    int p = pa;
    int n = i;
    for(; i < str.size(); ++i){
        if(str[i] == ')'){
            if(p == 1){
                string sub = str.substr(n, i - n);
                ++i;
                return sub;

            }else{
                --p;

            }

        }else if(str[i] == '(')
            ++p;
    }
    return string();
}
int ReadNum(string str, int &i){
    int n = 0;
    if(str[i] == '('){
        string sub = FindParent(str, ++i, 1);
        if(!sub.empty())
            n = FindSum(sub);
        else
            throw("Error when finding parents");

    } else
        while(str[i] >= '0' && str[i] <= '9'){
            n = 10 * n + str[i] - '0';
            ++i;

        }
    return n;
}
int FindSum(string str){
    if(str.empty())
        return 0;
    int num = 0;
    int right = 0;
    vector<int> stack;
    for(int i = 0; i < str.size(); ){
        if(str[i] >= '0' && str[i] <= '9'){
            num = ReadNum(str, i);
            stack.push_back(num);

        } else{
            switch(str[i]){
            case '+':
                ++i;
                right = ReadNum(str, i);
                num = stack.back();
                stack.pop_back();
                stack.push_back(num + right);
                break;
            case '-':
                ++i;
                right = ReadNum(str, i);
                num = stack.back();
                stack.pop_back();
                stack.push_back(num - right);
                break;

            }

        }

    }
    num = stack.back();
    return num;
}

int main(){
    string a = "1+2+(4-3)";
    cout << FindSum(a) << endl;
    return 0;
}
