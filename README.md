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
  Y: Rotaciona em Y
  X: Rotaciona em X
  C: Reseta posição inicial
