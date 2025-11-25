// C program to write all the members of an array of structures to a file using fwrite(). Read the array
// from the file and display on the screen.
//Name: Mohsin Ali
//Roll Number: 25P-0545
#include <stdio.h>
#include <string.h>

struct student{
    char name[256];
    int marks;
    
};
int main(){

    struct student s[3]={
        {"ali",25},
        {"ahmed",20},
        {"Maz",23}
    };

    //Writing
    
    FILE *ptr=fopen("task3.bin","wb");

    if(ptr==NULL){
        printf("Error Opening File: ");
    }

    fwrite(s,sizeof(struct student),3,ptr);
    printf("Writing Done...............\n");
    fclose(ptr);

    //Reading
    printf("Reading...................\n");
    ptr=fopen("task3.bin","rb");
    if(ptr==NULL){
        printf("Error Opening File: ");
    }
    struct student s_read[3];

    fread(s_read,sizeof(struct student),3,ptr);
    

    //Display

    for(int i=0;i<3;i++){
        printf("Name: %s : ",s_read[i].name);
        printf("Marks : %d : \n",s_read[i].marks);

    }

}