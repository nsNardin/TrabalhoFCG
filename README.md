# Campo Minado 3D
## Introdução
Nosso trabalho consiste em implementar o famoso jogo Campo Minado, mas usando OpenGL e tendo uma visualização 3D do tabuleiro.
## Contribuições
Norberto contribuiu principalmente na lógica da renderização dos objetos, da iluminação, das texturas, e da câmera livre. 
O João contribuindo principalmente para a lógica do jogo (campo minado), objetos com malhas complexas, e modelos de interpolação.

Nós desenvolvemos todo o trabalho em conjunto, sempre se reunindo online para conversarmos enquanto desenvolvíamos, e o material das aulas serviu como maior forma de suporte para os conhecimentos utilizados.
## Inteligência Artificial
Houve uso de ChatGPT na seção da lógica de picking (ray casting) para receber a posição correta que o cursor está apontando e assim revelar o cubo correto dentro do jogo. A ferramenta ajudou bastante, mas sempre precisando de ajustes finos para que funcione da forma esperada.
## Screenshots
![Screenshot 2025-07-06 184147](https://github.com/user-attachments/assets/5779faec-e5af-49d1-9416-ca3072e52688)
![Screenshot 2025-07-06 184212](https://github.com/user-attachments/assets/bdd1ed4a-ab60-4d0c-87f7-e4ea49426513)

## Como Jogar

### Controles
  F: Posiciona ou remove a bandeira
  LClick: Revela o que tem na posição
  RClick: O soldado vai até o bloco clicado
  RDrag: move a câmera

### Regras 
  - Você é um soldado que se move pelo campo minado.
  - O objetivo de revelar todas posições que não possuem bombas. 
  - Você pode revalar uma posição, se você estiver próximo o suficiente dela.
  - Você pode colocar uma bandeira, representada por uma tnt, em qualquer lugar do mapa.
  - Se você pisar em cima do bloco, revela ele também. 
  - A bandeira previne que você revele aquele bloco clicando, mas não pisando.
  - Se pisar ou revelar uma bomba, você perdeu.
  
  Infelizmente o jogo não reage à vitória ou derrota do jogador.

## Conceitos Aplicados
- O soldado é uma malha poligonal complexa
- A transalação do soldado é controlada pelo usuário
- A câmera é TPS, que é tanto livre quanto look-at
- Intersecção reta X matriz de quadrados, identifica qual quadrado foi clicado
- Intersecção ponto X matriz quadrado, para ver onde o soldado pisa.
- Intersecção ponto X esfera, para ver se o quadrado selecionado está ao alcance do soldado.
- Outras intersecções, para servir às anteriores
- Modelo de interpolação dos blocos são diversos
- Mapemaento de textura em todos blocos e no soldado.
- O soldado se move e gira baseado no tempo.

Apenas não implementamos a curva de bezier.


  Para compilar:
--- Windows com VSCode (Visual Studio Code)
-------------------------------------------
1) Instale o VSCode seguindo as instruções em https://code.visualstudio.com/ .

2) Instale o compilador GCC no Windows seguindo as instruções em
https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain .

Alternativamente, se você já possui o Code::Blocks instalado no seu PC
(versão que inclui o MinGW), você pode utilizar o GCC que vem com esta
instalação no passo 5.

3) Instale o CMake seguindo as instruções em https://cmake.org/download/ .
Alternativamente, você pode utilizar algum package manager do
Windows para fazer esta instalação, como https://chocolatey.org/ .

4) Instale as extensões "ms-vscode.cpptools" e "ms-vscode.cmake-tools"
no VSCode. Se você abrir o diretório deste projeto no VSCode,
automaticamente será sugerida a instalação destas extensões (pois
estão listadas no arquivo ".vscode/extensions.json").

5) Abra as configurações da extensão cmake-tools (Ctrl-Shift-P e
busque por "CMake: Open CMake Tools Extension Settings"), e adicione o
caminho de instalação do GCC na opção de configuração "additionalCompilerSearchDirs".

Por exemplo, se você quiser utilizar o compilador MinGW que vem junto
com o Code::Blocks, pode preencher o diretório como
"C:\Program Files\CodeBlocks\MinGW\bin" (verifique se este é o local
de instalação do seu Code::Blocks).

6) Clique no botão de "Play" na barra inferior do VSCode para compilar
e executar o projeto. Na primeira compilação, a extensão do CMake para
o VSCode irá perguntar qual compilador você quer utilizar. Selecione
da lista o compilador GCC que você instalou com o MSYS/MinGW.

