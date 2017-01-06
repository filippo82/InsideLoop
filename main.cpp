//==============================================================================
//
//                                  InsideLoop
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.txt for details.
//
//==============================================================================

#include <il/format.h>
#include <il/String.h>

int main() {
  il::String name{"Hello"};

  il::print("  String: {}\n", name.c_str());
  il::print("Is small: {}\n", name.is_small());
  il::print("    Size: {}\n", name.size());
  il::print("Capacity: {}\n", name.capacity());

  return 0;
}
