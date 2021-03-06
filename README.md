
# differential_drive

[![platform badge](https://img.shields.io/badge/platform-Arduino-orange.svg)](https://github.com/arduino)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/JoaoLopesF/SerialDebug/blob/master/LICENSE.txt)

## Conteúdo

- [Sobre](#sobre)
- [Funções](#funções)
- [Como Utilizar](#como-utilizar)
- [Implementações Futuras](#implementações-futuras)

## Sobre

Biblioteca para controle diferencial de um robô a partir de um Arduino Due.
Foi pensada para ser usada junto com [teleop_twist_keyboard](https://index.ros.org/r/teleop_twist_keyboard/#foxy).

**Assume-se que a base móvel (robô) é controlada pelo envio de comandos de velocidade desejados na forma de: velocidade linear (*v*), velocidade angular (*w*)**.  *v* é dado em metros por segundo e é responsável pela translação, equanto que *w* é dado em radianos por segundo e é reponsável pela parte que faz o robô virar.

Ainda, considera-se nove possibilidades a partir de cada variável isolada tem=-se: velocidades lineares negativas e positivas são considerados comandos para trâs e para frente, respectivamente, e comandos de velocidade angular negativas e positivas são considerados movimentos para esqueda e direita, respectivamente. A junção destes conceitos diz o tipo de movimento do robô, para um dado conjunto de valores (v e w)

Dessa forma, as possibilidades são:
- frente;
- reverso;
- girar em torno do próprio eixo para direita;
- girar em torno do próprio eixo para esquerda;
- frente inclinado para direita;
- frente inclinado para esquerda;
- reverso inclinado para direita;
- reverso inclinado para esquerda;
- parado.

## Comandos Básicos
### Definições
- DIFFERENTIAL_DRIVE_DEBUG: utilizado para habilitar ou desabilitar mensagens debug padrão. Utilize 1 para habilitar. Por default é igual a 0.
### Funções

- **DifferentialDrive::differentialForPWM(linear, angular)**: recebe os valores diferenciais (v e w) e relaciona de forma grosseira com o movimento do robô, enviando os comandos aos motores conforme a lógica descrita em "Sobre".

## Como utilizar

- Baixe e adicione a partir da IDE arduino.
- Teste o exemplo.

## Implementações Futuras

- Implementar o CÁLCULO da velocidade diferencial para controle do motor.
