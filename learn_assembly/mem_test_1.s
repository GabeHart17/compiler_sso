.text
.globl main
main:
  lw $t0 foo
  lw $t1 bar
  add $a0, $t0, $t1
  addi $v0, $zero, 1
  syscall
  addi $v0, $zero, 10
  syscall
