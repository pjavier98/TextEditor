# Text Editor (C++):
**Note:** There will be no graphic interface.

## How to run the program:

### Linux:
1. Open the terminal;
2. Command to compile:
```
make compile_text_editor
```
3. Command to execute:
```
./text
```

### Windows:
1. Open the cmd;
2. Command to compile:
```
g++ -std=c++17 utilities/header.h searchAlgorithm/search.h searchAlgorithm/search.cpp autocompleteAlgorithm/autocomplete.h autocompleteAlgorithm/autocomplete.cpp badnessAlgorithm/badness.h badnessAlgorithm/badness.cpp textEditor.cpp -o text
```
3. Command to execute:
```
text
```

### Badness:
* Enter the text in the file **input.txt** that is in the **input folder**

![input text](images/in_badness_search.png)

* Run the program;
* Choose option 3;
* Enter the width of the indentation of the text;
* See the output in the file **badness.txt** that is in the **output** folder

![output text](images/out_badness.png)

#### Explain and Complexity:
Para o texto justificado, a ideia é ter linhas balanceadas, ou seja, minimizar 
os custos totais para equilibrar os espaços, usamos programação dinâmica e 
preenchemos em uma tabela onde primeiro calculamos os custos de colocar todas 
as palavras em uma única linha, se não couber, é considerado como infinito para
não incluir na solução. Com a programação dinâmica evitamos de recalcular 
subproblemas já calculados. Com isso obtemos uma complexidade de O(n²) para 
calcularmos os custos e salvarmos na matriz.

### Autocomplete:
* Enter the text in the file **input.txt** that is in the **input folder**

![input text](images/in_autocomplete.png)


* In the words you want to autocomplete, type **\\*** at the end of the word
* Run the program;
* Choose option 2;
* See the output in the file **autocomplete.txt** that is in the **output** folder

![output text](images/out_autocomplete.png)

#### Explain and Complexity:
O algoritmo usado é um Trie de sufixos, onde a ideia é criar uma árvore
com todas as palavras presentes no texto, onde um prefixo pode ser um 
possivel prefixo de outra palavra, portanto se construirmos uma Trie, 
podemos encontrar um padrão de prefixos e adicionar uma palavra quando 
não possuimos seu sufixo. Com isso conseguimos uma complexidade de O(n) 
onde n é o tamanho do texto para criarmos a árvore.

### Search:
* Enter the text in the file **input.txt** that is in the **input folder**

![input text](images/in_badness_search.png)


* Run the program;
* Choose option 1;
* Enter the word you want to search;
* See the output in the file **search.txt** that is in the **output** folder

![output text](images/out_search.png)

#### Explain and Complexity:
The algorithm used is a Trie of suffixes, where the idea is to 
create a tree with all suffixes of the text, where a prefix can 
be a possible suffix of another word, so if we construct a Trie
suffixes, we can find a pattern. With this we achieved a complexity
of O (n) where n is the size of the text to create the tree. In each
node of the tree we save in what position the substring appeared.
To do the search we obtain a complexity of O (m + k) where m is the
size of the substring or string and k its quantity of occurrences.