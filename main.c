#include <stdio.h>
#include <stdlib.h>

char matrix[3][3]={"abc", "def", "ghi"};
int human=0,comp=0,player1=0,player2=0;

void HVC(void);
void HCH(void);
void reset(void);
void input(char);
void input2(char);
void computer(void);
void tampil(void);
int pengecekan(char);
int menang(void);

int main()
{
    int pilih;
    char jawab;
    do{
        printf("\tTIC TAC TOE\n");
        printf("===========================\n");
        printf("1. HUMAN VS COM\n");
        printf("2. HUMAN VS HUMAN\n");
        printf("Masukkan pilihan anda : ");
        scanf("%d",&pilih);
        if(pilih==1)
            HVC();
        else if(pilih==2)
            HVH();
        else
            printf("Pilihan tidak tersedia.");
        reset();
        printf("\nApakah akan bermain lagi [Y/T]? ");
        fflush(stdin);
        jawab=getchar();
    }while(jawab=='Y' || jawab =='y');
}

void HVC(void)
{
    char zona;
    printf("Human VS AI Computer\n\n");
    tampil();
    do{
        fflush(stdin);
        printf("\nMasukkan lokasi : ");
        scanf("%c",&zona);
        while(pengecekan(zona)==1 )
        {
            printf("Lokasi sudah terisi atau tidak ada.\n");
            fflush(stdin);
            printf("Masukkan lokasi : ");
            scanf("%c",&zona);
        }
        input(zona);
        if(menang()!=0){
            tampil();
            break;
            }
        computer();
        printf("\n");
        tampil();
    }while(menang()==0);
    if(menang()==1){
        printf("\nHuman Win.\n");
        human++;
    }
    else if(menang()==2){
        printf("\nComputer Win.\n");
        comp++;
    }
    else if(menang()==3)
        printf("\nSeri.\n");
    printf("============================");
    printf("\nHuman : %d\tComputer : %d\n",human,comp);
    printf("============================\n");
}

void HVH(void)
{
    char zona;
    printf("Player 1 VS Player 2\n");
    do{
        printf("\n'X' Player 1 Turn\n\n");
        tampil();
        fflush(stdin);
        printf("\nMasukkan lokasi : ");
        scanf("%c",&zona);
        while(pengecekan(zona)==1)
        {
            printf("Lokasi sudah terisi atau tidak ada.\n");
            fflush(stdin);
            printf("\nMasukkan loksi : ");
            scanf("%c",&zona);
        }
        input(zona);
        if(menang()!=0)
            break;
        printf("\n'O' Player 2 Turn\n\n");
        tampil();
        fflush(stdin);
        printf("\nMasukkan lokasi : ");
        scanf("%c",&zona);
        while(pengecekan(zona)==1)
        {
            printf("Lokasi sudah terisi atau tidak ada.\n");
            fflush(stdin);
            printf("\nMasukkan lokasi : ");
            scanf("%c",&zona);
        }
        input2(zona);
        if(menang()!=0)
            break;
    }while(menang()==0);
    tampil();
    if(menang()==1){
        printf("\nPlayer 1 Win.\n");
        player1++;
    }
    else if(menang()==2){
        printf("\nPlayer 2 Win.\n");
        player2++;
    }
    else if(menang()==3)
        printf("\nSeri.\n");
    printf("============================");
    printf("\nPlayer 1 : %d\tPlayer 2 : %d\n",player1,player2);
    printf("============================\n");
}

void reset(void)
{
    matrix[0][0]='a';
    matrix[0][1]='b';
    matrix[0][2]='c';
    matrix[1][0]='d';
    matrix[1][1]='e';
    matrix[1][2]='f';
    matrix[2][0]='g';
    matrix[2][1]='h';
    matrix[2][2]='i';
}

void tampil(void)
{
    int i,j;
    printf("   0 | 1 | 2\n\n");
    for(i=0;i<3;i++)
    {
        printf("%d ",i);
        for(j=0;j<3;j++)
        {
            printf(" %c ",matrix[i][j]);
            if(j==0 || j==1)
                printf("|");
        }
        if(i==0 || i==1)
            printf("\n   ---------\n");
        else
            printf("\n");
    }
}

