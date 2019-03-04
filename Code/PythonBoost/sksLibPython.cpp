/*=============================================================================

  SKSURGERYOPENCVCPP: Image-guided surgery functions, in C++, using OpenCV.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/
#include <boost/python.hpp>
#include <boost/python/exception_translator.hpp>
#include "sksMyFunctions.h"
#include "sksException.h"

#include <ostream>
#include <sstream>

namespace sks {

void translate_exception(Exception const& e)
{
  std::ostringstream ss;
  ss << e.GetDescription();
  ss << " in file:" << e.GetFileName();
  ss << ", line:" << e.GetLineNumber();
  PyErr_SetString(PyExc_RuntimeError, ss.str().c_str());
}

// The name of the module should match that in CMakeLists.txt
BOOST_PYTHON_MODULE(sksurgeryopencvpython)
{
  boost::python::def("my_first_add_function", sks::MyFirstAddFunction);
}

}  // end namespace sks