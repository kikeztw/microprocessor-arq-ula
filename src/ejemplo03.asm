.data
  v: 12,21,23
.text
  main:
    add x5, x0, 20
  while:
    add x3, x3, 1
    add x0, x0, 0
    add x0, x0, 0
    add x0, x0, 0
    bne x3, x5, while
    sw x3, 0(0)
    add x10, x5, 1
    add x11, x5, 2
