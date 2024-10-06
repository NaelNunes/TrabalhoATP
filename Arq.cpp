#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define TF 30

struct TpAlunos {
	char RA[13];
	char Nome[30];
};

struct TpDisc {
	char CodDisc[4];
	char Disc[30];
};

struct TpNota {
	char RA[13];
	char CodDisc[4];
	float Nota;
};

TpAlunos Alunos[TF];
int TLA = 0;
TpDisc Disc[TF];
int TLD = 0;
TpNota Notas[TF];
int TLN = 0;

void Moldura(int ColunaI, int LinhaI, int ColunaF, int LinhaF, int CorT/*, int CorF */) {
	int i;
	textcolor(CorT);
//	textbackground(CorF);
	gotoxy(ColunaI, LinhaI); printf("%c",201);
	gotoxy(ColunaF, LinhaI); printf("%c",187);
	gotoxy(ColunaI, LinhaF); printf("%c",200);
	gotoxy(ColunaF, LinhaF); printf("%c",188);
	for(i = ColunaI + 1; i < ColunaF; i++)
	{
		gotoxy(i,LinhaI); printf("%c",205);
		gotoxy(i,LinhaF); printf("%c",205);
		
	}
	for(i = LinhaI + 1; i < LinhaF; i++)
	{
		gotoxy(ColunaI,i); printf("%c",186);
		gotoxy(ColunaF,i); printf("%c",186);
	}
	textcolor(7);
	textbackground(0);
}

void InserirInterface(void) {
	Moldura(1,1,80,25,15/*,15*/);
	Moldura(2,2,79,4,15/*,15*/);
	textcolor(WHITE);
	gotoxy(32,3);
	printf("TITULO DO TRABALHO");
	Moldura(2,5,28,21,15/*,15*/);
	Moldura(29,5,79,21,15/*,15*/);
	Moldura(2,22,79,24,15/*,15*/);
	textcolor(4);
	gotoxy(3,23);
	printf("Mensagem: ");
}

void ExibirTelao(int col, int lin) {
	gotoxy(col,lin);
}

char Menu(void) {
	system("cls");
	InserirInterface();
	textcolor(15);
	gotoxy(12,6);
	printf("M E N U");
	textcolor(10);
	gotoxy(4,8);
	printf("[A] Cadastros");
	gotoxy(4,10);
	printf("[B] Exclusoes");
	gotoxy(4,12);
	printf("[C] Alteracoes");
	gotoxy(4,14);
	printf("[D] Consultas");
	gotoxy(4,16);
	printf("[ESC] Finalizar");
	gotoxy(12,23);
	return toupper(getche());
}

char MenuCadastros(void) {
	system("cls");
	InserirInterface();
	textcolor(15);
	gotoxy(7,6);
	printf("C A D A S T R O S");
	textcolor(10);
	gotoxy(4,8);
	printf("[A] Cadastrar Alunos");
	gotoxy(4,10);
	printf("[B] Cadastrar Disciplina");
	gotoxy(4,12);
	printf("[C] Registrar Notas");
	gotoxy(4,14);
	printf("[D] Inserir Dados");
	gotoxy(4,16);
	printf("[ESC] Voltar");
	gotoxy(12,23);
	return toupper(getche());
}

char MenuExclusoes(void) {
	system("cls");
	InserirInterface();
	textcolor(15);
	gotoxy(7,6);
	printf("E X C L U S O E S");
	textcolor(10);
	gotoxy(4,8);
	printf("[A] Excluir Aluno");
	gotoxy(4,10);
	printf("[B] Excluir Disciplina");
	gotoxy(4,12);
	printf("[C] Excluir Nota");
	gotoxy(4,16);
	printf("[ESC] Voltar");
	gotoxy(12,23);
	return toupper(getche());
}

char MenuAlteracoes(void) {
	system("cls");
	InserirInterface();
	textcolor(15);
	gotoxy(9,6);
	printf("A L T E R A R");
	textcolor(10);
	gotoxy(4,8);
	printf("[A] Alterar Alunos");
	gotoxy(4,10);
	printf("[B] Alterar Disciplinas");
	gotoxy(4,12);
	printf("[C] Alterar Notas");
	gotoxy(4,14);
	printf("[ESC] Voltar");
	gotoxy(12,23);
	return toupper(getche());
}

