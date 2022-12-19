//Dionatan Eduardo Correa Rodrigues

greenscren -> Recebe dois ponteiros, uma para imagem de fundo e outra para imagem da frente.
Em cada posição que a imagem da frente possui a cor indicada como mascara pelo usuario a função
 nao faz nada, caso a cor seja diferente subistitui o pixel referente a mesma posição da imagem
  de fundo pelo da frente.

rotaciona90 -> Recebe um ponteiro da imagem, utiliza a matriz original e rotaciona ela inserindo
seus dados em uma nova matriz.

copia -> Recebe uma matriz e um ponteiro de uma imagem, copia a matriz rotacionada para a matriz 
original que esta contida no ponteiro.

imprime_matrix -> Gera um arquivo do tipo P2.

imprime_img -> Gera um arquivo do tipo P3.
imp_pix -> Imprime cada pixel da matriz no arquivo P3.

converter -> Converte uma imagem P3 para P2.

le_arq -> Le o topo do arquivo de imagem e chama a função leitura para ler cada pixel, após isso
 armazena na matriz.

leitura -> Lê cada pixel da imagem.

ignoreComments -> Utilizada para ignorar toda linha que começa com '#'.

retalhar e retalharRGB - > Ambas tem mesmo objetivo recortar a imagem final a ser gerada, a diferença
 é que a função (retalhar) recorta uma imagem P2 e a função (retalharRGB) recorta uma imagem P3.
