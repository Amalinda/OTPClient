#pragma once

#include <glib.h>

G_BEGIN_DECLS

gpointer secure_malloc (gsize size);

void secure_free (gpointer ptr);

G_END_DECLS