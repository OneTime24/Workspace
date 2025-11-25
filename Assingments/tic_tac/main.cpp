 /* Name: Mohsin Ali
	Roll Number: 25P-0545
	Section: BCS-1C  */
	
#include<stdio.h>
#include <stdlib.h>
int main(){
	
	char b1,b2,b3,b4,b5,b6,b7,b8,b9; // Player 1
	char c1,c2,c3,c4,c5,c6,c7,c8,c9; // Player 2
	int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
	printf("^^^^^ Tic - Tac - Toe ^^^^^\n\n");
	
	printf(" 1 | 2 | 3 \n----------\n 4 | 5 | 6 \n----------\n 7 | 8 | 9 " );
	
	printf("\nPlayer 1 Turn (o): Please Select your box: ");
	scanf("%d",&x1);
	switch(x1){
		case 1:
			b1='o';
			printf("\n %c | 2 | 3 \n----------\n 4 | 5 | 6 \n----------\n 7 | 8 | 9 ",b1 );

			printf("\nPlayer 2 Turn (x): Please Select your box: ");
			scanf("%d",&y1);
			switch(y1){
				case 1:
					printf("Invalid Choice: Game Terminates: ");
					exit(0);
				case 2:
					c1='x';
					printf("\n %c | %c | 3 \n----------\n 4 | 5 | 6 \n----------\n 7 | 8 | 9 ",b1,c1 );
					
					printf("\nPlayer 1 Turn (o): Please Select your box: ");
					scanf("%d",&x2);
					switch(x2){
						case 1:
							printf("Invalid Choice: Game Terminates: ");
							exit(0);
						case 2:
							printf("Invalid Choice: Game Terminates: ");
							exit(0);
						case 3:
							b2='o';
							printf("\n %c | %c | %c \n----------\n 4 | 5 | 6 \n----------\n 7 | 8 | 9 ",b1,c1,b2 );
							printf("\nPlayer 2 Turn (x): Please Select your box: ");
							scanf("%d",&y2);
							switch(y2){
								case 1:
									printf("Invalid Choice: Game Terminates: ");
									exit(0);
								case 2:
									printf("Invalid Choice: Game Terminates: ");
									exit(0);
								case 3:
									printf("Invalid Choice: Game Terminates: ");
									exit(0);
								case 4:
									c2='x';
									printf("\n %c | %c | %c \n----------\n %c | 5 | 6 \n----------\n 7 | 8 | 9 ",b1,c1,b2,c2 );
									printf("\nPlayer 1 Turn (o): Please Select your box: ");
									scanf("%d",&x3);
									switch(x3){
										case 1:
											printf("Invalid Choice: Game Terminates: ");
											exit(0);
										case 2:
											printf("Invalid Choice: Game Terminates: ");
											exit(0);
										case 3:
											printf("Invalid Choice: Game Terminates: ");
											exit(0);
										case 4:
											printf("Invalid Choice: Game Terminates: ");
											exit(0);
										case 5:
											b3='o';
											printf("\n %c | %c | %c \n----------\n %c | %c | 6 \n----------\n 7 | 8 | 9 ",b1,c1,b2,c2,b3 );
											printf("\nPlayer 2 Turn (x): Please Select your box: ");
											scanf("%d",&y3);
											switch(y3){
												case 1:
													printf("Invalid Choice: Game Terminates: ");
													exit(0);
												case 2:
													printf("Invalid Choice: Game Terminates: ");
													exit(0);
												case 3:
													printf("Invalid Choice: Game Terminates: ");
													exit(0);
												case 4:
													printf("Invalid Choice: Game Terminates: ");
													exit(0);
												case 5:
													printf("Invalid Choice: Game Terminates: ");
													exit(0);
												case 6:
													c3='x';
													printf("\n %c | %c | %c \n----------\n %c | %c | %c \n----------\n 7 | 8 | 9 ",b1,c1,b2,c2,b3,c3 );
													printf("\nPlayer 1 Turn (o): Please Select your box: ");
													scanf("%d",&x4);
													switch(x4){
														case 1:
															printf("Invalid Choice: Game Terminates: ");
															exit(0);
														case 2:
															printf("Invalid Choice: Game Terminates: ");
															exit(0);
														case 3:
															printf("Invalid Choice: Game Terminates: ");
															exit(0);
														case 4:
															printf("Invalid Choice: Game Terminates: ");
															exit(0);
														case 5:
															printf("Invalid Choice: Game Terminates: ");
															exit(0);
														case 6:
															printf("Invalid Choice: Game Terminates: ");
															exit(0);
														case 7:
															b4='o';
															printf("\n %c | %c | %c \n----------\n %c | %c | %c \n----------\n %c | 8 | 9 ",b1,c1,b2,c2,b3,c3,b4 );
															printf("\nPlayer 2 Turn (x): Please Select your box: ");
															scanf("%d",&y4);
															switch(y4){
																case 1:
																	printf("Invalid Choice: Game Terminates: ");
																	exit(0);
																case 2:
																	printf("Invalid Choice: Game Terminates: ");
																	exit(0);
																case 3:
																	printf("Invalid Choice: Game Terminates: ");
																	exit(0);
																case 4:
																	printf("Invalid Choice: Game Terminates: ");
																	exit(0);
																case 5:
																	printf("Invalid Choice: Game Terminates: ");
																	exit(0);
																case 6:
																	printf("Invalid Choice: Game Terminates: ");
																	exit(0);
																case 7:
																	printf("Invalid Choice: Game Terminates: ");
																	exit(0);
																case 8:
																	c4='x';
																	printf("\n %c | %c | %c \n----------\n %c | %c | %c \n----------\n %c | %c | 9 ",b1,c1,b2,c2,b3,c3,b4,c4 );
																	
																	printf("\nPlayer 1 Turn (o): Please Select your box: ");
																	scanf("%d",&x5);
																	switch(x5){
																		case 1:
																			printf("Invalid Choice: Game Terminates: ");
																			exit(0);
																		case 2:
																			printf("Invalid Choice: Game Terminates: ");
																			exit(0);
																		case 3:
																			printf("Invalid Choice: Game Terminates: ");
																			exit(0);
																		case 4:
																			printf("Invalid Choice: Game Terminates: ");
																			exit(0);
																		case 5:
																			printf("Invalid Choice: Game Terminates: ");
																			exit(0);
																		case 6:
																			printf("Invalid Choice: Game Terminates: ");
																			exit(0);
																		case 7:
																			printf("Invalid Choice: Game Terminates: ");
																			exit(0);
																		case 8:
																			printf("Invalid Choice: Game Terminates: ");
																			exit(0);
																		case 9:
																			b5='o';
																			
																			if(((b1=='o')&&(c1=='o')&&(b2=='o')) || ((c2=='o')&&(b3=='o')&&(c3=='o')) || ((b4=='o')&&(c4=='o')&&(b5=='o')) || ((b1=='o')&&(b3=='o')&&(b5=='0'))||((b2=='o')&&(b3=='o')&&(b4=='0'))){
																				printf("Player One Won: ");
																			}else if(((b1=='x')&&(c1=='x')&&(b2=='x')) || ((c2=='x')&&(b3=='x')&&(c3=='x')) || ((b4=='x')&&(c4=='x')&&(b5=='x')) || ((b1=='x')&&(b3=='x')&&(b5=='x'))||((b2=='x')&&(b3=='x')&&(b4=='x'))){
																				printf("Player One Won: ");
																			}else{
																				printf("**********Game Drawn***********");
																			}
																			
																			
																		
																	}
															
																	
															}
															
					
															
															
													}
													
										
											}
															
	
										
									}

							}
						
					}
					
			}
	
	
	}
	
	
	
	
}
