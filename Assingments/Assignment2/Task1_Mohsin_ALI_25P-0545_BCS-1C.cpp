
// Name: Mohsin Ali
// Roll Number: 25P-0545

#include <stdio.h>
int main(){
	printf("Name: Mohsin Ali\n");
	printf("Roll Number: 25P-0545\n");
	printf("_________________________________\n");
	int m,n,ch;			// m = lockeres, n=students
	printf("Enter Number of Lockers: ");
	scanf("%d",&m);
	printf("\nEnter Number of Students: ");
	scanf("%d",&n);
	
	int num[m+1];
	int togg[m+1];
	//0 for closed
	//1 for open
	for(int i=1;i<=m;i++){		// To assign 0 to all elements of array! basically all lockers are close
		num[i]=0;			
		togg[i]=0;
	}
	
	for(int i=1;i<=n;i++){		//Loop throught each student
		for(int j=i;j<=m;j+=i){		// Loop through each locker for each student, Increment by j+=i, to toggle every nth+jth locker depending on the student.
			num[j]=!num[j];			// If 0 then 1 or 1 then 0
			togg[j]++;				// increment togg[j] by 1 for each jth iteration
		}
	}
	
	while(1){									// A continuous loop
		printf("Select Operation: \n");
		printf("---------------------------\n");
        printf("1. Show number of open lockers\n");
        printf("2. Show most toggled locker\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        int count=0;
        if(ch==1){					//If choice 1:
        	for(int i=1;i<=m;i++){		
        		if(num[i]==1){			//Counting Number of Open Lockers
        			count++;
				}
			}
			printf("Number of Open Lockers: %d\n",count);
		}else if(ch==2){			//If choice 2:
			 int max_t = 0, lc = 0;
            for (int i = 1; i <= m; i++) {
                int count = 0;
                for (int j = 1; j <= n; j++) {
                    if (i % j == 0) {		//If student mod locker ==0 then , increaes count by 1
                        count++;
                    }
                }

/*Condition to display the locker that was toggled the most times. If there are multiple lockers
tied for the highest number of toggles, display the highest locker number among
them. */
                if (count > max_t || 			
                   (count == max_t && i > lc)) {
                    max_t = count;
                    lc = i;
                }
		}
		  
            printf("Most toggled Locker: %d | Toggled %d times\n", lc, max_t);
    }

        else if (ch == 3) {
            printf("Exiting game...\n");
            break;
        }

        else {
            printf("Invalid choice! Try again.\n");
        }
    }
    }
	
	
	

