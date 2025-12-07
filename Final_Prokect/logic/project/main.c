#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "logic.h"

int main(){
    printf("\n========================================\n");
    printf("   PLAGIARISM CHECKER SYSTEM\n");
    printf("   FAST NUCES Peshawar\n");
    printf("========================================\n");

    while(1){
        printf("\n========================================\n");
        printf("           MAIN MENU\n");
        printf("========================================\n");
        printf("1. Text File Plagiarism Detection\n");
        printf("2. Code File Plagiarism Detection\n");
        printf("3. Exit\n");
        printf("========================================\n");

        int ch;
        printf("Select Option: ");
        scanf("%d",&ch);
        getchar(); // eats leftover '\n';

        if(ch==3) return 0;

        int n;
        printf("Enter number of files (2-20): ");
        scanf("%d",&n);
        if(n<2 || n>20){ printf("Invalid.\n"); continue; }

        char files[20][100];
        for(int i=0;i<n;i++){
            printf("Enter filename %d: ",i+1);
            scanf("%s",files[i]);
        }

        report_file = fopen("plagiarism_report.txt","a");
        fprintf(report_file,"========================================\n");
        fprintf(report_file,"   PLAGIARISM REPORT\n");
        fprintf(report_file,"========================================\n");

        if(ch==1){
            char *raw[20];
            char pre[20][5000];
            for(int i=0;i<n;i++){
                raw[i]=readFile(files[i]);
                if(!raw[i]) continue;
                preprocessText(raw[i],pre[i]);
            }
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    printf("\n--- Comparing %s and %s ---\n",files[i],files[j]);
                    fprintf(report_file,"Comparing: %s vs %s\n",files[i],files[j]);
                    float s = checkPlgText(pre[i],pre[j]);
                    printf("Similarity = %.2f%%\n",s);
                    fprintf(report_file,"Similarity Score: %.2f%%\n",s);
                }
            }
        }
        else if(ch==2){
            char *raw[20];
            char clean[20][5000];
            char nokey[20][5000];

            for(int i=0;i<n;i++){
                raw[i]=readFile(files[i]);
                removeCommentsAndHeaders(raw[i],clean[i]);
                removeKeywords(clean[i],nokey[i]);
            }
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    printf("\n--- Comparing %s and %s ---\n",files[i],files[j]);
                    fprintf(report_file,"Comparing: %s vs %s\n",files[i],files[j]);
                    sim_chek(nokey[i],nokey[j]);
                }
            }
        }
        fclose(report_file);
        printf("\nReport saved in plagiarism_report.txt\n");
    }
}