char MenuConsultas(void) {
	system("cls");
	InserirInterface();
	textcolor(15);
	gotoxy(8,6);
	printf("C O N S U L T A");
	textcolor(10);
	gotoxy(4,8);
	printf("[A] reprovados em 2 ou +");
	gotoxy(4,10);
	printf("[B] determinada letra");
	gotoxy(4,12);
	printf("[C] determinado termo");
	gotoxy(4,14);
	printf("[D] abaixo de 6,0");
	gotoxy(4,16);
	printf("[D] Relatorio Geral");
	gotoxy(4,18);
	printf("[ESC] Voltar");
	gotoxy(12,23);
	return toupper(getche());
}

int BuscarAluno(TpAlunos Alunos[TF], int TLA, char Aux[13])
{
	int pos = 0;
	while(pos < TLA && strcmp(Alunos[pos].RA,Aux) != 0)
		pos++;
	
	if(pos < TLA) {
		return pos;
	} else {
		return -1;
	}
}

void CadastrarAluno(TpAlunos Alunos[TF], int &TLA)
{
    	char AuxRA[13];
		ExibirTelao(30,6);
        printf("RA: ");
        fflush(stdin);
        gets(AuxRA);
        while(TLA<TF && strcmp(AuxRA,"\0")!=0)
        {
        	int x = BuscarAluno(Alunos,TLA,AuxRA);
        	if(x == -1) 
			{
            	strcpy(Alunos[TLA].RA,AuxRA);
            	ExibirTelao(30,7);
				printf("Nome: ");
            	fflush(stdin);
            	gets(Alunos[TLA].Nome);
            	TLA++;
            	ExibirTelao(30,6);
            	printf("                                                ");
            	ExibirTelao(30,7);
            	printf("                                                ");
        	} else {
        		ExibirTelao(30,7);
        		printf("RA ja cadastrado com o nome %s!", Alunos[x].Nome);
        		Sleep(2000);
        		ExibirTelao(30,6);
            	printf("                                                ");
            	ExibirTelao(30,7);
            	printf("                                                ");
			}
    		ExibirTelao(30,6);
            printf("RA: ");
            fflush(stdin);
            gets(AuxRA);
		}
}


int BuscarDisc(TpDisc Disc[TF], int TLD, char Aux[4])
{
	int pos = 0;
	while(pos < TLD && strcmp(Disc[pos].CodDisc,Aux) != 0)
		pos++;
	
	if(pos < TLD) {
		return pos;
	} else {
		return -1;
	}
}

void CadastrarDisciplina(TpDisc Disc[TF], int &TLD)
{
    	char AuxDisc[4];
    	ExibirTelao(30,6);
        printf("Codigo da Disciplina: ");
        fflush(stdin);
        gets(AuxDisc);
        while(TLD<TF && strcmp(AuxDisc,"\0") != 0)
        {
        	int x = BuscarDisc(Disc,TLD,AuxDisc);
        	if(x == -1)
        	{
	            strcpy(Disc[TLD].CodDisc,AuxDisc);
	            ExibirTelao(30,7);
	            printf("Nome da Disciplina: ");
	            fflush(stdin);
	            gets(Disc[TLD].Disc);
	            TLD++;
	            ExibirTelao(30,6);
	            printf("                                                ");
	            ExibirTelao(30,7);
	            printf("                                                ");
			} else {
				ExibirTelao(30,7);
        		printf("Codigo de disciplina ja cadastrado com o nome %s!", Disc[x].CodDisc);
        		Sleep(2000);
        		ExibirTelao(30,6);
            	printf("                                                ");
            	ExibirTelao(30,7);
            	printf("                                                ");
			}
			ExibirTelao(30,6);
	        printf("Codigo da Disciplina: ");
	        fflush(stdin);
        	gets(AuxDisc);
		}
        
}

int BuscarNota(TpNota notas[TF], int TLN, char CodDisc[4], char RA[13]) {
    int pos = 0;

    while (pos < TLN && (strcmp(notas[pos].CodDisc, CodDisc) != 0 && strcmp(notas[pos].RA, RA) != 0)) {
        pos++;
    }

    if (pos < TLN) {
        return pos;
    } else {
        return -1;
    }
}


