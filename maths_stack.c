#include "monty.h"

/* -------------- */
/* MATHS HANDLERS */
/* -------------- */
/* 1. Opcode to metod add */
maths_handler(add, ERROR_ADD)
/* 2. Opcode to sub */
maths_handler(sub, ERROR_SUB)
/* 3. Opcode to sub */
maths_handler(mul, ERROR_MUL)
/* 4. Opcode to div */
maths_handler(divs, ERROR_DIV)
/* 5. Opcode to mod */
maths_handler(mod, ERROR_MOD)

/* --------------------- */
/* CALLS MATHS HANDLERS  */
/* --------------------- */
/* 1. Opcode to metod add */
maths_methods(
	+=, add)
/* 2. Opcode to sub */
maths_methods(
	-=, sub)
/* 3. Opcode to sub */
maths_methods(
	*=, mul)
/* 4. Opcode to div */
maths_methods(
	/=, divs)
/* 5. Opcode to mod */
maths_methods(
	%=, mod)
