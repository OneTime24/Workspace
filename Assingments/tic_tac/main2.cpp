// Tic Tac Toe:

#include <stdio.h>
#include <stdlib.h>
int main(){
	
	char p1='1',p2='2',p3='3',p4='4',p5='5',p6='6',p7='7',p8='8',p9='9';
	int x1,y1;
	printf(" %c | %c | %c \n----------\n %c | %c | %c \n----------\n %c | %c | %c ",p1,p2,p3,p4,p5,p6,p7,p8,p9 );
	
	printf("\nPlayer 1 Turn (o): ");
	scanf("%d",&x1); 			//Player 1
	switch(x1){
		case 1:
			if(p1=='1'){
				p1='o';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 2:
			if(p2=='2'){
				p2='o';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 3:
			if(p3=='3'){
				p3='o';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 4:
		if(p4=='4'){
				p4='o';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 5:
		if(p5=='5'){
				p5='o';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 6:
		if(p6=='6'){
				p6='o';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 7:
			if(p7=='7'){
				p7='o';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 8:
		if(p8=='8'){
				p8='o';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 9:
			if(p9=='9'){
				p9='o';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;	
		default:
			printf("Invalid Choice: Game Terminating");
	}	
	
	printf("\n %c | %c | %c \n----------\n %c | %c | %c \n----------\n %c | %c | %c ",p1,p2,p3,p4,p5,p6,p7,p8,p9 );
	
	
		printf("\nPlayer 2 Turn (x): ");
		scanf("%d",y1);
		
		switch(y1){
			case 1:
			if(p1=='1'){
				p1='x';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 2:
			if(p2=='2'){
				p2='x';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 3:
			if(p3=='3'){
				p3='x';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 4:
		if(p4=='4'){
				p4='x';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 5:
		if(p5=='5'){
				p5='x';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 6:
		if(p6=='6'){
				p6='x';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 7:
			if(p7=='7'){
				p7='x';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 8:
		if(p8=='8'){
				p8='x';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;
		case 9:
			if(p9=='9'){
				p9='x';
			}else{
				printf("Invalid Choice: Game Terminating");
				exit(0);
			}
			break;	
		default:
			printf("Invalid Choice: Game Terminating");
	}
		}
	
	
	

