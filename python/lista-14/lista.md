# **Lista de Exercícios** - Python Aula 13

> **ATENÇÃO:** Todos exercicios deveram estar em um único Jupyter Notebook como apresentado em aula. Todos os gráficos devem possui legendas e eixos nomeados com as devidas unidades corretas quando houver. Além disso, no upload do notebook as células tem que estar rodadas.


1. **Point Cloud no Mundo**

    Neste exercício, o objetivo é desenvolver uma visualização de dados de um sensor LiDAR em diferentes sistemas de referência (*frames*).

    Vocês deverão ler:

    * o arquivo `lidar_info.json`, que contém as informações de configuração do LiDAR (como parâmetros angulares e características da medição);
    * o arquivo `lidar_data.csv`, que contém as distâncias medidas pelo LiDAR em uma determinada leitura.

    A partir das informações do LiDAR e das medições de distância, vocês deverão converter as leituras para coordenadas cartesianas, obtendo as posições dos pontos no espaço. Considere que as medições são realizadas em um plano, portanto a coordenada (z) de todos os pontos será igual a zero.

    Em seguida, devem ser gerados dois gráficos de dispersão (*scatter plots*):

    1. **Visualização no frame do robô (`robot frame`)**

    * Plotar os pontos detectados pelo LiDAR em relação ao robô.
    * Indicar a posição do robô na origem do sistema de coordenadas.
    * Utilizar a legenda para identificar corretamente a pose do robô.

    2. **Visualização no frame do mundo (`world frame`)**

    * Transformar os pontos do LiDAR para o sistema de coordenadas global utilizando a pose do robô.
    * Plotar os pontos no mapa global.
    * Indicar a posição e orientação do robô no mundo.
    * Utilizar a legenda para identificar a pose do robô e dos pontos representados.

    Todos os gráficos devem possuir:

    * eixos devidamente identificados;
    * unidades de medida quando aplicável;
    * legenda;
    * escala equivalente nos eixos (x) e (y), garantindo uma representação geométrica correta.

    > Para visualizar melhor os pontos, recomendo os limites para os eixos de -1 m a 1 m

    > Todas as unidades seguem o padrão SI