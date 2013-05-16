.model full
	.sourcedir 'C:\MoSync\workspace\The_Game/'
	.sourcefile 'C:\MoSync\workspace\The_Game\GameObj.cpp'
	.stabs	"gcc2_compiled.",60,0,0,0
	.stabs	"__vtbl_ptr_type:t(0,1)=*(0,2)=f(0,3)=r(0,3);-2147483648;2147483647;",128,0,0,0
	.stabs	"bool:t(0,4)=@s8;-16;",128,0,0,0
	.stabs	"wchar_t:t(0,5)=@s16;r(0,5);0;65535;",128,0,0,0
	.stabs	"void:t(0,6)=(0,6)",128,0,0,0
	.stabs	"long double:t(0,7)=r(0,3);8;0;",128,0,0,0
	.stabs	"double:t(0,8)=r(0,3);8;0;",128,0,0,0
	.stabs	"float:t(0,9)=r(0,3);4;0;",128,0,0,0
	.stabs	"unsigned char:t(0,10)=@s8;r(0,10);0;255;",128,0,0,0
	.stabs	"signed char:t(0,11)=@s8;r(0,11);-128;127;",128,0,0,0
	.stabs	"short unsigned int:t(0,12)=@s16;r(0,12);0;65535;",128,0,0,0
	.stabs	"short int:t(0,13)=@s16;r(0,13);-32768;32767;",128,0,0,0
	.stabs	"long long unsigned int:t(0,14)=@s64;r(0,14);0000000000000;01777777777777777777777;",128,0,0,0
	.stabs	"long long int:t(0,15)=@s64;r(0,15);01000000000000000000000;0777777777777777777777;",128,0,0,0
	.stabs	"long unsigned int:t(0,16)=r(0,16);0000000000000;0037777777777;",128,0,0,0
	.stabs	"unsigned int:t(0,17)=r(0,17);0000000000000;0037777777777;",128,0,0,0
	.stabs	"long int:t(0,18)=r(0,18);-2147483648;2147483647;",128,0,0,0
	.stabs	"int:t(0,3)",128,0,0,0
	.stabs	"char:t(0,19)=r(0,19);0;127;",128,0,0,0
	.stabs	"__builtin_va_list:t(0,20)=*(0,6)",128,0,0,0
	.stabs	"complex long double:t(0,21)=R3;16;0;",128,0,0,0
	.stabs	"complex double:t(0,22)=R3;16;0;",128,0,0,0
	.stabs	"complex float:t(0,23)=R3;8;0;",128,0,0,0
	.stabs	"complex int:t(0,24)=s8real:(0,3),0,32;imag:(0,3),32,32;;",128,0,0,0
	.stabs	"C:\\MoSync\\workspace\\The_Game\\/GameObj.h",130,0,0,0
	.stabs	"GameObj::Direction:t(1,1)=eUP:0,DOWN:1,LEFT:2,RIGHT:3,;",128,0,12,0
	.stabn	162,0,0,0
.code
	.stabs	"_ZN7GameObjC2Eii:F(0,6)",36,0,10,__ZN7GameObjC2Eii
	.stabs	"this:p(0,25)=k(0,26)=*(0,27)=xsGameObj:",160,0,10,-12
	.stabs	"px:p(0,3)",160,0,10,-16
	.stabs	"py:p(0,3)",160,0,10,-20
	.global	__ZN7GameObjC2Eii

.func __ZN7GameObjC2Eii, 3, void
	.line 10
	push rt,fr
	sub  sp,#0xc
	ld   fr,sp
	add  fr,#0x14
	ld   [fr,-12],i0
	ld   [fr,-16],i1
	ld   [fr,-20],i2
	.dlab LBB2
	.line 10
	ld   r14,[fr,-12]
	ld   r0,#__ZTV7GameObj+8
	ld   [r14],r0
	ld   r14,[fr,-12]
	ld   r0,[fr,-16]
	ld   [r14,4],r0
	ld   r14,[fr,-12]
	ld   r0,[fr,-20]
	ld   [r14,8],r0
	.dlab LBE2
	add  sp,#0xc
	pop  rt,fr
	ret
Lscope0:
	.stabs	"_ZN7GameObjC1Eii:F(0,6)",36,0,10,__ZN7GameObjC1Eii
	.stabs	"this:p(0,25)",160,0,10,-12
	.stabs	"px:p(0,3)",160,0,10,-16
	.stabs	"py:p(0,3)",160,0,10,-20
	.global	__ZN7GameObjC1Eii

.func __ZN7GameObjC1Eii, 3, void
	.line 10
	push rt,fr
	sub  sp,#0xc
	ld   fr,sp
	add  fr,#0x14
	ld   [fr,-12],i0
	ld   [fr,-16],i1
	ld   [fr,-20],i2
	.dlab LBB3
	.line 10
	ld   r14,[fr,-12]
	ld   r0,#__ZTV7GameObj+8
	ld   [r14],r0
	ld   r14,[fr,-12]
	ld   r0,[fr,-16]
	ld   [r14,4],r0
	ld   r14,[fr,-12]
	ld   r0,[fr,-20]
	ld   [r14,8],r0
	.dlab LBE3
	add  sp,#0xc
	pop  rt,fr
	ret
Lscope1:
	.stabs	"_ZNK7GameObj4getXEv:F(0,3)",36,0,15,__ZNK7GameObj4getXEv
	.stabs	"this:p(0,28)=k(0,29)=*(0,30)=k(0,27)",160,0,15,-12
	.global	__ZNK7GameObj4getXEv

