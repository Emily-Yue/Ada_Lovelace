#include <stdio.h>
#include "main.h"


int main() {
    printf("Hello World\n"); 
    for(int i = 1; i <= 19; i+=2){
        double curr_b = bernoulli((i + 1) / 2);
        printf("B_%d = %f\n", i, curr_b);
    }
}


double bernoulli(int n){
    // base case
    if(n <= 0){
        return 0;
    } 

    // recursive step

    // terms up to n
    double terms = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            terms+=(-((double) 1 / 2 ) *((double) (2*n - 1) / (2*n + 1)));
        } else {
            double coffe = 1;
            for(int j = 0; j < (2*i - 1); j++) {
                coffe*=((double) (2*n - j) / (2 + j));
            }
            double currentTerm = bernoulli(i)*coffe;
            terms+=(currentTerm);
        }
    }

    // n_th term coffe
    double coffe_curr = 1;
    for(int j = 0; j < (2*n - 1); j++){
        coffe_curr*=((double) (2*n - j) / (2+ j));
    }

    return -(terms) / coffe_curr;
}
