#include <stdio.h>
#include <string.h>

int main() {

    while (1) {

        int inp;

        // --- Main Menu ---
        printf("\n1. New Game\n2. Game History by Player Name\n3. Show Statistics of Top Three\n4. Exit ");
        printf("\nSelect Option: ");
        scanf("%d", &inp);

        switch (inp) {

        //  NEW GAME 
        case 1: 
        {
            // open the log file in append mode
            FILE *fp = fopen("games_log.txt", "a");
            if (fp == NULL) {
                printf("Error opening file!\n");
                break;
            }

            // 4x4 tic tac toe board
            char arr[4][4];
            int turn = 0;

            // Initialize board with '-'
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    arr[i][j] = '-';
                }
            }

            char name1[256];
            char name2[256];

            // Take Player 1 name
            printf("Enter Player 1 Name: ");
            scanf(" %[^\n]s", name1);

            // Convert player1 name to uppercase
            for (int i = 0; name1[i] != '\0'; i++) {
                if (name1[i] >= 'a' && name1[i] <= 'z') {
                    name1[i] -= 32;
                }
            }

            // Take Player 2 name
            printf("\nEnter Player 2 Name: ");
            scanf(" %[^\n]s", name2);

            // Convert player2 name to uppercase
            for (int i = 0; name2[i] != '\0'; i++) {
                if (name2[i] >= 'a' && name2[i] <= 'z') {
                    name2[i] -= 32;
                }
            }

            printf("\nPlayer 1: X\t\t|\tPlayer 2: O\n");

            int gameOver = 0;

            // Maximum 8 turns (since each turn = P1 + P2 moves)
            for (int i = 0; i < 8; i++) {

                if (gameOver) break;

                turn++;
              // Display board with row/column numbers
                printf("   0 1 2 3\n");        // Column numbers
                for (int r = 0; r < 4; r++) {
                    printf("%d  ", r);        // Row number at left
                    for (int c = 0; c < 4; c++) {
                        printf("%c ", arr[r][c]);
                    }
                    printf("\n");
                }

                int a, b;

                // Player 1 move
                printf("Turn %d :", turn);
                printf("\nPlayer 1 : Select Box row and colon: ");
                scanf("%d %d", &a, &b);

                if (arr[a][b] == '-') arr[a][b] = 'X';
                else {
                    printf("Already taken! Choose another box!\n");
                    continue;   // re-ask same player's turn
                }

                // Check win conditions (Player 1)
                if (turn > 3) {
                    if (
                        ((arr[0][0]=='X')&&(arr[0][1]=='X')&&(arr[0][2]=='X')&&(arr[0][3]=='X')) ||
                        ((arr[1][0]=='X')&&(arr[1][1]=='X')&&(arr[1][2]=='X')&&(arr[1][3]=='X')) ||
                        ((arr[2][0]=='X')&&(arr[2][1]=='X')&&(arr[2][2]=='X')&&(arr[2][3]=='X')) ||
                        ((arr[3][0]=='X')&&(arr[3][1]=='X')&&(arr[3][2]=='X')&&(arr[3][3]=='X')) ||
                        ((arr[0][0]=='X')&&(arr[1][0]=='X')&&(arr[2][0]=='X')&&(arr[3][0]=='X')) ||
                        ((arr[0][1]=='X')&&(arr[1][1]=='X')&&(arr[2][1]=='X')&&(arr[3][1]=='X')) ||
                        ((arr[0][2]=='X')&&(arr[1][2]=='X')&&(arr[2][2]=='X')&&(arr[3][2]=='X')) ||
                        ((arr[0][3]=='X')&&(arr[1][3]=='X')&&(arr[2][3]=='X')&&(arr[3][3]=='X')) ||
                        ((arr[0][0]=='X')&&(arr[1][1]=='X')&&(arr[2][2]=='X')&&(arr[3][3]=='X')) ||
                        ((arr[0][3]=='X')&&(arr[1][2]=='X')&&(arr[2][1]=='X')&&(arr[3][0]=='X'))
                    ) 
                    {
                        printf("\nPLAYER 1 WON : CONGRATULATIONS!\n");
                        fprintf(fp, "%s,%s,%s,%d\n", name1, name2, name1, turn);
                        fclose(fp);
                        gameOver = 1;
                        break;
                    }
                }

                                    /// Display board with row/column numbers
                    printf("   0 1 2 3\n");        // Column numbers
                    for (int r = 0; r < 4; r++) {
                        printf("%d  ", r);        // Row number at left
                        for (int c = 0; c < 4; c++) {
                            printf("%c ", arr[r][c]);
                        }
                        printf("\n");
                    }


                int p, q;

                // Player 2 move
                printf("Turn %d :", turn);
                printf("\nPlayer 2: Select Box row and colon: ");
                scanf("%d %d", &p, &q);

                if (arr[p][q] == '-') arr[p][q] = 'O';
                else {
                    printf("Already taken! Choose another box!\n");
                    continue;
                }

                // Check win conditions (Player 2)
                if (turn > 3) {
                    if (
                        ((arr[0][0]=='O')&&(arr[0][1]=='O')&&(arr[0][2]=='O')&&(arr[0][3]=='O')) ||
                        ((arr[1][0]=='O')&&(arr[1][1]=='O')&&(arr[1][2]=='O')&&(arr[1][3]=='O')) ||
                        ((arr[2][0]=='O')&&(arr[2][1]=='O')&&(arr[2][2]=='O')&&(arr[2][3]=='O')) ||
                        ((arr[3][0]=='O')&&(arr[3][1]=='O')&&(arr[3][2]=='O')&&(arr[3][3]=='O')) ||
                        ((arr[0][0]=='O')&&(arr[1][0]=='O')&&(arr[2][0]=='O')&&(arr[3][0]=='O')) ||
                        ((arr[0][1]=='O')&&(arr[1][1]=='O')&&(arr[2][1]=='O')&&(arr[3][1]=='O')) ||
                        ((arr[0][2]=='O')&&(arr[1][2]=='O')&&(arr[2][2]=='O')&&(arr[3][2]=='O')) ||
                        ((arr[0][3]=='O')&&(arr[1][3]=='O')&&(arr[2][3]=='O')&&(arr[3][3]=='O')) ||
                        ((arr[0][0]=='O')&&(arr[1][1]=='O')&&(arr[2][2]=='O')&&(arr[3][3]=='O')) ||
                        ((arr[0][3]=='O')&&(arr[1][2]=='O')&&(arr[2][1]=='O')&&(arr[3][0]=='O'))
                    ) 
                    {
                        printf("\nPLAYER 2 WON : CONGRATULATIONS!\n");
                        fprintf(fp, "%s,%s,%s,%d\n", name1, name2, name2, turn);
                        fclose(fp);
                        gameOver = 1;
                        break;
                    }
                }
            }

            // Draw case
            if (!gameOver) {
                printf("GAME DRAWN!\n");
                fprintf(fp, "%s,%s,DRAW,%d\n", name1, name2, turn);
                fclose(fp);
            }

            break;
        }

        // =============================================================
        // =================== SEARCH GAME HISTORY ======================
        // =============================================================
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

            // Input search name
            printf("Enter Player Name to Search: ");
            scanf(" %[^\n]s", searchName);

            // Convert search name to uppercase
            for (int i = 0; searchName[i] != '\0'; i++) {
                if (searchName[i] >= 'a' && searchName[i] <= 'z') {
                    searchName[i] -= 32;
                }
            }

            printf("\nPLAYER 1 | PLAYER 2 | WINNER | TURNS\n");
            printf("--------------------------------------\n");

            // Read each record from file
            while (fscanf(fp2, "%[^,],%[^,],%[^,],%d\n", p1, p2, win, &turns) != EOF) {

                // Make uppercase clones of names
                char p1u[256], p2u[256];
                strcpy(p1u, p1);
                strcpy(p2u, p2);

                for (int i = 0; p1u[i] != '\0'; i++)
                    if (p1u[i] >= 'a' && p1u[i] <= 'z') p1u[i] -= 32;

                for (int i = 0; p2u[i] != '\0'; i++)
                    if (p2u[i] >= 'a' && p2u[i] <= 'z') p2u[i] -= 32;

                // Match found
                if (strcmp(p1u, searchName) == 0 || strcmp(p2u, searchName) == 0) {
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

        case 3:
            {
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
                    // UPDATE PLAYER 1
                    int index1 = -1;
                    for (int i = 0; i < count; i++) {
                        if (strcmp(players[i], p1) == 0) {
                            index1 = i;
                            break;
                        }
                    }
                    if (index1 == -1) {
                        strcpy(players[count], p1);
                        games[count] = 1;
                        winsArr[count] = (strcmp(p1, win) == 0) ? 1 : 0;
                        count++;
                    } else {
                        games[index1]++;
                        if (strcmp(p1, win) == 0)
                            winsArr[index1]++;
                    }

                    // UPDATE PLAYER 2
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
                    } else {
                        games[index2]++;
                        if (strcmp(p2, win) == 0)
                            winsArr[index2]++;
                    }
                }

                fclose(fp3);

                // Sort by wins (descending bubble sort)
                for (int i = 0; i < count - 1; i++) {
                    for (int j = 0; j < count - i - 1; j++) {
                        if (winsArr[j] < winsArr[j + 1]) {
                            int temp = winsArr[j];
                            winsArr[j] = winsArr[j + 1];
                            winsArr[j + 1] = temp;

                            temp = games[j];
                            games[j] = games[j + 1];
                            games[j + 1] = temp;

                            char tmpName[256];
                            strcpy(tmpName, players[j]);
                            strcpy(players[j], players[j + 1]);
                            strcpy(players[j + 1], tmpName);
                        }
                    }
                }

                printf("\n===== TOP 3 Players =====\n");
                int limit = (count < 3) ? count : 3;
                for (int i = 0; i < limit; i++) {
                    printf("%d. %s  | Games: %d | Wins: %d\n",
                           i + 1, players[i], games[i], winsArr[i]);
                }
                break;
            }

            case 4:
                printf("Exiting | Goodbye...\n");
                return 0;

            default:
                printf("Enter a valid Option: Retry!\n");
        }
    }
      
}
