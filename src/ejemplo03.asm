.data
  v: 15,12,22,
  main:
    lw x9, 4(0)
    add x0, x0, 0
    add x0, x0, 0
    add x0, x0, 0
    add x5, x9, 8
    add x0, x0, 0
    add x0, x0, 0
    add x0, x0, 0
  while:
    add x3, x3, 1
    bne x3, x5, while
    sw x3, 16(0)