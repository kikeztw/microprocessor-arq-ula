.data
  v: 15,1,22
.text
  main:
    lw x9, 4(0)
    add x0, x0, 0
    addi x7, x0, 99
    add x0, x0, 0
    add x0, x0, 0
    addi x5, x9, 2
    add x0, x0, 0
    add x0, x0, 0
    add x0, x0, 0
  while:
    bne x3, x7, while
    sw x3, 4(0)