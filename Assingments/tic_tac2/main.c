// 4*4 TIC TAC TOE GAME!

//100% COMPLETED!!!!!!!!!!

#include <stdio.h>
#include <string.h>
int main(){
    
    while(1){

        int inp;
        printf("\n1. New Game\n2. Game History by Player Name\n3. Show Statistics of Top Three\n4. Exit ");
         printf("\nSelect Option: ");
         scanf("%d",&inp);

    switch(inp){

    case 1:
    {
        FILE *fp = fopen("games_log.txt", "a");  // Open in append mode
        if (fp == NULL) {
            printf("Error opening file!\n");
            break;
        }
        char arr[4][4];
        int turn=0;
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

        printf("Enter Player 1 Name: ");
        scanf(" %[^\n]s",name1);
        
        // Convert name1 to uppercase
        for (int i = 0; name1[i] != '\0'; i++) {
            if (name1[i] >= 'a' && name1[i] <= 'z') {
                name1[i] -= 32;
            }
        }

        printf("\nEnter Player 2 Name: ");
        scanf(" %[^\n]s",name2);
        
        // Convert name2 to uppercase
        for (int i = 0; name2[i] != '\0'; i++) {
            if (name2[i] >= 'a' && name2[i] <= 'z') {
                name2[i] -= 32;
            }
        }
        
        printf("\nPlayer 1: X\t\t|\tPlayer 2: O\n");
        int gameOver = 0;
        for(int i=0;i<8;i++){
            if(gameOver) break;
            turn++;
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    printf("%c ",arr[j][k]);
                }
                printf("\n");
            }
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
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 2:
                    if(arr[0][1]=='0'){
                        arr[0][1]='X';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 3:
                    if(arr[0][2]=='0'){
                        arr[0][2]='X';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 4:
                    if(arr[0][3]=='0'){
                        arr[0][3]='X';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 5:
                    if(arr[1][0]=='0'){
                        arr[1][0]='X';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 6:
                    if(arr[1][1]=='0'){
                        arr[1][1]='X';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 7:
                    if(arr[1][2]=='0'){
                        arr[1][2]='X';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 8:
                    if(arr[1][3]=='0'){
                        arr[1][3]='X';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 9:
                    if(arr[2][0]=='0'){
                        arr[2][0]='X';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 10:
                    if(arr[2][1]=='0'){
                        arr[2][1]='X';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 11:
                    if(arr[2][2]=='0'){
                        arr[2][2]='X';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 12:
                    if(arr[2][3]=='0'){
                        arr[2][3]='X';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 13:
                    if(arr[3][0]=='0'){
                        arr[3][0]='X';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 14:
                    if(arr[3][1]=='0'){
                        arr[3][1]='X';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 15:
                    if(arr[3][2]=='0'){
                        arr[3][2]='X';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 16:
                    if(arr[3][3]=='0'){
                        arr[3][3]='X';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
            }
            if(gameOver) break;
            if(turn>3){
                if(((arr[0][0]=='X')&&(arr[0][1]=='X')&&(arr[0][2]=='X')&&(arr[0][3]=='X'))||
                    ((arr[1][0]=='X')&&(arr[1][1]=='X')&&(arr[1][2]=='X')&&(arr[1][3]=='X'))||
                    ((arr[2][0]=='X')&&(arr[2][1]=='X')&&(arr[2][2]=='X')&&(arr[2][3]=='X'))||
                    ((arr[3][0]=='X')&&(arr[3][1]=='X')&&(arr[3][2]=='X')&&(arr[3][3]=='X'))||
                    ((arr[0][0]=='X')&&(arr[1][0]=='X')&&(arr[2][0]=='X')&&(arr[3][0]=='X'))||
                    ((arr[0][1]=='X')&&(arr[1][1]=='X')&&(arr[2][1]=='X')&&(arr[3][1]=='X'))||
                    ((arr[0][2]=='X')&&(arr[1][2]=='X')&&(arr[2][2]=='X')&&(arr[3][2]=='X'))||
                    ((arr[0][3]=='X')&&(arr[1][3]=='X')&&(arr[2][3]=='X')&&(arr[3][3]=='X'))||
                    ((arr[0][0]=='X')&&(arr[1][1]=='X')&&(arr[2][2]=='X')&&(arr[3][3]=='X'))||
                    ((arr[0][3]=='X')&&(arr[1][2]=='X')&&(arr[2][1]=='X')&&(arr[3][0]=='X'))){
                        printf("\nPLAYER 1 WON : CONGRATULATIONS: ");
                        fprintf(fp,"%s,%s,%s,%d\n",name1,name2,name1,turn);
                        fclose(fp);
                        gameOver=1;
                        break;
                    }
                    if(((arr[0][0]=='O')&&(arr[0][1]=='O')&&(arr[0][2]=='O')&&(arr[0][3]=='O'))||
                    ((arr[1][0]=='O')&&(arr[1][1]=='O')&&(arr[1][2]=='O')&&(arr[1][3]=='O'))||
                    ((arr[2][0]=='O')&&(arr[2][1]=='O')&&(arr[2][2]=='O')&&(arr[2][3]=='O'))||
                    ((arr[3][0]=='O')&&(arr[3][1]=='O')&&(arr[3][2]=='O')&&(arr[3][3]=='O'))||
                    ((arr[0][0]=='O')&&(arr[1][0]=='O')&&(arr[2][0]=='O')&&(arr[3][0]=='O'))||
                    ((arr[0][1]=='O')&&(arr[1][1]=='O')&&(arr[2][1]=='O')&&(arr[3][1]=='O'))||
                    ((arr[0][2]=='O')&&(arr[1][2]=='O')&&(arr[2][2]=='O')&&(arr[3][2]=='O'))||
                    ((arr[0][3]=='O')&&(arr[1][3]=='O')&&(arr[2][3]=='O')&&(arr[3][3]=='O'))||
                    ((arr[0][0]=='O')&&(arr[1][1]=='O')&&(arr[2][2]=='O')&&(arr[3][3]=='O'))||
                    ((arr[0][3]=='O')&&(arr[1][2]=='O')&&(arr[2][1]=='O')&&(arr[3][0]=='O'))){
                        printf("\nPLAYER 2 WON : CONGRATULATIONS: ");
                        fprintf(fp,"%s,%s,%s,%d\n",name1,name2,name2,turn);
                        fclose(fp);
                        gameOver=1;
                        break;
                    }
            }
            int bx2=0;
            for(int j=0;j<4;j++){
                for(int k=0;k<4;k++){
                    printf("%c ",arr[j][k]);
                }
                printf("\n");
            }
            printf("Player 2 : Select Box!\n");
            scanf("%d",&bx2);
            switch(bx2){            //PLAYER 2
                case 1:
                    if(arr[0][0]=='0'){
                        arr[0][0]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 2:
                    if(arr[0][1]=='0'){
                        arr[0][1]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 3:
                    if(arr[0][2]=='0'){
                        arr[0][2]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 4:
                    if(arr[0][3]=='0'){
                        arr[0][3]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 5:
                    if(arr[1][0]=='0'){
                        arr[1][0]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 6:
                    if(arr[1][1]=='0'){
                        arr[1][1]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 7:
                    if(arr[1][2]=='0'){
                        arr[1][2]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 8:
                    if(arr[1][3]=='0'){
                        arr[1][3]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 9:
                    if(arr[2][0]=='0'){
                        arr[2][0]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 10:
                    if(arr[2][1]=='0'){
                        arr[2][1]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 11:
                    if(arr[2][2]=='0'){
                        arr[2][2]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 12:
                    if(arr[2][3]=='0'){
                        arr[2][3]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 13:
                    if(arr[3][0]=='0'){
                        arr[3][0]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 14:
                    if(arr[3][1]=='0'){
                        arr[3][1]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 15:
                    if(arr[3][2]=='0'){
                        arr[3][2]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
                case 16:
                    if(arr[3][3]=='0'){
                        arr[3][3]='O';
                    }else{
                        printf("Not Available Try Another one: ");
                        fclose(fp);
                        gameOver=1;
                    }
                    break;
            }

            if(gameOver) break;
            if(turn>3){
                if(((arr[0][0]=='X')&&(arr[0][1]=='X')&&(arr[0][2]=='X')&&(arr[0][3]=='X'))||
                    ((arr[1][0]=='X')&&(arr[1][1]=='X')&&(arr[1][2]=='X')&&(arr[1][3]=='X'))||
                    ((arr[2][0]=='X')&&(arr[2][1]=='X')&&(arr[2][2]=='X')&&(arr[2][3]=='X'))||
                    ((arr[3][0]=='X')&&(arr[3][1]=='X')&&(arr[3][2]=='X')&&(arr[3][3]=='X'))||
                    ((arr[0][0]=='X')&&(arr[1][0]=='X')&&(arr[2][0]=='X')&&(arr[3][0]=='X'))||
                    ((arr[0][1]=='X')&&(arr[1][1]=='X')&&(arr[2][1]=='X')&&(arr[3][1]=='X'))||
                    ((arr[0][2]=='X')&&(arr[1][2]=='X')&&(arr[2][2]=='X')&&(arr[3][2]=='X'))||
                    ((arr[0][3]=='X')&&(arr[1][3]=='X')&&(arr[2][3]=='X')&&(arr[3][3]=='X'))||
                    ((arr[0][0]=='X')&&(arr[1][1]=='X')&&(arr[2][2]=='X')&&(arr[3][3]=='X'))||
                    ((arr[0][3]=='X')&&(arr[1][2]=='X')&&(arr[2][1]=='X')&&(arr[3][0]=='X'))){
                        printf("\nPLAYER 1 WON : CONGRATULATIONS: ");
                        fprintf(fp,"%s,%s,%s,%d\n",name1,name2,name1,turn);
                        fclose(fp);
                        gameOver=1;
                        break;
                    }
                    if(((arr[0][0]=='O')&&(arr[0][1]=='O')&&(arr[0][2]=='O')&&(arr[0][3]=='O'))||
                    ((arr[1][0]=='O')&&(arr[1][1]=='O')&&(arr[1][2]=='O')&&(arr[1][3]=='O'))||
                    ((arr[2][0]=='O')&&(arr[2][1]=='O')&&(arr[2][2]=='O')&&(arr[2][3]=='O'))||
                    ((arr[3][0]=='O')&&(arr[3][1]=='O')&&(arr[3][2]=='O')&&(arr[3][3]=='O'))||
                    ((arr[0][0]=='O')&&(arr[1][0]=='O')&&(arr[2][0]=='O')&&(arr[3][0]=='O'))||
                    ((arr[0][1]=='O')&&(arr[1][1]=='O')&&(arr[2][1]=='O')&&(arr[3][1]=='O'))||
                    ((arr[0][2]=='O')&&(arr[1][2]=='O')&&(arr[2][2]=='O')&&(arr[3][2]=='O'))||
                    ((arr[0][3]=='O')&&(arr[1][3]=='O')&&(arr[2][3]=='O')&&(arr[3][3]=='O'))||
                    ((arr[0][0]=='O')&&(arr[1][1]=='O')&&(arr[2][2]=='O')&&(arr[3][3]=='O'))||
                    ((arr[0][3]=='O')&&(arr[1][2]=='O')&&(arr[2][1]=='O')&&(arr[3][0]=='O'))){
                        printf("\nPLAYER 2 WON : CONGRATULATIONS: ");
                        fprintf(fp,"%s,%s,%s,%d\n",name1,name2,name2,turn);
                        fclose(fp);
                        gameOver=1;
                        break;
                    }
            }
        }
        if(!gameOver){
            printf("GAME DRAWN: BYE:");
            fprintf(fp,"%s,%s,DRAW,%d\n",name1,name2,turn);
            fclose(fp);
        }
        break;
    }
        case 2:
{
    FILE *fp2 = fopen("games_log.txt", "r");
    if (fp2 == NULL) {
        printf("No game history found!\n");
        break;
    }

    char searchName[256];
    char p1[256], p2[256], win[256];
    int turns;
    int found = 0;

    printf("Enter Player Name to Search: ");
    scanf(" %[^\n]s", searchName);

    // Convert searchName to uppercase
    for (int i = 0; searchName[i] != '\0'; i++) {
        if (searchName[i] >= 'a' && searchName[i] <= 'z') {
            searchName[i] -= 32;
        }
    }

    printf("\nPLAYER 1 | PLAYER 2 | WINNER | TURNS\n");
    printf("--------------------------------------\n");

    while (fscanf(fp2, "%[^,],%[^,],%[^,],%d\n", p1, p2, win, &turns) != EOF) {

        // Convert each name read from file to uppercase (temporary check copies)
        char p1u[256], p2u[256];

        for (int i = 0; i < 256; i++) {
            p1u[i] = p1[i];
            p2u[i] = p2[i];
        }

        // Convert to uppercase
        for (int i = 0; p1u[i] != '\0'; i++) {
            if (p1u[i] >= 'a' && p1u[i] <= 'z') p1u[i] -= 32;
        }
        for (int i = 0; p2u[i] != '\0'; i++) {
            if (p2u[i] >= 'a' && p2u[i] <= 'z') p2u[i] -= 32;
        }

        // Compare with searchName
        if ((strcmp(p1u, searchName) == 0) || (strcmp(p2u, searchName) == 0)) {

            printf("%s | %s | %s | %d\n", p1, p2, win, turns);
            found = 1;
        }
    }

    fclose(fp2);

    if (!found) {
        printf("\nNO RECORD FOUND FOR THIS PLAYER!\n");
    }

    break;
}

case 3: {
    FILE *fp3 = fopen("games_log.txt", "r");
    if (!fp3) {
        printf("No history file found.\n");
        break;
    }

    char p1[256], p2[256], win[256];
    int turns;

    char players[200][256];
    int games[200];
    int winsArr[200];
    int count = 0;

    while (fscanf(fp3, "%[^,],%[^,],%[^,],%d\n", p1, p2, win, &turns) != EOF) {

        // ---------- UPDATE PLAYER 1 ----------
        int index1 = -1;
        for (int i = 0; i < count; i++) {
            if (strcmp(players[i], p1) == 0) {
                index1 = i;
                break;
            }
        }
        if (index1 == -1) {   // new player
            strcpy(players[count], p1);
            games[count] = 1;
            winsArr[count] = (strcmp(p1, win) == 0) ? 1 : 0;
            count++;
        }
        else {
            games[index1]++;
            if (strcmp(p1, win) == 0)
                winsArr[index1]++;
        }

        // ---------- UPDATE PLAYER 2 ----------
        int index2 = -1;
        for (int i = 0; i < count; i++) {
            if (strcmp(players[i], p2) == 0) {
                index2 = i;
                break;
            }
        }
        if (index2 == -1) {
            strcpy(players[count], p2);
            games[count] = 1;
            winsArr[count] = (strcmp(p2, win) == 0) ? 1 : 0;
            count++;
        }
        else {
            games[index2]++;
            if (strcmp(p2, win) == 0)
                winsArr[index2]++;
        }
    }

    fclose(fp3);

    // --- SORT BY WINS (descending bubble sort) ---
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (winsArr[j] < winsArr[j + 1]) {
                // swap wins
                int temp = winsArr[j];
                winsArr[j] = winsArr[j + 1];
                winsArr[j + 1] = temp;

                // swap games
                temp = games[j];
                games[j] = games[j + 1];
                games[j + 1] = temp;

                // swap names
                char tmpName[256];
                strcpy(tmpName, players[j]);
                strcpy(players[j], players[j + 1]);
                strcpy(players[j + 1], tmpName);
            }
        }
    }

    // ---------- SHOW TOP 3 ----------
    printf("\n===== TOP 3 PLAYERS =====\n");
    int limit = (count < 3) ? count : 3;
    for (int i = 0; i < limit; i++) {
        printf("%d. %s  | Games: %d | Wins: %d\n",
               i + 1, players[i], games[i], winsArr[i]);
    }

    break;
}
case 4:
    printf("Exiting...\n");
    return 0;

}
}
}