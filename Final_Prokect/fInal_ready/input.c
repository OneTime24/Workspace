#include "plagiarism.h"


int check_f(char *fn) {         // to check if file is ok
    FILE *f = fopen(fn, "r");       // open the fn that points to d which points to converted text in r mode
    if (!f){        // if failed to open file? return 0 which means false
    return 0;
    }
    fseek(f, 0, SEEK_END);          // if file opened, then move the cursor to the end of the converted file!
    long sz = ftell(f);                 //ftell() tells us the position or location of the cursor in a file, since it is char type and 1 char = 1 byte, so a way to find text size
    fclose(f);          // close the file
    if (sz>0){              // basically we did that to check if conversion is properly done or not!
    return 1;   // return 1 if successful
    }
    return 0;       //return 0 otherwise
}


void to_txt(char *s,char *d) {     // convert pdf or docx,
    // using xpdf for windpws || docxtxt for linux && pdftotxt for linux and windows
    
    char cmd[512];              // a char array to store the command that we will be passing to the console using system     

    int ret = -1;    //flag   

    if (strstr(s, ".pdf")) {        // checking if passed file name contains .pdf
        // command to run pdftotext
        #ifdef _WIN32               // If Operating System is Windows
            sprintf(cmd, "pdftotext \"%s\" \"%s\" > NUL 2>&1", s, d);          // write this formatted text/values/string in cmd array
        #else
                                    //If Operating System is Linux
            sprintf(cmd, "pdftotext \"%s\" \"%s\" > /dev/null 2>&1", s, d);         // write this formatted text/values/string in cmd array
        #endif
        
        
        ret = system(cmd);      // pasing cmd value to system or console, it will return 0 if successful conversion!
        // after conversion, the converted text is being pointed by char *d pointer, d here is used for destination, and s for source
        if (ret != 0 || !check_f(d)) {              //Checking if conversion is successfull or not
            printf("Error: PDF convert fail for %s\n", s); 
        }
    }
    else if (strstr(s, ".docx")) {      // checking if passed file name contains .docx
        #ifdef _WIN32        // If Operating System is Windows
            sprintf(cmd, "docx2txt \"%s\" \"%s\" > NUL 2>&1", s, d);            // write this formatted text/values/string in cmd array
        #else                           //If Operating System is Windows
            sprintf(cmd, "docx2txt < \"%s\" > \"%s\" 2> /dev/null", s, d);          // write this formatted text/values/string in cmd array
        #endif

        ret = system(cmd);              // pasing cmd value to system or console, it will return 0 if successful conversion!
        // after conversion, the converted text is being pointed by char *d pointer, d here is used for destination, and s for source

        if (ret != 0 || !check_f(d)) {      //Checking if conversion is successfull or not
             printf("Error: DOCX convert fail for %s\n", s);
        }
    }
}

// main read function
char* read_f(char *fname) {
    char tmp[] = "temp_conv.txt";
    char *target = fname;           // a pointer that points to fname pointer
    int conv = 0;          // flag

    if (strstr(fname, ".pdf") || strstr(fname, ".docx")) {          // check if we need conversion    
        remove(tmp);                        // delete old temp
        to_txt(fname, tmp);         // passing fname, and tmp to to_txt for conversion if file type is docx or pdf
        
        if (check_f(tmp)) {             // checking again if conversion and passed by reference got the correct address of the file
            target = tmp;   //target will now point to that converted file if the file was pdf or docx, as well as txt
            conv = 1;           // a flag to show succeesful operation
        } else {
            return NULL; 
        }
    }


    FILE *fp = fopen(target, "r");          // fp pointer which points to target which points to the converted file which is being opened in read mode

    if (!fp) {      // If failed to open the file
        printf("Cannot open %s\n", target);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);     // otherwise move the cursor to the end
    long l = ftell(fp);         // read the file size
    rewind(fp);                     // rewind moves back the cursor to the start of the file
    

    char *buf = (char*)malloc(l + 10);          //Using simple malloc to stay safe and increase the size of buf pointer dynamically by +10
    fread(buf, 1, l, fp);   // fread reads the whole program at once, it will read till NULL
    buf[l] = '\0';      // adding \0 in the end to termnate the file
    
    fclose(fp);     // close the file
    
    if (conv) {                 // that flag is being used here, after each successfull conversion
        remove(tmp);                //remove the tmp file
    }
    
    return buf;    //the read_f function will return the buf, which returns the address to the converted file(txt,pdf or docx).
}