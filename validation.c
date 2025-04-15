#include "push_swap.h"

// Función para validar argumentos (verifica que sean números y que no haya duplicados)
int validate_args(int argc, char **argv)
{
    int	i;
	int	j;
    int	num1;
	int	num2;

    for (i = 1; i < argc; i++)
    {
        j = 0;
        while (argv[i][j])
        {
            if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
                j++;
            if (!ft_isdigit(argv[i][j]))
                return (0);
            j++;
        }
        
        // Comprobación de duplicados
        num1 = ft_atoi(argv[i]);
        for (j = 1; j < i; j++)
        {
            num2 = ft_atoi(argv[j]);
            if (num1 == num2)
                return (0);
        }
    }
    return (1);
}

static int	find_duplicate(int argc, char	**argv);
