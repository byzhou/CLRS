#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <stdio.h>

using namespace std;

void merge_sort(int *A, int p, int q, int r){
    int j = 0;
    int k = 0;
    int i = 0;
    int Left[q - p];
    int Right[r - q + 1];
    
    //Left is going to scan indices from p to q - 1
    for (i = 0; i < q - p; i ++)
        Left[i] = A[i + p];

    //Right is going to scan indices from q to r
    for (j = 0; j < r - q + 1; j ++)
        Right[i] = A[i + q];


    for (i = p; i < r + 1; i ++)
        if (Left[j] >= Right[k]){
            A[i] = Right[j];
            j ++;
        } else {
            A[i] = Left[k];
            k++;
        }

    merge_sort(A,p,q/2,r/2);
    merge_sort(A,q/2+1,(r-q)/2+q,r);
}

int main(){
    //length of the array
    const int num = 1333;
    //random generator seed
    srand(time(0));
    //time generation
    clock_t t;


    int array[num*num];
    int i,j;

    //record start time
    t = clock();
    for ( i = 0; i < num; i++){
          for ( j = 0; j < num; j++){
            array[i*num+j]=rand()/1000000;
            //printf("array %d value is %d \n", i*num+j, array[i*num+j]);
          }
    }

    printf("The time spent on the array generation is: %4.2f \n", (float)( clock() - t) / CLOCKS_PER_SEC);    

    long double key;
    //record start time
    t = clock();
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
    printf("The time spent on the array sorting is: %4.2f \n", (float)( clock() - t) / CLOCKS_PER_SEC);
    cout<<"The array has been sorted."<<endl;

    //print the sorted array
    /*
    for ( i = 0; i < num; i++){
          for ( j = 0; j < num; j++){
            printf("array %d value is %d \n", i*num+j, array[i*num+j]);
          }
    }
    */
    
    return 0;
}