void CadastroNotas(TpNota Nota[TF],int &TLN, TpAlunos Alunos[TF], int &TLA, TpDisc Disc[TF], int &TLD)
{
    	char AuxDisc[4];
    	char AuxRA[13];
    	ExibirTelao(30,6);
        printf("Codigo da Disciplina: ");
        fflush(stdin);
        gets(AuxDisc);
        while(TLN<TF && strcmp(AuxDisc,"\0")!=0)
        {
        	int y = BuscarDisc(Disc,TLD,AuxDisc);
        	if(y != -1) {
				ExibirTelao(30,7);
            	printf("RA: ");
       			fflush(stdin);
        		gets(AuxRA);
        		int z = BuscarAluno(Alunos,TLA,AuxRA);
        		if(z != -1) {
        			int x = BuscarNota(Nota,TLN,AuxDisc,AuxRA);
					if(x == -1)
					{
			        	strcpy(Nota[TLN].RA,AuxRA);
			        	strcpy(Nota[TLN].CodDisc,AuxDisc);
			            ExibirTelao(30,8);
			            printf("Nota do Aluno: ");
			            fflush(stdin);
			            scanf("%f",&Nota[TLN].Nota);
			            TLN++;
			            ExibirTelao(30,6);
			            printf("                                                ");
			            ExibirTelao(30,7);
			            printf("                                                ");
			            ExibirTelao(30,8);
			            printf("                                                ");
					} else {
						ExibirTelao(30,8);
		        		printf("Nota nesta disciplina, e deste aluno ja foi");
						ExibirTelao(30,9);
						printf("cadastrada, nota: %.2f!", Nota[x].Nota);
		        		Sleep(3000);
		        		ExibirTelao(30,6);
		            	printf("                                                ");
		            	ExibirTelao(30,7);
		            	printf("                                                ");
		            	ExibirTelao(30,8);
		            	printf("                                                ");
		            	ExibirTelao(30,9);
		            	printf("                                                ");
					}
				} else {
					ExibirTelao(30,7);
					printf("Este Aluno nao existe!");
				}
			} else {
				ExibirTelao(30,7);
				printf("Esta Disciplina nao existe!");
			}
            
			ExibirTelao(30,6);
        	printf("Codigo da Disciplina: ");
        	fflush(stdin);
       		gets(AuxDisc);
        }
}

void InserirDados(TpAlunos Aluno[TF], int &TLA, TpDisc Disc[TF], int &TLD, TpNota Nota[TF],int &TLN) {
	strcpy(Aluno[TLA].RA, "26.24.1261-6");
	strcpy(Aluno[TLA].Nome, "Nathanael");
	TLA++;
	strcpy(Aluno[TLA].RA, "26.24.1261-5");
	strcpy(Aluno[TLA].Nome, "Andre");
	TLA++;
	strcpy(Aluno[TLA].RA, "26.24.1261-4");
	strcpy(Aluno[TLA].Nome, "Silvio");
	TLA++;
	strcpy(Aluno[TLA].RA, "26.24.1261-3");
	strcpy(Aluno[TLA].Nome, "Erick");
	TLA++;
	strcpy(Aluno[TLA].RA, "26.24.1261-2");
	strcpy(Aluno[TLA].Nome, "Joao");
	TLA++;
	strcpy(Aluno[TLA].RA, "26.24.1261-1");
	strcpy(Aluno[TLA].Nome, "Pedro");
	TLA++;
	strcpy(Disc[TLD].CodDisc,"100");
	strcpy(Disc[TLD].Disc, "Matematica");
	TLD++;
	strcpy(Disc[TLD].CodDisc,"101");
	strcpy(Disc[TLD].Disc, "Portugues");
	TLD++;
	strcpy(Disc[TLD].CodDisc,"102");
	strcpy(Disc[TLD].Disc, "Ingles");
	TLD++;
	strcpy(Disc[TLD].CodDisc,"103");
	strcpy(Disc[TLD].Disc, "Espanhol");
	TLD++;
	strcpy(Disc[TLD].CodDisc,"104");
	strcpy(Disc[TLD].Disc, "Fisica");
	TLD++;
	strcpy(Nota[TLN].RA, "26.24.1261-6");
	strcpy(Disc[TLN].CodDisc,"100");
	Nota[TLN].Nota = 8.5;
	TLN++;
	strcpy(Nota[TLN].RA, "26.24.1261-6");
	strcpy(Disc[TLN].CodDisc,"101");
	Nota[TLN].Nota = 4.0;
	TLN++;
	strcpy(Nota[TLN].RA, "26.24.1261-5");
	strcpy(Disc[TLN].CodDisc,"102");
	Nota[TLN].Nota = 2.0;
	TLN++;
	strcpy(Nota[TLN].RA, "26.24.1261-4");
	strcpy(Disc[TLN].CodDisc,"103");
	Nota[TLN].Nota = 9.0;
	TLN++;
	strcpy(Nota[TLN].RA, "26.24.1261-3");
	strcpy(Disc[TLN].CodDisc,"104");
	Nota[TLN].Nota = 5.0;
	TLN++;
	gotoxy(30,6);
	printf("Dados Inseridos!");
	gotoxy(12,23);
	getche();
}
// Função para excluir aluno e todas as suas notas
void excluirAluno(TpAlunos TbAlunos[TF],int &TLA, TpNota TbNota[TF], int &TLN) {
    char ra[13];
    printf("Digite o RA do aluno a ser excluído: ");
    fflush(stdin);
    gets(ra);
	    int i, j;
	
	    // Excluindo o aluno
	    for (i = 0; i < TLA; i++) {
	        if (strcmp(TbAlunos[i].RA, ra) == 0) {
	            for (j = i; j < TLA - 1; j++) {
	                TbAlunos[j] = TbAlunos[j + 1];
	            }
	            TLA--;
	            printf("Aluno removido com sucesso!\n");
	            break;
	        }
	    }
	
	    // Excluindo todas as notas associadas ao RA
	    for (i = 0; i < TLN; ) 
			{
	        if (strcmp(TbNota[i].RA, ra) == 0) 
				{
	            for (j = i; j < TLN - 1; j++) 
					{
	                TbNota[j] = TbNota[j + 1];
	            	}
	            TLN--;
	        	} 
			else 
	            i++;
	    	}
		
}

