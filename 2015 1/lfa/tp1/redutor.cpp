#include <bits/stdc++.h>

using namespace std;

vector<string> line;

void split(string s){
	line.clear();

	for (int i = 0; i < s.size(); ++i){
		if(s[i] == '\t' || 
		   s[i] == '-'  || 
		   s[i] == '>'  || 
		   s[i] == '{'  ||
		   s[i] == '}'  ||
		   s[i] == ','  ||
		   s[i] == ':'  ||
		   s[i] == ';')
			s[i] = ' ';
	}

	int i=0, j=0;
	
	while(1){
		i = s.find_first_not_of(' ', j);

		if(i == -1)
			break;

		j = s.find_first_of(' ', i);

		line.push_back(s.substr(i, j-i));
	}
}

class AFD{
public:
	vector<string> estados;
	vector<string> alfabeto;
	map< string, vector<string> > transicoes;
	vector<string> iniciais;
	vector<string> finais;

	// qual grupo o estado pertence
	map<string, int> ref;
	// grupos com os estados
	vector< vector<string> > grupos;


	// verifica se o estado é inicial
	bool ehInicial(string estado){		
		for (int i = 0; i < iniciais.size(); ++i)
			if(estado == iniciais[i])
				return true;

		return false;
	}

	// verifica se o estado é final
	bool ehFinal(string estado){
		for (int i = 0; i < finais.size(); ++i)
			if(estado == finais[i])
				return true;

		return false;
	}

	// verifica se dois estados estao no mesmo grupo
	// e se suas transicoes levam para os mesmos grupos
	bool ehIgual(string e1, string e2){
		if(ref[e1] == ref[e2]){
			vector<string> t1 = transicoes[e1];
			vector<string> t2 = transicoes[e2];

			for (int i = 0; i < t1.size(); ++i)
				if(ref[t1[i]] != ref[t2[i]])
					return false;

			return true;
		}

		return false;
	}

	// procura um grupo para um estado
	// caso não exista, retorna -1
	int procuraGrupo(string e){
		for (int i = 0; i < grupos.size(); ++i)
			if(ehIgual(grupos[i][0], e))
				return i;
		
		return -1;
	}


	// remove um estado de determinado grupo
	void removeDoGrupo(string e, int g){
		ref[e] = -1;
		for (int i = 0; i < grupos[g].size(); ++i){
			if(grupos[g][i] == e){
				grupos[g].erase(grupos[g].begin() + i);
				break;
			}
		}
	}

	// insere estado em determinado grupo
	void colocaNoGrupo(string e, int g){
		ref[e] = g;
		grupos[g].push_back(e);
	}


	// muda o estado de grupo
	void mudaGrupo(string e){
		int g = procuraGrupo(e);
		if(g == -1){
			removeDoGrupo(e, ref[e]);
			vector<string> v;
			v.push_back(e);
			grupos.push_back(v);
			ref[e] = grupos.size() - 1;
		}
		else {
			removeDoGrupo(e, ref[e]);			
			colocaNoGrupo(e, g);
		}
	}

	// separa os estados finais e não-finais
	// em dois grupos
	void inicializa(){
		for (int i = 0; i < estados.size(); ++i){
			if(ehFinal(estados[i])){				
				grupos[0].push_back(estados[i]);				
				ref[estados[i]] = 0;
			}
			else{
				grupos[1].push_back(estados[i]);
				ref[estados[i]] = 1;
			}
		}
	}


	void imprime(){
		cout << endl;
		for (int i = 0; i < estados.size(); ++i){
			cout << estados[i] << " ";
			for (int j = 0; j < transicoes[estados[i]].size(); ++j){
				cout << transicoes[estados[i]][j] << " ";
			}
			cout << endl;
		}
	}

	// insere estado no vector de iniciais
	// a funcao e util para a minimizacao
	// para que nao se insera estados repetidos
	void insereInicial(string e){
		// verifica se já inseriu
		for (int i = 0; i < iniciais.size(); ++i)
			if(iniciais[i] == e)
				return;
		
		// caso contrario insere
		iniciais.push_back(e);
	}

	// insere estado no vector de finais
	void insereFinal(string e){
		// verifica se já inseriu
		for (int i = 0; i < finais.size(); ++i)
			if(finais[i] == e)
				return;
		
		// caso contrario insere
		finais.push_back(e);
	}

	void geraMinimo(){
		AFD novo;

		novo.alfabeto = alfabeto;

		// cada grupo se torna um estado
		for (int i = 0; i < grupos.size(); ++i)
			novo.estados.push_back("G" + to_string(i));
		
		// insere os estados iniciais
		for (int i = 0; i < iniciais.size(); ++i)
			novo.insereInicial("G" + to_string(ref[iniciais[i]]));
		
		// insere os estados finais
		for (int i = 0; i < finais.size(); ++i)
			novo.insereFinal("G" + to_string(ref[finais[i]]));

		// insere as transicoes
		for (int i = 0; i < grupos.size(); ++i){
			for (int j = 0; j < alfabeto.size(); ++j){
				string e = grupos[i][0];
				e = "G" + to_string(ref[transicoes[e][j]]);
				novo.transicoes[novo.estados[i]].push_back(e);
			}
		}

		*this = novo;
	}


