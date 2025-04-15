#include "push_swap.h"

// Función para ejecutar y mostrar una operación
static void	execute_op(t_ring *a, t_ring *b, char *op)
{
    ft_printf("\nExecuting: %s\n", op);
    if (ft_strncmp(op, "sa", 3) == 0)
        swap(a);
    else if (ft_strncmp(op, "sb", 3) == 0)
        swap(b);
    else if (ft_strncmp(op, "ss", 3) == 0)
        ss(a, b);
    else if (ft_strncmp(op, "pa", 3) == 0)
        push(b, a);
    else if (ft_strncmp(op, "pb", 3) == 0)
        push(a, b);
    else if (ft_strncmp(op, "ra", 3) == 0)
        rotate(a, false);
    else if (ft_strncmp(op, "rb", 3) == 0)
        rotate(b, false);
    else if (ft_strncmp(op, "rr", 3) == 0)
        rr(a, b, false);
    else if (ft_strncmp(op, "rra", 4) == 0)
        rotate(a, true);
    else if (ft_strncmp(op, "rrb", 4) == 0)
        rotate(b, true);
    else if (ft_strncmp(op, "rrr", 4) == 0)
        rr(a, b, true);
    print_stack(a, 'A');
    print_stack(b, 'B');
}

// Función principal para demostrar las operaciones básicas
int main(int argc, char **argv)
{
    t_ring *a;
    t_ring *b;
    
    if (argc < 2)
    {
        ft_printf("Usage: %s <numbers>\n", argv[0]);
        return (1);
    }
    // Validación de argumentos
    if (!validate_args(argc, argv))
    {
        ft_printf("Error: Invalid arguments\n");
        return (1);
    }
    
    // Inicialización de stacks
    a = init_ring_a(argc, argv);
    b = init_ring();
    
    if (!a || !b)
    {
        if (a)
            free_ring(a);
        if (b)
            free_ring(b);
        ft_printf("Error: Memory allocation failed\n");
        return (1);
    }
    
    // Mostrar estado inicial
    ft_printf("Initial state:\n");
    print_stack(a, 'A');
    print_stack(b, 'B');
    // Demostración de operaciones
    if (a->size >= 2)
    {
        execute_op(a, b, "sa");
        execute_op(a, b, "ra");
        execute_op(a, b, "rra");
    }
    if (a->size >= 1)
    {
        execute_op(a, b, "pb");
        execute_op(a, b, "pb");
    }
    if (b->size >= 1)
    {
        execute_op(a, b, "rb");
        execute_op(a, b, "rrb");
        execute_op(a, b, "pa");
    }
    // Verificar si está ordenado
    ft_printf("\nIs stack A sorted? %s\n", is_sorted(a) ? "Yes" : "No");
    // Mostrar mínimo y máximo
    if (a->size > 0)
    {
        t_node *min = get_min(a);
        t_node *max = get_max(a);
        
        ft_printf("Min value in stack A: %d (position: %d)\n", 
                min->value, get_position(a, min));
        ft_printf("Max value in stack A: %d (position: %d)\n", 
                max->value, get_position(a, max));
    }
    // Liberar memoria
    free_ring(a);
    free_ring(b);
    return (0);
}
