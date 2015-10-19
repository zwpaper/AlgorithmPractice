#include <iostream>
#include <ctime>
using namespace std;

void CreateMines(int *mine_tab, int k, int n){
    int i = 0;
    int mines[k];
    for(; i < k; ++i){
        mines[i] = i;
    }
    srand(time(0));
    int ran_num;
    for(; i < n; ++i){
        ran_num = rand() % i;
        if(ran_num < k){
            mines[rand() % k] = i;
        }
    }
    for(i = 0; i < k; ++i){
        *(mine_tab + mines[i]) = 1;
    }
    return;
}

void CountMines(int *mines, int i, int j, int n, int m, int &sum){
    if(i < 0 || i > n - 1 || j < 0 || j > m - 1)
        return;
    if(*(mines + i * n + j) == 1)
        ++sum;
    return;
}

void CreateMap(int *tab, int n, int m, int *mines){
    int sum = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            sum = 0;
            CountMines(mines, i - 1, j - 1, n, m, sum);
            CountMines(mines, i - 1, j, n, m, sum);
            CountMines(mines, i - 1, j + 1, n, m, sum);
            CountMines(mines, i, j - 1, n, m, sum);
            CountMines(mines, i, j + 1, n, m, sum);
            CountMines(mines, i + 1, j - 1, n, m, sum);
            CountMines(mines, i + 1, j, n, m, sum);
            CountMines(mines, i + 1, j + 1, n, m, sum);
            *(tab + i * n + j) = sum;
        }
    }
    return;
}
int main(){
    int n = 10, m = 10, k = 10;
    cout << "Please input the size of map, and the number of mines:" << endl
         << "like: 10 10 10:" << endl;
    cin >> n >> m >> k;

    int *mine_tab = new int[n * m]();
    int *mine_map = new int[n * m]();
    CreateMines(mine_tab, k, n * m);
    CreateMap(mine_map, n, m, mine_tab);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(*(mine_tab + i * n + j) == 1)
                cout << 'X' << '\t';
            else
                cout << *(mine_map + i * n + j) << '\t';
        }
        cout << endl;
    }
    delete [] mine_tab;
    delete [] mine_map;

    return 0;

}
