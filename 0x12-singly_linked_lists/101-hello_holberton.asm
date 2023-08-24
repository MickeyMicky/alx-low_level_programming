section .data
	hello_message db "Hello, Holberton " ,0
	newline db 10, 0
section .text
	global main

extern printf

main:
	push rdi

	lea rdi, [hello_message]
	call printf

	lea rdi, [newline]
	call printf

	pop rdi
	ret
