#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *ptr = fopen("taha.txt", "r");
    if(ptr == NULL){
        printf("Failed to open file\n");
        return 0;
    }

    char ch;
    int ln = 0;
    while((ch = fgetc(ptr)) != EOF){
        ln++;
    }

    rewind(ptr); 

    int arr[10];
    int i = 0;

    while(fscanf(ptr, "%d", &arr[i]) == 1){
        i++;
    }

    fclose(ptr);

    printf("Total characters in file: %d\n", ln);
    printf("Numbers read: %d\n", i);

    printf("Numbers: ");
    for(int j = 0; j < i; j++){
        printf("%d ", arr[j]);
    }
    FILE *ptr1=fopen("even.txt","a");
    FILE *ptr2=fopen("odd.txt","a");
    for(int i=0;i<100;i++){
    	
    	if(arr[i]%2==0){
    		fprintf(ptr1,"%d ",arr[i]);
		}else{
			fprintf(ptr2,"%d ",arr[i]);
		}
	}
	fclose(ptr1);
	fclose(ptr2);
	fclose(ptr);
    return 0;
}

