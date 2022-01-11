
# differential_drive

[![platform badge](https://img.shields.io/badge/platform-Arduino-orange.svg)](https://github.com/arduino)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/JoaoLopesF/SerialDebug/blob/master/LICENSE.txt)

Biblioteca para controle diferencial de um robô a partir de um Arduino Due.

## Sobre

Esta biblioteca foi criada para o controle de um robô de acionamento diferencial. Um robô de acionamento diferencial pode se mover para frente, para trás e virar à esquerda e à direita. Ele faz isso girando as rodas em diferentes velocidades e/ou em diferentes direções [[1]](https://snapcraft.io/blog/your-first-robot-the-controller-3-5).

**Assume-se que a base móvel (robô) é controlada pelo envio de comandos de velocidade desejados na forma de: velocidade linear (*v*), velocidade angular (*w*)**.  *v* é dado em metros por segundo e é responsável pela translação, equanto que *w* é dado em radianos por segundo e é reponsável pela parte que faz o robô virar.

Considerando que o robô utilize este tipo de controle, é necessário desenvolver uma maneira de converter as velocidades do modelo diferencial para PWM, utilizado pelo arduino para controle das rodas.

## Lógica Matemática Utilizada

Considere o seguinte sistema.

<p align="center">
  <img src="https://github.com/SciCoBot/differential_drive/blob/main/images/differentialDesign.jpg"/>
</p>

Onde *L* é o comprimento entre as rodas e *RADIUS* o raio da roda.
Além disso, considere

<p align="center">
  <img src="https://github.com/SciCoBot/differential_drive/blob/main/images/modelo_diferencial.jpg"/ height="250" width="250">
</p>

<p align="center">
  <a href="https://www.youtube.com/watch?v=XlFLSFByIcw">[2]</a>
</p>

```
vl = (v - L/2 * w)/r [rad/sec]
```
```
vr = (v + L/2 * w)/r [rad/sec]
```
Onde vl é a velocidade da roda esquerda e vr a velocidade da roda direita.

Considerando os valores padrão utilizador por [Twist](https://github.com/ros2/teleop_twist_keyboard), tem-se o valor máximo de *w* igual a 1 e o mínimo igual a -1. Ainda, que *v* possui valor máximo 0.5 e mínimo -0.5.
Logo, o valor máximo de vr e vl é:

```
(0.5 + (1) * L/2)/r
```

Agora é possível limitar os valores de vr e vl entre os limites conhecidos (aqui tanto faz usar o máximo ou o mínimo, já que em módulo são iguais):

```
vr/máximo
```
e
```
vl/máximo
```
resultando em um valor entre -1 e 1. Além disso, pode-se, usando-se o conceito anterior, converter os valores para um intervalo entre -255 e 255, para  implementação do PWM.

```
pwmL = 255 * vr/máximo
```
```
pwmR = 255 * vl/máximo
```

Sendo os valores negativos considerados como sentido reverso (trás).

## Funções:

- convertDifferential(*flaot*, *float*, *DifferentialValues*): recebe os valores diferenciais (v e w) e converte para  velocidades de cada roda, em radianos por segundo. Salva os valores em uma estrutura DifferentialValues;
- differentialForPWM(*DifferentialValues*, *PwmValues*): acessa as velocidades de cada roda, que estão em radianos por segundo, e converte para valores entre -255 e 255, que serão usados para a lógica de controle PWM. Salva os valores em uma estrutura PwmValues;

## Como utilizar

- Baixe e adicione a partir da IDE arduino.
- Altere L, RADIUS e MAX_WHEEL para os valores referentes a sua arquitetura robótica.
- Teste o exemplo.

## Correções

- Os resultados dos calculos diferenciais (vl e vr) retornam valores que não consegui rotular para valores PWM "coerentes". Ainda mais se considerarmos que em valores menores que 150 o robô não opera.

## Referências extras

- [nanosaur](https://github.com/rnanosaur/nanosaur_robot/blob/accce638de45a1ad452667abf7bae3346b001e96/nanosaur_base/nanosaur_base/nanosaur.py#L131);
- [ROSbots](https://medium.com/hackernoon/unicycle-to-differential-drive-courseras-control-of-mobile-robots-with-ros-and-rosbots-part-2-6d27d15f2010);
- [Elvira](http://classes.elvirarafikova.com/rma/mobilidade/).