int pengecekan(char lokasi)
{
    int cek;
    if(lokasi=='a'){
        if(matrix[0][0]=='X' || matrix[0][0]=='O')
            cek=1;
    }
    else if(lokasi=='b'){
        if(matrix[0][1]=='X' || matrix[0][1]=='O')
            cek=1;
    }
    else if(lokasi=='c'){
        if(matrix[0][2]=='X' || matrix[0][2]=='O')
            cek=1;
    }
    else if(lokasi=='d'){
        if(matrix[1][0]=='X' || matrix[1][0]=='O')
            cek=1;
    }
    else if(lokasi=='e'){
        if(matrix[1][1]=='X' || matrix[1][1]=='O')
            cek=1;
    }
    else if(lokasi=='f'){
        if(matrix[1][2]=='X' || matrix[1][2]=='O')
            cek=1;
    }
    else if(lokasi=='g'){
        if(matrix[2][0]=='X' || matrix[2][0]=='O')
            cek=1;
    }
    else if(lokasi=='h'){
        if(matrix[2][1]=='X' || matrix[2][1]=='O')
            cek=1;
    }
    else if(lokasi=='i'){
        if(matrix[2][2]=='X' || matrix[2][2]=='O')
            cek=1;
    }
    else if(lokasi!='a' || lokasi!='b' || lokasi!='c' || lokasi!='d' || lokasi!='e' || lokasi!='f' || lokasi!='g' || lokasi!='h' || lokasi!='i')
        cek=1;
    else
        cek=0;
    return cek;
}

void input(char zona)
{
    switch(zona)
    {
        case 'a': matrix[0][0]='X';break;
        case 'b': matrix[0][1]='X';break;
        case 'c': matrix[0][2]='X';break;
        case 'd': matrix[1][0]='X';break;
        case 'e': matrix[1][1]='X';break;
        case 'f': matrix[1][2]='X';break;
        case 'g': matrix[2][0]='X';break;
        case 'h': matrix[2][1]='X';break;
        case 'i': matrix[2][2]='X';break;
    }
}

void input2(char zona)
{
    switch(zona)
    {
        case 'a': matrix[0][0]='O';break;
        case 'b': matrix[0][1]='O';break;
        case 'c': matrix[0][2]='O';break;
        case 'd': matrix[1][0]='O';break;
        case 'e': matrix[1][1]='O';break;
        case 'f': matrix[1][2]='O';break;
        case 'g': matrix[2][0]='O';break;
        case 'h': matrix[2][1]='O';break;
        case 'i': matrix[2][2]='O';break;
    }
}

int menang(void)
{
    if(matrix[0][0]==matrix[0][1] && matrix[0][0]==matrix[0][2]){
        if(matrix[0][0]=='X')
            return 1;
        else
            return 2;
    }
    else if(matrix[1][0]==matrix[1][1] && matrix[1][0]==matrix[1][2]){
        if(matrix[1][0]=='X')
            return 1;
        else
            return 2;
    }
    else if(matrix[2][0]==matrix[2][1] && matrix[2][0]==matrix[2][2]){
        if(matrix[2][0]=='X')
            return 1;
        else
            return 2;
    }
    else if(matrix[0][0]==matrix[1][0] && matrix[0][0]==matrix[2][0]){
        if(matrix[0][0]=='X')
            return 1;
        else
            return 2;
    }
    else if(matrix[0][1]==matrix[1][1] && matrix[0][1]==matrix[2][1]){
        if(matrix[0][1]=='X')
            return 1;
        else
            return 2;
    }
    else if(matrix[0][2]==matrix[1][2] && matrix[0][2]==matrix[2][2]){
        if(matrix[0][2]=='X')
            return 1;
        else
            return 2;
    }
    else if(matrix[0][0]==matrix[1][1] && matrix[0][0]==matrix[2][2]){
        if(matrix[0][0]=='X')
            return 1;
        else
            return 2;
    }
    else if(matrix[2][0]==matrix[1][1] && matrix[2][0]==matrix[0][2]){
        if(matrix[2][0]=='X')
            return 1;
        else
            return 2;
    }
    else if((matrix[0][0]=='X' || matrix[0][0]=='O') && (matrix[0][1]=='X' || matrix[0][1]=='O') && (matrix[0][2]=='X' || matrix[0][2]=='O') && (matrix[1][0]=='X' || matrix[1][0]=='O') && (matrix[1][1]=='X' || matrix[1][1]=='O') && (matrix[1][2]=='X' || matrix[1][2]=='O') && (matrix[2][0]=='X' || matrix[2][0]=='O') && (matrix[2][1]=='X' || matrix[2][1]=='O') && (matrix[2][2]=='X' || matrix[2][2]=='O'))
        return 3;
    else
        return 0;
}

