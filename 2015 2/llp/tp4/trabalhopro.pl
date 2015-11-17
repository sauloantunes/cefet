code = 2000

Domains

    cod_emprestimo = integer
    cod_cliente    = integer
    cod_livro      = integer
    idade          = integer
    titulo         = string
    genero         = string
    nome           = string
    data           = string    

    lista_str   = string*
    lista_int   = integer*


Database

         livro (                  cod_livro,    titulo,  genero)
       cliente (                cod_cliente,      nome,  idade)
    emprestimo (cod_emprestimo, cod_cliente, cod_livro,  data)


Predicates

    add_cliente.
    rem_cliente (integer, integer)
    bus_cliente (integer, integer).

    add_livro.
    bus_livro (integer,integer).
    rem_livro (integer,integer).

    lis_clientes.
    lis_livros.

    log_cliente (integer, integer).
    log_livro   (integer, integer).

    imp_clientes    (lista_int).
    imp_livros      (lista_int).
    imp_emprestimos (lista_int, integer).

    qtd_clientes    (integer)
    qtd_livros      (integer)
    qtd_emprestimos (integer)

    qtd (lista_int, integer)

    pegar.

    menu     (integer, string).
    boot     (integer).
    processa (integer).
  
    cab (string).                /*Cabeçalho*/
    opc (lista_str, integer).    /*Opções*/
    rod (string).                /*Rodape*/
    rep (string, integer).       /*Repete*/
    
    le_i (string,integer).
    le_s (string,string).


