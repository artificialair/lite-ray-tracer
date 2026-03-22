    .global syscall_wrapper
syscall_wrapper:
    push %rbp
    movq %rsp, %rbp
    movl %ecx, %eax
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

