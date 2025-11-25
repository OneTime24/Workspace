// 4*4 TIC TAC TOE GAME!

//50% COMPLETED!!!!!!!!!!

#include <stdio.h>
int main(){
    
    char arr[4][4];
    int turn=1;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            arr[i][j]='0';
        }
    }

    // for(int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         printf("%c ",arr[i][j]);
    //     }
    //     printf("\n");
    // }
    char name1[256];
    char name2[256];

    // printf("Enter Player 1 Name: ");
    // scanf("%[^\n]s",name1);

    // printf("\nEnter Player 2 Name: ");
    // scanf(" %[^\n]s",name2);
    printf("\nPlayer 1: X\t\t|\tPlayer 2: O");
    for(int i=0;i<8;i++){
        printf("\n___________________________________\n1\t|2\t|3\t4\n5\t|6\t|7\t8\n9\t|10\t|11\t12\n13\t|14\t|15\t16\n____________________________________________\n");
        int bx1=0;
        printf("Turn %d :",turn);
        printf("\nPlayer 1 : Select Box!\n");
        scanf("%d",&bx1);
        switch(bx1){            //PLAYER 1
            case 1:
                if(arr[0][0]=='0'){
                    arr[0][0]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 2:
                if(arr[0][1]=='0'){
                    arr[0][1]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 3:
                if(arr[0][2]=='0'){
                    arr[0][2]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 4:
                if(arr[0][3]=='0'){
                    arr[0][3]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 5:
                if(arr[1][0]=='0'){
                    arr[1][0]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 6:
                if(arr[1][1]=='0'){
                    arr[1][1]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 7:
                if(arr[1][2]=='0'){
                    arr[1][2]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 8:
                if(arr[1][3]=='0'){
                    arr[1][3]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 9:
                if(arr[2][0]=='0'){
                    arr[2][0]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 10:
                if(arr[2][1]=='0'){
                    arr[2][1]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 11:
                if(arr[2][2]=='0'){
                    arr[2][2]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 12:
                if(arr[2][3]=='0'){
                    arr[2][3]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 13:
                if(arr[3][0]=='0'){
                    arr[3][0]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 14:
                if(arr[3][1]=='0'){
                    arr[3][1]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 15:
                if(arr[3][2]=='0'){
                    arr[3][2]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 16:
                if(arr[3][3]=='0'){
                    arr[3][3]='X';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
        }
         if(turn>3){
            if(((arr[0][0]=='X')&&(arr[0][1]=='X')&&(arr[0][2]=='X')&&(arr[0][3]=='X'))||
                ((arr[1][0]=='X')&&(arr[1][1]=='X')&&(arr[1][2]=='X')&&(arr[1][3]=='X'))||
                ((arr[2][0]=='X')&&(arr[2][1]=='X')&&(arr[2][2]=='X')&&(arr[2][3]=='X'))||
                ((arr[3][0]=='X')&&(arr[3][1]=='X')&&(arr[3][2]=='X')&&(arr[3][3]=='X'))||
                ((arr[0][0]=='X')&&(arr[1][0]=='X')&&(arr[2][0]=='X')&&(arr[3][0]=='X')||
                (arr[0][1]=='X')&&(arr[1][1]=='X')&&(arr[2][1]=='X')&&(arr[3][1]=='X')||
                (arr[0][2]=='X')&&(arr[1][2]=='X')&&(arr[2][2]=='X')&&(arr[3][2]=='X')||
                (arr[0][3]=='X')&&(arr[1][3]=='X')&&(arr[2][3]=='X')&&(arr[3][3]=='X')||
                (arr[0][0]=='X')&&(arr[1][1]=='X')&&(arr[2][2]=='X')&&(arr[3][3]=='X')||
                (arr[0][3]=='X')&&(arr[1][2]=='X')&&(arr[2][1]=='X')&&(arr[3][0]=='X'))){
                    printf("\nPLAYER 1 WON : CONGRATULATIONS: ");
                    return 0;
                }
                if(((arr[0][0]=='O')&&(arr[0][1]=='O')&&(arr[0][2]=='O')&&(arr[0][3]=='O'))||
                ((arr[1][0]=='O')&&(arr[1][1]=='O')&&(arr[1][2]=='O')&&(arr[1][3]=='O'))||
                ((arr[2][0]=='O')&&(arr[2][1]=='O')&&(arr[2][2]=='O')&&(arr[2][3]=='O'))||
                ((arr[3][0]=='O')&&(arr[3][1]=='O')&&(arr[3][2]=='O')&&(arr[3][3]=='O'))||
                ((arr[0][0]=='O')&&(arr[1][0]=='O')&&(arr[2][0]=='O')&&(arr[3][0]=='O')||
                (arr[0][1]=='O')&&(arr[1][1]=='O')&&(arr[2][1]=='O')&&(arr[3][1]=='O')||
                (arr[0][2]=='O')&&(arr[1][2]=='O')&&(arr[2][2]=='O')&&(arr[3][2]=='O')||
                (arr[0][3]=='O')&&(arr[1][3]=='O')&&(arr[2][3]=='O')&&(arr[3][3]=='O')||
                (arr[0][0]=='O')&&(arr[1][1]=='O')&&(arr[2][2]=='O')&&(arr[3][3]=='O')||
                (arr[0][3]=='O')&&(arr[1][2]=='O')&&(arr[2][1]=='O')&&(arr[3][0]=='O'))){
                    printf("\nPLAYER 2 WON : CONGRATULATIONS: ");
                    return 0;
                }
        }
        int bx2=0;
        printf("Player 2 : Select Box!\n");
        scanf("%d",&bx2);
        switch(bx2){            //PLAYER 2
            case 1:
                if(arr[0][0]=='0'){
                    arr[0][0]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 2:
                if(arr[0][1]=='0'){
                    arr[0][1]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 3:
                if(arr[0][2]=='0'){
                    arr[0][2]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 4:
                if(arr[0][3]=='0'){
                    arr[0][3]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 5:
                if(arr[1][0]=='0'){
                    arr[1][0]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 6:
                if(arr[1][1]=='0'){
                    arr[1][1]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 7:
                if(arr[1][2]=='0'){
                    arr[1][2]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 8:
                if(arr[1][3]=='0'){
                    arr[1][3]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 9:
                if(arr[2][0]=='0'){
                    arr[2][0]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 10:
                if(arr[2][1]=='0'){
                    arr[2][1]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 11:
                if(arr[2][2]=='0'){
                    arr[2][2]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 12:
                if(arr[2][3]=='0'){
                    arr[2][3]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 13:
                if(arr[3][0]=='0'){
                    arr[3][0]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 14:
                if(arr[3][1]=='0'){
                    arr[3][1]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 15:
                if(arr[3][2]=='0'){
                    arr[3][2]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
            case 16:
                if(arr[3][3]=='0'){
                    arr[3][3]='O';
                }else{
                    printf("Not Available Try Another one: ");
                    return 0;
                }
                break;
        }

        turn++;
        if(turn>3){
            if(((arr[0][0]=='X')&&(arr[0][1]=='X')&&(arr[0][2]=='X')&&(arr[0][3]=='X'))||
                ((arr[1][0]=='X')&&(arr[1][1]=='X')&&(arr[1][2]=='X')&&(arr[1][3]=='X'))||
                ((arr[2][0]=='X')&&(arr[2][1]=='X')&&(arr[2][2]=='X')&&(arr[2][3]=='X'))||
                ((arr[3][0]=='X')&&(arr[3][1]=='X')&&(arr[3][2]=='X')&&(arr[3][3]=='X'))||
                ((arr[0][0]=='X')&&(arr[1][0]=='X')&&(arr[2][0]=='X')&&(arr[3][0]=='X')||
                (arr[0][1]=='X')&&(arr[1][1]=='X')&&(arr[2][1]=='X')&&(arr[3][1]=='X')||
                (arr[0][2]=='X')&&(arr[1][2]=='X')&&(arr[2][2]=='X')&&(arr[3][2]=='X')||
                (arr[0][3]=='X')&&(arr[1][3]=='X')&&(arr[2][3]=='X')&&(arr[3][3]=='X')||
                (arr[0][0]=='X')&&(arr[1][1]=='X')&&(arr[2][2]=='X')&&(arr[3][3]=='X')||
                (arr[0][3]=='X')&&(arr[1][2]=='X')&&(arr[2][1]=='X')&&(arr[3][0]=='X'))){
                    printf("\nPLAYER 1 WON : CONGRATULATIONS: ");
                    return 0;
                }
                if(((arr[0][0]=='O')&&(arr[0][1]=='O')&&(arr[0][2]=='O')&&(arr[0][3]=='O'))||
                ((arr[1][0]=='O')&&(arr[1][1]=='O')&&(arr[1][2]=='O')&&(arr[1][3]=='O'))||
                ((arr[2][0]=='O')&&(arr[2][1]=='O')&&(arr[2][2]=='O')&&(arr[2][3]=='O'))||
                ((arr[3][0]=='O')&&(arr[3][1]=='O')&&(arr[3][2]=='O')&&(arr[3][3]=='O'))||
                ((arr[0][0]=='O')&&(arr[1][0]=='O')&&(arr[2][0]=='O')&&(arr[3][0]=='O')||
                (arr[0][1]=='O')&&(arr[1][1]=='O')&&(arr[2][1]=='O')&&(arr[3][1]=='O')||
                (arr[0][2]=='O')&&(arr[1][2]=='O')&&(arr[2][2]=='O')&&(arr[3][2]=='O')||
                (arr[0][3]=='O')&&(arr[1][3]=='O')&&(arr[2][3]=='O')&&(arr[3][3]=='O')||
                (arr[0][0]=='O')&&(arr[1][1]=='O')&&(arr[2][2]=='O')&&(arr[3][3]=='O')||
                (arr[0][3]=='O')&&(arr[1][2]=='O')&&(arr[2][1]=='O')&&(arr[3][0]=='O'))){
                    printf("\nPLAYER 2 WON : CONGRATULATIONS: ");
                    return 0;
                }
        }

    }
        printf("GAME DRAWN: BYE:");

}