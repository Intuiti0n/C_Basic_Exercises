#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void line(int n,int value){
    int i=0;
    for(i=0;i<n;i++)
        if(i!=n-1)
        printf("%d ",value);
        else printf("%d",value);
}

int main()
{
    int n=5,i=0,j=0,aux_i=0;
    //scanf("%d", &n);

    int size=n*2-1;

    for(i=0;i<2*n-1;i++){
        if(i==0||i==size-1){
            line(n*2-1, n);
            printf("\n");
        }
        else if(i<n-1){
            for(j=0;j<i;j++){
                printf("%d ",n-j);
            }
            line((n-i)*2-2,n-i);

            for(j=i;j>0;j--){
                printf(" %d",n-j);
            }

            printf(" %d\n",n);
            //printf("\n");
        }
        else if(i==n-1){
            int aux = 0;
            for(aux_i=0;aux_i<2*n-1;aux_i++){

                if(aux_i < (2*n -1)/2+1)
                printf("%d ",n-aux_i);

                else {
                aux= aux +2;
                printf("%d ",n-aux_i+aux);
                }
            }
        }
        else{
            int aux= 0;
            //para i==5
            //5 4 3 2 2 2 3 4 5
            for(j=0;j<i+aux++;j++){
                printf("%d ",n-j);
            }
            line((n-i)*2-2,n-i);

            for(j=i;j>0;j--){
                printf(" %d",n-j);
            }

            printf(" %d\n",n);
            //printf("\n");

        }

    }

    return 0;
}
