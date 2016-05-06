.section .rodata

.data
.globl global_U
.align 4
.type global_U, @object
global_U: 
	.long 1
.globl global_V
.align 4
.type global_V, @object
global_V: 
	.long -1
.globl global_X
.align 4
.type global_X, @object
global_X: 
	.long 2
.globl global_Y
.align 4
.type global_Y, @object
global_Y: 
	.long 4
.globl global_Z
.align 4
.type global_Z, @object
global_Z: 
	.long 6
.globl global_0
.align 4
.type global_0, @object
global_0: 
	.long 0
.globl global_1
.align 4
.type global_1, @object
global_1: 
	.long 0
.globl global_2
.align 4
.type global_2, @object
global_2: 
	.long 0
.globl global_3
.align 4
.type global_3, @object
global_3: 
	.long 1
.globl global_4
.align 4
.type global_4, @object
global_4: 
	.long 1
.globl global_5
.align 4
.type global_5, @object
global_5: 
	.long 0
.globl global_6
.align 4
.type global_6, @object
global_6: 
	.long 1
.globl global_7
.align 4
.type global_7, @object
global_7: 
	.long 0
.globl global_8
.align 4
.type global_8, @object
global_8: 
	.long 0
.globl global_9
.align 4
.type global_9, @object
global_9: 
	.long 1
.globl global_10
.align 4
.type global_10, @object
global_10: 
	.long 0
.globl global_11
.align 4
.type global_11, @object
global_11: 
	.long 1
.globl global_12
.align 4
.type global_12, @object
global_12: 
	.long 1
.globl global_13
.align 4
.type global_13, @object
global_13: 
	.long 1
.globl global_14
.align 4
.type global_14, @object
global_14: 
	.long 1
.globl global_15
.align 4
.type global_15, @object
global_15: 
	.long 1
.globl global_16
.align 4
.type global_16, @object
global_16: 
	.long 0
.globl global_17
.align 4
.type global_17, @object
global_17: 
	.long 0
.globl global_18
.align 4
.type global_18, @object
global_18: 
	.long 1
.globl global_19
.align 4
.type global_19, @object
global_19: 
	.long 0

.text
.globl test
.type test, @fuction
.globl func
.type func, @fuction
.globl func2
.type func2, @fuction
.globl func3
.type func3, @fuction
.globl func4
.type func4, @fuction
.globl func5
.type func5, @fuction
.globl func6
.type func6, @fuction
.globl func7
.type func7, @fuction
.globl func8
.type func8, @fuction
.globl func9
.type func9, @fuction
.globl func10
.type func10, @fuction
.globl func11
.type func11, @fuction
.globl func12
.type func12, @fuction
.globl func13
.type func13, @fuction
.globl func14
.type func14, @fuction
.globl func15
.type func15, @fuction
.globl func16
.type func16, @fuction

test:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%48,	%rsp
	movl	%edi,	-4(%rbp)
	movl	%esi,	-8(%rbp)
	movl	%edx,	-12(%rbp)
	movl	%ecx,	-16(%rbp)
	movl	%r8d,	-20(%rbp)
	movl	%r9d,	-24(%rbp)
	movl	16(%rbp),	%eax
	movl	%eax,	-28(%rbp)
	movl	20(%rbp),	%eax
	movl	%eax,	-32(%rbp)
	movl	24(%rbp),	%eax
	movl	%eax,	-36(%rbp)
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%0,	%rsp
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func2:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%0,	%rsp
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func3:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%16,	%rsp
	movl	%edi,	-4(%rbp)
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func4:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%16,	%rsp
	movl	%edi,	-4(%rbp)
	movl	%esi,	-8(%rbp)
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func5:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%16,	%rsp
	movl	%edi,	-4(%rbp)
	movl	%esi,	-8(%rbp)
	movl	%edx,	-12(%rbp)
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func6:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%0,	%rsp
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func7:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%16,	%rsp
	movl	%edi,	-4(%rbp)
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func8:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%16,	%rsp
	movl	%edi,	-4(%rbp)
	movl	%esi,	-8(%rbp)
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func9:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%48,	%rsp
	movl	%edi,	-4(%rbp)
	movl	%esi,	-8(%rbp)
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func10:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%112,	%rsp
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func11:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%32,	%rsp
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func12:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%16,	%rsp
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func13:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%16,	%rsp
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func14:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%16,	%rsp
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func15:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%32,	%rsp
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

func16:
	pushq	%rbp
	movq	%rsp,	%rbp
	subq	%48,	%rsp
	# Codigo DefinicionFuncion
	movq	%rbp,	%rsb
	popq	%rbp
	ret

