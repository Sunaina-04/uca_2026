#include <stdio.h>

int sumEvenFibonacciOptimized(int n){
	if (n < 2){
		return 0;
	}

	int dp[n+1];
	dp[0] = 0;
	dp[1] = 1;

	int sum = 0;
	int i = 2;


	do {
		dp[i] = dp[i - 1] + dp[i - 2];

		if(dp[i] % 2 ==0 && dp[i] <= n ){
			sum += dp[i];
		}
		i++;
	}while (dp[i-1] <= n);

	return sum;	
}

int  main (int argc, char* argv[]){
	int n = 100;
	printf("Sum of even Fibonacci terms: %d \n", sumEvenFibonacciOptimized(n));
	return 0;
}
