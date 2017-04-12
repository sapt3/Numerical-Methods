#include <stdio.h>
#include <math.h>

float computePolynomial(float);
float findRoot(float, float, int , float);
int main(void) {
    int n;
    float e, x1, x2;
    //Put your function here
    //Let the function be x^3 + x^2 -2
	// your code goes here
	printf("Enter two initial guesses of the polynomial \n");
	scanf("%f %f",&x1,&x2);
	printf("Enter the maximum numberof iterations and tolerance \n");
	scanf("%d %f", &n, &e);
	printf("Debug: Entered values are %f, %f, %d, %f", x1, x2, n, e);
	
	
	float result = findRoot(x1,x2,n,e);
	if(result!= -1){
	    printf("Root of the above equation found as %f which gives value of %f", result, computePolynomial(result));
	}
	else{
	    printf("The above equation is not convergent for the given choices of input");
	}
	return 0;
}

float computePolynomial(float x){
    //The function is x^3 + x^2 -2
    float result = pow(x,5) + pow(x,2) -1;
    return result;
}

float findRoot(float x1, float x2, int n, float e)
{
    int flag = 0;
    float f1 = computePolynomial(x1);
	float f2 = computePolynomial(x2);
    int i;
    for (i = 1; i < n; i++) {
        /* code */
        float x0 = (x1*f2 - x2*f1)/(f2-f1);
        printf("Debug: %f \n", x0);
        float f0 = computePolynomial(x0);
        float modulus;
        
        printf("\nDebug: %f, %f", f1,f2);
        //Find the modulus
        if(f1>f2) modulus = f1-f2;
        else if(f2>f1) modulus = f2-f1;
        printf("%f %f \n",modulus, x0);
        if(modulus <= e) {
            
            flag = 1;
            return x0;
        }
        if(f0*f1 < 0){
            x2 = x0;
            f2 = f0;
        } 
        else {
            x1 = x0;
            f1 = f0;
        }
    }
    
    if(flag == 0)
    return -1; //Problem occurs if the root is -1
}

