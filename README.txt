# Region_Quadtree
<br />
Por: Alan Monroy<br />
<br />
  0     1     2     3     4
0 +-----+-----+-----+-----+
  |     |     |     |     |<br />
  |     |     |     |     |<br />
1 +-----+-----+-----+-----+
  |     | x   |     |     |<br />
  |     |     |     |     |<br />
2 +-----+-----+-----+-----+
  |  x  |     |     | x   |<br />
  |     |     |     |   x |<br />
3 +-----+-----+-----+-----+
  |     |     |     |     |
  |     |   x |     |     |
4 +-----+-----+-----+-----+<br />
<br />
El numero de nodos se imprime usando el Z-order<br />
<br />
padre(hijo1 hijo2 hijo3 hijo4)<br />
