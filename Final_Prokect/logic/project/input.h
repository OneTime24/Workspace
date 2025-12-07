#ifndef INPUT_H
#define INPUT_H

char* readFile(char *filename);
void preprocessText(char *src, char *dest);
void convertToText(const char *src, const char *out);
void extractTextFromPDF(const char *filename, const char *output);

#endif
