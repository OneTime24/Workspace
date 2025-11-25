//Write a C program to read name and marks of n number of students and store them in a file
//Name: Mohsin Ali
//Roll Number: 25P-0545
#include <stdio.h>
#include <string.h>
int main(){

    int n;
    printf("Enter number of students: ");
    scanf("%d",&n);

    getchar();
    FILE *ptr=fopen("task2.txt","a");

    if(ptr==NULL){
        printf("ERROR OPENING! ");
    }else{
    for(int i=0;i<n;i++){
        char name[256];
        int marks;
        printf("Enter Student %d Name: ",i+1);
        scanf("%[^\n]s",name);
        // fgets(name,sizeof(name),stdin);

         printf("Enter Student %d Marks: ",i+1);
        scanf("%d",&marks);
        getchar();
        fprintf(ptr,"%s : %d\n",name,marks);

        
    }  

    fclose(ptr);
}
}