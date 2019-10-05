# include "vm.h"

void	live(t_vm *vm, t_carry *cr)
{
	unsigned int	dir;
	unsigned char	*ptr;
	int				i;

	cr->last_live = 0;
	vm->live_counter++;
	ptr = (unsigned char*)&dir;
	i = 0;
	while (i < cmd_prms[cr->cmd_code - 1].dir_size)
	{
		ptr[i] = vm->area[cr->position + 1 + i];
		i++;
	}
	if (ft_islitendian())
		dir = ft_reverseint(dir);
	if (dir == cr->reg[0])
		vm->last_alive = dir;
}

void	ld(t_vm *vm, t_carry *cr)
{
	//
}

void	st(t_vm *vm, t_carry *cr)
{
	//
}

void	add(t_vm *vm, t_carry *cr)
{
	//
}

void	sub(t_vm *vm, t_carry *cr)
{
	//
}

void	and(t_vm *vm, t_carry *cr)
{
	//
}

void	or(t_vm *vm, t_carry *cr)
{
	//
}

void	xor(t_vm *vm, t_carry *cr)
{
	//
}

void	zjmp(t_vm *vm, t_carry *cr)
{
	//
}

void	ldi(t_vm *vm, t_carry *cr)
{
	//
}

void	sti(t_vm *vm, t_carry *cr)
{
	//
}

void	frk(t_vm *vm, t_carry *cr)
{
	//
}

void	lld(t_vm *vm, t_carry *cr)
{
	//
}

void	lldi(t_vm *vm, t_carry *cr)
{
	//
}

void	lfrk(t_vm *vm, t_carry *cr)
{
	//
}

void	aff(t_vm *vm, t_carry *cr)
{
	//
}
