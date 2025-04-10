#include "push_swap.h"

// Función para imprimir el contenido de un stack
void print_stack(t_ring *ring, char stack_name)
{
    t_node *current;
    int i;
    
    if (!ring || ring->size == 0)
    {
        ft_printf("Stack %c: [empty]\n", stack_name);
        return;
    }
    
    ft_printf("Stack %c: [", stack_name);
    current = ring->head;
    i = 0;
    while (i < ring->size)
    {
        ft_printf("%d", current->value);
        if (i < ring->size - 1)
            ft_printf(", ");
        current = current->next;
        i++;
    }
    ft_printf("] (size: %d)\n", ring->size);
}

// Función para ejecutar y mostrar una operación
void execute_op(t_ring *a, t_ring *b, char *op)
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
        rotate(a);
    else if (ft_strncmp(op, "rb", 3) == 0)
        rotate(b);
    else if (ft_strncmp(op, "rr", 3) == 0)
        rr(a, b);
    else if (ft_strncmp(op, "rra", 4) == 0)
        r_rotate(a);
    else if (ft_strncmp(op, "rrb", 4) == 0)
        r_rotate(b);
    else if (ft_strncmp(op, "rrr", 4) == 0)
        rrr(a, b);
    
    print_stack(a, 'A');
    print_stack(b, 'B');
}

// Función para validar argumentos (verifica que sean números y que no haya duplicados)
int validate_args(int argc, char **argv)
{
    int i, j;
    int num1, num2;
    
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

// Función para inicializar el stack A con los argumentos
t_ring *init_stack_a(int argc, char **argv)
{
    t_ring *a;
    t_node *new_node;
    int i;
    
    a = init_ring();
    if (!a)
        return (NULL);
    
    for (i = 1; i < argc; i++)
    {
        new_node = create_node(ft_atoi(argv[i]));
        if (!new_node)
        {
            free_ring(a);
            return (NULL);
        }
        add_back(a, new_node);
    }
    
    return (a);
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
    a = init_stack_a(argc, argv);
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
