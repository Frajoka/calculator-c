#include <stdio.h>

#define GRN "\e[0;32m"
#define WHT "\e[0;37m"

//Variaveis Globais
int step=0;
int numeros[2]={0,0};
char funcao;
int resultado;
char decisao;

//Metodos
int getInput(char* text){

    int numero;

    printf(text);
    scanf("%d",&numero);

    return numero;
};
char getFuncao(char* text){
    char fun;

    printf(text);
    scanf("%s",&fun);

    return fun;
};
int soma(int num1, int num2){
    return num1+num2;
};

int subtrai(int num1, int num2){
    return num1-num2;
};

int multiplica(int num1, int num2){
    return num1*num2;
};

int divide(int num1, int num2){
    return num1/num2;
};

void createUI(){
    //21 Caractéres
    printf("==== CALCULADORA ====\n");

    if(step==0){
        printf(GRN);
    }
    else{
        printf(WHT);
    };
    printf("Digite o 1 Numero;\nDepois;\n");

    if(step==1){
        printf(GRN);
    }
    else{
        printf(WHT);
    };
    printf("Digite o 2 Numero;\nDepois;\n");

    if(step==2){
        printf(GRN);
    }
    else{
        printf(WHT);
    };
    printf("(+)SOMAR ou\n(-)SUBTRAIR ou\n(*)MULTIPLICAR ou\n(/)DIVIDIR\n");
    printf(WHT);
    return;
};

int recognize(char c){
    int ret;
    switch(c){
        case '+':
            ret=soma(numeros[0],numeros[1]);
            break;
        case '-':
            ret=subtrai(numeros[0],numeros[1]);
            break;
        case '*':
            ret=multiplica(numeros[0],numeros[1]);
            break;
        case '/':
            ret=divide(numeros[0],numeros[1]);
            break;
        default:
            ret=0;
    };
    return ret;
};

void main(){
    for (int i = 0; i < 8; i++){
        createUI();
        numeros[0]=getInput(">>");
        step++;
        
        createUI();
        numeros[1]=getInput(">>");
        step++;
        
        createUI();
        funcao=getFuncao(">>");

        resultado=recognize(funcao);

        printf("Resultado=%d \n",resultado);
        printf("Pressione 'S' para Continuar\n ou 'N' para fechar a Aplicação.\n>>");

        scanf("%s",&decisao);
        if(decisao == 'n' || decisao == 'N'){
            break;
        };
    };
    printf(GRN);
    printf("Obrigado por Usar!!");
    printf(WHT);
    return;
};