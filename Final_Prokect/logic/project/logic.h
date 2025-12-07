#ifndef LOGIC_H
#define LOGIC_H
#include <stdio.h>
float checkPlgText(char *txt1, char *txt2);
void sim_chek(char *s1, char *s2);
void removeCommentsAndHeaders(char *src, char *dest);
void removeKeywords(char *src, char *dest);
extern FILE *report_file;

#endif
