.section .rodata

.data
.globl global
.align 4
global: 
	.long 1

.text
.globl main
.globl aritmeticaBasica
.globl operacionX
.globl unarios

main:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	$16,	%rsp
	call	.aritmeticaBasica
	pushq	%r10
	movl 	$3,	%eax
	movl	%eax,	%r10d
	pushq	%r11
	movl 	$2,	%eax
	movl	%eax,	%r11d
	movl	%r11d,	%edi
	movl	%r10d,	%esi
	call	.operacionX
	popq	%r11
	popq	%r10
	movl	%eax,	-4(%rbp)
	call	unarios
	movl 	$0,	%eax
	jmp	.retorno_main
.retorno_main:
	movq	%rbp,	%rsp
	popq	%rbp
	ret

.aritmeticaBasica:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	$32,	%rsp
	movl 	$1,	%eax
	movl	%eax,	-4(%rbp)
	pushq	%rbx
	movl	-4(%rbp),	%eax
	movl	%eax,	%ebx
	movl 	$2,	%eax
	addl	%eax,	%ebx
	movl	%ebx,	%eax
	popq	%rbx
	movl	%eax,	-8(%rbp)
	pushq	%rbx
	movl	-8(%rbp),	%eax
	movl	%eax,	%ebx
	movl 	$1,	%eax
	subl	%eax,	%ebx
	movl	%ebx,	%eax
	popq	%rbx
	movl	%eax,	-12(%rbp)
	pushq	%rbx
	movl	-12(%rbp),	%eax
	movl	%eax,	%ebx
	movl 	$2,	%eax
	xchgl	 %eax,	 %ebx
	imul	%ebx
	popq	%rbx
	movl	%eax,	-16(%rbp)
	pushq	%rbx
	movl	-16(%rbp),	%eax
	movl	%eax,	%ebx
	movl 	$1,	%eax
	xchgl	 %eax,	 %ebx
	xor	%rdx,	%rdx
	idiv	%ebx
	popq	%rbx
	movl	%eax,	-20(%rbp)
	pushq	%rbx
	movl	-20(%rbp),	%eax
	movl	%eax,	%ebx
	movl 	$2,	%eax
	xchgl	 %eax,	 %ebx
	xor	%rdx,	%rdx
	idiv	%ebx
	movl	%edx,	%eax
	popq	%rbx
	movl	%eax,	-24(%rbp)
	movl 	$0,	%eax
	movl	%eax,	-16(%rbp)
	movl	%eax,	-12(%rbp)
	movl	%eax,	-8(%rbp)
	movl	%eax,	-4(%rbp)
	movl	%eax,	-28(%rbp)
.retorno_aritmeticaBasica:
	movq	%rbp,	%rsp
	popq	%rbp
	ret

.operacionX:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	$16,	%rsp
	movl	%edi,	-4(%rbp)
	movl	%esi,	-8(%rbp)
	pushq	%rbx
	pushq	%rbx
	movl	-4(%rbp),	%eax
	movl	%eax,	%ebx
	movl	-8(%rbp),	%eax
	xchgl	 %eax,	 %ebx
	xor	%rdx,	%rdx
	idiv	%ebx
	movl	%edx,	%eax
	popq	%rbx
	movl	%eax,	%ebx
	pushq	%rbx
	pushq	%rbx
	movl	-4(%rbp),	%eax
	movl	%eax,	%ebx
	movl	-8(%rbp),	%eax
	addl	%eax,	%ebx
	movl	%ebx,	%eax
	popq	%rbx
	movl	%eax,	%ebx
	pushq	%rbx
	movl	-4(%rbp),	%eax
	movl	%eax,	%ebx
	movl	-8(%rbp),	%eax
	subl	%eax,	%ebx
	movl	%ebx,	%eax
	popq	%rbx
	xchgl	 %eax,	 %ebx
	xor	%rdx,	%rdx
	idiv	%ebx
	popq	%rbx
	xchgl	 %eax,	 %ebx
	imul	%ebx
	popq	%rbx
	movl	%eax,	-12(%rbp)
	movl	-12(%rbp),	%eax
	jmp	.retorno_operacionX
.retorno_operacionX:
	movq	%rbp,	%rsp
	popq	%rbp
	ret

unarios:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	$48,	%rsp
	movl 	$1,	%eax
	movl	%eax,	-4(%rbp)
	movl 	$1,	%eax
	neg	%eax
	movl	%eax,	-8(%rbp)
	movl 	$1,	%eax
	neg	%eax
	sbb	%eax,	%eax
	add	$1,	%eax
	movl	%eax,	-12(%rbp)
	movl 	$0,	%eax
	neg	%eax
	sbb	%eax,	%eax
	add	$1,	%eax
	movl	%eax,	-16(%rbp)
	movl	-4(%rbp),	%r10d
	addl	$1,	%r10d
	movl	%r10d,	-4(%rbp)
	movl	%r10d,	%eax
	movl	%eax,	-20(%rbp)
	movl	-4(%rbp),	%r10d
	subl	$1,	%r10d
	movl	%r10d,	-4(%rbp)
	movl	%r10d,	%eax
	movl	%eax,	-24(%rbp)
	movl	-4(%rbp),	%r10d
	movl	%r10d,	%eax
	addl	$1,	%r10d
	movl	%r10d,	-4(%rbp)
	movl	%eax,	-28(%rbp)
	movl	-4(%rbp),	%r10d
	movl	%r10d,	%eax
	subl	$1,	%r10d
	movl	%r10d,	-4(%rbp)
	movl	%eax,	-32(%rbp)
	movl	-4(%rbp),	%eax
	movl	%eax,	-36(%rbp)
retorno_unarios:
	movq	%rbp,	%rsp
	popq	%rbp
	ret

