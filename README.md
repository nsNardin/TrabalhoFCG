Nosso trabalho consiste em implementar o famoso jogo Campo Minado, mas usando OpenGL e tendo uma visualização 3D do tabuleiro.

Norberto contribuiu principalmente na lógica da renderização dos objetos, da iluminação, das texturas, e da câmera livre. 
O João contribuindo principalmente para a lógica do jogo (campo minado), objetos com malhas complexas, e modelos de interpolação.
	
Houve uso de ChatGPT na seção da lógica de picking (ray casting) para receber a posição correta que o cursor está apontando e assim revelar o cubo correto dentro do jogo. A ferramenta ajudou bastante, mas sempre precisando de ajustes finos para que funcione da forma esperada.

A gente desenvolvou todo o trabalho em conjunto, sempre se reunindo online para conversarmos enquanto desenvolvíamos, e o material das aulas serviu como maior forma de suporte para os conhecimentos utilizados.

![Screenshot 2025-07-06 184147](https://github.com/user-attachments/assets/5779faec-e5af-49d1-9416-ca3072e52688)
![Screenshot 2025-07-06 184212](https://github.com/user-attachments/assets/bdd1ed4a-ab60-4d0c-87f7-e4ea49426513)

Manual do jogo :
  W: frente
  S: trás
  A: esquerda
  D: direita
  CTRL: baixo
  SPACEBAR: cima

Mouse:
  Right-click: (Hold): Gira a câmera esférica
  Left-click: Revela os blocos do jogo

Soldadinho: (coordenadas locais)
  Z: Rotaciona em Z
  Shift+Z: Rotaciona em -Z
  Y: Rotaciona em Y
  Shift+Z: Rotaciona em -Y
  X: Rotaciona em X
  Shift+Z: Rotaciona em -X
  C: Reseta posição inicial

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

