#include <iostream>
#include <vector>
using namespace std;

int CalBackOrder(string s){
    vector<string> stack_num;
    string num;
    char *result = new char[100];
    for(auto a : s){
        if(a >= '0' && a <= '9'){
            num += a;

        } else{
            if(!num.empty()) {
                stack_num.push_back(num);
                num.clear();

            }
            int i, j;
            i = atoi(stack_num.back().c_str());
            j = atoi(stack_num[stack_num.size() - 2].c_str());
            switch(a){
            case '+':
                stack_num.pop_back();
                stack_num.pop_back();
                sprintf(result, "%d", j + i);
                stack_num.push_back(result);
                break;
            case '-':
                stack_num.pop_back();
                stack_num.pop_back();
                sprintf(result, "%d", j - i);
                stack_num.push_back(result);
                break;
            case '*':
                stack_num.pop_back();
                stack_num.pop_back();
                sprintf(result, "%d", j * i);
                stack_num.push_back(result);
                break;
            case '/':
                stack_num.pop_back();
                stack_num.pop_back();
                sprintf(result, "%d", j / i);
                stack_num.push_back(result);
                break;
            case '=':
                num = stack_num.back();
                stack_num.pop_back();
                return atoi(num.c_str());
            default:
                break;


            }


        }

    }
    if(!stack_num.empty()){
        num = stack_num.back();
        stack_num.pop_back();
        return atoi(num.c_str());

    } else
        throw("error");
}

int main() {
    string data;
    while(getline(cin, data))
    cout << CalBackOrder(data) << endl;
    return 0;
}
