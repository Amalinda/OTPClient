#include <glib.h>

static gpointer
guaranteed_memset (gpointer v, gint c, gsize n) {
    volatile char *p = v;
    while (n--) *p++ = c;
    return v;
}

gpointer
secure_malloc (gsize size)
{
    /* Store the memory area size in the beginning of the block */
    gpointer ptr = malloc(size + 8);
    *((gsize *)ptr) = size;
    return ptr + 8;
}

void
secure_free (gpointer ptr)
{
    ptr -= 8;
    gsize size = *((gsize *)ptr);

    guaranteed_memset (ptr, 0, size + 8);
    free (ptr);
}