// Função para excluir disciplina e todas as notas associadas a ela
void excluirDisciplina(TpDisc TbDisc[TF],int&TLD,TpNota TbNota[TF], int&TLN) {
    int codigo;
    printf("Digite o codigo da disciplina a ser excluída: ");
    scanf("%d", &codigo);

    int i, j;

    // Excluindo a disciplina
    for (i = 0; i < TLD; i++) {
       if (*(TbDisc[i].CodDisc) == codigo) {
            for (j = i; j < TLD - 1; j++) {
                TbDisc[j] = TbDisc[j + 1];
            }
           	TLD--;
            printf("Disciplina removida com sucesso!\n");
            break;
        }
    }

    // Excluindo todas as notas associadas à disciplina
    for (i = 0; i < TLN; ) {
    	if (*(TbDisc[i].CodDisc) == codigo) {
            for (j = i; j <TLN - 1; j++) {
                TbNota[j] = TbNota[j + 1];
            }
            TLN--;
        } else {
            i++;
        }
    }
}

void AlterarAlunos(TpAlunos Alu[TF],int TL)
{
    char AuxRA[13];
    int pos;
    ExibirTelao(30,6);
    printf(" RA p/ alterar:");
    fflush(stdin);
    gets(AuxRA);
    while(strcmp(AuxRA,"\0")!=0)
    {
        pos=BuscarAluno(Alu,TL,AuxRA);
        if(pos==-1)
        {
        	ExibirTelao(30,7);
        	printf("RA não encontrado!");
            Sleep(2000);
        	ExibirTelao(30,6);
            printf("                                                ");
            ExibirTelao(30,7);
            printf("                                                ");
            
        }
        else
        {
			ExibirTelao(30,7);
            printf("#Dados encontrados#");
            printf("RA: %s\n",Alu[pos].RA);
            printf("Nome: %s",Alu[pos].Nome);
            printf("Confirma Alteracao? S/N ");
            fflush(stdin);
            if(toupper(getche())=='S')
            {
            	ExibirTelao(30,7);
                printf(" RA p/ alterar: ");
                gets(Alu[pos].RA);
                printf(" Alterado!\n");
                printf(" Nome p/ alterar: ");
                gets(Alu[pos].Nome);
                printf(" Alterado!\n");
                getch();
            }
        }
        ExibirTelao(30,6);
        printf("RA p/ Alterar");
        gets(AuxRA);
    }

}

