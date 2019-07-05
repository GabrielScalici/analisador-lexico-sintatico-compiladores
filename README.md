<p align="center">
  <img src="https://media.giphy.com/media/NAcNfRrU6f2bC/giphy.gif"/>
  <h1 align="center">Analisador Léxico e Sintático </h1>
  <p align="center"> SCC0217 - Compiladores, ICMC - USP.</p>
</p>

<p align="center">
  <img src="http://ForTheBadge.com/images/badges/made-with-c.svg"/>
</p>

# Descrição Analisador Léxico

* As seguintes tarefas devem ser desenvolvidas neste trabalho prático:

1. Modelar a tarefa do analisador léxico: tokens possíveis, expressões regulares utilizadas, formas de tratamento de erros (ver slides das aulas).

2. Buscar e estudar o lex/flex ou JavaCC: note que quase todos os livros de compiladores têm apresentações dessas ferramentas; também há muitos tutorias na Web (alguns estão disponíveis no site da disciplina). O grupo pode decidir por implementar o analisador de maneira manual, sem o uso das ferramentas mencionadas.

3. Gerar o analisador léxico usando o lex/flex ou javaCC: o grupo deve incorporar no lex/flex/javaCC a geração de uma função principal que analise todo o arquivo de entrada, chamando o analisador léxico várias vezes, o qual, a cada chamada, deve retornar um único par <cadeia,token>. Note que esta função será substituída posteriormente pelo analisador sintático.



# Descrição Analisador Sintático

* Especificação: implementar o analisador sintático para a linguagem LALG, usando YACC ou JAVACC. A implementação também pode ser feita manualmente.

* As seguintes tarefas devem ser desenvolvidas neste trabalho prático:

1. (Para quem não implementar manualmente) Buscar e estudar o YACC ou JavaCC: note que quase todos os livros de compiladores têm apresentações dessas ferramentas; também há muitos tutorias na Web (alguns estão disponíveis no site da disciplina).

2. Gerar o analisador sintático usando o YACC ou JavaCC: substitua o programa principal do Trabalho 1 pelo analisador sintático. Corrija o analisador léxico (se necessário).

3. Implementar o tratamento de erro usando o modo pânico, sempre relatando os erros para o usuário.


# :file_folder: Organização das pastas

    .
    ├── ...
    ├── test                     # Arquivos para testes no projeto
    ├── MakeFile                 # Arquivo para facilitar a compilação do projeto e execução.
    ├── Relatório                # Infos detalhadas do projeto
    ├── main                     # Programa compilado
    ├── lalg.l                   # programa Lex para a linguagem LALG
    ├── lalg.y                   # programa em Bison para a linguagem LALG.
    ├── ...
    .
    
    
# :cd: Como usar:

### Compilar
```
make
```

### Testar
```
make run
```

