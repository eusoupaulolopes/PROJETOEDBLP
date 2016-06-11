## Resumo

**buscaIMD** é um programa para uso no terminal linux, basicamente, seu objetivo é receber, via linha de comando, palavras-chave para entregar quais linhas dos arquivos em uma determinada base de buscas contem os termos buscados, segundo critério préviamente estipulado.

## Funcionamento

O programa funciona através do gerenciamento de arquivos-texto cadastrados em uma base de busca, é possivel inserir, atualizar, remover e listar arquivos dessa base.
Com os arquivos pre-processados nessa base é possivel buscar por ocorrencia de termos nos arquivos-texto inseridos na base. Dois modos distintos são válidos: 
* -bAND retorna a conjunção dos termos nas linhas dos arquivos. 
* -bOR entrega a disjunção dos termos. 

É possivel imprimir a lista de ocorrencias por dados critérios:
* -pC : por ordem de ocorrencia nos arquivos;
* -pA : por ordem alfabetica do nome dos arquivos-texto na base;
* -pI : por ordem de inserção dos arquivos-text na base.

No mais, é disponibilizado opcionalmente, o tempo total das buscas em milisegundos.


## Instalação
baixe uma copia do projeto em [buscaIMD].
- desconpacte os arquivos
- No terminal, acesse a pasta criada
- execute:
```sh
 $ make
```       
caso preferir compilar manualmente:

```sh
$    g++ -w main.cpp funcoes/inserir.cpp suporte.cpp funcoes/estruturas.cpp funcoes/remover.cpp funcoes/listar.cpp funcoes/buscar.cpp funcoes/listabusca.cpp funcoes/relogio.cpp -o buscaIMD -std=c++11
```    
   

## Uso
Para gerenciar a base de busca:
```sh
> ./buscaIMD <opção> <nome_arquivo> 
```
onde <opção> recebe qualquer um dos seguintes paramentos:
* -i insere <nome_arquivo> na base de busca (atualiza o mesmo caso já exista)
* -r remove <nome_arquivo> na base de busca
* -li lista arquivos na base de busca por ordem de inserção
* -la lista arquivos na base de busca por ordem alfabetica
* -lt lista arquivos na base de busca por por quantidade de palavras
 

## Tests

Describe and show how to run the tests with code examples.

## Contributors

Let people know how they can dive into the project, include important links to things like issue trackers, irc, twitter accounts if applicable.

## License

A short snippet describing the license (MIT, Apache, etc.)


[buscaIMD]: <https:///github.com/lopespaulo/PROJETOEDBLP/archive/master.zip>