void AlterarDisc(TpDisc TbDisc[TF],int TL)
{
    char Cod[4];
    int pos;
    printf("\n###Alterar pelo Codigo da Disciplina\n###");
    printf("\n Codigo p/ alterar");
    gets(Cod);
    while(strcmp(Cod,"\0")!=0)
    {
        pos=BuscarDisc(TbDisc,TL,Cod);
        if(pos==-1)
            printf("\nCodigo não encontrado!");
        else
        {
            printf("\n#Dados encontrados#\n");
            printf("Codigo: %s\n",TbDisc[pos].CodDisc);
            printf("Nome Da disciplina: %s\n", TbDisc[pos].Disc);
            printf("\nConfirma Alteracao? S/N \n");
            fflush(stdin);
            if(toupper(getche())=='S')
            {
                printf("\n Codigo p/ alterar: ");
                gets(TbDisc[pos].CodDisc);
                printf("\n Alterado!\n");
                printf("\n Nome Da disciplina p/ alterar: ");
                gets(TbDisc[pos].Disc);
                printf("\n Alterado!\n");
                getch();
            }
        }
        printf("\nCodigo p/ Alterar");
        gets(Cod);
    }

}

void AlterarNotas(TpNota Notas[TF],int TL)
{
    char AuxRA[13];
    char AuxDisc[4];
    int pos;
    ExibirTelao(30,6);
    printf("RA p/ alterar: ");
    fflush(stdin);
    gets(AuxRA);
    while(strcmp(AuxRA,"\0")!=0)
    {
    	ExibirTelao(30,7);
    	printf("Codigo da Disciplina: ");
    	fflush(stdin);
    	gets(AuxDisc);
        pos = BuscarNota(Notas,TL,AuxDisc,AuxRA);
        if(pos==-1) {
         	ExibirTelao(30,6);
			printf("                                                ");
			ExibirTelao(30,7);
			printf("                                                ");
			ExibirTelao(30,6);
            printf("Dados não encontrados!");
            Sleep(2000);
		}
        else
        {
        	ExibirTelao(30,6);
			printf("                                                ");
			ExibirTelao(30,7);
			printf("                                                ");
			ExibirTelao(30,6);
            printf("#Dados encontrados#");
            ExibirTelao(30,7);
            printf("RA: %s\n", Notas[pos].RA);
            ExibirTelao(30,8);
            printf("Codigo da Disciplina: %s", Notas[pos].CodDisc);
            ExibirTelao(30,9);
            printf("Nota: %f", Notas[pos].Nota);
            ExibirTelao(30,10);
            printf("Gostaria de Alterar a nota? S/N");
            fflush(stdin);
            if(toupper(getche()) =='S' )
            {
            	ExibirTelao(30,6);
				printf("                                                ");
				ExibirTelao(30,7);
				printf("                                                ");
				ExibirTelao(30,8);
				printf("                                                ");
				ExibirTelao(30,9);
				printf("                                                ");
				ExibirTelao(30,10);
				printf("                                                ");
				ExibirTelao(30,6);
                printf("Nota p/ alterar: ");
                scanf("%f", &Notas[pos].Nota);
                ExibirTelao(30,7);
                printf("\n Alterado!\n");
                getch();
            }
        }
        ExibirTelao(30,6);
		printf("                                                ");
		ExibirTelao(30,7);
		printf("                                                ");
        ExibirTelao(30,6);
        printf("RA p/ Alterar");
        gets(AuxRA);
    }

}
void Reprov2(TpNota AuxNotas[30],int TLN,TpAlunos AuxAlunos[30],int TLA)
{
	int i,j,k,x=7;
			
	printf("Alunos que ficaram com 2 materias ou mais com a media abaixo de 6: ");
	
	
	for(j=0;j<TLA;j++)
	{
		k=0;
		
		for(i=0;i<TLN;i++)
			if(strcmp(AuxAlunos[j].RA,AuxNotas[i].RA)==0)
				if(AuxNotas[i].Nota<6)
					k++;
		if(k>=2)
		{
			x++;
			gotoxy(5,x++);
			printf("RA: %s",AuxAlunos[j].RA);
			gotoxy(5,x++);
			printf("Nome: %s",AuxAlunos[j].Nome);
		}
	}
	
	x=38-(strlen("### Aperte qualquer teclar para sair ###")/2);
	gotoxy(x,22);
    printf("### Aperte qualquer teclar para sair ###");
	getch();
		
}
void BuscaInicial(TpAlunos AuxAlunos[30],int TLA)
{
	int i, j=9,x;
	
	char busca;
	

    x=38-(strlen("Busca por Inicial Aluno")/2);
    gotoxy(x,7);		
	printf("Busca por Inicial Aluno");
	
	gotoxy(5,j++);		
	printf("Digite a Inicial que deseja buscar: ");
	busca=toupper(getch());
		
	for(i=0;i<TLA;i++)
		if(toupper(AuxAlunos[i].Nome[0])==busca)
			{
				if(j==10)
				{
				
					j=9;
					gotoxy(5,j++);		
					printf("Alunos que comecam com a Inicial '%c':", busca);
					j++;
				}
					
				gotoxy(5,j++);		
				printf("- %s", AuxAlunos[i].Nome);
			}
	
	if(j==10)
	{
	
		x=38-(strlen("Nao tem nenhum aluno com a inicial 'C'")/2);
		gotoxy(x,14);		
		printf("Nao tem nenhum aluno com a inicial '%c'",busca);
	
	}
	else
	{
		x=38-(strlen("### Aperte qualquer teclar para sair ###")/2);
		gotoxy(x,22);
	    printf("### Aperte qualquer teclar para sair ###");
		getch();
	}	
}
void BuscaPalavra(TpDisc AuxDisci[30],int TLD)
{
	int i, j=9,x;
	
	char busca[100],busca2[100];
	

    x=38-(strlen("Busca por Palavra Disciplina")/2);
    gotoxy(x,7);		
	printf("Busca por Palavra Disciplina");
	
	gotoxy(5,j++);		
	printf("Digite a Palavra que deseja buscar: ");
	scanf(" %s",&busca);
	
	for(x=0;x<=strlen(busca);x++)
		busca[x]=toupper(busca[x]);

	for(i=0;i<TLD;i++)
	{
		
		for(x=0;x<=strlen(AuxDisci[i].Disc);x++)
			busca2[x]=toupper(AuxDisci[i].Disc[x]);
		 
		if(strstr(busca2,busca))
			{
				if(j==10)
				{
				
					j=9;
					gotoxy(5,j++);		
					printf("Diciplinas que tem a palavra '%s':", busca);
					j++;
				}
					
				gotoxy(5,j++);		
				printf("- %s", AuxDisci[i].Disc);
			}
	}
}

