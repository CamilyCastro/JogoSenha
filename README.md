# JogoSenha
Jogo cujo objetivo é descobrir uma senha de 4 dígitos, em 10 tentativas. Feito em linguagem C.

Neste projeto, segui o seguinte raciocinio:

Criei três vetores de 4 posições, SENHA, senhadig, e result. 

O vetor SENHA foi preenchido com 4 números aleatórios, gerados pela função rand(), são estes números que terão de ser descobertos pelo usuário.

O vetor senhadig é preenchido por números digitados pelo usuário, durante as tentativas.

Já o vetor result, é preenchido inicialmente com -1, em todas as posições.

Em seguida, são feitas comparações entre SENHA e senhadig, e caso o usuário tenha digitado um número correto, na posição correta, a posição em questão de result, é preenchida com 1. Lembrando que cada passo citado acima, e este inclusive, foram feitas dentro de laços.
Dentro deste mesmo laço também é verificado se o número digitado pelo usuário esta presente em alguma outra posição do vetor SENHA, e caso esteja, a posição em questão de result recebe 0.

A cada tentativa, sãos exibidos os vetores senhadig e result. Então , supondo que o vetor SENHA esteja preenchido com os números 1;2;3;4, e o vetor senhadig com 7;8;2;4, então result será exibido da seguinte forma: -1;-1;0;1.

A cada tentativa, uma variavel auxíliar recebe +1 em seu valor, e cada vez que uma posição do vetor result recebe 1, outra variavel auxíliar tambem recebe +1 em seu valor, garantindo que o jogo encerre após o usuário acertar os 4 digitos da senha, ou estourar o número de tentativas.
