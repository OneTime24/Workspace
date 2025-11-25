/*Task-4
Write a program in which user enters his NTS and F.Sc marks and your program
will help student in selection of university. Based on these marks Student will be
allocated a seat at different department of different university.
? Oxford University 

IT: Above 70% in Fsc. and 70 % in NTS
Electronics: Above 70% in Fsc. and 60 % in NTS
Telecommunication Above 70% in Fsc. and 50 % in NTS

? MIT

IT: 70% - 60 % in Fsc. and 50 % in NTS
Chemical: 59% – 50 % in Fsc. and 50 % in NTS
Computer: Above 40% and below 50 % in Fsc. and 50 % in NTS */


#include <stdio.h>
int main(){
	int fsc,nts;
	float fsc_p;
	printf("Enter FSC Obtained Marks out of 1100: ");
	scanf("%d",&fsc);
	printf("Enter NTS Obtained Marks out of 100: ");
	scanf("%d",&nts);
	if(fsc_p>70){
		printf("OXFORD UNIVERSITY: ");
		if(fsc_p>70&&nts>70){
			printf("\nIT");
		}else if(fsc_p>70&&nts>60){
			printf("\nElectronics: ");
		}else if(fsc_p>70&&nts>50){
			printf("\nTelecommunication: ");
				}
}else if(nts>50){
	printf("MIT\n");
	if(nts>50 && (fsc_p>=60 && fsc_p<70)){
		printf("Computer: ");
		}else if(nts>50&&(fsc_p>=50&&fsc_p<60)){
			printf("Chemical: ");
		}else if(nts>50&&(fsc_p>=40&&fsc_p<50)){
			printf("IT");
			}
		}
		return 0;
	}
