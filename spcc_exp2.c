#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    // this is input file 
    FILE *input = fopen("input1.txt", "r");
    FILE *output = fopen("output2.txt", "w");


    if(input == NULL || output == NULL){
        printf("Error opening file\n");
        return 1;
    }

    int lineNumber=1;
    int tokenNumber=0;

    const char *keywords[] = {
        "int","main","char","exit","if","else","do","while","scanf","malloc"
    };


    fprintf(output, "Line no \t token no \t token type \t value");


    char ch;
    char str[20];
    int i;

    while((ch = fgetc(input)) != EOF) {
        if(ch = '\n'){
            lineNumber++;
        }else if (strchr("+-*/",ch)){
            fprintf(output, "%d\t\t%d\t\toperator\t\t%c\n", lineNumber, tokenNumber++, ch);
        }else if (strchr("!@#$&(){};",ch)){
            fprintf(output, "%d\t\t%d\t\tSpecial Symbols\t\t%c\n", lineNumber, tokenNumber++, ch);
        }else if (isdigit(ch)){
            fprintf(output, "%d\t\t%d\t\tConstant\t\t%c\n", lineNumber, tokenNumber++, ch);
        }else if (isalpha(ch)){
            i=0;
            str[i++]=ch;
            while(isalnum((ch = fgetc(input)))&& ch != ' '){
                str[i++]=ch;
            }
            str[i]='\0';

            int iskeyword = 0;
            for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
                if (strcmp(str, keywords[i]) == 0) {
                    iskeyword = 1; // It's a keyword
                    break;
                }
                
            }

            if(iskeyword){
                fprintf(output,"%d\t\t%d\t\tKeyword\t\t%c", lineNumber, tokenNumber++, str);
            }else{
                fprintf(output,"%d\t\t%d\t\tIdentifier\t\t%c", lineNumber, tokenNumber++, str);
            }
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}    






















