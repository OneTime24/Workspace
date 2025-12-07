// Cookie Problem!!!!!!
//done but need imp
#include <stdio.h>
int main(){


    int tot_cookies,nc_box,nb_cont;
    int full_bx,lf_bx,full_cnt,lf_cnt;
    printf("Enter Total number of cookies: ");
    scanf("%d",&tot_cookies);
    printf("Enter number of cookies in a box: ");
    scanf("%d",&nc_box);
    printf("Enter number of boxes in a container: ");
    scanf("%d",&nb_cont);

    full_bx=tot_cookies/nc_box;
    lf_bx=tot_cookies%nc_box;

    full_cnt=full_bx/nb_cont;
    lf_cnt=full_bx%nb_cont;


    printf("Number of Boxes Required to ship: %d",full_bx);
    printf("\nNumber of COntainers Required to ship: %d",full_cnt);

    printf("\nLeft over cookies : %d",lf_bx);
    printf("\nLeft over boxes: %d",lf_cnt);

    

}