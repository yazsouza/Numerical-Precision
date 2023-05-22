

#include <stdio.h>
#include <math.h>


float findSum(int start, int end)
{
    float c = 0; //Kahan algorithm compensation of lost bits from arithmetic operations
    float tempSum = 0; 
    float sum = 0; //holds final sum
    float term = 0;

    for (int n = start; n < end; n++)
    {
        term = (1 / (float)n) * pow(-1.0, n + 1) - c; //taylor series approximation of ln2
        
        tempSum = sum + term; //add nth term with current sum
        c = tempSum - sum - term; //calculate error to be subtracted from next iteration
        sum = tempSum; //save new sum
    }
    return sum;
}

void main()
{
    unsigned int n = 100000000; 

    float proc1 = findSum(1, n / 4); //procesor 1 - calculates 1st quarter of sum          
    float proc2 = findSum(n / 4, n / 2); //procesor 2 - calculates 2nd quarter of sum        
    float proc3 = findSum(n / 2, 3 * n / 4); //procesor 3 - calculates 3rd quarter of sum  
    float proc4 = findSum(3 * n / 4, n + 1);   //procesor 4 - calculates 4th quarter of sum  

    proc1+= proc2; //processor 1 adds its sum with the sum of processor 2 to find the 1st half sum
    proc3+= proc4; //processor 3 adds its sum with the sum of processor 4 to find the 2nd half sum

    proc1+=proc3; //processor 1 adds the 2nd half sum to the 1st to find the overall sum approx of ln2
    
    printf("\n");
    printf("  the calulated value of ln2 with 100000000 terms = %.10f", proc1);
    printf("\n\n");
    printf("  the value of ln2 from the built-in log function = %.10f", log(2));
}

