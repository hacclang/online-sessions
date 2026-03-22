int main1()
{
	return 89;

	// registers => storage locations inside the processor
	// rax => 8 bytes
	// eax => 4 bytes
	// ax  => 2 bytes
	// al  => 1 byte
	//
	// i64 => rax 
	// i32 => eax
	// i16 => ax
	// i8  => al
	//
	//
	/*  global main:
	 *  main:
	 *  	push rbp
	 *  	mov rbp,rsp
	 *
	 *  	mov eax,0x59
	 *
	 *  	mov rsp,rbp
	 *  	pop rbp
	 *  	ret
	 *
	 */
}


int main2()
{
	int a = 90; // int has => 4 bytes , allocate 4 bytes on the stack
	int b = 78;
	return b;

	/*
	 *   bottom [  stack  ] top
	 *
	 *   push value
	 *   pop a
	 *
	 *   [ ] top
	 *   push 67
	 *
	 *   [ 67 ] top
	 *
	 *   push 59
	 *
	 *   [67,59] top
	 *
	 *   push 100
	 *
	 *   [67,59,100] top
	 *
	 *   pop a
	 *
	 *   [ 67,59] top
	 *
	 *   a // 100
	 *   pop a 
	 *
	 *   [67] top
	 *   
	 *   a // 59
	 *	
	 *   int a = 90;
	 *   return a;
	 *
	 *   [ 0,1]
	 *   100
	 *   0                                                                              top [] 100
	 *   push 56
	 *
	 *   push rbp
	 *   mov rbp,rsp
	 *   sub rbp,0x08
	 *   mov [rbp - 8],0x5a
	 *   mov [rbp - 4],0x4e
	 *   mov eax,DWORD[rbp - 4]
	 *   mov rsp,rbp
	 *   pop rbp
	 *   ret
	 *
	 *
	 *   a = 90
	 *   dst = src
	 *   mov dst,src
	 *   mov a,90
	 *
	 */
}


int main3()
{
	int a = 90;

	if(a)
	{
		return 89;
	}
	else
	{
		return 0;
	}

	/*
	 * 	push rbp
	 * 	mov rbp,rsp  // noise
	 *      sub rsp,0x04
	 *      mov DWORD[rbp - 4],90
	 *
	 * -----
	 *  	mov eax,DWORD[rbp - 0x4]
	 *  	cmp eax,0
	 *  	je if_false
	 *----
	 * 	cmp DWORD[rbp - 0x4],0
	 * 	jz if_false
	 *---
	 * 	mov eax,0x59
	 * 	jmp if_return
	 * if_false:
	 * 	mov eax,0x0
	 * if_return:
	 * 	pop rbp
	 * 	ret
	 *
	 */
}



int main4()
{
	int a = 90;

	if(a)
	{
		return 89;
	}
	else if(a)
	{
		return 6;
	}
	else
	{
		return 0;
	}

	/*
	 * 	push rbp
	 * 	mov rbp,rsp  // noise
	 *      sub rsp,0x04
	 *      mov DWORD[rbp - 4],90
	 *
	 * -----
	 *  	mov eax,DWORD[rbp - 0x4]
	 *  	cmp eax,0
	 *  	je if_false
	 *----
	 * 	cmp DWORD[rbp - 0x4],0
	 * 	jz if_false
	 *---
	 * 	mov eax,0x59
	 * 	jmp if_return
	 * if_false:
	 * 	mov eax,0x0
	 * if_return:
	 * 	pop rbp
	 * 	ret
	 *
	 *
	 * 	push rbp
	 * 	mov rbp,rsp
	 *
	 * 	cmp eax,0
	 * 	je if_else_if
	 *      mov eax,89
	 *      jmp if_return
	 * if_else_if1:
	 *      // load the else if condition inside eax
	 * 	cmp eax,0
	 * 	je if_end
	 * 	mov eax,0x6;
	 * 	jmp if_return
	 * if_end:
	 * 	mov eax,0x0
	 * 	jmp if_return
	 * if_return:
	 * 	pop rbp
	 * 	ret
	 * 
	 */
}

int get_day(int a,int b,int c)
{
	return a;
	/*
	 * push rbp
	 * mov rbp,rsp
	 * mov eax,edi
	 * pop rbp
	 * ret
	 *
	 */
}

int main()
{
	return get_day(32,48,64);

	/*
	 *
	 *  push rbp
	 *  mov rbp,rsp
	 *  call get_day
	 *  mov eax,0x0
	 *  pop rbp
	 *  ret
	 *
	 *  push rbp
	 *  mov rbp,rsp
	 *  call get_day
	 *  pop rbp
	 *  ret
	 *
	 *
	 *  func(int arg1,int arg2,int arg3,int arg4,int arg5,int arg6)
	 *
	 *  arg1 => rdi
	 *  arg2 => rsi
	 *  arg3 => rdx
	 *  arg4 => rcx
	 *  arg5 => r9
	 *  arg6 => r8
	 *
	 *  r => 64
	 *  e => 32
	 *    => 16
	 *
	 *  rax => 64
	 *  eax => 32
	 *   ax => 16
	 *
	 *  
	 *  push rbp
	 *  mov rbp,rsp
	 *  mov edi,0x20
	 *  call get_day
	 *  pop rbp
	 *  ret
	 *
	 *  push rbp
	 *  mov rbp,rsp
	 *  mov edi,0x20
	 *  mov esi,0x30
	 *  call get_day
	 *  pop rbp
	 *  ret
	 *
	 *  push rbp
	 *  mov rbp,rsp
	 *  mov edx,0x40
	 *  mov esi,0x30
	 *  mov edi,0x20
	 *  call get_day
	 *  pop rbp
	 *  ret
	 *
	 */
}


/*

	[                                        compiler                                              ][        assembler         ]gcc => lexing => parsing(syntax analysis) => semantic analysis => IR(Intermediate Representation) => assembly generation => machine code

				forward engineering(information lost)

				reverse engineering

machine code => assembly generation  =>  C (or another high-level language) ...This is called decompiling

*/








