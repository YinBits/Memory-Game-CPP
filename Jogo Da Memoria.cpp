#include <iostream>
using namespace std;

string c1 = " A",  c2 = " B",  c3 = " C" , c4 = " D",  c5 = " E",  c6 = " F",  c7 = " A",  c8 = " B",  c9 = " C",  c10 =  " D",  c11 = " E",  c12 = " F";
int v1 = 0,  v2 = 0,  v3 = 0 , v4 = 0,  v5 = 0,  v6 = 0,  v7 = 0,  v8 = 0,  v9 = 0,  v10 =  0,  v11 = 0,  v12 = 0;
string carta1 ="", carta2="";
int pontosJogador1 = 0;
int pontosJogador2 = 0;

void tabuleiro ()  
{	
	cout << "+----+----+----+----+" << endl;
	cout << "| "<< (v1 == 0 ? " 1" : c1) <<" | " << (v2 == 0 ? " 2" : c2) <<" | " <<  (v3 == 0 ? " 3" : c3)  << " | "<< (v4 == 0 ? " 4" : c4) <<" |" << endl;
	cout << "+----+----+----+----+" << endl;
	cout << "| "<< (v5 == 0 ? " 5" : c5) <<" | " << (v6 == 0 ? " 6" : c6) <<" | " <<  (v7 == 0 ? " 7" : c7)  << " | "<< (v8 == 0 ? " 8" : c8) <<" |" << endl;
	cout << "+----+----+----+----+" << endl;
	cout << "| "<< (v9 == 0 ? " 9" : c9) <<" | " << (v10 == 0 ? "10" : c10) <<" | " <<  (v11 == 0 ? "11" : c11)  << " | "<< (v12 == 0 ? "12" : c12) <<" |" << endl;
	cout << "+----+----+----+----+" << endl;
}

string viraCarta(int pJogada, int valor)
{
	string valorCarta = "";
	
	switch(pJogada)
	{
		case 1: v1 = valor; valorCarta = c1; break;
		case 2: v2 = valor; valorCarta = c2; break;
		case 3: v3 = valor; valorCarta = c3; break;
		case 4: v4 = valor; valorCarta = c4; break;
		case 5: v5 = valor; valorCarta = c5; break;
		case 6: v6 = valor; valorCarta = c6; break;
		case 7: v7 = valor; valorCarta = c7; break;
		case 8: v8 = valor; valorCarta = c8; break;
		case 9: v9 = valor; valorCarta = c9; break;
		case 10: v10 = valor; valorCarta = c10; break;
		case 11: v11 = valor; valorCarta = c11; break;
		case 12: v12 = valor; valorCarta = c12; break;
	
	}	
	
	return valorCarta;
}

bool cartaJaVirada(int pJogada)
{
    switch(pJogada)
    {
        case 1: return v1 != 0;
        case 2: return v2 != 0;
        case 3: return v3 != 0;
        case 4: return v4 != 0;
        case 5: return v5 != 0;
        case 6: return v6 != 0;
        case 7: return v7 != 0;
        case 8: return v8 != 0;
        case 9: return v9 != 0;
        case 10: return v10 != 0;
        case 11: return v11 != 0;
        case 12: return v12 != 0;
        default: return false;
    }
}



int main () 
{	
	int jogador = 1; 
    int jogada1 = 0, jogada2 = 0;
    bool jogarNovamente = false;
    
    tabuleiro ();
    
    while (true) {
        if (!jogarNovamente) {
            do {
                cout << "Jogador " << jogador << " escolha uma carta de 1 a 12: ";
                cin >> jogada1;
            } while (cartaJaVirada(jogada1));
            
            system("cls");
            carta1 = viraCarta(jogada1, 1);   
            tabuleiro ();
        }

        do {
            cout << "Jogador " << jogador << " escolha outra carta de 1 a 12: ";
            cin >> jogada2;
        } while (cartaJaVirada(jogada2));
        
        system("cls");
        carta2 = viraCarta(jogada2, 1);   
        tabuleiro ();

        if(carta1 != carta2)
        {
            viraCarta(jogada1, 0);
            viraCarta(jogada2, 0);
            system("pause");
            system("cls");
            tabuleiro ();
        }
        else
        {
            cout << "Jogador " << jogador << " encontrou um par!" << endl;
            if (jogador == 1) pontosJogador1++;
            else pontosJogador2++;
            cout << "Pontos do Jogador 1: " << pontosJogador1 << endl;
            cout << "Pontos do Jogador 2: " << pontosJogador2 << endl;
            system("pause");
            system("cls");
            tabuleiro ();
            jogarNovamente = true;
        }
        
        if ((pontosJogador1 + pontosJogador2) == 6) {
            cout << "Fim do jogo!" << endl;
            if (pontosJogador1 > pontosJogador2) cout << "Jogador 1 venceu!" << endl;
            else if (pontosJogador2 > pontosJogador1) cout << "Jogador 2 venceu!" << endl;
            else cout << "Empate!" << endl;
            break;
        }

        if (!jogarNovamente)
            jogador = (jogador == 1) ? 2 : 1;
        else
            jogarNovamente = false;
    }
    
    return 0;
}
