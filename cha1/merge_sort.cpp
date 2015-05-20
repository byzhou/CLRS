#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <stdio.h>

using namespace std;

bool merge_sort(int *A, int p, int q, int r){
    int i = 0;
    int j = 0;
    int k = 0;

    int Left[q - p];
    int Right[r - q + 1];

    printf ( " p %d , q %d , r %d \n " , p , q , r ) ;

    if ( p >= q || q >= r || p >= r ) 
        return true;
    else {
        
        //Left is going to scan indices from p to q - 1
        printf ( "This is left : \n " ) ;
        for (i = p ; i < q ; i ++) {
            Left[i - p] = A[i];
            printf ( " A [ %d ] %d \t " , i , A[i] ) ;
        }
        printf ( "\n" ) ;

        printf ( "This is right : \n " ) ;
        //Right is going to scan indices from q to r
        for (j = q ; j < r + 1 ; j ++) {
            Right[j - q] = A[j];
            printf ( " A [ %d ] %d \t " , j , A[j] ) ;
        }
        printf ( "\n" ) ;

        j = 0 ;
        k = 0 ;

        printf ( "Sorted in this round. \n " ) ;

        for (i = p ; i < r + 1; i ++) {
            if ( Left[j] >= Right[k] ){
                A[i] = Right[k];
                k ++;
                printf ( " A [ %d ] %d \t " , i , A[i] ) ;
            } else {
                A[i] = Left[j];
                j++;
                printf ( " A [ %d ] %d \t " , i , A[i] ) ;
            }
        }
        printf ( "\n" ) ;

        
        printf ( " Inside merge. \n " ) ;
        merge_sort ( A , p , p + ( q - p ) / 2 , q ) ;
        merge_sort ( A , q + 1 , q + ( r - q ) / 2 , r ) ;
        return false ;
    }
}

int main(){
    //length of the array
    const int num = 2;
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
            printf("array %d value is %d \n", i*num+j, array[i*num+j]);
          }
    }
    

    printf("The time spent on the array generation is: %4.2f \n", (float)( clock() - t) / CLOCKS_PER_SEC);    

    long double key;
    //record start time
    t = clock();

    printf ( "Start Merge Sorting. \n " ) ;
    merge_sort ( array , 0 , num * num / 2 , num * num - 1 ) ;
    printf ( "Merge Sort complete. \n " ) ;
    /*
    for (i = num*num-2; i >= 0; i--){
        key = array[i];
        j=i+1;
        while ((j < num*num) && (array[j] < key)){
            array[j-1]=array[j];
            j=j+1;
        }
        array[j-1]=key;
    }*/

    //record end time
    printf("The time spent on the array sorting is: %4.2f \n", (float)( clock() - t) / CLOCKS_PER_SEC);
    cout<<"The array has been sorted."<<endl;

    //print the sorted array
    for ( i = 0; i < num; i++){
          for ( j = 0; j < num; j++){
            printf("array %d value is %d \n", i*num+j, array[i*num+j]);
          }
    }
    
    return 0;
}
