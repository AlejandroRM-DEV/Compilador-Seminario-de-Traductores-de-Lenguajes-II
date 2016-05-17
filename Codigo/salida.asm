.section .rodata

.data

.text
.globl main

main:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	$16,	%rsp
	movl 	$1,	%eax
	movl	%eax,	-8(%rbp)
	movl 	$1,	%eax
	movl	%eax,	-12(%rbp)
IF_1: 
	pushq	%rbx
	movl	-8(%rbp),	%eax
	movl	%eax,	%ebx
	movl	-12(%rbp),	%eax
	cmp	%eax,	%ebx
	jne	FALSO_2
	movl	$1,	%eax
	jmp	FIN_2
FALSO_2: 
	movl	$0,	%eax
FIN_2: 
	popq	%rbx
	cmp	$1,	%eax
	jl	FIN_IF_1
	movl 	$1,	%eax
	movl	%eax,	-4(%rbp)
FIN_IF_1: 
IF_3: 
	pushq	%rbx
	movl	-8(%rbp),	%eax
	movl	%eax,	%ebx
	movl	-12(%rbp),	%eax
	cmp	%eax,	%ebx
	je	FALSO_4
	movl	$1,	%eax
	jmp	FIN_4
FALSO_4: 
	movl	$0,	%eax
FIN_4: 
	popq	%rbx
	cmp	$1,	%eax
	jl	FIN_IF_3
	movl 	$1,	%eax
	movl	%eax,	-4(%rbp)
FIN_IF_3: 
IF_5: 
	pushq	%rbx
	movl	-8(%rbp),	%eax
	movl	%eax,	%ebx
	movl	-12(%rbp),	%eax
	cmp	%eax,	%ebx
	jle	FALSO_6
	movl	$1,	%eax
	jmp	FIN_6
FALSO_6: 
	movl	$0,	%eax
FIN_6: 
	popq	%rbx
	cmp	$1,	%eax
	jl	FIN_IF_5
	movl 	$1,	%eax
	movl	%eax,	-4(%rbp)
FIN_IF_5: 
IF_7: 
	pushq	%rbx
	movl	-8(%rbp),	%eax
	movl	%eax,	%ebx
	movl	-12(%rbp),	%eax
	cmp	%eax,	%ebx
	jl	FALSO_8
	movl	$1,	%eax
	jmp	FIN_8
FALSO_8: 
	movl	$0,	%eax
FIN_8: 
	popq	%rbx
	cmp	$1,	%eax
	jl	FIN_IF_7
	movl 	$1,	%eax
	movl	%eax,	-4(%rbp)
FIN_IF_7: 
IF_9: 
	pushq	%rbx
	movl	-8(%rbp),	%eax
	movl	%eax,	%ebx
	movl	-12(%rbp),	%eax
	cmp	%eax,	%ebx
	jge	FALSO_10
	movl	$1,	%eax
	jmp	FIN_10
FALSO_10: 
	movl	$0,	%eax
FIN_10: 
	popq	%rbx
	cmp	$1,	%eax
	jl	FIN_IF_9
	movl 	$1,	%eax
	movl	%eax,	-4(%rbp)
FIN_IF_9: 
IF_11: 
	pushq	%rbx
	movl	-8(%rbp),	%eax
	movl	%eax,	%ebx
	movl	-12(%rbp),	%eax
	cmp	%eax,	%ebx
	jg	FALSO_12
	movl	$1,	%eax
	jmp	FIN_12
FALSO_12: 
	movl	$0,	%eax
FIN_12: 
	popq	%rbx
	cmp	$1,	%eax
	jl	FIN_IF_11
	movl 	$1,	%eax
	movl	%eax,	-4(%rbp)
FIN_IF_11: 
	movl 	$0,	%eax
	jmp	retorno_main
retorno_main:
	movq	%rbp,	%rsp
	popq	%rbp
	ret

