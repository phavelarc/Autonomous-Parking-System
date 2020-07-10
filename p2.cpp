
//Pedro Henrique Avelar Curiel
//Horário de funcionamento para cálculo-> 8:00h às 18:00h

#include <iostream>
#include <time.h>

using namespace std;

int main(){
    string andar1carro[20], andar1caminhonete[30], andar2[25], andar3[10], andar4[15], andar5[20];
    string placa;
    int carro_atendido = 0, caminhonete_atentida = 0, lotacao = 0, faturamento_total = 0, escolha, escolha_auto, escolha_andar, escolha_vaga;
    float faturamento_medio = 0;
    int i = 1, total_vagas = 120, tempo, cobrar;
    time_t t;
    struct tm * infoTempo1; //entrada
    struct tm * infoTempo2; //saída

    do {
        cout << "[1] Deixar automóvel?" << endl;
        cout << "[2] Retirar automóvel?" << endl;
        cout << "[3] Veículos que não foram atendidos por lotação" << endl;
        cout << "[4] Faturamento médio por hora e faturamento total" << endl;
        cout << "[0] Sair" << endl;
        cin >> escolha;

        if (escolha == 1){                  // Deixar
            cout << "Qual tipo?" << endl;
            cout << "[1] Carro" << endl;
            cout << "[2] Caminhonete" << endl;
            cin >> escolha_auto;
            
            time(&t);
            infoTempo1 = localtime(&t);
            cout << "Hora e data de entrada: " << asctime(infoTempo1) << endl;

            if (escolha_auto == 1){
                carro_atendido++;
                cout << "Deixar em qual andar?\nAndar 1, Andar 2 ou Andar 4" << endl;
                cin >> escolha_andar;
                cout << "Qual a placa?" << endl;
                cin >> placa;
                cout << "Estacionado!" << endl;

                switch (escolha_andar){
                    case 1:
                        andar1carro[i] = placa;
                    case 2:
                        andar2[i] = placa;
                    case 4:
                        andar4[i] = placa;
                }
            }
            else {
                if (escolha_auto == 2){
                    caminhonete_atentida++;
                    cout << "Deixar em qual andar?\nAndar 1, Andar 3 ou Andar 5" << endl;
                    cin >> escolha_andar;
                    cout << "Qual a placa?" << endl;
                    cin >> placa;
                    cout << "Estacionado!" << endl;

                    switch (escolha_andar){
                        case 1:
                            andar1caminhonete[i] = placa;
                        case 3:
                            andar3[i] = placa;
                        case 5:
                            andar5[i] = placa;
                    }
                }
                else {
                    cout << "Apenas carro ou caminhonete!" << endl;
                }
            }
            total_vagas--;
        }
        else {
            if (escolha == 2){              //Retirar
                cout << "Qual tipo?" << endl;
                cout << "[1] Carro" << endl;
                cout << "[2] Caminhonete" << endl;
                cin >> escolha_auto;

                time(&t);
                infoTempo2 = localtime(&t);
                cout << "Hora e data de saída: " << asctime(infoTempo2) << endl;

                if (escolha_auto == 1){
                    cout << "Retirar em qual andar?\nAndar 1, Andar 2 ou Andar 4" << endl;
                    cin >> escolha_andar;

                    switch (escolha_andar){
                        case 1:
                            for(i = 1; i <= 20; i++){
                                cout << andar1carro[i] << endl;
                            }
                            cout << "Insira a placa: " << endl;
                            cin >> placa;
                            cout << "Retirando carro..." << endl;
                            break;
                        case 2:
                            for(i = 1; i <= 25; i++){
                                cout << andar2[i] << endl;
                            }
                            cout << "Insira a placa: " << endl;
                            cin >> placa;
                            cout << "Retirando carro..." << endl;
                            break;
                        case 4:
                            for(i = 1; i <= 15; i++){
                                cout << andar4[i] << endl;
                            }
                            cout << "Insira a placa: " << endl;
                            cin >> placa;
                            cout << "Retirando carro..." << endl;
                            break;
                    }
                }
                else {
                    if (escolha_auto == 2){
                        cout << "Retirar em qual andar?\nAndar 1, Andar 2 ou Andar 4" << endl;
                        cin >> escolha_andar;
                    
                        switch (escolha_andar){
                            case 1:
                                for(i = 1; i <= 30; i++){
                                    cout << andar1caminhonete[i] << endl;
                                }
                                cout << "Insira a placa: " << endl;
                                cin >> placa;
                                cout << "Retirando caminhonete..." << endl;
                                break;
                            case 3:
                                for(i = 1; i <= 10; i++){
                                    cout << andar3[i] << endl;
                                }
                                cout << "Insira a placa: " << endl;
                                cin >> placa;
                                cout << "Retirando caminhonete..." << endl;
                                break;
                            case 5:
                                for(i = 1; i <= 20; i++){
                                    cout << andar5[i] << endl;
                                }
                                cout << "Insira a placa: " << endl;
                                cin >> placa;
                                cout << "Retirando caminhonete..." << endl;
                                break;
                        }
                    }    
                    else {
                        cout << "Opção Inválida!" << endl;
                    }   
                }
                
                total_vagas++;
                tempo = infoTempo2->tm_hour - infoTempo1->tm_hour;
                if (escolha_auto == 1){
                    cobrar = tempo * 5;
                }
                else {
                    cobrar = tempo * 7;        
                }
                cout << "Valor à cobrar: R$ " << cobrar << endl;
            }
            else {
                if (escolha == 3){
                    if (total_vagas <= 0){
                        lotacao++;
                    }
                    cout << "A quantidade de carros não atendidos devido a lotação é: " << lotacao << endl;
                }
                else {
                    if(escolha == 4){
                        faturamento_medio += cobrar / 12;
                        faturamento_total += cobrar;
                        cout << "Faturamento médio: R$" << faturamento_medio << endl;
                        cout << "Faturamento total: R$" << faturamento_total << endl;
                    }
                }
            }
        }
        i++;
        
    } while (escolha != 0);

    return 0;
}