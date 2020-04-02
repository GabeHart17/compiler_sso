.text
main:
  li $t2, 10
  li $t3, 20
loop:
  beq $t2, $t3, end
  addi $t2, $t2, 2
  j loop
end:
  li $v0, 1
  li $a0, 17
  syscall
  li $v0, 10
  syscall
