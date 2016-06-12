
**buscaIMD** é um programa para uso no terminal linux. Basicamente, seu objetivo é receber, via linha de comando, palavras-chaves para entregar quais linhas dos arquivos em uma determinada base de buscas contem os termos buscados, segundo critério préviamente estipulado. Para isso, utiliza estruturas e algoritmos apresentados nas disciplinas de Estrutura Básica de Dados I, as mesmas devidamente praticadas em Linguagem de Programação I do curso Bacharelado em Tecnologia da Informação da Universidade Federal do Rio Grande do Norte.



## Funcionamento

O programa foi desenvolvido para gerenciamento de arquivos-texto cadastrados em uma base de busca, é possivel inserir, atualizar, remover e listar arquivos dessa base.
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

>1. desconpacte os arquivos,
>2. No terminal, acesse a pasta criada,
>3. execute:

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



## Exemplos

__Inserir arquivos na base de buscas__

Exemplo 1: Inserindo só um arquivo por vez 
```sh
> ./buscaIMD ­i libertadores.txt 
>> Arquivo "libertadores.txt" inserido na base de buscas.
```
Exemplo 2: Inserindo mais de um arquivo por vez 
```sh
> ./buscaIMD ­i libertadores.txt granja.txt 
>> Arquivo "libertadores.txt" inserido na base de buscas. 
>> Arquivo "granja.txt" inserido na base de buscas. 
```
Obs.: *Caso precise atualizar um arquivo na base de busca, basta inseri-lo novamente o sistema verificará que o arquivo já existe e fará os ajustes necessários.*


__Remover arquivos da base de buscas__

Exemplo 1: Removendo só um arquivo por vez 
```sh
> ./buscaIMD ­r libertadores.txt 
>> Arquivo "libertadores.txt" removido da base de buscas. 
```
Exemplo 2: Removendo dois arquivos por vez 
```sh
> ./buscaIMD ­r libertadores.txt granja.txt 
>> Arquivo "libertadores.txt" removido da base de buscas. 
>> Arquivo "granja.txt" removido da base de buscas.
```
Obs.: *Podemos remover todos os arquivos na base de busca com a entrada *.txt*


__Listar arquivos da base de buscas__

Exemplo 1: Listando arquivos da base de buscas em *ordem de inserção*
```sh
> ./buscaIMD ­li  
>> Arquivos contidos na base de buscas:  
­ "libertadores.txt" 
­ "granja.txt" 
```

Obs.: *também é possivel listar os arquivos por ordem alfabética [-la] ou por ordem de quantidade de palavras [-lt]*


__Realizar buscas por palavras­chaves__

Exemplo 1: Buscando só uma palavra­chave  
```sh
> ./buscaIMD ­bAND galo 
   >> Foram encontradas 2 linhas no arquivo "libertadores.txt": 
­ linha 23: "o galo mais uma vez se salvou na libertadores" 
­ linha 50: "na próxima fase, o galo joga em casa contra o" 
  >> Foram encontradas 3 linhas no arquivo "granja.txt": 
­ linha 1: "o galo é o macho da galinha, comumente tratado" 
­ linha 4: "Algumas especies de galo são criadas como aves" 
­ linha 8: " O galo é extremamente territorialista, sempre"
```

Exemplo 2: Buscando mais de uma palavra­chave com opção AND 
```sh
  ./buscaIMD ­bAND galo macho 
   >> Foram encontradas 0 linhas no arquivo "libertadores.txt": 
   >> Foram encontradas 1 linhas no arquivo "granja.txt": 
  linha 1: "o galo é o macho da galinha, comumente tratado" 
   >> Foram encontradas 0 linhas no arquivo "clima.txt": 
```

Exemplo 3: Buscando mais de uma palavra­chave com opção OR 
```sh
> ./buscaIMD ­bOR galo macho 
   >> Foram encontradas 2 linhas no arquivo "libertadores.txt": 
­ linha 23: "o galo mais uma vez se salvou na libertadores" 
­ linha 50: "na próxima fase, o galo joga em casa contra o" 
   >> Foram encontradas 5 linhas no arquivo "granja.txt": 
­ linha 1: "o galo é o macho da galinha, comumente tratado" 
­ linha 4: "Algumas especies de galo são criadas como aves " 
­ linha 8: "O galo é extremamente territorialista, sempre" 
­ linha 15: "a relação é restrita com relação a outro macho" 
­ linha 45: "o macho é ligeiramente maior que a fêmea" 
   >> Foram encontradas 0 linhas no arquivo "clima.txt": 
```


__Configurar impressão das buscas__ 

Exemplo 1: Exibindo resultados em ordem alfabética dos nomes dos arquivos 
```sh
> ./buscaIMD ­bAND ­pA galo 
   >> Foram encontradas 0 linhas no arquivo "clima.txt": 
   >> Foram encontradas 3 linhas no arquivo "granja.txt": 
­ linha 1: "o galo é o macho da galinha, comumente tratado" 
­ linha 4: "Algumas especies de galo são criadas como aves" 
­ linha 8: " O galo é extremamente territorialista, sempre" 
   >> Foram encontradas 2 linhas no arquivo "libertadores.txt": 
­ linha 23: "o galo mais uma vez se salvou na libertadores" 
```
Obs: *Outras opções de configuração são: [-pC] para exibir por ordem de ocorrencia dos termos e [-pI] para ordem de inserção dos arquivos na base de busca*


__Registrar tempo de execução das buscas__ 
Exemplo 1: Exibindo tempo de execução das buscas 
```sh
> ./buscaIMD ­bAND ­pA ­tT galo 
   >> Foram encontradas 0 linhas no arquivo "clima.txt": 
   >> Foram encontradas 3 linhas no arquivo "granja.txt": 
­ linha 1: "o galo é o macho da galinha, comumente tratado" 
­ linha 4: " Algumas especies de galo são criadas como aves" 
­ linha 8: "O galo é extremamente territorialista, sempre" 
   >> Foram encontradas 2 linhas no arquivo "libertadores.txt": 
­ linha 23: "o galo mais uma vez se salvou na libertadores" 
­ linha 50: "na próxima fase, o galo joga em casa contra o" 
   >> Tempo total de execução: 3021 ms 
```
por padrão caso o parametro -tT não seja informado, o sistema não medira o tempo de execução das buscas

## Desenvolvedores

[Clarissa Soares]

[Paulo Lopes]

## Licensa de Uso

[![License (LGPL version 3.0)](https://img.shields.io/badge/license-GNU%20LGPL%20version%203.0-blue.svg?style=flat-square)](http://opensource.org/licenses/LGPL-3.0)


[buscaIMD]: <https:///github.com/lopespaulo/PROJETOEDBLP/archive/master.zip>
[Clarissa Soares]: <https://github.com/clahzita>
[Paulo Lopes]: <https://github.com/lopespaulo>


