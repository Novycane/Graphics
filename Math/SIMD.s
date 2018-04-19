	.text
	.def	 add_f2;
	.scl	2;
	.type	32;
	.endef
	.globl	add_f2                  # -- Begin function add_f2
	.p2align	4, 0x90
add_f2:                                 # @add_f2
.Lcfi0:
.seh_proc add_f2
# BB#0:
	subq	$24, %rsp
.Lcfi1:
	.seh_stackalloc 24
.Lcfi2:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovaps	(%rdx), %xmm0
	vaddps	(%r8), %xmm0, %xmm0
	vmovaps	%xmm0, (%rcx)

	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi3:
	.seh_endproc
                                        # -- End function
	.def	 subtract_f2;
	.scl	2;
	.type	32;
	.endef
	.globl	subtract_f2             # -- Begin function subtract_f2
	.p2align	4, 0x90
subtract_f2:                            # @subtract_f2
.Lcfi4:
.seh_proc subtract_f2
# BB#0:
	subq	$24, %rsp
.Lcfi5:
	.seh_stackalloc 24
.Lcfi6:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovaps	(%rdx), %xmm0
	vsubps	(%r8), %xmm0, %xmm0
	vmovaps	%xmm0, (%rcx)

	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi7:
	.seh_endproc
                                        # -- End function
	.def	 multiply_f2;
	.scl	2;
	.type	32;
	.endef
	.globl	multiply_f2             # -- Begin function multiply_f2
	.p2align	4, 0x90
multiply_f2:                            # @multiply_f2
.Lcfi8:
.seh_proc multiply_f2
# BB#0:
	subq	$24, %rsp
.Lcfi9:
	.seh_stackalloc 24
.Lcfi10:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovaps	(%rdx), %xmm0
	vmulps	(%r8), %xmm0, %xmm0
	vmovaps	%xmm0, (%rcx)

	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi11:
	.seh_endproc
                                        # -- End function
	.def	 divide_f2;
	.scl	2;
	.type	32;
	.endef
	.globl	divide_f2               # -- Begin function divide_f2
	.p2align	4, 0x90
divide_f2:                              # @divide_f2
.Lcfi12:
.seh_proc divide_f2
# BB#0:
	subq	$24, %rsp
.Lcfi13:
	.seh_stackalloc 24
.Lcfi14:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovaps	(%r8), %xmm0
	vdivps	(%rdx), %xmm0, %xmm0
	vmovaps	%xmm0, (%rcx)

	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi15:
	.seh_endproc
                                        # -- End function
	.def	 add_f4;
	.scl	2;
	.type	32;
	.endef
	.globl	add_f4                  # -- Begin function add_f4
	.p2align	4, 0x90
add_f4:                                 # @add_f4
.Lcfi16:
.seh_proc add_f4
# BB#0:
	subq	$24, %rsp
.Lcfi17:
	.seh_stackalloc 24
.Lcfi18:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovaps	(%rdx), %xmm0
	vaddps	(%r8), %xmm0, %xmm0
	vmovaps	%xmm0, (%rcx)

	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi19:
	.seh_endproc
                                        # -- End function
	.def	 subtract_f4;
	.scl	2;
	.type	32;
	.endef
	.globl	subtract_f4             # -- Begin function subtract_f4
	.p2align	4, 0x90
subtract_f4:                            # @subtract_f4
.Lcfi20:
.seh_proc subtract_f4
# BB#0:
	subq	$24, %rsp
.Lcfi21:
	.seh_stackalloc 24
.Lcfi22:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovaps	(%rdx), %xmm0
	vsubps	(%r8), %xmm0, %xmm0
	vmovaps	%xmm0, (%rcx)

	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi23:
	.seh_endproc
                                        # -- End function
	.def	 multiply_f4;
	.scl	2;
	.type	32;
	.endef
	.globl	multiply_f4             # -- Begin function multiply_f4
	.p2align	4, 0x90
multiply_f4:                            # @multiply_f4
.Lcfi24:
.seh_proc multiply_f4
# BB#0:
	subq	$24, %rsp
.Lcfi25:
	.seh_stackalloc 24
.Lcfi26:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovaps	(%rdx), %xmm0
	vmulps	(%r8), %xmm0, %xmm0
	vmovaps	%xmm0, (%rcx)

	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi27:
	.seh_endproc
                                        # -- End function
	.def	 divide_f4;
	.scl	2;
	.type	32;
	.endef
	.globl	divide_f4               # -- Begin function divide_f4
	.p2align	4, 0x90
divide_f4:                              # @divide_f4
.Lcfi28:
.seh_proc divide_f4
# BB#0:
	subq	$24, %rsp
.Lcfi29:
	.seh_stackalloc 24
.Lcfi30:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovaps	(%r8), %xmm0
	vdivps	(%rdx), %xmm0, %xmm0
	vmovaps	%xmm0, (%rcx)

	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi31:
	.seh_endproc
                                        # -- End function
	.def	 matrix_multiply_f4;
	.scl	2;
	.type	32;
	.endef
	.globl	matrix_multiply_f4      # -- Begin function matrix_multiply_f4
	.p2align	4, 0x90
matrix_multiply_f4:                     # @matrix_multiply_f4
.Lcfi32:
.seh_proc matrix_multiply_f4
# BB#0:
	subq	$24, %rsp
.Lcfi33:
	.seh_stackalloc 24
