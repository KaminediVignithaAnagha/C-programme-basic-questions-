//To find prime no.
#include<stdio.h>
int main(){
    int n,i,count=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        if(n%i==0){
            count++;
        }
    }
    if(count==2){
        printf("The number is prime.");
    }
    else{
        printf("The number is not prime.");
    }
    return 0;
}
//to give the prime numbers between 1 to n
#include<stdio.h>
int main(){
    int n,i,j,count;
    printf("Enter a number:");
    scanf("%d",&n);
    printf("The prime numbers between 1 to %d are:",n);
    for(i=2;i<=n;i++){
        count=0;
        for(j=1;j<=i;j++){
            if(i%j==0){
                count++;
            }
        }
    }
}