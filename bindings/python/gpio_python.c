#include <Python.h>

#include "libsoc_gpio.h"

static PyMethodDef functions[] = {
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static void
_add_constants(PyObject *m)
{
  PyModule_AddIntConstant(m, "DIRECTION_ERROR", DIRECTION_ERROR);
  PyModule_AddIntConstant(m, "DIRECTION_INPUT", INPUT);
  PyModule_AddIntConstant(m, "DIRECTION_OUTPUT", OUTPUT);

  PyModule_AddIntConstant(m, "LEVEL_ERROR", LEVEL_ERROR);
  PyModule_AddIntConstant(m, "LEVEL_LOW", LOW);
  PyModule_AddIntConstant(m, "LEVEL_HIGH", HIGH);

  PyModule_AddIntConstant(m, "EDGE_ERROR", EDGE_ERROR);
  PyModule_AddIntConstant(m, "EDGE_RISING", RISING);
  PyModule_AddIntConstant(m, "EDGE_FALLING", FALLING);
  PyModule_AddIntConstant(m, "EDGE_NONE", NONE);
  PyModule_AddIntConstant(m, "EDGE_BOTH", BOTH);

  PyModule_AddIntConstant(m, "LS_SHARED", LS_SHARED);
  PyModule_AddIntConstant(m, "LS_GREEDY", LS_GREEDY);
  PyModule_AddIntConstant(m, "LS_WEAK", LS_WEAK);
}


#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "_libsoc",
        NULL,
        -1,
        functions,
        NULL,
        NULL,
        NULL,
        NULL
};

PyMODINIT_FUNC
PyInit__libsoc(void) {
  PyObject *m;
  m = PyModule_Create(&moduledef);
  if (!m)
   return NULL;
  _add_constants(m);
  return m;
}
#else
PyMODINIT_FUNC
init_libsoc(void)
{
  PyObject *m;
  m = Py_InitModule ("_libsoc", functions);
  _add_constants(m);
}
#endif