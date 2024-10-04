
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
	int CodDisc;
	char Disc[30];
};

struct TpNota {
	char RA[13];
	int CodDisc;
	float Nota;
};

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
	printf("[A] Alterar");
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

char MenuConsultas(void) {
	system("cls");
	InserirInterface();
	textcolor(15);
	gotoxy(8,6);
	printf("C O N S U L T A");
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

void CadastrarAluno(TpAlunos Alunos[TF], int &TLA)
{
    	char AuxRA[13];
		ExibirTelao(30,6);
        printf("RA: ");
        fflush(stdin);
        gets(AuxRA);
        while(TLA<TF && strcmp(AuxRA,"\0")!=0)
        {
            strcpy(Alunos[TLA].RA,AuxRA);
            ExibirTelao(30,7);
			printf("Nome: ");
            fflush(stdin);
            gets(Alunos[TLA].Nome);
            TLA++;
            ExibirTelao(30,6);
            printf("                                             ");
            ExibirTelao(30,7);
            printf("                                             ");
    		ExibirTelao(30,6);
            printf("RA: ");
            fflush(stdin);
            gets(AuxRA);
        }
}

void CadastrarDisciplina(TpDisc Disc[TF], int &TLD)
{
    	int AuxCODDIC;
    	ExibirTelao(30,6);
        printf("Codigo da Disciplina: ");
        fflush(stdin);
        scanf("%d",&AuxCODDIC);
        while(TLD<TF && AuxCODDIC != 0)
        {
            Disc[TLD].CodDisc = AuxCODDIC;
            ExibirTelao(30,7);
            printf("Nome da Disciplina: ");
            fflush(stdin);
            gets(Disc[TLD].Disc);
            TLD++;
            ExibirTelao(30,6);
            printf("                                             ");
            ExibirTelao(30,7);
            printf("                                             ");
    		ExibirTelao(30,6);
            printf("Codigo da Disciplina: ");
            fflush(stdin);
            scanf("%d",&AuxCODDIC);
        }
        
}

void CadastroNotas(TpNota TbNota[TF],int &TLN)
{
    	char AuxRA[13];
    	ExibirTelao(30,6);
        printf("RA: ");
        fflush(stdin);
        gets(AuxRA);
        while(TLN<TF && strcmp(AuxRA,"\0")!=0)
        {
            strcpy(TbNota[TLN].RA,AuxRA);
            ExibirTelao(30,7);
            printf("Codigo da Disciplina: ");
            fflush(stdin);
            scanf("%d",&TbNota[TLN].CodDisc);
            ExibirTelao(30,8);
            printf("Nota do Aluno: ");
            fflush(stdin);
            scanf("%f",&TbNota[TLN].Nota);
            TLN++;
            ExibirTelao(30,6);
            printf("                                             ");
            ExibirTelao(30,7);
            printf("                                             ");
            ExibirTelao(30,8);
            printf("                                             ");
    		ExibirTelao(30,6);
            printf("RA: ");
            fflush(stdin);
            gets(AuxRA);
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
	Disc[TLD].CodDisc = 100;
	strcpy(Disc[TLD].Disc, "Matematica");
	TLD++;
	Disc[TLD].CodDisc = 101;
	strcpy(Disc[TLD].Disc, "Portugues");
	TLD++;
	Disc[TLD].CodDisc = 102;
	strcpy(Disc[TLD].Disc, "Ingles");
	TLD++;
	Disc[TLD].CodDisc = 103;
	strcpy(Disc[TLD].Disc, "Espanhol");
	TLD++;
	Disc[TLD].CodDisc = 104;
	strcpy(Disc[TLD].Disc, "Fisica");
	TLD++;
	strcpy(Nota[TLA].RA, "26.24.1261-6");
	Nota[TLA].CodDisc = 100;
	Nota[TLA].Nota = 8.5;
	TLN++;
	strcpy(Nota[TLA].RA, "26.24.1261-6");
	Nota[TLA].CodDisc = 101;
	Nota[TLA].Nota = 4.0;
	TLN++;
	strcpy(Nota[TLA].RA, "26.24.1261-5");
	Nota[TLA].CodDisc = 102;
	Nota[TLA].Nota = 2.0;
	TLN++;
	strcpy(Nota[TLA].RA, "26.24.1261-4");
	Nota[TLA].CodDisc = 103;
	Nota[TLA].Nota = 9.0;
	TLN++;
	strcpy(Nota[TLA].RA, "26.24.1261-3");
	Nota[TLA].CodDisc = 104;
	Nota[TLA].Nota = 5.0;
	TLN++;
	gotoxy(30,6);
	printf("Dados Inseridos!");
	gotoxy(12,23);
	getche();
}

void ExecCadastros(void) {
	char opcao;
	TpAlunos Alunos[TF];
	int TLA = 0;
	TpDisc Disc[TF];
	int TLD = 0;
	TpNota Notas[TF];
	int TLN = 0;
	do{
		opcao=MenuCadastros();
		switch(opcao)
		{
			case 'A': CadastrarAluno(Alunos,TLA);
			break;
			
			case 'B': CadastrarDisciplina(Disc,TLD);
			break;
			
			case 'C': CadastroNotas(Notas,TLN);
			break;
			
			case 'D': InserirDados(Alunos,TLA,Disc,TLD,Notas,TLN);
			break;
			
		}
		
	}while(opcao!=27);
		Menu();
}

void ExecExclusoes(void) {
	char opcao;
	do{
		opcao=MenuExclusoes();
		switch(opcao)
		{
			case 'A': MenuCadastros();
			break;
			
			case 'B': MenuExclusoes();
			break;
			
			case 'C': MenuAlteracoes();
			break;
			
			case 'D': MenuConsultas();
			break;
			
		}
		
	}while(opcao!=27);
		MenuExclusoes();
}

void ExecAlteracoes(void) {
	char opcao;
	do{
		opcao=MenuAlteracoes();
		switch(opcao)
		{
			case 'A': MenuCadastros();
			break;
			
			case 'B': MenuExclusoes();
			break;
			
			case 'C': MenuAlteracoes();
			break;
			
			case 'D': MenuConsultas();
			break;
			
		}
		
	}while(opcao!=27);
		MenuAlteracoes();
}

void ExecConsultas(void) {
	char opcao;
	do{
		opcao=MenuConsultas();
		switch(opcao)
		{
			case 'A': MenuCadastros();
			break;
			
			case 'B': MenuExclusoes();
			break;
			
			case 'C': MenuAlteracoes();
			break;
			
			case 'D': MenuConsultas();
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
	int largura = 80;
    int altura = 25;
    setConsoleSize(largura, altura);
	char opcao;
	do{
		opcao=Menu();
		switch(opcao)
		{
			case 'A': 
			ExecCadastros();
			break;
			
			case 'B': 
			ExecExclusoes();
			break;
			
			case 'C': 
			ExecAlteracoes();
			break;
			
			case 'D': 
			ExecConsultas();
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