void mediag_abaixo(TpNota ad[TF], int TLN, TpDisc dcp[TF], int TLD){
	int cont;
	float soma;
	system("cls");
	printf("\n**DISCIPLINAS COM MEDIAS ABAIXO DE 6**\n");
	for(int i=0;i<TLD;i++){
		cont=0;
		soma=0;
		for(int j=0;j<TLN;j++){
			if(stricmp(dcp[i].CodDisc,ad[j].CodDisc)==0){
				cont++; 
				soma+=ad[j].Nota;
			}
		}
		if(soma/cont<6)
			printf("\nDisciplina: %s Media: %.f\n",dcp[i].Disc,soma/cont);
	}
	getch();	
}


void VisualizarDados(TpNota AuxNotas[30],int &TLN,TpAlunos AuxAlunos[30],int TLA,TpDisc AuxDisci[50],int TLD)
{
	int i,j=7,k,x,y;
	for(i=0;i<TLA;i++)
	{
		 printf("RA: %s   Nome: %s",AuxAlunos[i].RA,AuxAlunos[i].Nome);
		

		for(k=0;k<TLN;k++)
			if(strcmp(AuxAlunos[i].RA,AuxNotas[k].RA)==0)
			{
				y=0;
				
				while(AuxNotas[k].CodDisc != AuxDisci[y].CodDisc && y<TLD)
					y++;
				if(AuxNotas[k].Nota>6)
				{
					gotoxy(5,j);printf("Disciplina: %d - %s",AuxDisci[y].CodDisc,AuxDisci[y].Disc);gotoxy(5,j++);printf("Nota: %.1f  Situacao: %s",AuxNotas[k].Nota,"Aprovado");
				}
				else
				{
					gotoxy(5,j);printf("Disciplina: %d - %s",AuxDisci[y].CodDisc,AuxDisci[y].Disc);gotoxy(43,j++);printf("Nota: %.1f  Situacao: %s",AuxNotas[k].Nota,"Reprovado");
				}
			}
		j++;
	}
	
	getch();
	
}


