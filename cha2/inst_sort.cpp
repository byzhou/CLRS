#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    //length of the array
    const int num = 3;
    //random generator seed
    srand(time(0));
    //time generation
    time_t timer_start;
    time_t timer_end;


    int array[num*num];
    int i,j;

    //record start time
    time(&timer_start);
    for ( i = 0; i < num; i++){
          for ( j = 0; j < num; j++){
            array[i*num+j]=rand()/1000000;
            printf("array %d value is %d \n", i*num+j, array[i*num+j]);
          }
    }
    //record end time
    time(&timer_end);

    long double time_diff = timer_end - timer_start;
    printf("The time spent on the array generation is: %4.2Lf \n", time_diff);
    
    long double key;
    //record start time
    time(&timer_start);
    for (i = num*num-2; i >= 0; i--){
        key = array[i];
        j=i+1;
        while ((j < num*num) && (array[j] < key)){
            array[j-1]=array[j];
            j=j+1;
        }
        array[j-1]=key;
    }
    //record end time
    time(&timer_end);
    time_diff = timer_end - timer_start;
    printf("The time spent on the array sorting is: %4.2Lf \n", time_diff);
    cout<<"The array has been sorted."<<endl;

    //print the sorted array
    for ( i = 0; i < num; i++){
          for ( j = 0; j < num; j++){
            printf("array %d value is %d \n", i*num+j, array[i*num+j]);
          }
    }
    
    return 0;
}
