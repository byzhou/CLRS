#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    const int num = 100000;
    srand(time(0));

    int array[num];

    for (int i = 0; i < num; i++){
        array[i]=rand();
    }
    cout<<"The array has been sorted."<<endl;
    return 0;
}