Clauses

    opc([],_) :- !.
    opc([S|L],N) :- 
            write("  ", N, " - ", S),nl,
            N1 = N + 1,
            opc(L,N1).
                    
    rep(_,0) :- !.
    rep(C,N) :- 
            write(C), 
            N1 = N-1,
            rep(C,N1). 

    le_i(M,I) :-
            nl, write(M), readInt(I), nl.

    le_s(M,S) :-
            nl, write(M), readln(S), nl.
  
    cab(Titulo) :-  
            str_len(Titulo,T),
            N = (24 - T)/2 ,
            clearwindow,nl,
            rep(" ", N),
            write(Titulo),nl,
            rep("-", 24).

    rod(Mensagem) :-
            nl,write(Mensagem),
            readchar(_).

    qtd([],0) :- !.
    qtd([_|L],N) :- 
            qtd(L,N2), 
            N = N2 + 1.                

    qtd_clientes(N) :- 
            findall(X,cliente(X,_,_),L),
            qtd(L,N).

    qtd_livros(N) :-  
            findall(X,livro(X,_,_),L),
            qtd(L,N).                       

    qtd_emprestimos(N) :- 
            findall(X,emprestimo(X, _, _, _),L),
            qtd(L,N).

    processa(0) :- !.

    processa(1) :- add_cliente.
    processa(2) :- add_livro.

    processa(3) :- bus_cliente (0,_).
    processa(4) :- bus_livro   (0,_).
    
    processa(5) :- rem_cliente (0,_).
    processa(6) :- rem_livro   (0,_).

    processa(7) :- lis_clientes.
    processa(8) :- lis_livros.

    processa(9)  :- log_cliente (0,_).
    processa(10) :- log_livro   (0,_).
    
    processa(11) :- pegar.

    menu(0,_) :- 
            cab("BIBLIOTECA MAT014"),
            opc(["Nova","Carregar","Apagar"],1),
            opc(["Sair"],0),
            le_i("> ",Op),
            boot(Op).

    menu(1,Nome) :- 
            Nome = Nome,
            cab(Nome),

            write("Adicionar:"),nl,
            opc(["Cliente","Livro"],1),nl,
            
            write("Buscar:"),nl,
            opc(["Cliente","Livro"],3),nl,

            write("Remover:"),nl,
            opc(["Cliente","Livro"],5),nl,

            write("Listar:"),nl,
            opc(["Clientes","Livros"],7),nl,
            
            write("Relatorio:"),nl,
            opc(["Cliente","Livro"],9),nl,
            
            write("Emprestimo:"),nl,
            opc(["Pegar"],11),nl,
            
            opc(["Sair"],0),nl,
            le_i("> ",Op),

            processa(Op),

            Op <> 0,
            menu(1,Nome).

    menu(1,Nome) :- 
            Nome = Nome,
            save(Nome),!.

    boot(0) :- !.

    boot(1) :- 
            cab("Nova Biblioteca"),
            le_s("Nome: ",Nome),
            save(Nome),
            rod("Criado com sucesso"),
            menu(1,Nome).
    
    boot(2) :- 
            cab("Carregar Biblioteca"),
            le_s("Nome: ",Nome),
            consult(Nome),
            rod("Carregado com sucesso."),
            menu(1,Nome).

    boot(3) :- 
            cab("Apagar Biblioteca"),
            le_s("Nome: ",Nome),
            deletefile(Nome),
            rod("Apagado com sucesso."),
            menu(0,_).

    add_cliente() :- 
            cab("Adicionar Cliente"),
            le_s("Nome: ", Nome),
            not(cliente(_,Nome,_)),
            le_i("Idade: ", Idade),
            qtd_clientes(COD),
            COD1 = COD+1,
            assertz(cliente(COD1,Nome,Idade)),
            rod("Adicionado com sucesso.").

    add_cliente() :- 
            write("Cliente ja existe."),nl,
            rod("Tecle para continuar...").

    add_livro() :-
            cab("Adicionar Livro"),
            le_s("Titulo: ",Titulo),          
            not(livro(_,Titulo,_)),
            le_s("Genero: ",Genero),
            qtd_livros(COD),
            COD1 = COD+1,
            assertz(livro(COD1,Titulo,Genero)),
            rod("Adicionado com sucesso."),!.

    add_livro() :-   
            write("Livro ja existe."),nl,
            rod("Tecle para continuar...").

    rem_cliente(0,_) :- 
            cab("Remover Cliente"),
            opc(["Codigo","Nome"],1),
            le_i("> ",Op),
            rem_cliente(Op,_).

    rem_cliente(1,_) :-
            le_i("Informe o Cod: ",CodCliente),
            cliente(CodCliente, _, _),
            rem_cliente(3,CodCliente).

    rem_cliente(1,_) :- 
            nl,write("Codigo Invalido."),nl,
            rod("Tecle para continuar...").

    rem_cliente(2,_) :-
            le_s("Informe o Nome: ",Nome),
            cliente(CodCliente,Nome,_),
            rem_cliente(3,CodCliente).

    rem_cliente(2,_) :- 
            nl,write("Nome Invalido."),nl,
            rod("Tecle para continuar...").

    rem_cliente(3,CodCliente) :-
            retract(cliente(CodCliente, _, _)),
            /* PARA NAO ATRAPALHAR O COD AUTO */
            asserta(cliente(0," ",0)),
            write("Removido com sucesso."),nl,
            rod("Tecle para continuar..."),!.

    rem_cliente(N,_) :-
            N > 3, 
            write("Opcao Invalida."),nl,
            rod("Tecle para continuar..."),!.

    rem_livro(0,_) :- 
            cab("Remover Livro"),
            opc(["Codigo","Titulo"],1),
            le_i("> ",Op),
            rem_livro(Op,_).

    rem_livro(1,_) :-
            le_i("Informe o Cod: ",CodLivro),
            livro(CodLivro, _, _),
            rem_livro(3,CodLivro).

    rem_livro(1,_) :- 
            nl,write("Codigo Invalido."),nl,
            rod("Tecle para continuar...").

    rem_livro(2,_) :-
            le_s("Informe o Titulo: ",Titulo),
            livro(CodLivro,Titulo,_),
            rem_livro(3,CodLivro).

    rem_livro(2,_) :- 
            nl,write("Titulo Invalido."),nl,
            rod("Tecle para continuar...").

    rem_livro(3,CodLivro) :-
            retract(livro(CodLivro,_,_)),
            /* PARA NAO ATRAPALHAR O COD AUTO */
            asserta(livro(0," "," ")),
            write("Removido com sucesso."),nl,
            rod("Tecle para continuar..."),!.

    rem_livro(N,_) :-
            N > 3, 
            write("Opcao Invalida."),nl,
            rod("Tecle para continuar..."),!.

    bus_cliente(0,_) :- 
            cab("Buscar Cliente"),
            opc(["Codigo","Nome"],1),
            le_i("> ",Op),
            bus_cliente(Op,_).

    bus_cliente(1,_) :-
            le_i("Informe o Cod: ",CodCliente),
            cliente(CodCliente, _, _),
            bus_cliente(3,CodCliente).

    bus_cliente(1,_) :- 
            nl,write("Codigo Invalido."),nl,
            rod("Tecle para continuar...").

    bus_cliente(2,_) :-
            le_s("Informe o Nome: ",Nome),
            cliente(CodCliente,Nome,_),
            bus_cliente(3,CodCliente).

    bus_cliente(2,_) :- 
            nl,write("Nome Invalido."),nl,
            rod("Tecle para continuar...").

    bus_cliente(3,CodCliente) :-
            cliente(CodCliente,Nome,Idade),
            write("Codigo: ",CodCliente),nl,
            write("  Nome: ",Nome),nl,
            write(" Idade: ",Idade),nl,
            rod("Tecle para conitnuar...").

    bus_cliente(N,_) :-
            N > 3, 
            write("Opcao Invalida."),nl,
            rod("Tecle para continuar..."),!.

    bus_livro(0,_) :- 
            cab("Buscar Livro"),
            opc(["Codigo","Titulo"],1),
            le_i("> ",Op),
            bus_livro(Op,_).

    bus_livro(1,_) :-
            le_i("Informe o Cod: ",CodLivro),
            livro(CodLivro, _, _),
            bus_livro(3,CodLivro).

    bus_livro(1,_) :- 
            nl,write("Codigo Invalido."),nl,
            rod("Tecle para continuar...").

    bus_livro(2,_) :-
            le_s("Informe o Titulo: ",Titulo),
            livro(CodLivro,Titulo,_),
            bus_livro(3,CodLivro).

    bus_livro(2,_) :- 
            nl,write("Titulo Invalido."),nl,
            rod("Tecle para continuar...").

    bus_livro(3,CodLivro) :-
            livro(CodLivro,Titulo,Genero),
            write("Codigo: ", CodLivro),nl,
            write("Titulo: ", Titulo),nl,
            write("Genero: ", Genero),nl,
            rod("Tecle para conitnuar...").

    bus_livro(N,_) :-
            N > 3, 
            write("Opcao Invalida."),nl,
            rod("Tecle para continuar..."),!.

    imp_clientes([]) :- !.

    imp_clientes([0|CodClientes]) :- 
            imp_clientes(CodClientes).

    imp_clientes([CodCliente|CodClientes]) :-
            cliente(CodCliente,Nome,Idade),
            write("  COD: ",CodCliente),nl,
            write(" Nome: ",Nome),nl,
            write("Idade: ",Idade),nl,
            rep("-",24),nl,
            imp_clientes(CodClientes). 

    imp_livros([]) :- !.

    imp_livros([0|CodLivros]) :- 
            imp_livros(CodLivros).

    imp_livros([CodLivro|CodLivros]) :-
            livro(CodLivro,Titulo,Genero),
            write("   COD: ",CodLivro),nl,
            write("  Nome: ",Titulo),nl,
            write("Genero: ",Genero),nl,
            rep("-",24),nl,
            imp_livros(CodLivros).

    imp_emprestimos([],_) :- !.

    imp_emprestimos([Emprestimo|Emprestimos], 0) :-
            emprestimo(Emprestimo,_ ,CodLivro,Data),
            livro(CodLivro,Titulo,_),
            write("   COD: ",Emprestimo),nl,
            write("Titulo: ",Titulo),nl,
            write("  Data: ",Data),nl,
            rep("-",24),nl,
            imp_emprestimos(Emprestimos, 0),!.

    imp_emprestimos([Emprestimo|Emprestimos], 0) :-
            write("   COD: ",Emprestimo),nl,
            write("  NOTA: Livro excluido"),nl,
            rep("-",24),nl,
            imp_emprestimos(Emprestimos, 0).


    imp_emprestimos([Emprestimo|Emprestimos], 1) :-
            emprestimo(Emprestimo,CodCliente,_ ,Data),
            cliente(CodCliente,Nome,_),
            write("   COD: ",Emprestimo),nl,
            write("  Nome: ",Nome),nl,
            write("  Data: ",Data),nl,
            rep("-",24),nl,
            imp_emprestimos(Emprestimos, 1),!.

    imp_emprestimos([Emprestimo|Emprestimos], 1) :-
            write("   COD: ",Emprestimo),nl,
            write("  NOTA: Cliente excluido"),nl,
            rep("-",24),nl,
            imp_emprestimos(Emprestimos, 1).

    lis_clientes() :- 
            cab("Clientes"),
            findall(X,cliente(X,_,_),CodClientes),
            imp_clientes(CodClientes),
            rod("Tecle para continuar...").

    lis_livros() :- 
            cab("Livros"),
            findall(X,livro(X,_,_),CodLivros),
            imp_livros(CodLivros),
            rod("Tecle para continuar...").

    log_cliente(0,_) :- 
            cab("Log Cliente"),
            opc(["Codigo","Nome"],1),
            le_i("> ",Op),
            log_cliente(Op,_).

    log_cliente(1,_) :-
            le_i("Informe o Codigo: ",CodCliente),
            cliente(CodCliente,_,_),
            log_cliente(3,CodCliente).

    log_cliente(1,_) :- 
            nl,write("Codigo Invalido."),nl,
            rod("Tecle para continuar...").

    log_cliente(2,_) :-
            le_s("Informe o Nome: ",Nome),
            cliente(CodCliente,Nome,_),
            log_cliente(3,CodCliente).

    log_cliente(2,_) :- 
            nl,write("Nome Invalido."),nl,
            rod("Tecle para continuar...").

    log_cliente(3,CodCliente) :-
            cliente(CodCliente,Nome,Idade),
            cab("Log Cliente"),
            write("  COD: ",CodCliente),nl,
            write(" Nome: ",Nome),nl,
            write("Idade: ",Idade),nl,nl,
            findall(X,emprestimo(X,CodCliente,_,_),CodEmprestimos),
            qtd(CodEmprestimos,Qtd),
            write("Emprestimos: ", Qtd),nl,nl,
            imp_emprestimos(CodEmprestimos, 0),
            rod("Tecle para continuar..."),!.            

    log_cliente(N,_) :-
            N > 3, 
            write("Opcao Invalida."),nl,
            rod("Tecle para continuar..."),!.

    log_livro(0,_) :- 
            cab("Log Livro"),
            opc(["Codigo","Titulo"],1),
            le_i("> ",Op),
            log_livro(Op,_).

    log_livro(1,_) :-
            le_i("Informe o Codigo: ",CodLivro),
            Livro(CodLivro,_,_),
            log_livro(3,CodLivro).

    log_livro(1,_) :- 
            nl,write("Codigo Invalido."),nl,
            rod("Tecle para continuar...").

    log_livro(2,_) :-
            le_s("Informe o Titulo: ",Titulo),
            Livro(CodLivro,Titulo,_),
            log_livro(3,CodLivro).

    log_livro(2,_) :- 
            nl,write("Titulo Invalido."),nl,
            rod("Tecle para continuar...").

    log_livro(3,CodLivro) :-
            Livro(CodLivro,Titulo,Genero),
            cab("Log Livro"),
            write("   COD: ",CodLivro),nl,
            write("Titulo: ",Titulo),nl,
            write("Genero: ",Genero),nl,nl,
            findall(X,emprestimo(X,_,CodLivro,_),CodEmprestimos),
            qtd(CodEmprestimos,Qtd),
            write("Emprestimos: ", Qtd),nl,nl,
            imp_emprestimos(CodEmprestimos, 1),
            rod("Tecle para continuar..."),!.

    log_livro(N,_) :-
            N > 3, 
            write("Opcao Invalida."),nl,
            rod("Tecle para continuar..."),!.

    pegar() :- 
            cab("Pegar Livro"),
            le_i("Cod Cliente: ",CodCliente),
            cliente(CodCliente,_,_),
            le_i("Cod Livro: ",CodLivro),
            livro(CodLivro,_,_),
            le_s("Data: ",Data),
            qtd_emprestimos(COD),
            COD1 = COD + 1,
            assertz(emprestimo(COD1,CodCliente,CodLivro,Data)),
            rod("Adicionado com sucesso."),!.

    pegar() :- 
            write("Codigo Invalido."),nl,
            rod("Tecle para continuar..."),!.


Goal
    menu(0,_).
