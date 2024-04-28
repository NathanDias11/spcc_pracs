#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int main(){

    char label[10], opcode[10], operand[10], mneumonic[10],locctr[10],mlabel[10];
    

    FILE *fp1, *fp2, *fp3, *fp4, *fp5;


    fp1 = fopen("input.txt","r");
    fp2 = fopen("mot.txt","r");
    fp3 = fopen("output.txt","r");
    fp4 = fopen("outTable.txt","w");
    fp5 = fopen("bt.txt","w");


    fscanf(fp1, "%s %s %s %s \n",locctr, label, opcode, operand);
    fscanf(fp1, "%s %s %s %s \n",locctr, label, opcode, operand);
    fprintf(fp5, "Y %c%c  00 00 00 ",operand[2],operand[3]);
    fprintf(fp3, "%s %s %s %s \n",locctr, label, opcode, operand);


    while(strcmp(opcode,"END")!=0){
        if(strcmp(opcode,"DC")==0){
            fprintf(fp4,"%s\t%c",locctr, operand[2])
        } 
        else if (strcmp(opcode,"DS")==0){
            fprint(fp4, "%s\t\n",locctr);
        }
        else {
            fscanf(fp2,"%s %s\n", mneumonic, mlabel);
            while(strcmp(mneumonic,"END")!=0){
                if(strcmp(opcode,mneumonic)==0){
                    fprintf(fp4, "%s\t%s\n", mlabel, operand);
                    break;
                }
                fscanf(fp2,"%s %s\n", mneumonic, mlabel);
            }
            rewind(fp2)

        }
        printf(fp3,"%s %s %s %s",locctr, label, opcode, operand);
    }

    
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);

    return 0;
}





















