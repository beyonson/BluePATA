	.cpu cortex-m3
	.arch armv7-m
	.fpu softvfp
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 1
	.eabi_attribute 18, 4
	.file	"main.c"
	.text
	.align	1
	.global	reset_handler
	.syntax unified
	.thumb
	.thumb_func
	.type	reset_handler, %function
reset_handler:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r7, lr}
	add	r7, sp, #0
	bl	main
.L2:
	b	.L2
	.size	reset_handler, .-reset_handler
	.align	1
	.global	main
	.syntax unified
	.thumb
	.thumb_func
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 0
	@ frame_needed = 1, uses_anonymous_args = 0
	@ link register save eliminated.
	push	{r7}
	add	r7, sp, #0
	ldr	r3, .L5
	ldr	r3, [r3, #20]
	ldr	r2, .L5
	orr	r3, r3, #16
	str	r3, [r2, #20]
	ldr	r3, .L5+4
	ldr	r3, [r3, #4]
	ldr	r2, .L5+4
	bic	r3, r3, #15728640
	str	r3, [r2, #4]
	ldr	r3, .L5+4
	ldr	r3, [r3, #4]
	ldr	r2, .L5+4
	orr	r3, r3, #3145728
	str	r3, [r2, #4]
	movs	r3, #0
	mov	r0, r3
	mov	sp, r7
	@ sp needed
	pop	{r7}
	bx	lr
.L6:
	.align	2
.L5:
	.word	1073876992
	.word	1073811456
	.size	main, .-main
	.ident	"GCC: (Arm GNU Toolchain 12.2.Rel1 (Build arm-12.24)) 12.2.1 20221205"
