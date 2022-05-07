.data
  v: 56,-2,50,423,-15
.text
  main:
    add x7, x0, 0
    add x5, x0, 1
    add x6, x0, 5
    add x0, x0, 0
    lw x10, 0(x7)
    add x0, x0, 0
    add x0, x0, 0
    add x0, x0, 0
    add x7, x7, 1
    add x0, x0, 0
    add x0, x0, 0
  while:
    beq x5, x6, fin
    add x0, x0, 0
    add x0, x0, 0
    lw x28, 0(x7)
    add x0, x0, 0
    add x0, x0, 0
    add x0, x0, 0
    ble x28, x10, next
    add x0, x0, 0
    add x0, x0, 0
    add x0, x0, 0
    add x10, x0, x28
  next:
    add x7, x7, 1
    add x5, x5, 1
    add x0, x0, 0
    add x0, x0, 0
    add x0, x0, 0
    beq x0, x0, while
  fin:
    add x0, x0, 0




