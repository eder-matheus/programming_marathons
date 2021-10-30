#include <iostream>
#include <vector>
#include <string>

#include <iostream>
#include <fstream>

using namespace std;

int N;

int soluciona(int c) {
    if (c < N)
        return c;

    int tam_palavra = 1;
    int tam_seq = N;

    while ((tam_seq*tam_palavra) < c) {
        c = c - (tam_seq*tam_palavra);
        tam_seq = tam_seq*N;
        tam_palavra += 1;
    }
    tam_seq = tam_seq*tam_palavra;
    
    bool sair = false;
    int obj = c;
    int group = 0;
    int i = 0;
    while(obj != 0 and !sair) {
        tam_seq = tam_seq/N;
        group = obj/tam_seq;
        obj = obj%tam_seq;
        sair = (obj%tam_palavra == i++);
    }

    return group;
}

int main() {
    int Q, c;

    ofstream myfile;
    myfile.open ("example.txt");
   
    while(cin >> N >> Q) {
        if(!N && !Q)
            break;
        
        vector<string> titulos(N);
      
        for(int i = 0; i < Q; i++)
            cin >> titulos[i];

        for(int i = 0; i < Q; i++) {
            cin >> c;
            int index = soluciona(c-1);
            string titulo_certo = titulos[index];

            myfile << titulo_certo << endl;
        }

        myfile << endl;
    }
    myfile.close();
}