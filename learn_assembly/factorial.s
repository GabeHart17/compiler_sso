.text
.globl main
main:
  addi $s0, $zero, 6  # argument for factorial
  addi $t0, $s0, 0
factorial:
  sub $t0, $t0, 1
  beq $zero, $t0 end
  mul $s0, $s0, $t0
  j factorial
end:
  addi $a0, $s0, 0
  addi $v0, $zero, 1
  syscall
  addi $v0, $zero, 10
  syscall
