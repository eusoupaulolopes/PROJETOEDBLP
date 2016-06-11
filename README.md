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
1) desconpacte os arquivos,
2) No terminal, acesse a pasta criada,
3) execute:
```sh
 $ make
```       
caso preferir compilar manualmente:

```sh
$    g++ -w main.cpp funcoes/inserir.cpp suporte.cpp funcoes/estruturas.cpp funcoes/remover.cpp funcoes/listar.cpp funcoes/buscar.cpp funcoes/listabusca.cpp funcoes/relogio.cpp -o buscaIMD -std=c++11
```    
   

## Uso
**Gerenciamento da base de busca:**

```sh
> ./buscaIMD <opção> <nome_arquivo> 
```
 onde < opção > deve recebe qualquer um dos seguintes paramentos:
* -i insere < nome_arquivo > na base de busca (atualiza o mesmo caso já exista)
* -r remove < nome_arquivo > na base de busca
* -li lista arquivos na base de busca por ordem de inserção
* -la lista arquivos na base de busca por ordem alfabetica
* -lt lista arquivos na base de busca por por quantidade de palavras
 
**Modos de busca:**
```sh
> /buscaIMD <opção_busca> <opção_impressão> <tempo> <palavras_chave>
```
 onde < opção_busca > deve receber um dos seguintes parametros, indicando de que forma a busca deve ser realizada:
- -bAND: A busca é feita por linhas nos arquivos texto da base de busca que contém todos os termos < palavras_chave >, passadas como argumento.
- -bOR: A busca é feita por linhas nos arquivos texto da base de busca que contém ao menos um dos termos < palavras_chave > passsados como argumento de entraga.

Alem disso < opção_impressão > indica como o resultado da busca deve ser exibida ao usuário, é possivel:
- -pA: A impressão é feita exibindo os resultados em ordem alfabética do nome do arquivo-texto.
- -pC: A impressão é feita exibindo os resultados em ordem decrescente do número de vezes que os termos < palavras_chave> ocorreram em cada arquivo-texto.
- -pI: A impressão é feita exibindo os resultados na ordem em que cada arquivo foi inserido na base de busca.

Caso seja necessário, o tempo total de realização das buscas é exibido através do parametro < tempo > que deve receber:
- tT: O programa registra e exibe o tempo total de execução da busca.
- tF: O programa não registra nem exibe o tempo total de execução da busca. 



## Tests

Describe and show how to run the tests with code examples.

## Contributors

Let people know how they can dive into the project, include important links to things like issue trackers, irc, twitter accounts if applicable.

## License

A short snippet describing the license (MIT, Apache, etc.)


[buscaIMD]: <https:///github.com/lopespaulo/PROJETOEDBLP/archive/master.zip>


