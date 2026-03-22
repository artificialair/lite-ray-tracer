    .global sys_exit
sys_exit:
    movl $60, %eax
    syscall

    .global sys_write
sys_write:
    push %rbp
    movq %rsp, %rbp
    movl $1, %eax
    syscall
    movq %rbp, %rsp
    popq %rbp
    retq

    .global sys_mmap
sys_mmap:
    push %rbp
    movq %rsp, %rbp
    movl $9, %eax
    movq %rcx, %r10
    syscall
    movq %rbp, %rsp
    popq %rbp
    retq

    .global sys_munmap
sys_munmap: 
    push %rbp
    movq %rsp, %rbp
    movl $11, %eax
    syscall
    movq %rbp, %rsp
    popq %rbp
    retq

