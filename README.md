<h1>Controle Remoto Com RF 433MHz</h1>
<h3>Introdução</h3>
<p align=justify>Este projeto consiste em desenvolver um controle remoto por radiofrequência. Há 3 arquivos na pasta: o código do transmissor (Comunicacao_RF_Emissor), o código do receptor (Comunicacao_RF_Receptor) e a biblioteca VirtualWire, que permite o uso do módulo RF 433MHz. De um lado temos 4 botões e do outro 4 LEDs. Conforme os botões são acionados os LEDs acendem ou apagam.</p>
<h4>Materiais</h4>
<p><li>1 Módulo RF 433MHz transmissor + receptor</li>
<li>2 Arduinos Mega</li>
<li>4 LEDs</li>
<li>4 Resistores 150Ω</li>
<li>4 Push button</li>
<li>2 Protoboards</li>
<li>Fios jumper</li></p>
<h3>Radiofrequência</h3>
<p align=justify>Ondas de radiofrequência (RF) são ondas eletromagnéticas que não precisam de um meio para propagação. Suas frequências são menores do que a da luz visível, estando entre 3KHz e 300GHz. Presente em diversas aplicações tecnológicas, a RF permite transmitir informações à longas distâncias quase instantaneamente. Dentre as aplicações podemos destacar radares, satélites, telefonia móvel, rádio e TV. O sistema é compreendido por um elemento transmissor e um elemento receptor. O transmissor é responsável por enviar as informações. Ele possui um oscilador em seu circuito para gerar os sinais nas frequências apropriadas para serem irradiados pela antena. Já o receptor recebe as informações enviadas e filtra os sinais, eliminando os ruídos que possam existir e por isso o circuito é mais complexo.</p>
<h3>Módulo RF 433MHz</h3>
<p align=justify>O módulo RF 433MHz permite o envio de informações entre dois sistemas microcontrolados à distância. A comunicação é unidirecional, uma vez que os módulos de transmissão e recepção são separados. Ele utiliza a modulação ASK (<i>amplitude shift keying</i>) para interpretar os sinais. Basicamente considera que toda vez que há um sinal de 433MHz o sinal digital será 1 e quando houver ausência de sinal de frequência o sinal digital será 0. Usar um fio de 17cm em espiral aumenta a distância de transmissão.</p>
<h3>O Projeto</h3>
<p align=justify>Temos 2 circuitos separados. No conjunto transmissor temos 4 botões do tipo push button conectados diretamente ao Arduino. Ao acionar um dos botões uma vez o seu respectivo LED no conjunto receptor acende. Pressionando o mesmo botão novamente o LED apaga. Cada botão controla o estado de um LED. Se estiver acesso apagará, se estiver apagado acenderá.</p>
<h4>Transmissor</h4>
<p align=justify>Optei por utilizar os resistores PULLUP do Arduino nos botões, eliminando a necessidade de utilizar os resistores externos. Para aciona-lo deve-se utilizar o modo <b>INPUT_PULLUP</b> no código para os pinos de entrada. Este comando habilita as portas em nível lógico alto, logo os botões devem ser conectados ao terra. Sem a antena, o alcance do sinal foi de aproximadamente 10cm. A biblioteca VirtualWire possui como padrão a porta 12 do Arduino para envio de informação. Toda informação enviada deve ser como string.</p>
<img src="https://github.com/TioDavis/RF433MHz/blob/master/Circuito%20Transmissor.jpg">
<h4>Receptor</h4>
<p align=justify>Assim como no transmissor, o receptor também possui uma porta padrão pela biblioteca VirtualWire, neste caso o pino 11. A informação é recebida como decimal ou hexadecimal, por isso é recomendado ter a tabela ASCII por perto para consulta. O padrão é o decimal, mas você pode mudar ao adicionar HEX na condicional (buf[0],HEX). Eu utilizei os valores correspondentes aos caracteres enviados pelo transmissor em decimal conforme tabela ASCII.</p>
<img src="https://github.com/TioDavis/RF433MHz/blob/master/Circuito%20Receptor.jpg">
