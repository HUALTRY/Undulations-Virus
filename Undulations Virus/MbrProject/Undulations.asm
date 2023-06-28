bits 16
org 0x7C00

main:
    mov ax, 0x0013
    int 0x10
    
    mov ax, 0xA000
    mov es, ax
    
    xor bx, bx
    
animation_loop:
    call generate_random_color
    call generate_random_position
    
    mov cx, 4
    
pixel_loop:
    mov al, [es:bx]
    add al, dl
    mov [es:bx], al
    
    add bx, 1
    loop pixel_loop
    
    add bx, 316
    
    jmp animation_loop

generate_random_color:
    mov ax, 0x1000
    call generate_random_byte
    and ax, 0x00F0
    or ax, 0x000A
    
    mov dl, al
    ret

generate_random_position:
    mov ax, 0x13AD
    call generate_random_byte
    sub ax, 0x007F
    
    ret

generate_random_byte:
    mov ax, bx
    imul ax, 0x152D
    add ax, 0x271D
    mov bx, ax
    
    mov al, bl
    ret

times 510-($-$$) db 0
dw 0xAA55