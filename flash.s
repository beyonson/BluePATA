stack_size      =       0x400
stack_start     =       0x20000000+stack_size
gpioc_base      =       0x40011000
rcc_base        =       0x40021000
rcc_apb2enr     =       rcc_base+0x18
gpio_crh        =       gpioc_base+0x04
gpioc_odr       =       gpioc_base+0x0C


.syntax unified
.cpu cortex-m3
.thumb

vtable:
    .word   stack_start
    .word   reset_handler


.thumb_func
reset_handler:
    B main

main:
    LDR R0, =rcc_apb2enr
    LDR R1, [R0]
    LDR R2, =0x10 // Activate 3rd bit in registry
    ORR R1, R2
    STR R1, [R0]

    // Configure GPIO_CRL
    LDR R0, =gpio_crh
    LDR R1, [R0]
    LDR R2, =0xFF0FFFFF
    AND R1,R1,R2
    ORR R1, R1, #0x300000
    STR R1, [R0] // Reset register

    //Configure GPIOB_ODR
    LDR R0, =gpioc_odr
    LDR R1, [R0]
    ORR R1, #0x2000
    STR R1, [R0]
    B .
