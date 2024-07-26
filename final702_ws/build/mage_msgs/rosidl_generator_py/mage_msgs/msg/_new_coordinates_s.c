// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from mage_msgs:msg/NewCoordinates.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "mage_msgs/msg/detail/new_coordinates__struct.h"
#include "mage_msgs/msg/detail/new_coordinates__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool mage_msgs__msg__new_coordinates__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("mage_msgs.msg._new_coordinates.NewCoordinates", full_classname_dest, 45) == 0);
  }
  mage_msgs__msg__NewCoordinates * ros_message = _ros_message;
  {  // x_coordinate
    PyObject * field = PyObject_GetAttrString(_pymsg, "x_coordinate");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x_coordinate = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y_coordinate
    PyObject * field = PyObject_GetAttrString(_pymsg, "y_coordinate");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y_coordinate = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * mage_msgs__msg__new_coordinates__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of NewCoordinates */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("mage_msgs.msg._new_coordinates");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "NewCoordinates");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  mage_msgs__msg__NewCoordinates * ros_message = (mage_msgs__msg__NewCoordinates *)raw_ros_message;
  {  // x_coordinate
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x_coordinate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x_coordinate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y_coordinate
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y_coordinate);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y_coordinate", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
