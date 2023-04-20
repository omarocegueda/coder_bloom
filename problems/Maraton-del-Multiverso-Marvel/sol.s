	.file	"sol.cc"
	.text
	.section	.rodata
	.type	_ZStL19piecewise_construct, @object
	.size	_ZStL19piecewise_construct, 1
_ZStL19piecewise_construct:
	.zero	1
	.align 4
	.type	_ZL5MAX_N, @object
	.size	_ZL5MAX_N, 4
_ZL5MAX_N:
	.long	1000001
	.align 4
	.type	_ZL5MAX_M, @object
	.size	_ZL5MAX_M, 4
_ZL5MAX_M:
	.long	10001
	.text
	.globl	_Z9SolveFastiPiiS_
	.type	_Z9SolveFastiPiiS_, @function
_Z9SolveFastiPiiS_:
.LFB2080:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$40064, %rsp
	movl	%edi, -40036(%rbp)
	movq	%rsi, -40048(%rbp)
	movl	%edx, -40040(%rbp)
	movq	%rcx, -40056(%rbp)
	movl	$0, -4(%rbp)
.L3:
	movl	-4(%rbp), %eax
	cmpl	-40036(%rbp), %eax
	jge	.L2
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40048(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cltq
	movl	-4(%rbp), %edx
	movl	%edx, -40016(%rbp,%rax,4)
	addl	$1, -4(%rbp)
	jmp	.L3
.L2:
	movl	$0, -40020(%rbp)
	movl	$0, -8(%rbp)
.L7:
	movl	-8(%rbp), %eax
	cmpl	-40040(%rbp), %eax
	jge	.L4
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40056(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %eax
	cltq
	movl	-40016(%rbp,%rax,4), %eax
	movl	%eax, -12(%rbp)
	movl	$0, -40024(%rbp)
.L6:
	movl	-12(%rbp), %eax
	cmpl	-40036(%rbp), %eax
	jge	.L5
	movl	-8(%rbp), %eax
	cmpl	-40040(%rbp), %eax
	jge	.L5
	movl	-12(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-40048(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-40056(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jne	.L5
	movl	-40024(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -40024(%rbp)
	addl	$1, -12(%rbp)
	addl	$1, -8(%rbp)
	jmp	.L6
.L5:
	leaq	-40020(%rbp), %rdx
	leaq	-40024(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt3maxIiERKT_S2_S2_
	movl	(%rax), %eax
	movl	%eax, -40020(%rbp)
	addl	$1, -8(%rbp)
	jmp	.L7
.L4:
	movl	-40020(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2080:
	.size	_Z9SolveFastiPiiS_, .-_Z9SolveFastiPiiS_
	.globl	_Z9SolveSlowiPiiS_
	.type	_Z9SolveSlowiPiiS_, @function
_Z9SolveSlowiPiiS_:
.LFB2081:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	%edx, -24(%rbp)
	movq	%rcx, -40(%rbp)
	movl	$0, -12(%rbp)
	movl	$0, -4(%rbp)
.L15:
	movl	-4(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jge	.L10
	movl	$0, -8(%rbp)
.L12:
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	je	.L11
	addl	$1, -8(%rbp)
	jmp	.L12
.L11:
	movl	$0, -16(%rbp)
.L14:
	movl	-8(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jge	.L13
	movl	-4(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jge	.L13
	movl	-8(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jne	.L13
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -16(%rbp)
	addl	$1, -8(%rbp)
	addl	$1, -4(%rbp)
	jmp	.L14
.L13:
	leaq	-12(%rbp), %rdx
	leaq	-16(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt3maxIiERKT_S2_S2_
	movl	(%rax), %eax
	movl	%eax, -12(%rbp)
	addl	$1, -4(%rbp)
	jmp	.L15
.L10:
	movl	-12(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2081:
	.size	_Z9SolveSlowiPiiS_, .-_Z9SolveSlowiPiiS_
	.section	.text._ZSt3minIiERKT_S2_S2_,"axG",@progbits,_ZSt3minIiERKT_S2_S2_,comdat
	.weak	_ZSt3minIiERKT_S2_S2_
	.type	_ZSt3minIiERKT_S2_S2_, @function
_ZSt3minIiERKT_S2_S2_:
.LFB2084:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %edx
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L18
	movq	-16(%rbp), %rax
	jmp	.L19
.L18:
	movq	-8(%rbp), %rax
.L19:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2084:
	.size	_ZSt3minIiERKT_S2_S2_, .-_ZSt3minIiERKT_S2_S2_
	.section	.rodata
.LC0:
	.string	"void Generate(int, int, int)"
.LC1:
	.string	"sol.cc"
.LC2:
	.string	"m>1"
.LC3:
	.string	"n>1"
.LC4:
	.string	"case_"
.LC5:
	.string	".in"
.LC6:
	.string	"w"
.LC7:
	.string	"%d\n"
.LC8:
	.string	"%d "
.LC9:
	.string	"\n%d\n"
.LC10:
	.string	".out"
	.text
	.globl	_Z8Generateiii
	.type	_Z8Generateiii, @function
_Z8Generateiii:
.LFB2082:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA2082
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$4040952, %rsp
	.cfi_offset 3, -24
	movl	%edi, -4040948(%rbp)
	movl	%esi, -4040952(%rbp)
	movl	%edx, -4040956(%rbp)
	movl	-4040952(%rbp), %eax
	cmpl	$1, %eax
	jg	.L21
	leaq	.LC0(%rip), %rcx
	movl	$49, %edx
	leaq	.LC1(%rip), %rsi
	leaq	.LC2(%rip), %rdi
	call	__assert_fail@PLT
.L21:
	movl	-4040956(%rbp), %eax
	cmpl	$1, %eax
	jg	.L22
	leaq	.LC0(%rip), %rcx
	movl	$50, %edx
	leaq	.LC1(%rip), %rsi
	leaq	.LC3(%rip), %rdi
	call	__assert_fail@PLT
.L22:
	movl	$0, -20(%rbp)
.L24:
	movl	-4040952(%rbp), %eax
	cmpl	%eax, -20(%rbp)
	jge	.L23
	movl	-20(%rbp), %eax
	cltq
	movl	-20(%rbp), %edx
	movl	%edx, -40160(%rbp,%rax,4)
	addl	$1, -20(%rbp)
	jmp	.L24
.L23:
	movl	$0, -24(%rbp)
.L26:
	movl	-4040952(%rbp), %eax
	cmpl	%eax, -24(%rbp)
	jge	.L25
	call	rand@PLT
	movl	-4040952(%rbp), %edx
	movl	%edx, %ecx
	subl	-24(%rbp), %ecx
	cltd
	idivl	%ecx
	movl	-24(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -48(%rbp)
	leaq	-40160(%rbp), %rdx
	movl	-48(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rax, %rdx
	leaq	-40160(%rbp), %rcx
	movl	-24(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rcx, %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_
	addl	$1, -24(%rbp)
	jmp	.L26
.L25:
	movl	$0, -28(%rbp)
.L28:
	movl	-4040956(%rbp), %eax
	cmpl	%eax, -28(%rbp)
	jge	.L27
	call	rand@PLT
	movl	-4040952(%rbp), %ecx
	cltd
	idivl	%ecx
	movl	-28(%rbp), %eax
	cltq
	movl	%edx, -4040176(%rbp,%rax,4)
	addl	$1, -28(%rbp)
	jmp	.L28
.L27:
	movl	$0, -32(%rbp)
.L32:
	cmpl	$9, -32(%rbp)
	jg	.L29
	call	rand@PLT
	movl	%eax, %ebx
	leaq	-4040956(%rbp), %rdx
	leaq	-4040952(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZSt3minIiERKT_S2_S2_
	movl	(%rax), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, %ecx
	movl	%ebx, %eax
	cltd
	idivl	%ecx
	movl	%edx, -52(%rbp)
	call	rand@PLT
	movl	-4040952(%rbp), %edx
	addl	$1, %edx
	movl	%edx, %ecx
	subl	-52(%rbp), %ecx
	cltd
	idivl	%ecx
	movl	%edx, -56(%rbp)
	call	rand@PLT
	movl	-4040956(%rbp), %edx
	addl	$1, %edx
	movl	%edx, %ecx
	subl	-52(%rbp), %ecx
	cltd
	idivl	%ecx
	movl	%edx, -60(%rbp)
	movl	$0, -36(%rbp)
.L31:
	movl	-36(%rbp), %eax
	cmpl	-52(%rbp), %eax
	jge	.L30
	movl	-56(%rbp), %edx
	movl	-36(%rbp), %eax
	addl	%edx, %eax
	movl	-60(%rbp), %ecx
	movl	-36(%rbp), %edx
	addl	%edx, %ecx
	cltq
	movl	-40160(%rbp,%rax,4), %edx
	movslq	%ecx, %rax
	movl	%edx, -4040176(%rbp,%rax,4)
	addl	$1, -36(%rbp)
	jmp	.L31
.L30:
	addl	$1, -32(%rbp)
	jmp	.L32
.L29:
	leaq	-4040560(%rbp), %rax
	movq	%rax, %rdi
.LEHB0:
	call	_ZNSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEEC1Ev@PLT
.LEHE0:
	leaq	-4040560(%rbp), %rax
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
.LEHB1:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4040948(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	-144(%rbp), %rax
	leaq	-4040560(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEE3strEv@PLT
.LEHE1:
	leaq	-144(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv@PLT
	leaq	.LC6(%rip), %rsi
	movq	%rax, %rdi
.LEHB2:
	call	fopen@PLT
.LEHE2:
	movq	%rax, -72(%rbp)
	leaq	-144(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	movl	-4040952(%rbp), %edx
	movq	-72(%rbp), %rax
	leaq	.LC7(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
.LEHB3:
	call	fprintf@PLT
	movl	$0, -40(%rbp)
.L34:
	movl	-4040952(%rbp), %eax
	cmpl	%eax, -40(%rbp)
	jge	.L33
	movl	-40(%rbp), %eax
	cltq
	movl	-40160(%rbp,%rax,4), %edx
	movq	-72(%rbp), %rax
	leaq	.LC8(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	addl	$1, -40(%rbp)
	jmp	.L34
.L33:
	movl	-4040956(%rbp), %edx
	movq	-72(%rbp), %rax
	leaq	.LC9(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	movl	$0, -44(%rbp)
.L36:
	movl	-4040956(%rbp), %eax
	cmpl	%eax, -44(%rbp)
	jge	.L35
	movl	-44(%rbp), %eax
	cltq
	movl	-4040176(%rbp,%rax,4), %edx
	movq	-72(%rbp), %rax
	leaq	.LC8(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	fprintf@PLT
	addl	$1, -44(%rbp)
	jmp	.L36
.L35:
	movq	-72(%rbp), %rax
	movq	%rax, %rsi
	movl	$10, %edi
	call	fputc@PLT
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movl	-4040956(%rbp), %edx
	movl	-4040952(%rbp), %eax
	leaq	-4040176(%rbp), %rcx
	leaq	-40160(%rbp), %rsi
	movl	%eax, %edi
	call	_Z9SolveFastiPiiS_
	movl	%eax, -76(%rbp)
	leaq	-4040944(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEEC1Ev@PLT
.LEHE3:
	leaq	-4040944(%rbp), %rax
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
.LEHB4:
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movl	-4040948(%rbp), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEi@PLT
	leaq	.LC10(%rip), %rsi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	leaq	-112(%rbp), %rax
	leaq	-4040944(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEE3strEv@PLT
.LEHE4:
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv@PLT
	leaq	.LC6(%rip), %rsi
	movq	%rax, %rdi
.LEHB5:
	call	fopen@PLT
.LEHE5:
	movq	%rax, -72(%rbp)
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	movl	-76(%rbp), %edx
	movq	-72(%rbp), %rax
	leaq	.LC7(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
.LEHB6:
	call	fprintf@PLT
.LEHE6:
	leaq	-4040944(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev@PLT
	leaq	-4040560(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L45
.L42:
	movq	%rax, %rbx
	leaq	-144(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L38
.L44:
	movq	%rax, %rbx
	leaq	-112(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L40
.L43:
	movq	%rax, %rbx
.L40:
	leaq	-4040944(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev@PLT
	jmp	.L38
.L41:
	movq	%rax, %rbx
.L38:
	leaq	-4040560(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1119basic_ostringstreamIcSt11char_traitsIcESaIcEED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB7:
	call	_Unwind_Resume@PLT
.LEHE7:
.L45:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2082:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA2082:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2082-.LLSDACSB2082
.LLSDACSB2082:
	.uleb128 .LEHB0-.LFB2082
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB2082
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L41-.LFB2082
	.uleb128 0
	.uleb128 .LEHB2-.LFB2082
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L42-.LFB2082
	.uleb128 0
	.uleb128 .LEHB3-.LFB2082
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L41-.LFB2082
	.uleb128 0
	.uleb128 .LEHB4-.LFB2082
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L43-.LFB2082
	.uleb128 0
	.uleb128 .LEHB5-.LFB2082
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L44-.LFB2082
	.uleb128 0
	.uleb128 .LEHB6-.LFB2082
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L43-.LFB2082
	.uleb128 0
	.uleb128 .LEHB7-.LFB2082
	.uleb128 .LEHE7-.LEHB7
	.uleb128 0
	.uleb128 0
.LLSDACSE2082:
	.text
	.size	_Z8Generateiii, .-_Z8Generateiii
	.globl	_Z13GenerateCasesv
	.type	_Z13GenerateCasesv, @function
_Z13GenerateCasesv:
.LFB2085:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	movl	$20, %edx
	movl	$10, %esi
	movl	$0, %edi
	call	_Z8Generateiii
	movl	$10, %edx
	movl	$20, %esi
	movl	$1, %edi
	call	_Z8Generateiii
	movl	$30, %edx
	movl	$15, %esi
	movl	$2, %edi
	call	_Z8Generateiii
	movl	$15, %edx
	movl	$30, %esi
	movl	$3, %edi
	call	_Z8Generateiii
	movl	$50, %edx
	movl	$20, %esi
	movl	$4, %edi
	call	_Z8Generateiii
	movl	$20, %edx
	movl	$50, %esi
	movl	$5, %edi
	call	_Z8Generateiii
	movl	$300, %edx
	movl	$100, %esi
	movl	$6, %edi
	call	_Z8Generateiii
	movl	$100, %edx
	movl	$300, %esi
	movl	$7, %edi
	call	_Z8Generateiii
	movl	$5000, %edx
	movl	$1000, %esi
	movl	$8, %edi
	call	_Z8Generateiii
	movl	$1000, %edx
	movl	$5000, %esi
	movl	$9, %edi
	call	_Z8Generateiii
	movl	$10000, %edx
	movl	$100, %esi
	movl	$10, %edi
	call	_Z8Generateiii
	movl	$50000, %edx
	movl	$300, %esi
	movl	$11, %edi
	call	_Z8Generateiii
	movl	$100000, %edx
	movl	$500, %esi
	movl	$12, %edi
	call	_Z8Generateiii
	movl	$500000, %edx
	movl	$1000, %esi
	movl	$13, %edi
	call	_Z8Generateiii
	movl	$600000, %edx
	movl	$2000, %esi
	movl	$14, %edi
	call	_Z8Generateiii
	movl	$700000, %edx
	movl	$3000, %esi
	movl	$15, %edi
	call	_Z8Generateiii
	movl	$800000, %edx
	movl	$5000, %esi
	movl	$16, %edi
	call	_Z8Generateiii
	movl	$900000, %edx
	movl	$7000, %esi
	movl	$17, %edi
	call	_Z8Generateiii
	movl	$950000, %edx
	movl	$9000, %esi
	movl	$18, %edi
	call	_Z8Generateiii
	movl	$1000000, %edx
	movl	$10000, %esi
	movl	$19, %edi
	call	_Z8Generateiii
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2085:
	.size	_Z13GenerateCasesv, .-_Z13GenerateCasesv
	.section	.rodata
.LC11:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2086:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$4040048, %rsp
	leaq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -12(%rbp)
	movl	$0, -4(%rbp)
.L49:
	movl	-24(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jge	.L48
	leaq	-4040048(%rbp), %rdx
	movl	-4(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -12(%rbp)
	addl	$1, -4(%rbp)
	jmp	.L49
.L48:
	leaq	-20(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -12(%rbp)
	movl	$0, -8(%rbp)
.L51:
	movl	-20(%rbp), %eax
	cmpl	%eax, -8(%rbp)
	jge	.L50
	leaq	-4000032(%rbp), %rdx
	movl	-8(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	%eax, -12(%rbp)
	addl	$1, -8(%rbp)
	jmp	.L51
.L50:
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %eax
	leaq	-4000032(%rbp), %rcx
	leaq	-4040048(%rbp), %rsi
	movl	%eax, %edi
	call	_Z9SolveSlowiPiiS_
	movl	%eax, -16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2086:
	.size	main, .-main
	.section	.text._ZSt3maxIiERKT_S2_S2_,"axG",@progbits,_ZSt3maxIiERKT_S2_S2_,comdat
	.weak	_ZSt3maxIiERKT_S2_S2_
	.type	_ZSt3maxIiERKT_S2_S2_, @function
_ZSt3maxIiERKT_S2_S2_:
.LFB2331:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jge	.L54
	movq	-16(%rbp), %rax
	jmp	.L55
.L54:
	movq	-8(%rbp), %rax
.L55:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2331:
	.size	_ZSt3maxIiERKT_S2_S2_, .-_ZSt3maxIiERKT_S2_S2_
	.section	.text._ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_,"axG",@progbits,_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_,comdat
	.weak	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	.type	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_, @function
_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_:
.LFB2333:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2333:
	.size	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_, .-_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	.section	.text._ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_,"axG",@progbits,_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_,comdat
	.weak	_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_
	.type	_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_, @function
_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_:
.LFB2332:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movl	%edx, (%rax)
	leaq	-4(%rbp), %rax
	movq	%rax, %rdi
	call	_ZSt4moveIRiEONSt16remove_referenceIT_E4typeEOS2_
	movl	(%rax), %edx
	movq	-32(%rbp), %rax
	movl	%edx, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2332:
	.size	_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_, .-_ZSt4swapIiENSt9enable_ifIXsrSt6__and_IJSt6__not_ISt15__is_tuple_likeIT_EESt21is_move_constructibleIS4_ESt18is_move_assignableIS4_EEE5valueEvE4typeERS4_SE_
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.ident	"GCC: (Debian 10.2.1-6+build2) 10.2.1 20210110"
	.section	.note.GNU-stack,"",@progbits
