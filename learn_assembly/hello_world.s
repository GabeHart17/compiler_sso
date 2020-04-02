.data
out_string: .asciiz "\nHello, world!\n"
.text
main:
  li $v0, 4  # 4 is syscall code for printing string
  la $a0, out_string
  syscall
