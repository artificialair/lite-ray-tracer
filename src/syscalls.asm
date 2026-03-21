    .global sys_exit
sys_exit:
    movl $60, %eax
    syscall