.func __ZNK7GameObj4getXEv, 1, int
	.line 15
	push rt,fr
	sub  sp,#0x4
	ld   fr,sp
	add  fr,#0xc
	ld   [fr,-12],i0
	.dlab LBB4
	.line 15
	ld   r14,[fr,-12]
	ld   r14,[r14,4]
	.dlab LBE4
	add  sp,#0x4
	pop  rt,fr
	ret
Lscope2:
	.stabs	"_ZN7GameObj4setXEi:F(0,6)",36,0,16,__ZN7GameObj4setXEi
	.stabs	"this:p(0,25)",160,0,16,-12
	.stabs	"x:p(0,3)",160,0,16,-16
	.global	__ZN7GameObj4setXEi

.func __ZN7GameObj4setXEi, 2, void
	.line 16
	push rt,fr
	sub  sp,#0x8
	ld   fr,sp
	add  fr,#0x10
	ld   [fr,-12],i0
	ld   [fr,-16],i1
	.dlab LBB5
	.line 16
	ld   r14,[fr,-12]
	ld   r0,[fr,-16]
	ld   [r14,4],r0
	.dlab LBE5
	add  sp,#0x8
	pop  rt,fr
	ret
Lscope3:
	.stabs	"_ZNK7GameObj4getYEv:F(0,3)",36,0,18,__ZNK7GameObj4getYEv
	.stabs	"this:p(0,28)",160,0,18,-12
	.global	__ZNK7GameObj4getYEv

.func __ZNK7GameObj4getYEv, 1, int
	.line 18
	push rt,fr
	sub  sp,#0x4
	ld   fr,sp
	add  fr,#0xc
	ld   [fr,-12],i0
	.dlab LBB6
	.line 18
	ld   r14,[fr,-12]
	ld   r14,[r14,8]
	.dlab LBE6
	add  sp,#0x4
	pop  rt,fr
	ret
Lscope4:
	.stabs	"_ZN7GameObj4setYEi:F(0,6)",36,0,19,__ZN7GameObj4setYEi
	.stabs	"this:p(0,25)",160,0,19,-12
	.stabs	"y:p(0,3)",160,0,19,-16
	.global	__ZN7GameObj4setYEi

.func __ZN7GameObj4setYEi, 2, void
	.line 19
	push rt,fr
	sub  sp,#0x8
	ld   fr,sp
	add  fr,#0x10
	ld   [fr,-12],i0
	ld   [fr,-16],i1
	.dlab LBB7
	.line 19
	ld   r14,[fr,-12]
	ld   r0,[fr,-16]
	ld   [r14,8],r0
	.dlab LBE7
	add  sp,#0x8
	pop  rt,fr
	ret
Lscope5:
	.stabs	"_ZNK7GameObj9getHeightEv:F(0,3)",36,0,21,__ZNK7GameObj9getHeightEv
	.stabs	"this:p(0,28)",160,0,21,-12
	.global	__ZNK7GameObj9getHeightEv

.func __ZNK7GameObj9getHeightEv, 1, int
	.line 21
	push rt,fr
	sub  sp,#0x4
	ld   fr,sp
	add  fr,#0xc
	ld   [fr,-12],i0
	.dlab LBB8
	.line 21
	ld   r14,[fr,-12]
	ld   r14,[r14,16]
	.dlab LBE8
	add  sp,#0x4
	pop  rt,fr
	ret
Lscope6:
	.stabs	"_ZN7GameObj9setHeightEi:F(0,6)",36,0,22,__ZN7GameObj9setHeightEi
	.stabs	"this:p(0,25)",160,0,22,-12
	.stabs	"height:p(0,3)",160,0,22,-16
	.global	__ZN7GameObj9setHeightEi

.func __ZN7GameObj9setHeightEi, 2, void
	.line 22
	push rt,fr
	sub  sp,#0x8
	ld   fr,sp
	add  fr,#0x10
	ld   [fr,-12],i0
	ld   [fr,-16],i1
	.dlab LBB9
	.line 22
	ld   r14,[fr,-12]
	ld   r0,[fr,-16]
	ld   [r14,16],r0
	.dlab LBE9
	add  sp,#0x8
	pop  rt,fr
	ret
Lscope7:
	.stabs	"_ZNK7GameObj8getWidthEv:F(0,3)",36,0,24,__ZNK7GameObj8getWidthEv
	.stabs	"this:p(0,28)",160,0,24,-12
	.global	__ZNK7GameObj8getWidthEv

.func __ZNK7GameObj8getWidthEv, 1, int
	.line 24
	push rt,fr
	sub  sp,#0x4
	ld   fr,sp
	add  fr,#0xc
	ld   [fr,-12],i0
	.dlab LBB10
	.line 24
	ld   r14,[fr,-12]
	ld   r14,[r14,12]
	.dlab LBE10
	add  sp,#0x4
	pop  rt,fr
	ret
Lscope8:
	.stabs	"_ZN7GameObj8setWidthEi:F(0,6)",36,0,25,__ZN7GameObj8setWidthEi
	.stabs	"this:p(0,25)",160,0,25,-12
	.stabs	"width:p(0,3)",160,0,25,-16
	.global	__ZN7GameObj8setWidthEi

.func __ZN7GameObj8setWidthEi, 2, void
	.line 25
	push rt,fr
	sub  sp,#0x8
	ld   fr,sp
	add  fr,#0x10
	ld   [fr,-12],i0
	ld   [fr,-16],i1
	.dlab LBB11
	.line 25
	ld   r14,[fr,-12]
	ld   r0,[fr,-16]
	ld   [r14,12],r0
	.dlab LBE11
	add  sp,#0x8
	pop  rt,fr
	ret
Lscope9:
	.text
	.stabs "",100,0,0,Letext
Letext:
