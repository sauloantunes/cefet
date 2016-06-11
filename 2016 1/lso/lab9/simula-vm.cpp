#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
	string s = argv[1];
	int quadros = stoi(s.c_str());

	int paginasNaFila[100000];
	memset(paginasNaFila, 0, sizeof paginasNaFila);
	
	queue<int> fila;

	int referencias = 0;
	int falhas = 0;
	int n;

	while(cin >> n){
		referencias++;

		if(paginasNaFila[n])
			continue;
		
		falhas++;
		paginasNaFila[n] = 1;

		if(fila.size() < quadros){
			fila.push(n);
		}
		else{
			paginasNaFila[fila.front()] = 0;
			fila.pop();
			fila.push(n);
			cout << endl;
		}
	}

	cout << "Quadros: " << quadros << endl;
	cout << "Referências: " << referencias << endl;
	cout << "Falhas: " << falhas << endl;
	cout << endl;

	return 0;
}