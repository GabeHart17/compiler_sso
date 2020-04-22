.data
size: .word 4  # number of discs to move from a to c
piles: .ascii "abc"
outstr: .asciiz "a -> b\n"  # string for output

.text
.globl main
main:
  li $a0, 0
  li $a1, 2
  lw $a2, size
  jal solve
  j end

solve:  # args 0-2: from pile, to pile, num discs
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  li $t0, 1
  bne $a2, $t0, solverec
  jal printstep
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  jr $ra
solverec:
  addi $sp, $sp, -16
  sw $a0, 12($sp)
  sw $a1, 8($sp)
  sw $a2, 4($sp)
  li $t0, 3
  sub $t0, $t0, $a0
  sub $t0, $t0, $a1
  sw $t0, 0($sp)  # "intermediate pile"
  add $a1, $t0, $zero
  addi $a2, $a2, -1
  jal solve
  lw $a0, 12($sp)
  lw $a1, 8($sp)
  jal printstep
  lw $a0, 0($sp)
  lw $a1, 8($sp)
  lw $a2, 4($sp)
  addi $a2, $a2, -1
  jal solve
  lw $ra, 16($sp)
  addi $sp, $sp, 20
  jr $ra

printstep:  # arg 0: from pile, arg 1: to pile
  li $v0, 4
  la $t0, piles
  la $t3, outstr
  addu $t1, $t0, $a0
  lbu $t2, 0($t1)
  sb $t2, 0($t3)
  addu $t1, $t0, $a1
  lbu $t2, 0($t1)
  sb $t2, 5($t3)
  la $a0, outstr
  syscall
  jr $ra

end:
  li $v0 10
  syscall