	void removeEstadosInuteis(){
		set<string> alcancaveis;

		for (int i = 0; i < iniciais.size(); ++i)
			alcancaveis.insert(iniciais[i]);
		
		set<string>::iterator it = alcancaveis.begin();

		while(it != alcancaveis.end()){
			int flag = 0;

			for (int i = 0; i < alfabeto.size(); ++i){
				string e = transicoes[*it][i];
				if(alcancaveis.count(e) == 0){
					alcancaveis.insert(e);
					flag = 1;
				}
			}
			if(flag)
				it = alcancaveis.begin();
			else
				it++;
		}

		for (int i = 0; i < estados.size(); ++i){
			if(!alcancaveis.count(estados[i])){
				transicoes.erase(transicoes.find(estados[i])); 
				estados.erase(estados.begin() + i);
				i = -1;
			}
		}

	}

	void minimiza(){
		// separa os grupos
		vector<string> v;
		vector<string> dif;
		vector<string> aux;
		grupos.push_back(v); // iniciais
		grupos.push_back(v); // nao iniciais

		inicializa();

		removeEstadosInuteis();

		int mudou = 1;

		while(mudou){
			mudou = 0;

			for (int i = 0; i < grupos.size(); ++i){
				dif.clear();
				for (int j = 1; j < grupos[i].size(); ++j){
					//verifica se o elemento ainda pertence ao grupo
					if(ehIgual(grupos[i][j], grupos[i][0]))
						continue;

					dif.push_back(grupos[i][j]);
				}
				
				vector<string> aux;

				for (int j = 0; j < dif.size(); ++j){
					aux.push_back(dif[j]);
					for (int k = j+1; k < aux.size(); ++k)
						if(ehIgual(aux[j], aux[k]))
							aux.push_back(aux[k]);

					mudaGrupo(aux[0]);
					for (int k = 1; k < aux.size(); ++k){
						removeDoGrupo(aux[k], ref[aux[k]]);
						colocaNoGrupo(aux[k], ref[aux[0]]);
					}		
	
					mudou = 1;
				}
			}
		}

		geraMinimo();
	}

	int read(string arquivo){
		int na, ne, nt, ni, nf;
		string s;

		ifstream file(arquivo);

		// ESTADOS
		file.ignore(256, '(');
		file >> ne;
		file.ignore(256, ' ');

		for (int i = 0; i < ne; ++i){
			file >> s;
			s.pop_back();
			estados.push_back(s);
		}

		// ALFABETO
		file.ignore(256, '(');
		file >> na;
		file.ignore(256, ' ');

		for (int i = 0; i < na; ++i){
			file >> s;
			s.pop_back();
			alfabeto.push_back(s);
		}

		// TRANSIÇÕES
		file.ignore(256, '(');
		file >> nt;
		getline(file, s);

		for (int i = 0; i < nt; ++i){
			getline(file, s);
			split(s);
			for (int i = 1; i < line.size(); ++i)
				transicoes[line[0]].push_back(line[i]);
		}

		// INICIAIS
		file.ignore(256, '(');
		file >> ni;
		file.ignore(256, ' ');

		for (int i = 0; i < ni; ++i){
			file >> s;
			s.pop_back();
			iniciais.push_back(s);
		}
		
		// FINAIS
		file.ignore(256, '(');
		file >> nf;
		file.ignore(256, ' ');

		for (int i = 0; i < nf; ++i){
			file >> s;
			s.pop_back();
			finais.push_back(s);
		}

		file.close();
	}

	// gera arquivo tipo dot
	void dot(string arquivo){
		ofstream myfile;
		myfile.open(arquivo);

		myfile << "digraph \"AFD\" {\n";

		for (int i = 0; i < iniciais.size(); ++i){
			myfile << "\t_nil [style=\"invis\"];\n";
			myfile << "\t_nil -> " << iniciais[i] <<" [label=\"\"];\n";
		}

		for (int i = 0; i < finais.size(); ++i){
			myfile << "\t" << finais[i] << " [peripheries=2];\n";
		}

		for (int i = 0; i < estados.size(); ++i){
			for (int j = 0; j < alfabeto.size(); ++j){
				myfile << "\t" << estados[i] << " -> " << transicoes[estados[i]][j] << " [label=" << alfabeto[j] << "];" << endl;
			}
		}

		myfile << "}";

		myfile.close();
	}

};

int main(int argc, char const *argv[]){

	string afd_entrada, orig_dot, min_dot;

	for (int i = 1; i < argc; i += 2){
		string s = argv[i];

		if(s == "-o"){
			orig_dot = argv[i+1];
			continue;
		}
		if(s == "-m"){
			min_dot = argv[i+1];
			continue;
		}

		afd_entrada = s;
	}

	AFD original, min;
	
	original.read(afd_entrada);
	min = original;
	min.minimiza();
	
	if(original.estados.size() == min.estados.size())
		cout << "Sim" << endl;
	else
		cout << "Nao" << endl;

	if(!orig_dot.empty())
		original.dot(orig_dot);
		
	if(!min_dot.empty())
		min.dot(min_dot);
}