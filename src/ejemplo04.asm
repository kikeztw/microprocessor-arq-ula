#
# Ejemplo 4: Máximo número en un vector
# 	int i = 1, size = 5;
# 	int m = v[0]
# 	while (i<5)
#			if v[i]>m
#				m = v[i]
#			i+=1;
#
#.data
#  v: 56, -2, 50, 423, -15
.text
  main:
    add, x1, x1, 5
    add, x2, x0, -5
    sub, x3, 5, 1
    lw,x0,x1,2
    add,x2,x2,4
  while:  
    beq, x0, x1, fin
    beq, x0, 1, fin
    lw, x3, x0, x2
    ble, x3, x0, next
    add, x0, x1, x3
  next:
    addi, t2, t2, 4
    addi, t0,t0,1
    beq, zero, zero, while
  fin:
    jalr, zero, ra, 0