void ExecCadastros(TpAlunos Alunos[TF],int &TLA,TpDisc Disc[TF],int &TLD,TpNota Notas[TF],int &TLN) {
	char opcao;
	do{
		opcao=MenuCadastros();
		switch(opcao)
		{
			case 'A': CadastrarAluno(Alunos,TLA);
			break;
			
			case 'B': CadastrarDisciplina(Disc,TLD);
			break;
			
			case 'C': CadastroNotas(Notas,TLN,Alunos,TLA,Disc,TLD);
			break;
			
			case 'D': InserirDados(Alunos,TLA,Disc,TLD,Notas,TLN);
			break;
			
		}
		
	}while(opcao!=27);
		Menu();
}

void ExecExclusoes(TpAlunos Alunos[TF],int &TLA,TpDisc Disc[TF],int&TLD,TpNota Notas[TF],int&TLN){
	char opcao;
	do{
		opcao=MenuExclusoes();
		switch(opcao)
		{
			case 'A': excluirAluno(Alunos,TLA,Notas,TLN);
			break;
			
			case 'B':excluirDisciplina(Disc,TLD,Notas,TLN);
			break;
			
			case 'C': MenuAlteracoes();
			break;
			
			case 'D': MenuConsultas();
			break;
			
		}
		
	}while(opcao!=27);
		MenuExclusoes();
}

void ExecAlteracoes(TpAlunos Alunos[TF],int &TLA,TpDisc Disc[TF],int &TLD,TpNota Notas[TF],int &TLN) {
	char opcao;
	do{
		opcao=MenuAlteracoes();
		switch(opcao)
		{
			case 'A': AlterarAlunos(Alunos,TLA);
			break;
			
			case 'B': AlterarDisc(Disc,TLD);
			break;
			
			case 'C': AlterarNotas(Notas,TLN);
			break;
					
		}
		
	}while(opcao!=27);
		MenuAlteracoes();
}

void ExecConsultas(TpAlunos Alunos[TF],int &TLA,TpDisc Disc[TF],int &TLD,TpNota Notas[TF],int &TLN) {
	char opcao;
	do{
		opcao=MenuConsultas();
		switch(opcao)
		{
			case 'A': Reprov2(Notas,TLN,Alunos,TLA);
			break;
			
			case 'B': BuscaInicial(Alunos,TLA);
			break;
			
			case 'C': BuscaPalavra(Disc,TLD);
			break;
			
			case 'D': mediag_abaixo(Notas,TLN,Disc,TLD);
			break;
			
			case 'E': VisualizarDados(Notas,TLN,Alunos,TLA,Disc,TLD);
			break;
			
		}
		
	}while(opcao!=27);
		MenuConsultas();
}

void setConsoleSize(int width, int height) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) return;

    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = width - 1;
    rect.Bottom = height - 1;

    SetConsoleWindowInfo(hConsole, TRUE, &rect);
    
    COORD coord;
    coord.X = width;
    coord.Y = height;
    SetConsoleScreenBufferSize(hConsole, coord);
}

void Executar(void) {
	TpAlunos Alunos[TF];
	int TLA = 0;
	TpDisc Disc[TF];
	int TLD = 0;
	TpNota Notas[TF];
	int TLN = 0;
	
	int largura = 80;
    int altura = 25;
    setConsoleSize(largura, altura);
    
	char opcao;
	do{
		opcao=Menu();
		switch(opcao)
		{
			case 'A': 
			ExecCadastros(Alunos,TLA,Disc,TLD,Notas,TLN);
			break;
			
			case 'B': 
			ExecExclusoes(Alunos,TLA,Disc,TLD,Notas,TLN);
			break;
			
			case 'C': 
			ExecAlteracoes(Alunos,TLA,Disc,TLD,Notas,TLN);
			break;
			
			case 'D': 
			ExecConsultas(Alunos,TLA,Disc,TLD,Notas,TLN);
			break;		
		}
		
	}while(opcao!=27);
		Menu();
}

int main(void) {
	Executar();
	system("cls");
	return 0;	
}


