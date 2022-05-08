.data
  v: 56, -2, 50, 423, -15
.text
  main:
    addi x5, x0, 1
    addi x6, x0, 5
    lw x11, 0(x7)
    addi x31, x0, 4
    addi x0, x0, 0
    addi x0, x0, 0
    addi x0, x0, 0
  while:
    beq x5, x6, fin
    lw x8, x31(x7)
    addi x0, x0, 0
    addi x0, x0, 0
    addi x0, x0, 0
    blt x8, x11, next
    addi x0, x0, 0
    addi x0, x0, 0
    addi x0, x0, 0
    add x11, x8, x0
    addi x0, x0, 0
    addi x0, x0, 0
    addi x0, x0, 0
  next:
    addi x31, x31, 4
    addi x5, x5, 1
    addi x0, x0, 0
    addi x0, x0, 0
    addi x0, x0, 0
    beq x0, x0, while
  fin:
    jalr zero, ra, 0