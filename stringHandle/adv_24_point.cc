#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void chk_print_sum(vector<string> nums, string exp, int sum, int should){
    if(nums.size() == 0){
        if(sum == should)
            cout << exp + "=" << sum << endl;
        return ;
    }
    for(int i = 0; i < nums.size(); ++i){
        vector<string> sub(nums);
        sub.erase(sub.begin()+i);
        chk_print_sum(sub, exp + "+" + (nums[i]), sum + stoi(nums[i]), should);
        chk_print_sum(sub, exp + "-" + (nums[i]), sum - stoi(nums[i]), should);
        chk_print_sum(sub, exp + "*" + (nums[i]), sum * stoi(nums[i]), should);
        chk_print_sum(sub, exp + '/' + (nums[i]), sum / stoi(nums[i]), should);
    }
    return ;
}
int main(){
    string in_data;
    vector<string> numbers;

    int sum;
    while(!cin.eof()){
        getline(cin, in_data);
        istringstream iss(in_data);
        copy(istream_iterator<string>(iss),
             istream_iterator<string>(),
             back_inserter(numbers));
        sum = stoi(numbers.back());
        numbers.pop_back();

	    for(int i = 0; i < numbers.size(); ++i){
	        vector<string> sub(numbers);
	        sub.erase(sub.begin()+i);
	        chk_print_sum(sub, numbers[i], stoi(numbers[i]), sum);
	}

        in_data.clear();
        numbers.clear();

    }
    return 0;
}
