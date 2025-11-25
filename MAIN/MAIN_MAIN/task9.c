/*Junaid wants to keep track of all mobile phone bills in his X company branches. Let Y be
the number of company mobile phones in each branch. Create a 2D array for bill amount,
where keep track of branch ID in row subscript, mobile phone IDs in column subscript. Ask
users to enter a bill for all mobile phones in all branches. Your program should print the
following:
- Total bill for all branches
- Total bill for each branch
- Branch ID where maximum bill arrived
- Branch and Mobile Phone IDs where bill is highest of all mobile phones.*/



//Name: Mohsin Ali
//Roll Number: 25P-0545

#include <stdio.h>

int main(){

    printf("Name: Mohsin Ali\nRoll Number: 25P-0545\n_______________________________\n");

    int x,y;
    printf("Enter Branches: ");
    scanf("%d",&x);

    printf("Enter Total Numbre of Mobile Phones for brancH: ");
    scanf("%d",&y);

    int arr[x][y];          // x= branches, y=mobile phones;

    for(int i=0;i<x;i++){
        printf("Branch %d",i+1);
        for(int j=0;j<y;j++){
            printf("\nMobile Value %d: ",j+1);
            scanf("%d",&arr[i][j]);
        }
    }


    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    //Total Bill:
    int sum=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            sum+=arr[i][j];
        }
    }

    printf("\nTotal Bill: %d ",sum);


    int sum1=0;
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            sum1+=arr[i][j];
        }
        printf("\nTotal Bill for Branch %d is %d",i+1,sum1);
        sum1=0;
    }


    int row;
    int max=arr[0][0];
    int col=0;

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(arr[i][j]>max){
                max=arr[i][j];
                row=i;
                col=j;
            }
        }
    }


    printf(" \nBranch Id where Max Bill Arrived: %d\nMobile ID where Max Bill Arrives: %d",row+1,col+1);

}