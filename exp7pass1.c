#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int main(){

    char label[10], opcode[10], operand[10], mneumonic[10];
    int locctr;

    FILE *fp1, *fp2, *fp3, *fp4;


    fp1 = fopen("input.txt","r");
    fp2 = fopen("mot.txt","r");
    fp3 = fopen("output.txt","w");
    fp4 = fopen("st.txt","w");


    fscanf(fp1, "%s %s %s \n",label, opcode, operand);
    fprintf(fp3, "%d %s %s %s \n",locctr, label, opcode, operand);
    fscanf(fp1, "%s %s %s \n",label, opcode, operand);
    fprintf(fp3, "%d %s %s %s \n",locctr, label, opcode, operand);


    while(strcmp(opcode,"END")!=0){
        if(strcmp(opcode,"DS")==0 || strcmp(opcode,"DC")==0){
            fprintf(fp4, "%s %d \n", label, locctr);
            fprintf(fp3, "%d %s %s %s \n",locctr, label, opcode, operand);
            locctr += 4;
        }
        else {
            fscanf(fp2,"%s\n", mneumonic);
            while(strcmp(mneumonic,"END")!=0){
                if(strcmp(opcode,mneumonic)==0){
                    locctr += 4;
                    break;
                }
                fscanf(fp2,"%s\n", mneumonic);
            }
            rewind(fp2)

        }
        fprintf(fp1,"%s %s %s", label, opcode, operand);
    }

    fprintf(fp3, "%d %s %s %s \n",locctr, label, opcode, operand);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);

    return 0;
}





















