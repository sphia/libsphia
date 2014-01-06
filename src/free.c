
#include <stdlib.h>
#include "sphia.h"

/**
 * Free the sphia structure.
 */

void
sphia_free(sphia_t *sphia) {
  if (sphia->env) sp_destroy(sphia->env);
  if (sphia->db) sp_destroy(sphia->db);
  free(sphia);
}
