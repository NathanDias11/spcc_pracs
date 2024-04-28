#include<stdio.h>
#include<string.h>

#define SUCCESS 1
#define FAILED 0


int E();
int Edash();
int T();
int Tdash();
int F();


const char *pt;
char grammer[64];

int main() {


    printf("Enter the expression");
    scanf("%s", grammer);

    pt=grammer;
    
    puts("\nInput\t\taction");

    if(E() && *pt == '\0'){
        puts("string parsed succesfully");
        return 0;
    }
    else {
        puts("Error in string parsing");
        return 1;
    }
}

int E() {

    printf("%-16s E -> T E'\n",pt);

    if(T()&&Edash()) {
        return SUCCESS;
    } else {
        return FAILED;
    }
}


int Edash() {

    if(*pt == '+'){
        printf("%-16s E' -> + T E'\n",pt);
        pt++;

        if(T()&&Edash()) {
            return SUCCESS;
        } else {
            return FAILED;
        }
    } else {
        printf("%-16s E' -> $\n",pt);
        return SUCCESS;
    }
}


int T() {

    printf("%-16s T -> F T'\n",pt);

    if(F()&&Tdash()) {
        return SUCCESS;
    } else {
        return FAILED;
    }
}


int Tdash() {

    if(*pt == '*'){
        printf("%-16s T' -> * F T'\n",pt);
        pt++;

        if(F()&&Tdash()) {
            return SUCCESS;
        } else {
            return FAILED;
        }
    } else {
        printf("%-16s T' -> $\n",pt);
        return SUCCESS;
    }
}


int F() {
    if(*pt == '('){
        printf("%-16s F' -> ( E )\n",pt);
        pt++;

        if(E()&& *pt == ')'){
            pt++;
            return SUCCESS;
        } else {
            return FAILED;
        }
    

    } else if (*pt == 'i'){
        printf("%-16s F -> i\n",pt);
        pt++;
        return SUCCESS;
    } else {
        return FAILED;
    }
}