void computer(void)
{
    int row,cols,a,b;
    if(matrix[0][0]=='O' && matrix[0][1]=='O' && matrix[0][2]!='X')
        matrix[0][2]='O';
    else if(matrix[1][0]=='O' && matrix[1][1]=='O' && matrix[1][2]!='X')
        matrix[1][2]='O';
    else if(matrix[2][0]=='O' && matrix[2][1]=='O' && matrix[2][2]!='X')
        matrix[2][2]='O';
    else if(matrix[0][0]!='X' && matrix[0][1]=='O' && matrix[0][2]=='O')
        matrix[0][0]='O';
    else if(matrix[1][0]!='X' && matrix[1][1]=='O' && matrix[1][2]=='O')
        matrix[1][0]='O';
    else if(matrix[2][0]!='X' && matrix[2][1]=='O' && matrix[2][2]=='O')
        matrix[2][0]='O';
    else if(matrix[0][0]=='O' && matrix[0][1]!='X' && matrix[0][2]=='O')
        matrix[0][1]='O';
    else if(matrix[1][0]=='O' && matrix[1][1]!='X' && matrix[1][2]=='O')
        matrix[1][1]='O';
    else if(matrix[2][0]=='O' && matrix[2][1]!='X' && matrix[2][2]=='O')
        matrix[2][1]='O';
    else if(matrix[0][0]=='O' && matrix[1][0]=='O' && matrix[2][0]!='X')
        matrix[2][0]='O';
    else if(matrix[0][1]=='O' && matrix[1][1]=='O' && matrix[2][1]!='X')
        matrix[2][1]='O';
    else if(matrix[0][2]=='O' && matrix[1][2]=='O' && matrix[2][2]!='X')
        matrix[2][2]='O';
    else if(matrix[0][0]!='X' && matrix[1][0]=='O' && matrix[2][0]=='O')
        matrix[0][0]='O';
    else if(matrix[0][1]!='X' && matrix[1][1]=='O' && matrix[2][1]=='O')
        matrix[0][1]='O';
    else if(matrix[0][2]!='X' && matrix[1][2]=='O' && matrix[2][2]=='O')
        matrix[0][2]='O';
    else if(matrix[0][0]=='O' && matrix[1][0]!='X' && matrix[2][0]=='O')
        matrix[1][0]='O';
    else if(matrix[0][1]=='O' && matrix[1][1]!='X' && matrix[2][1]=='O')
        matrix[1][1]='O';
    else if(matrix[0][2]=='O' && matrix[1][2]!='X' && matrix[2][2]=='O')
        matrix[1][2]='O';
    else if(matrix[0][0]=='O' && matrix[1][1]=='O' && matrix[2][2]!='X')
        matrix[2][2]='O';
    else if(matrix[0][0]!='X' && matrix[1][1]=='O' && matrix[2][2]=='O')
        matrix[0][0]='O';
    else if(matrix[0][0]=='O' && matrix[1][1]!='X' && matrix[2][2]=='O')
        matrix[1][1]='O';
    else if(matrix[0][2]=='O' && matrix[1][1]=='O' && matrix[2][0]!='X')
        matrix[2][0]='O';
    else if(matrix[0][2]!='X' && matrix[1][1]=='O' && matrix[2][0]=='O')
        matrix[0][2]='O';
    else if(matrix[0][2]=='O' && matrix[1][1]!='X' && matrix[2][0]=='O')
        matrix[1][1]='O';
    else if(matrix[0][0]=='X' && matrix[0][1]=='X' && matrix[0][2]!='O')
        matrix[0][2]='O';
    else if(matrix[1][0]=='X' && matrix[1][1]=='X' && matrix[1][2]!='O')
        matrix[1][2]='O';
    else if(matrix[2][0]=='X' && matrix[2][1]=='X' && matrix[2][2]!='O')
        matrix[2][2]='O';
    else if(matrix[0][0]!='O' && matrix[0][1]=='X' && matrix[0][2]=='X')
        matrix[0][0]='O';
    else if(matrix[1][0]!='O' && matrix[1][1]=='X' && matrix[1][2]=='X')
        matrix[1][0]='O';
    else if(matrix[2][0]!='O' && matrix[2][1]=='X' && matrix[2][2]=='X')
        matrix[2][0]='O';
    else if(matrix[0][0]=='X' && matrix[0][1]!='O' && matrix[0][2]=='X')
        matrix[0][1]='O';
    else if(matrix[1][0]=='X' && matrix[1][1]!='O' && matrix[1][2]=='X')
        matrix[1][1]='O';
    else if(matrix[2][0]=='X' && matrix[2][1]!='O' && matrix[2][2]=='X')
        matrix[2][1]='O';
    else if(matrix[0][0]=='X' && matrix[1][0]=='X' && matrix[2][0]!='O')
        matrix[2][0]='O';
    else if(matrix[0][1]=='X' && matrix[1][1]=='X' && matrix[2][1]!='O')
        matrix[2][1]='O';
    else if(matrix[0][2]=='X' && matrix[1][2]=='X' && matrix[2][2]!='O')
        matrix[2][2]='O';
    else if(matrix[0][0]!='O' && matrix[1][0]=='X' && matrix[2][0]=='X')
        matrix[0][0]='O';
    else if(matrix[0][1]!='O' && matrix[1][1]=='X' && matrix[2][1]=='X')
        matrix[0][1]='O';
    else if(matrix[0][2]!='O' && matrix[1][2]=='X' && matrix[2][2]=='X')
        matrix[0][2]='O';
    else if(matrix[0][0]=='X' && matrix[1][0]!='O' && matrix[2][0]=='X')
        matrix[1][0]='O';
    else if(matrix[0][1]=='X' && matrix[1][1]!='O' && matrix[2][1]=='X')
        matrix[1][1]='O';
    else if(matrix[0][2]=='X' && matrix[1][2]!='O' && matrix[2][2]=='X')
        matrix[1][2]='O';
    else if(matrix[0][0]=='X' && matrix[1][1]=='X' && matrix[2][2]!='O')
        matrix[2][2]='O';
    else if(matrix[0][0]!='O' && matrix[1][1]=='X' && matrix[2][2]=='X')
        matrix[0][0]='O';
    else if(matrix[0][0]=='X' && matrix[1][1]!='O' && matrix[2][2]=='X')
        matrix[1][1]='O';
    else if(matrix[0][2]=='X' && matrix[1][1]=='X' && matrix[2][0]!='O')
        matrix[2][0]='O';
    else if(matrix[0][2]!='0' && matrix[1][1]=='X' && matrix[2][0]=='X')
        matrix[0][2]='O';
    else if(matrix[0][2]=='X' && matrix[1][1]!='O' && matrix[2][0]=='X')
        matrix[1][1]='O';
    else if(matrix[1][1]!='X' && matrix[1][1]!='O')
        matrix[1][1]='O';
    else{
    do{
        a=rand();
        b=rand();
        row=a%3;
        cols=b%3;
    }while(matrix[row][cols]=='X' || matrix[row][cols]=='O');
    matrix[row][cols]='O';
    }
}