.Lcfi34:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	8(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovaps	(%rdx), %xmm0
	vmovaps	%xmm0, (%rcx)
	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi35:
	.seh_endproc
                                        # -- End function
	.def	 add_d2;
	.scl	2;
	.type	32;
	.endef
	.globl	add_d2                  # -- Begin function add_d2
	.p2align	4, 0x90
add_d2:                                 # @add_d2
.Lcfi36:
.seh_proc add_d2
# BB#0:
	subq	$24, %rsp
.Lcfi37:
	.seh_stackalloc 24
.Lcfi38:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovapd	(%r8), %xmm0
	vaddpd	(%rdx), %xmm0, %xmm0
	vmovapd	%xmm0, (%rcx)
	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi39:
	.seh_endproc
                                        # -- End function
	.def	 subtract_d2;
	.scl	2;
	.type	32;
	.endef
	.globl	subtract_d2             # -- Begin function subtract_d2
	.p2align	4, 0x90
subtract_d2:                            # @subtract_d2
.Lcfi40:
.seh_proc subtract_d2
# BB#0:
	subq	$24, %rsp
.Lcfi41:
	.seh_stackalloc 24
.Lcfi42:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovapd	(%rdx), %xmm0
	vsubpd	(%r8), %xmm0, %xmm0
	vmovapd	%xmm0, (%rcx)
	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi43:
	.seh_endproc
                                        # -- End function
	.def	 multiply_d2;
	.scl	2;
	.type	32;
	.endef
	.globl	multiply_d2             # -- Begin function multiply_d2
	.p2align	4, 0x90
multiply_d2:                            # @multiply_d2
.Lcfi44:
.seh_proc multiply_d2
# BB#0:
	subq	$24, %rsp
.Lcfi45:
	.seh_stackalloc 24
.Lcfi46:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovapd	(%rdx), %xmm0
	vmulpd	(%r8), %xmm0, %xmm0
	vmovapd	%xmm0, (%rcx)
	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi47:
	.seh_endproc
                                        # -- End function
	.def	 divide_d2;
	.scl	2;
	.type	32;
	.endef
	.globl	divide_d2               # -- Begin function divide_d2
	.p2align	4, 0x90
divide_d2:                              # @divide_d2
.Lcfi48:
.seh_proc divide_d2
# BB#0:
	subq	$24, %rsp
.Lcfi49:
	.seh_stackalloc 24
.Lcfi50:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovapd	(%rdx), %xmm0
	vdivpd	(%r8), %xmm0, %xmm0
	vmovapd	%xmm0, (%rcx)
	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi51:
	.seh_endproc
                                        # -- End function
	.def	 add_d4;
	.scl	2;
	.type	32;
	.endef
	.globl	add_d4                  # -- Begin function add_d4
	.p2align	4, 0x90
add_d4:                                 # @add_d4
.Lcfi52:
.seh_proc add_d4
# BB#0:
	subq	$24, %rsp
.Lcfi53:
	.seh_stackalloc 24
.Lcfi54:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovapd	(%r8), %ymm0
	vaddpd	(%rdx), %ymm0, %ymm1
	vmovapd	%ymm1, (%rcx)
	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi55:
	.seh_endproc
                                        # -- End function
	.def	 subtract_d4;
	.scl	2;
	.type	32;
	.endef
	.globl	subtract_d4             # -- Begin function subtract_d4
	.p2align	4, 0x90
subtract_d4:                            # @subtract_d4
.Lcfi56:
.seh_proc subtract_d4
# BB#0:
	subq	$24, %rsp
.Lcfi57:
	.seh_stackalloc 24
.Lcfi58:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovapd	(%rdx), %ymm0
	vsubpd	(%r8), %ymm0, %ymm1
	vmovapd	%ymm1, (%rcx)
	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi59:
	.seh_endproc
                                        # -- End function
	.def	 multiply_d4;
	.scl	2;
	.type	32;
	.endef
	.globl	multiply_d4             # -- Begin function multiply_d4
	.p2align	4, 0x90
multiply_d4:                            # @multiply_d4
.Lcfi60:
.seh_proc multiply_d4
# BB#0:
	subq	$24, %rsp
.Lcfi61:
	.seh_stackalloc 24
.Lcfi62:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovapd	(%rdx), %ymm0
	vmulpd	(%r8), %ymm0, %ymm1
	vmovapd	%ymm1, (%rcx)
	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi63:
	.seh_endproc
                                        # -- End function
	.def	 divide_d4;
	.scl	2;
	.type	32;
	.endef
	.globl	divide_d4               # -- Begin function divide_d4
	.p2align	4, 0x90
divide_d4:                              # @divide_d4
.Lcfi64:
.seh_proc divide_d4
# BB#0:
	subq	$24, %rsp
.Lcfi65:
	.seh_stackalloc 24
.Lcfi66:
	.seh_endprologue
	movq	%r8, 16(%rsp)
	movq	%rdx, 8(%rsp)
	movq	%rcx, (%rsp)
	movq	16(%rsp), %rcx
	movq	(%rsp), %rdx
	movq	8(%rsp), %r8
	#APP
	vmovapd	(%rdx), %ymm0
	vdivpd	(%r8), %ymm0, %ymm1
	vmovapd	%ymm1, (%rcx)
	#NO_APP
	addq	$24, %rsp
	retq
	.seh_handlerdata
	.text
.Lcfi67:
	.seh_endproc
                                        # -- End function

